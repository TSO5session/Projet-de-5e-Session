maVar="$(cat histocan)"
echo $maVar > /dev/ttySCMA0
#if [ -f histocan ]; then             # Vérifie si mon fichier est un fichier
#   for line in "$(cat histocan)"; # Pour chaque ligne du fichier passé en paramètre
#   do 
#     echo $line > /dev/ttySCMA0                
#   done                                       # Fin du scan de l'historique
#fi


