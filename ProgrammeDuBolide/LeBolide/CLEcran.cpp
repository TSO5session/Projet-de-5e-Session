// ************************** FICHIER: CLEcran.CPP  ****************************
//
//  Fonctions de controle pour LCD.
//
//  Application realisee avec IAR C++ 8.10
//
//  LIMITATION DU COMPILATEUR:
//    Impossible de faire de l'heritage multiple.
//
//  Note: on peut utiliser XAR pour creer des librairies.
//  On peut mettre les librairies dans le projets et Exclure de la compilation
//  les modules qui sont contenus dans la librairie.
//
//  AUTEUR : LOUIS-NORMAND ANG HOULE
//  DATE CREATION :    2014/02/20       VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
// *****************************************************************************

#include "CLEcran.h" 


// Constructeur par defaut //////////////////////////////////////////////////// 
CLEcran :: CLEcran(void)
 {
 uiAdresseEcran = 0xF800;
 vLCDInit();
 }

// Constructeur par defaut //////////////////////////////////////////////////// 
CLEcran :: CLEcran(USI uiAdresse)
 {
 uiAdresseEcran = uiAdresse;
 vLCDInit();
 }

// Destructeur ////////////////////////////////////////////////////////////////
CLEcran :: ~CLEcran(void)
 {
 vLCDClr();
 }

///////////////////////////////////////////////////////////////////////////////
// void CLEcran :: vDelaiLCD(USI uiDelai)
///////////////////////////////////////////////////////////////////////////////
//
// Description: 
// Fonction de delai pour l'ecran LCD
//
// Parametres d'entrees: 
// - uiDelai: temps de delai; maximum de 65535 operations 
//            
// Parametres de sortie: null
//
// Appel de la fonction: vDelaiLCD(UI uiDelai);
//
// Cree le  10 octobre 2013 par Louis-Normand Ang Houle 
// 
// Modifications:   
// -
//
//
///////////////////////////////////////////////////////////////////////////////

void CLEcran :: vDelaiLCD(USI uiDelai)
{
 USI i;
 for(i=0;i<=uiDelai; i++);
}

///////////////////////////////////////////////////////////////////////////////
// void CLEcran :: vLCDBusy(void)
///////////////////////////////////////////////////////////////////////////////
//
// Description: 
// Attente de la descente du flag BUSY
//
// Parametres d'entrees: null            
// Parametres de sortie: null
//
// Appel de la fonction: vLCDBusy();
//
// Cree le 10 octobre 2013 par Louis-Normand Ang Houle 
// 
// Modifications:   
// -
//
//
///////////////////////////////////////////////////////////////////////////////

void CLEcran :: vLCDBusy(void)
 {
 while(ucIn(uiAdresseEcran + ECRANFLAG) & 0x80);
 }

///////////////////////////////////////////////////////////////////////////////
// void CLEcran :: vLCDClr(void)
///////////////////////////////////////////////////////////////////////////////
//
// Description: 
// Essuie l'ecran, remise du curseur a la position initiale
// 
// Parametres d'entrees: null      
// Parametres de sortie: null
//
// Appel de la fonction: LCDClr();
// 
// Cree le 10 octobre 2013 par Louis-Normand Ang Houle 
// 
// Modifications:   
// -
//
//
///////////////////////////////////////////////////////////////////////////////

void CLEcran :: vLCDClr(void)
 {
   vLCDBusy();
   vOut(uiAdresseEcran + ECRANCONFIG, 0x01);
 }

///////////////////////////////////////////////////////////////////////////////
// void CLEcran :: vLCDInit(void)
///////////////////////////////////////////////////////////////////////////////
//
// Description: 
// Initialisation de l'ecran.
//
// Parametres d'entrees: null            
// Parametres de sortie: null
//
// Appel de la fonction: vLCDInit()
//
// Cree le 10 octobre 2013 par Louis-Normand Ang Houle 
// 
// Modifications:   
// -
//
//
///////////////////////////////////////////////////////////////////////////////

void CLEcran :: vLCDInit(void)
 {
   USI i;
   for(i=0; i<=3; i++)             //Faire 3 fois
    {    
     vDelaiLCD(10000);             //Attendre la stabilisation des parametres
     vOut(uiAdresseEcran + ECRANCONFIG,0x38);    //
    }   
   vLCDBusy();                                    //Attente du Busy Flag
   vOut(uiAdresseEcran + ECRANCONFIG, 0x38);      //
   vLCDBusy();                                    //Attente du Busy Flag
   vOut(uiAdresseEcran + ECRANCONFIG, 0x01);      //
   vLCDBusy();                                    //Attente du Busy Flag
   vOut(uiAdresseEcran + ECRANCONFIG, 0x0C);      //
   vLCDBusy();                                    //Attente du Busy Flag
   vOut(uiAdresseEcran + ECRANCONFIG, 0x06);      //
 }

///////////////////////////////////////////////////////////////////////////////
// void CLEcran :: vLCDCursor(UC ucCol, UC ucLine)
///////////////////////////////////////////////////////////////////////////////
//
// Description: 
// Deplacement du curseur pour une ecriture sur l'ecran LCD
//
// Parametres d'entrees:
// -ucCol : Definition de la position "X" du curseur 
// -ucLine:   Definition de la position "Y" du curseur
//             
// Parametres de sortie: null
//
// Appel de la fonction: vLCDCursor (ucCol, ucLine)
//
// Cree le 10 octobre 2013 par Louis-Normand Ang Houle 
// 
// Modifications:   
// -
//
//
///////////////////////////////////////////////////////////////////////////////

void CLEcran :: vLCDCursor(UC ucCol, UC ucLine)
 {
 UC ucPosition;
 switch (ucLine)
 { 
 case 1:            //Si ligne 1   choisi
 ucPosition = 0x00 + ucCol;      //Curseur sur ligne 1 (1,Y)
 break;

 case 2:                           //Si ligne 2   choisi
 ucPosition = 0x40 + ucCol;      //Curseur sur ligne 2 (2,Y)
 break;

 case 3:                           //Si ligne 3   choisi
 ucPosition = 0x14 + ucCol;      //Curseur sur ligne 3 (3,Y)
 break;

 case 4:                           //Si ligne 4   choisi 
 ucPosition = 0x54 + ucCol;      //Curseur sur ligne 4 (4,Y)
 break;

 default:                        //Sinon
 ucPosition = 0x00 + ucCol;      //Curseur à position initial (0,0)
 break;
 }
 ucPosition = ucPosition | 0x80; //Definition du registre du curseur

 vLCDBusy();                     //Attente du Flag Busy
 vOut(uiAdresseEcran+ECRANCONFIG, ucPosition); //Envoi de la commande 
 }

///////////////////////////////////////////////////////////////////////////////
// void CLEcran :: vLCDDisplayCarac(UC ucCaractere)
///////////////////////////////////////////////////////////////////////////////
//
// Description: Affichage d'un caractere ASCII sur l'ecran LCD
//
// Parametres d'entrees: 
// -ucCaractere: Caractere ASCII a afficher
//            
// Parametres de sortie: null 
//
// Appel de la fonction: vLCDDisplayCarac('ucCaractere'); 
//
// Cree le 10 octobre 2013 par Louis-Normand Ang Houle 
// 
// Modifications:   
// -
//
//
///////////////////////////////////////////////////////////////////////////////

void CLEcran :: vLCDDisplayCarac(UC ucCaractere) 
 {
 vLCDBusy();
 vOut(uiAdresseEcran+ECRANWR, ucCaractere);
 } 

void CLEcran :: vLCDDisplayCarac(char cCaractere)
{
  vLCDBusy();
  vOut(uiAdresseEcran+ECRANWR, cCaractere);
}


