maVar="$(cat histocan)"
echo $maVar > /dev/ttySCMA0
#if [ -f histocan ]; then             # V�rifie si mon fichier est un fichier
#   for line in "$(cat histocan)"; # Pour chaque ligne du fichier pass� en param�tre
#   do 
#     echo $line > /dev/ttySCMA0                
#   done                                       # Fin du scan de l'historique
#fi


