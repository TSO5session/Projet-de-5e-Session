compteur=0
while true
do
echo "Allo" > /dev/ttySCMA0 #Envoi la string Allo à chaque sec
if grep -qs Allo /dev/ttySCMA0 #Vérifie si un Allo à été recu
  then
   echo -n 1 >/sys/class/leds/led/brightness
   > /dev/ttySCMA0             #Efface le port série 
   sleep 1
   echo -n 0 >/sys/class/leds/led/brightness
   compteur=0 
  else
   sleep 1
   let "compteur+=1"       #On incremente le compteur de min.
   if [ $compteur -eq 30 ]              #Si on atteint deux minutes
   then
     echo 1 > /sys/class/misc/beep/val
     sleep 1                             #Attend une seconde
     echo 0 > /sys/class/misc/beep/val  
     compteur=0 
   fi
fi
done