///////////////////////////////////////////////////////////////////////////////
// void CLEcran :: vHexToASCII(UC ucHexCar, UC *ucpHi, UC *ucpLo)
///////////////////////////////////////////////////////////////////////////////
//
// Description: Conversion de nombres hexadecimaux en ASCII
//
// Parametres d'entrees: 
// -ucHexCar: Byte hexadecimal a convertir
// -*ucHi   : MSB du byte a convertir 
// -*ucLo   : LSB du byte a convertir
//            
// Parametres de sortie: null
//
// Appel de la fonction: vHexToASCII(ucHexCar, *ucHi, *ucLo)
//
// Cree le 10 octobre 2013 par Louis-Normand Ang Houle 
// 
// Modifications:   
// -
//
//
///////////////////////////////////////////////////////////////////////////////

void CLEcran :: vHexToASCII(UC ucHexCar, UC *ucpHi, UC *ucpLo)
 {
  UC ucTemp;
  ucTemp = ucHexCar;

  *ucpHi = ucTemp >> 4;
  *ucpLo = ucHexCar & 0x0F;
   
  if( *ucpHi <= 9 )          //SI MSB est chiffe
  {
   *ucpHi = *ucpHi + 0x30;  //Convertion hexa a ASCII (Chiffre)
  }
  else                      //SINON
  {
   *ucpHi = *ucpHi + 0x37;    //Convertion hexa a ASCII (Lettre)
  }

  if(*ucpLo <= 9 )          //SI LSB est chiffre
  {
   *ucpLo = *ucpLo + 0x30;    //Convertion hexa a ASCII (Chiffre)
  }
  else                      //SINON
  {
   *ucpLo = *ucpLo + 0x37;    //Convertion hexa a ASCII (Lettre)
  }
 }

////////////////////////////////////////////////////////////////////////////////

void CLEcran :: vHexToASCII(USI uiHexCar, UC *ucpHiOctHi, UC *ucpLoOctHi, 
                                          UC *ucpHiOctLo, UC *ucpLoOctLo)
 { 
  *ucpHiOctHi = (uiHexCar >> 12) & 0x0F;
  *ucpLoOctHi = (uiHexCar >> 8 ) & 0x0F;
    
  *ucpHiOctLo = (uiHexCar >> 4 ) & 0x0F;
  *ucpLoOctLo =  uiHexCar        & 0x0F;
  
//------------------------------------------------------------------------------
  if( *ucpHiOctHi <= 9 )          //SI MSB est chiffe
  {
   *ucpHiOctHi = *ucpHiOctHi + 0x30;  //Convertion hexa a ASCII (Chiffre)
  }
  else                         //SINON
  {
   *ucpHiOctHi = *ucpHiOctHi + 0x37; //Convertion hexa a ASCII (Lettre)
  }
//------------------------------------------------------------------------------
  if(*ucpLoOctHi <= 9 )          //SI LSB est chiffre
  {
   *ucpLoOctHi = *ucpLoOctHi + 0x30;    //Convertion hexa a ASCII (Chiffre)
  }
  else                         //SINON
  {
    *ucpLoOctHi = *ucpLoOctHi + 0x37; //Convertion hexa a ASCII (Lettre)
  }
//------------------------------------------------------------------------------
  if(*ucpHiOctLo <= 9 )          //SI MSB est chiffre
  {
   *ucpHiOctLo = *ucpHiOctLo + 0x30;    //Convertion hexa a ASCII (Chiffre)
  }
  else                         //SINON
  {
   *ucpHiOctLo = *ucpHiOctLo + 0x37;    //Convertion hexa a ASCII (Lettre)
  }
//------------------------------------------------------------------------------
  if(*ucpLoOctLo <= 9 )          //SI LSB est chiffre
  {
   *ucpLoOctLo = *ucpLoOctLo + 0x30;    //Convertion hexa a ASCII (Chiffre)
  }
  else                         //SINON
  {
   *ucpLoOctLo = *ucpLoOctLo + 0x37;    //Convertion hexa a ASCII (Lettre)
  }
//------------------------------------------------------------------------------
 }

