# Note: cette méthode fonctionne sur un vrai système linux, mais pas sur le SOC2800

var="can0 6 [7] 00 00 0E 12 23 00 00"
DeviceData="${var:11:5}"              # Dissecte les données CAN et exracte les données sur la commande
Data="${var:17:8}"                    # Dissecte les données CAN et exracte la timestamp 
echo "************Trame brute****************** "
echo "$var"
echo "************Infos sur la commande******** "
echo "$DeviceData"
echo "************TimeStamp******************** "
echo "$Data"
##################COULEUR DU BLOC#########################
if [ "$DeviceData" = "00 00" ] # Si un bloc métallique est recu
   then
     echo "************Output************ "
     echo "Start the engine | TimeStamp = $Data"
   fi
       
if [ "$DeviceData" = "00 01" ] # Si un bloc métallique est recu
   then
     echo "************Output************ "
     echo "Stop the engine | TimeStamp = $Data"
   fi
exit 0