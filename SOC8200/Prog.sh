compteur=0 # Initialisation de variables
flagetat=0 # Initialisation de variables
PIDCAN=0   # Initialisation de variables
#------------------------------------------# Initialisation des leds
echo -n 0 > /sys/class/leds/led/brightness #
echo 0 > /sys/class/misc/beep/val          #
#--------------------------------------------------------------------# CAN init
/usr/bin/ip link set can0 down                                       #
/usr/bin/ip link set can0 type can bitrate 125000 triple-sampling on #
/usr/bin/ip link set can0 up                                         #
#--------------------------------------------------------------------#
#-------------# Démarrage de scripts externes asychrones
./portserie & # Démarrage du port série
./RxCan &     # Démarrage du bus  CAN
#-------------#
while true
do
  #-----------------------------------------------------# Lecture "asychrone" du clavier via passe passe du coyote
  read -t 1 output                                      # Lit le clavier avec un timout
  #-----------------------------------------------------#
  if   [ "$output" = "A" ] || [ "$output" = "a" ]; then # Si l'utilisateur entre a ou A
       echo "Actif"         | tee mode                  # Écrit Actif dans un fichier
  elif [ "$output" = "P" ] || [ "$output" = "p" ]; then # Si l'utilisateur entre p ou P
       echo "Passif"        | tee mode                  # Écrit Passif dans un fichier#  
  fi #--------------------------------------------------#
maVar="$(cat mode)"                                     #Met le contenu du fichier mode dans maVar
#----------------------------------------------# Gestion du mode passif
if [ "$maVar" = "Passif" ]; then               #
 if grep -q "Allo" ./hbeat                     # Si un heartbeat est recu
   then                                        #
     echo "Non-recu" > ./hbeat                 #
     echo -n 0 >/sys/class/leds/led/brightness # Fait clignotter la lumière
     sleep 1                                   # Fait clignotter la lumière
     echo -n 1 >/sys/class/leds/led/brightness # Fait clignotter la lumière
     compteur=0                                #
     if [ $flagetat -eq 1 ]                    #
       then                                    #
         echo PASSIF                           #
         kill $PIDCAN                          # Tue le processus CAN
     fi                                        #
   flagetat=0                                  #
 fi                                            #
fi                                             #
#----------------------------------------------# Gestion du mode actif
if [ "$maVar" = "Actif" ]; then                #
 if grep -q "Non-recu" ./hbeat                 # Si les heartbeats ne sont pas reçus
  then                                         #
    echo -n 0 > /sys/class/leds/led/brightness # Éteint la lumière
    let "compteur+=1"                          # On incremente le compteur de min.
     if [ $compteur -eq 10 ]                   # Si on atteint deux minutes
       then                                    #
         echo 1 > /sys/class/misc/beep/val     # Fait sonner le buzzer
         sleep 1                               # Attend une seconde
         echo 0 > /sys/class/misc/beep/val     # Fait sonner le buzzer
         compteur=0                            #
         if [ $flagetat -eq 0 ]                # Si tu n'est pas le master du bus CAN
           then                                #
             ./can &                           # Démarre un processus CAN
             PIDCAN=$!                         # Enregistre son PID
             echo ACTIF                        # Mode = actif
             flagetat=1                        # Devient le master du bus CAN
         fi                                    #
     else                                      #
       sleep 1                                 #
     fi                                        #
 fi                                            #
fi                                             #
#----------------------------------------------# 
echo "Allo" > /dev/ttySCMA0                    # Envoi la string Allo à chaque secs
done                                           # Fin de la boucle de while 1
exit 0                                         # Fin du script
#----------------------------------------------#
