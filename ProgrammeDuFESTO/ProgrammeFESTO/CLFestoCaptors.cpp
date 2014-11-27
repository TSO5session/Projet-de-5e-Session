// **************************CLFestoCaptors.cpp
// Auteur:       Vincent Chouinard
// Date:         27 novembre 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.10
//
// Description:
// *****************************************************************************
#include "_DeclarationGenerale.h"  // Raccourcis de programmation & variables
#include "CLFestoCaptors.h"             


//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
CLFestoCaptors :: CLFestoCaptors(void)
{

}

//******************************************************************************
//                            LE CONSTRUCTEUR INITIALISATEUR
// *****************************************************************************
CLFestoCaptors :: CLFestoCaptors(UC ucParametre)
{

}

// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
CLFestoCaptors :: ~CLFestoCaptors(void)
{

}

// **********************FONCTION: readCapacitiveCaptor()
//
// DESCRIPTION        : Lit le capteur capacitif et retourne la valeur lue
//
// INCLUDE            : "_DeclarationGenerale.h" "CLFestoCaptors.h"
//                      
// PROTOTYPE          : UC readOpticCaptor(void)
//
// PROCEDURE D'APPEL  : data = readOpticCaptor()
//
// PARAMETRE D'ENTREE : AUCUN
//
// PARAMETRE DE SORTIE: UC
//
// Auteur             : Vincent Chouinard
// Date               : 25 novembre 2014   (Version 1.0)
// Modification       :
// *****************************************************************************
UC CLFestoCaptors :: ReadCapacitiveCaptor (void)
{
return(PCF3.Read());
}

// **********************FONCTION: readOpticCaptor()
//
// DESCRIPTION        : Lit le capteur optique et retourne la valeur lue
//
// INCLUDE            : "_DeclarationGenerale.h" "CLFestoCaptors.h"
//                      
// PROTOTYPE          : UC readOpticCaptor(void)
//
// PROCEDURE D'APPEL  : data = readOpticCaptor()
//
// PARAMETRE D'ENTREE : AUCUN
//
// PARAMETRE DE SORTIE: UC
//
// Auteur             : Vincent Chouinard
// Date               : 25 novembre 2014   (Version 1.0)
// Modification       :
// *****************************************************************************
UC CLFestoCaptors :: ReadOpticCaptor (void)
{
return(PCF3.Read()); 
}

// **********************FONCTION: readMagneticCaptor()
//
// DESCRIPTION        : Lit le capteur magnétique et retourne la valeur lue
//
// INCLUDE            : "_DeclarationGenerale.h" "CLFestoCaptors.h"
//                      
// PROTOTYPE          : UC readInductiveCaptor(void)
//
// PROCEDURE D'APPEL  : data = readInductiveCaptor()
//
// PARAMETRE D'ENTREE : AUCUN
//
// PARAMETRE DE SORTIE: UC
//
// Auteur             : Vincent Chouinard
// Date               : 25 novembre 2014   (Version 1.0)
// Modification       :
// *****************************************************************************
UC CLFestoCaptors :: ReadInductiveCaptor (void)
{
return(PCF3.Read());   
}

// **********************FONCTION: readHeightCaptor()
//
// DESCRIPTION        : Lit le capteur de hauteur du bloc
//
// INCLUDE            : "_DeclarationGenerale.h" "CLFestoCaptors.h"
//                      
// PROTOTYPE          : UC readHeightCaptor(void)
//
// PROCEDURE D'APPEL  : data = readHeightCaptor()
//
// PARAMETRE D'ENTREE : AUCUN
//
// PARAMETRE DE SORTIE: UC
//
// Auteur             : Vincent Chouinard
// Date               : 25 novembre 2014   (Version 1.0)
// Modification       :
// *****************************************************************************
UC CLFestoCaptors :: ReadHeightCaptor (void)
{
return(PCF4.Read());
}

// **********************FONCTION: readPreVentouseCaptor()
//
// DESCRIPTION        : Lit le dernier capteur avant que la ventouse ne prenne le bloc
//
// INCLUDE            : "_DeclarationGenerale.h" "CLFestoCaptors.h"
//                      
// PROTOTYPE          : UC readPreVentouseCaptor(void)
//
// PROCEDURE D'APPEL  : data = readPreVentouseCaptor()
//
// PARAMETRE D'ENTREE : AUCUN
//
// PARAMETRE DE SORTIE: UC
//
// Auteur             : Vincent Chouinard
// Date               : 25 novembre 2014   (Version 1.0)
// Modification       :
// *****************************************************************************
UC CLFestoCaptors :: ReadPreVentouseCaptor(void)
{
return(PCF4.Read());  
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX