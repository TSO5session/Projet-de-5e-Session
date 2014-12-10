LastCommand="$(tail -1 histocan)"                  # Lit la dernière trame CAN reçue
echo "$LastCommand" > "LastCAN"                    # Met la dernière trame reçue dans le fichier LastCAN
var="$(grep -o '^......................' LastCAN)" # Met la partie invariable (sans timestamp) de la trame dans le fichier LastCAN
############START
if [ "$var" == "  can0    6  [7] 00 00" ]; then
   echo " "
   echo "*********************************"
   echo " START the car (00 00)"
fi
############STOP
if [ "$var" == "  can0    6  [7] 00 01" ]; then
   echo " "
   echo "*********************************"
   echo " STOP the car (00 01)"
fi
############HAS STOPPED
if [ "$var" == "  can0    6  [7] 01 00" ]; then
   echo " "
   echo "*********************************"
   echo " The car has stopped(01 00)"
fi
############IS MOVING
if [ "$var" == "  can0    6  [7] 01 01" ]; then
   echo " "
   echo "*********************************"
   echo " The car is moving (01 01)"
fi
