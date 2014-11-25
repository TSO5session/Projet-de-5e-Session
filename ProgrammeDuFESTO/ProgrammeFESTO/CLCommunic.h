//**********************  Fichier: CLCommunic.h
//  Description : Fichier d'entete pour le fichier CLCommunic.cpp
//                version miniminaliste pour carte Dallas
//  Composition : aucune
//  Heritage    : aucun
//
//  Programmeur : Vincent Chouinard
//  Cours       : 247-436
//                                                                           
//  Date        : 10 avril 2014
//                                                                           
//  Compilateur : IAR 8.1                                  
//                                                                           
//  Modification:                                                            
//                                                                           
///////////////////////////////////////////////////////////////////////////////
#ifndef CLCOMMUNICH               // Si CLCOMMUNICH non defini.
   #define CLCOMMUNICH            // Defini CLCOMMUNICH

#include <stdio.h>               // Definition des function I/O (printf, getchar
#include "_DeclarationGenerale.h" // Pour les declaration generale
#include "TypeCible.h"            // Pour les definition des registre.
#include "ConversionKeilToIAR.h"  //

class RS232            
{
public:                     
   RS232(void);                                    // Constructeur par defaut.
   RS232(UC ucLongBuf, UC ucLongTrame, UI uiBaud); // Constructeur initialisateur                                   
  ~RS232(void);                                    // Destructeur
  
   void SendString (char const *ucpMessage);      // Envoyer un string
   void SendCar    (char Caractere);
   char GetCar     (void);
                                    
protected:
  
private:                      
   void SetConfig(void);
}; 
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
















