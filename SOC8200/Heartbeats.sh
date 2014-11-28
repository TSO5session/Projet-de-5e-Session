Compteur=0
export Actif=0
if [ $1 == "actif" ]
 then
  Actif=1
 else
  Actif=0
fi
#bash Can Actif &
while :
do
 if [ grep -w "Allo" /dev/ttySCMA0 ]   #Si on trouve Allo dans le port
  then
   > ttySCMA0                          #Efface le fichier
   com_norts -d  /dev/ttySCMA0 -s Allo #Envoi la string Allo à chaque sec
   sleep 1                             #Attend une seconde
 else
   Compteur='expr $Compteur + 1'       #On incremente le compteur de min.
   if [ $Compteur -gt "120" ]              #Si on atteint deux minutes sans reception de Allo 
    then
    kill $(ps -o pid= --ppid $$)       #On tue le process enfant
     Actif=1   
     Compteur=0  
    bash Can Actif &                   #On relance le programme de can avec le parametre actif 
   fi
 fi
done
exit 0
