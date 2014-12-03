#fichié outdated, NE PAS UTILISER
echo "A = mode actif   ###   P = mode passif"
echo " "
echo " "
while : # Équialent du while(1)
do
  read ouinon                                             # Lit le clavier
  if [ "$ouinon" = "A" ] || [ "$ouinon" = "a" ]; then     # Si l'utilisateur entre a ou A
     echo "Actif" | tee keyboard                          # Écrit Actif dans un fichier
  elif [ "$ouinon" = "P" ] || [ "$ouinon" = "p" ]; then   # Si l'utilisateur entre p ou P
     echo "Passif" | tee keyboard                         # Écrit Passif dans un fichier
  else                                                    # Si autre lettre, écrit autre chose
     echo "Seuls les lettres aApP sont acceptées, pas $ouinon" #| tee keyboard
     echo "" | tee keyboard                               # Vide le fichier de récetion du clavier
  fi
done