///////////////////////////////////////////////////////////////////////////////
// void CLEcran :: vLCDDisplayHexCarac(UC ucHexCar)
///////////////////////////////////////////////////////////////////////////////
//
// Description: 
// Affiche, en hexadecimal, la variable d'entree dans la fonction
//
//
// Parametres d'entrees:  
// -ucHexcar: Caractere a afficher 
//           
// Parametres de sortie: null
//
// Appel de la fonction: vLCDDisplayHexCarac();
//
// Cree le 10 octobre 2013 par Louis-Normand Ang Houle 
// 
// Modifications:   
// -
//
//
///////////////////////////////////////////////////////////////////////////////

void CLEcran :: vLCDDisplayHexCarac(UC ucHexCar)
 {
  UC ucHi;      
  UC ucLo;      

  vHexToASCII(ucHexCar, &ucHi, &ucLo);   //Conversion de Hexadecimal a ASCII

  vLCDDisplayCarac(ucHi);            //Affiche MSB
  vLCDDisplayCarac(ucLo);            //Affiche LSB
 } 

////////////////////////////////////////////////////////////////////////////////
void CLEcran :: vLCDDisplayHexCarac(USI uiHexCar)
 {
  UC ucHiOctHi;      
  UC ucLoOctHi;
  
  UC ucHiOctLo;
  UC ucLoOctLo;

  vHexToASCII(uiHexCar, &ucHiOctHi, &ucLoOctHi, &ucHiOctLo, &ucLoOctLo);

  vLCDDisplayCarac(ucHiOctHi);            //Affiche MSB OctHI
  vLCDDisplayCarac(ucLoOctHi);            //Affiche LSB OctHI
  
  vLCDDisplayCarac(ucHiOctLo);            //Affiche MSB OctLO
  vLCDDisplayCarac(ucLoOctLo);            //Affiche LSB OctLO
 } 


///////////////////////////////////////////////////////////////////////////////
// void CLEcran :: vLCDDisplayCaracChain(const UC *ucpMessage)
// void CLEcran ::vLCDDisplayCaracChain (const char *cpMessage)
///////////////////////////////////////////////////////////////////////////////
//
// Description: Affiche une chaine de caracteres sur l'ecran LCD
//
// Parametres d'entrees:
// *ucpMessage: Pointeur vers le début d'une chaine de caracteres
//             
// Parametres de sortie: null
//
// Appel de la fonction: vLCDDisplayCaracChain("UC *ucpMessage");
//
// Cree le 10 octobre 2013 par Louis-Normand Ang Houle 
// 
// Modifications:   
// -
//
//
///////////////////////////////////////////////////////////////////////////////

void CLEcran :: String(const UC *ucpMessage)
 {                           
  while (*ucpMessage != 0x00)
   {
      vLCDDisplayCarac(*ucpMessage);
      ucpMessage++;
   }
 }  

void CLEcran :: String (const char *cpMessage)
 {
    while (*cpMessage != 0x00)
     {
        vLCDDisplayCarac(*cpMessage);
        cpMessage++;
     }
 } 

 
///////////////////////////////////////////////////////////////////////////////
// void CLEcran :: vLCDDisplayScreen(const UC *ucpEcran)
///////////////////////////////////////////////////////////////////////////////
//
// Description: 
// Remplissage de caracteres de l'ecran LCD
//
// Parametres d'entrees:
// -*ucpEcran: Pointeur vers le debut d'un tableau a 2 dimensions
//             
// Parametres de sortie: null
//
// Appel de la fonction: vLCDDisplayScreen(NOMDTABLEAU);
//
// Cree le 10 octobre 2013 par Louis-Normand Ang Houle 
// 
// Modifications:   
// -
//
//
///////////////////////////////////////////////////////////////////////////////

void CLEcran :: vLCDDisplayScreen(const UC *ucpEcran)
 {
   UC ucLigne;
   for (ucLigne=1; ucLigne <=4; ucLigne++)          
   {
    vLCDCursor(1,ucLigne);       
    String(ucpEcran);  
    ucpEcran = ucpEcran + 1;    
   }
 }

