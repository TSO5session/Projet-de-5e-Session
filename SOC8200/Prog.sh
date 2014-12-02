compteur=0  
flagetat=0
PIDCAN=0

echo -n 0 > /sys/class/leds/led/brightness
echo 0 > /sys/class/misc/beep/val

/usr/bin/ip link set can0 down
/usr/bin/ip link set can0 type can bitrate 125000 triple-sampling on
/usr/bin/ip link set can0 up

./portserie & # Démarrage du port série
./RxCan &     # Démarrage du bus  CAN
#./read.sh &   # Lecture synchrone du clavier

while true
do 
 if grep -q "Allo" ./hbeat                     # Si un heartbeat est recu
   then
     echo "Non-recu" > ./hbeat
     echo -n 0 >/sys/class/leds/led/brightness # Fait clignotter la lumière
     sleep 1                                   # Fait clignotter la lumière
     echo -n 1 >/sys/class/leds/led/brightness # Fait clignotter la lumière
     compteur=0
     if [ $flagetat -eq 1 ]
       then
         echo PASSIF
         kill $PIDCAN        # Tue le processus CAN
     fi  
    flagetat=0 
 fi 
 

 if grep -q "Non-recu" ./hbeat                 # Si les heartbeats ne sont pas reçus
  then
    echo -n 0 > /sys/class/leds/led/brightness # Éteint la lumière
    let "compteur+=1"                          # On incremente le compteur de min.
     if [ $compteur -eq 10 ]                   # Si on atteint deux minutes
       then
         echo 1 > /sys/class/misc/beep/val     # Fait sonner le buzzer
         sleep 1                               # Attend une seconde
         echo 0 > /sys/class/misc/beep/val     # Fait sonner le buzzer  
         compteur=0
         if [ $flagetat -eq 0 ]                # Si tu n'est pas le master du bus CAN
           then
             ./can &                           # Démarre un processus CAN
             PIDCAN=$!                         # Enregistre son PID
             echo ACTIF                        # Mode = actif
             flagetat=1                        # Devient le master du bus CAN
         fi
     else
       sleep 1   
     fi
 fi
echo "Allo" > /dev/ttySCMA0 #Envoi la string Allo à chaque secs 
done
exit 0

