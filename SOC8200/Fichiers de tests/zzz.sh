var="can0 6 [7] 00 01 0E 12 23 00 00"
echo $var | cut -c1-4 $var





#IP="192.168.1.5"
#echo $IP | cut -f1-3 -d"."







exit 0
##################COULEUR DU BLOC#########################
if [[ $var == *"can0 6 [7] 00 00"* ]]
   then
     echo "************Output************ "
     echo "Start the engine | Identifiant CAN = 00 00"
   fi
       
if [[ $var == *"can0 6 [7] 00 01"* ]]
   then
     echo "************Output************ "
     echo "Stop the engine | Identifiant CAN = 00 00"
   fi
   echo " "
   echo " "
exit 0