///////////////////////////////////////////////////////////////////////////////
// void CLEcran :: vLCDDisplayEtatPort(UC ucEtatPort)
///////////////////////////////////////////////////////////////////////////////
//
// Description: 
// Affiche l'etat d'un port sur le LCD
//
// Parametres d'entrees:
// -ucEtatPort: Variable contenant l'etat du port
//             
// Parametres de sortie: null
//
// Appel de la fonction: vLCDDisplayEtatPort(NOMVARIABLE);
//
// Cree le 14 avril 2014 par Louis-Normand Ang Houle 
// 
// Modifications:   
// -
//
//
///////////////////////////////////////////////////////////////////////////////

void CLEcran :: vLCDDisplayEtatPort(UC ucEtatPort)
 {
   for(UC i = 0; i < 8; i++)
    {
      if((ucEtatPort & 0x80) == 0x80) vLCDDisplayCarac('1');
      else                            vLCDDisplayCarac('0');
      
      ucEtatPort = ucEtatPort << 1;
    }   
 }

///////////////////////////////////////////////////////////////////////////////
// void CLEcran :: vLCDDisplaydecimal(F fDecimal)
///////////////////////////////////////////////////////////////////////////////
//
// Description: 
// Affiche un nombre sur le LCD
//
// Parametres d'entrees:
// -fDecimal: Nombre a afficher
//             
// Parametres de sortie: null
//
// Appel de la fonction: vLCDDisplayDecimal (NOMVARIABLE);
//
// Cree le 30 septembre 2014 par Louis-Normand Ang Houle 
// 
// Modifications:   
// -
//
//
///////////////////////////////////////////////////////////////////////////////

void CLEcran :: vLCDDisplayDecimal (F fDecimal)
 {

 }

void CLEcran :: vLCDDisplayDecimal (SI siDecimal)
 {
   UC ucMilliers;
   UC ucCentaines;
   UC ucDizaines;
   UC ucUnites;
   
   if(siDecimal  < 0)
    {
      vLCDDisplayCarac('-');
      
      siDecimal  ^= 0xFFFF;
      
      ucMilliers  = siDecimal / 1000;
      siDecimal   = siDecimal-(ucMilliers * 1000);
      
      ucCentaines = siDecimal / 100;
      siDecimal   = siDecimal-(ucCentaines * 100);
      
      ucDizaines  = siDecimal / 10;
      siDecimal   = siDecimal-(ucDizaines * 10);
      
      ucUnites    = siDecimal / 1;
      
      ucMilliers  = ucMilliers  + 0x30;
      ucCentaines = ucCentaines + 0x30;
      ucDizaines  = ucDizaines  + 0x30;
      ucUnites    = ucUnites    + 0x30;
      
      vLCDDisplayCarac(ucMilliers);      
      vLCDDisplayCarac(ucCentaines);
      vLCDDisplayCarac(ucDizaines);
      vLCDDisplayCarac(ucUnites);      
    }
   
   else
    {
      vLCDDisplayCarac(' ');
     
      ucMilliers  = siDecimal / 1000;
      siDecimal   = siDecimal-(ucMilliers * 1000);
      
      ucCentaines = siDecimal / 100;
      siDecimal   = siDecimal-(ucCentaines * 100);
      
      ucDizaines  = siDecimal / 10;
      siDecimal   = siDecimal-(ucDizaines * 10);
      
      ucUnites    = siDecimal / 1;
      
      ucMilliers  = ucMilliers  + 0x30;
      ucCentaines = ucCentaines + 0x30;
      ucDizaines  = ucDizaines  + 0x30;
      ucUnites    = ucUnites    + 0x30;
      
      vLCDDisplayCarac(ucMilliers);      
      vLCDDisplayCarac(ucCentaines);
      vLCDDisplayCarac(ucDizaines);
      vLCDDisplayCarac(ucUnites);        
    }
   
 }
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
