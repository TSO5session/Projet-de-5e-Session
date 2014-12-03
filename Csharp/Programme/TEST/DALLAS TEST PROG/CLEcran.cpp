// **************************CLEcran.cpp
// Auteur:      Vincent Chouinard
// Date:        13 fevrier 2014
// Version :    1.0
//
// vLcdAffCar      ---> Affiche un caracter (a-z,A-Z0-9)
// vLcdClr         ---> Efface l'ecran
// vLcdPoscurC0L1  ---> Positionne le curseur
// vLcdInit        ---> Initialise l'ecran
// vDelaisEcran    ---> Delais a tout faire
// vLcdAffChaine   ---> Affiche un string de "Texte"
// vLcdAffEcran    ---> Pour afficher des menus
// vLcdAffCarHex   ---> Pour afficher un caracter en HEX
// vLcdCarGen      ---> Pour creer des caracteres customs
// vHexToAscii2    ---> Pour transformer l'ASCII en HEX
// vLcdBusy        ---> Busy Polling
//
// Compilateur: IAR 8.2 && Keil 4.79.9
//
// Description: Fichier de definitions pour utiliser un ecran LCD
//
// *****************************************************************************
#include "CLEcran.h"
// *****************************************************************************
//                            LES CONSTRUCTEURS
// *****************************************************************************
CLEcran :: CLEcran(void)
{
uiAdresseEcran = 0xF800;
vLCDInit();
}

CLEcran :: CLEcran(USI uiAdresse)
{
uiAdresseEcran = uiAdresse;
vLCDInit();
}

// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
CLEcran :: ~CLEcran(void)
{
vLCDClr();
}

// **********************FONCTION: NomDeLaFonction()**************************
//
// DESCRIPTION: Positionne le curseur d'ecriture a l'endroit spécifie par
//              la fonction appelante
//
// INCLUDE: <_DeclarationGenerale.h>
//          "CLEcran.h"
//
// PROTOTYPE:           void vLcdPoscurC0L1(UC,UC)
//
// PROCEDURE D'APPEL:   vLcdPoscurC0L1(ucCol,ucLigne)
//
// PARAMETRE D'ENTREE:  ucCol   ---> Positionne la colone
//                      ucLigne ---> Positionne la ligne
//
// PARAMETRE DE SORTIE: AUCUN
//
// EXEMPLE: vLcdPoscurC0L1(0,1) ---> Met le curseur au debut de l'ecran
//
// Auteur:              Vincent Chouinard
// Date:                22 mars 2014   (Version 1.0)
// Modification:
// *****************************************************************************
void CLEcran :: vDelaiLCD(USI uiDelai)
{
USI i;
for(i = 0;i <= uiDelai; i++);
}

void CLEcran :: vLCDBusy(void)
{
while(ucIn(uiAdresseEcran + ECRANFLAG) & 0x80);
}

void CLEcran :: vLCDClr(void)
{
vLCDBusy();
vOut(uiAdresseEcran + ECRANCONFIG, 0x01);
}

void CLEcran :: vLCDInit(void)
{
USI i;
for(i = 0; i <= 3; i++)    //Faire 3 fois
  {
   vDelaiLCD(10000);                  //Attendre la stabilisation des parametres
   vOut(uiAdresseEcran + ECRANCONFIG,0x38);
  }

vLCDBusy();vOut(uiAdresseEcran + ECRANCONFIG,0x38); // Attente du Busy Flag
vLCDBusy();vOut(uiAdresseEcran + ECRANCONFIG,0x01); // Attente du Busy Flag
vLCDBusy();vOut(uiAdresseEcran + ECRANCONFIG,0x0C); // Attente du Busy Flag
vLCDBusy();vOut(uiAdresseEcran + ECRANCONFIG,0x06); // Attente du Busy Flag
}

// **********************FONCTION: NomDeLaFonction()**************************
//
// DESCRIPTION: Positionne le curseur d'ecriture a l'endroit spécifie par
//              la fonction appelante
//
// INCLUDE: <_DeclarationGenerale.h>
//          "CLEcran.h"
//
// PROTOTYPE:           void vLcdPoscurC0L1(UC,UC)
//
// PROCEDURE D'APPEL:   vLcdPoscurC0L1(ucCol,ucLigne)
//
// PARAMETRE D'ENTREE:  ucCol   ---> Positionne la colone
//                      ucLigne ---> Positionne la ligne
//
// PARAMETRE DE SORTIE: AUCUN
//
// EXEMPLE: vLcdPoscurC0L1(0,1) ---> Met le curseur au debut de l'ecran
//
// Auteur:              Vincent Chouinard
// Date:                22 mars 2014   (Version 1.0)
// Modification:
// *****************************************************************************
void CLEcran :: vLCDCursor(UC ucCol, UC ucLine)
{
UC ucPosition;
switch(ucLine)
  {
   case 1:                       //Si ligne 1 choisi
      ucPosition = 0x00 + ucCol; //Curseur sur ligne 1 (1,Y)
   break;

   case 2:                       //Si ligne 2 choisi
      ucPosition = 0x40 + ucCol; //Curseur sur ligne 2 (2,Y)
   break;

   case 3:                       //Si ligne 3 choisi
      ucPosition = 0x14 + ucCol; //Curseur sur ligne 3 (3,Y)
   break;

   case 4:                       //Si ligne 4 choisi
      ucPosition = 0x54 + ucCol; //Curseur sur ligne 4 (4,Y)
   break;

   default:                      //Sinon
      ucPosition = 0x00 + ucCol; //Curseur à position initial (0,0)
   break;
  }

ucPosition = ucPosition | 0x80; //Definition du registre du curseur
vLCDBusy();                                   //Attente du Flag Busy
vOut(uiAdresseEcran+ECRANCONFIG, ucPosition); //Envoi de la commande
}

void CLEcran :: Lettre(UC ucCaractere)
{
vLCDBusy();
vOut(uiAdresseEcran+ECRANWR, ucCaractere);
}

void CLEcran :: Lettre(char cCaractere)
{
vLCDBusy();
vOut(uiAdresseEcran+ECRANWR, cCaractere);
}

void CLEcran :: vHexToASCII(UC ucHexCar, UC *ucpHi, UC *ucpLo)
{
UC ucTemp;
ucTemp = ucHexCar;
*ucpHi = ucTemp   >> 4;
*ucpLo = ucHexCar & 0x0F;

if(*ucpHi <= 9)             //SI MSB est chiffe
  {
   *ucpHi = *ucpHi + 0x30;  //Convertion hexa a ASCII (Chiffre)
  }
else                        //SINON
  {
   *ucpHi = *ucpHi + 0x37;  //Convertion hexa a ASCII (Lettre)
  }

if(*ucpLo <= 9)             //SI LSB est chiffre
  {
   *ucpLo = *ucpLo + 0x30;  //Convertion hexa a ASCII (Chiffre)
  }
else                        //SINON
  {
   *ucpLo = *ucpLo + 0x37;  //Convertion hexa a ASCII (Lettre)
  }
}

void CLEcran :: vHexToASCII(USI uiHexCar, UC *ucpHiOctHi, UC *ucpLoOctHi,
                                          UC *ucpHiOctLo, UC *ucpLoOctLo)
{
*ucpHiOctHi = (uiHexCar >> 12) & 0x0F;
*ucpLoOctHi = (uiHexCar >> 8 ) & 0x0F;
*ucpHiOctLo = (uiHexCar >> 4 ) & 0x0F;
*ucpLoOctLo =  uiHexCar        & 0x0F;

if(*ucpHiOctHi <= 9)                  //SI MSB est chiffe
  {
   *ucpHiOctHi = *ucpHiOctHi + 0x30;  //Convertion hexa a ASCII (Chiffre)
  }
else                                  //SINON
  {
   *ucpHiOctHi = *ucpHiOctHi + 0x37;  //Convertion hexa a ASCII (Lettre)
  }

if(*ucpLoOctHi <= 9)                  //SI LSB est chiffre
  {
   *ucpLoOctHi = *ucpLoOctHi + 0x30;  //Convertion hexa a ASCII (Chiffre)
  }
else                                  //SINON
  {
   *ucpLoOctHi = *ucpLoOctHi + 0x37;  //Convertion hexa a ASCII (Lettre)
  }

if(*ucpHiOctLo <= 9 )                 //SI MSB est chiffre
  {
   *ucpHiOctLo = *ucpHiOctLo + 0x30;  //Convertion hexa a ASCII (Chiffre)
  }
else                                  //SINON
  {
   *ucpHiOctLo = *ucpHiOctLo + 0x37;  //Convertion hexa a ASCII (Lettre)
  }

if(*ucpLoOctLo <= 9 )                 //SI LSB est chiffre
  {
   *ucpLoOctLo = *ucpLoOctLo + 0x30;  //Convertion hexa a ASCII (Chiffre)
  }
else                                  //SINON
  {
   *ucpLoOctLo = *ucpLoOctLo + 0x37;  //Convertion hexa a ASCII (Lettre)
  }
}

void CLEcran :: vLCDDisplayHexCarac(UC ucHexCar)
 {
  UC ucHi;UC ucLo;

  vHexToASCII(ucHexCar, &ucHi, &ucLo); //Conversion de Hexadecimal a ASCII
  Lettre(ucHi);              //Affiche MSB
  Lettre(ucLo);              //Affiche LSB
 }

void CLEcran :: vLCDDisplayHexCarac(USI uiHexCar)
{
UC ucHiOctHi;
UC ucLoOctHi;
UC ucHiOctLo;
UC ucLoOctLo;

vHexToASCII(uiHexCar, &ucHiOctHi, &ucLoOctHi, &ucHiOctLo, &ucLoOctLo);

Lettre(ucHiOctHi); //Affiche MSB OctHI
Lettre(ucLoOctHi); //Affiche LSB OctHI
Lettre(ucHiOctLo); //Affiche MSB OctLO
Lettre(ucLoOctLo); //Affiche LSB OctLO
}

void CLEcran :: String(const UC *ucpMessage)
{
while(*ucpMessage != 0x00)
  {
   Lettre(*ucpMessage);
   ucpMessage++;
  }
}

void CLEcran ::String (const char *cpMessage)
{
while(*cpMessage != 0x00)
  {
   Lettre(*cpMessage);
   cpMessage++;
  }
}

void CLEcran :: vLCDDisplayScreen(const UC *ucpEcran)
{
UC ucLigne;
for(ucLigne = 1; ucLigne <= 4; ucLigne++)
  {
   vLCDCursor(1,ucLigne);
   String(ucpEcran);
   ucpEcran = ucpEcran + 1;
  }
}

void CLEcran :: vLCDDisplayEtatPort(UC ucEtatPort)
{
for(UC i = 0; i < 8; i++)
  {
   if((ucEtatPort & 0x80) == 0x80)
     {
      Lettre('1');
     }
   else
     {
      Lettre('0');
     }
   ucEtatPort = ucEtatPort << 1;
  }
}

void CLEcran :: vLCDDisplayFloat(float fInputFloat)
{
int i                 = 0; // Pour les boucles de comptage
float fTemporaire     = 0; // Pour le calcul de decimales
USI usiLesEntiers     = 0; // Pour la conversion d'un float en entier
USI usiLesEntiersTemp = 0; // Pour la conversion d'un float en entier
USI usiDecimalesTemp  = 0; // Pour convertir les decimales d'un float en entier
USI usiLesDecimales   = 0; // Pour convertir les decimales d'un float en entier

usiLesEntiers   = (USI)fInputFloat; // Conversion des floats en USI sans virgule
usiLesDecimales = (USI)fInputFloat; // Enleve les decimales du float
fTemporaire     = (fInputFloat - (float)usiLesDecimales) * 100;//Decimales 0-999
usiLesDecimales = (USI)fTemporaire; //Conversion (.0 a .999) vers (0 a 999)

for(i = 0; i < 3; i++) //Pour trois fois (Centaine, dizaine, unite)
  {
   if(i == 0) // Pour les centaines
     {
      usiLesEntiersTemp = usiLesEntiers /  100;
      usiLesEntiers     = usiLesEntiers - (100 * usiLesEntiersTemp);
     }
   if(i == 1) // Pour les dizaines
     {
      usiLesEntiersTemp = usiLesEntiers /  10;
      usiLesEntiers     = usiLesEntiers - (10 * usiLesEntiersTemp);
     }
   if(i == 2) // Pour les unitees
     {
      usiLesEntiersTemp=usiLesEntiers;
     }

   switch(usiLesEntiersTemp) // Affiche un caractere correspondant a l'unite
     {                       // float lue
      case 0:
         Lettre('0');
      break;

      case 1:
         Lettre('1');
      break;

      case 2:
         Lettre('2');
      break;

      case 3:
         Lettre('3');
      break;

      case 4:
         Lettre('4');
      break;

      case 5:
         Lettre('5');
      break;

      case 6:
         Lettre('6');
      break;

      case 7:
         Lettre('7');
      break;

      case 8:
         Lettre('8');
      break;

      case 9:
         Lettre('9');
      break;
     }
   }

Lettre('.'); // Affiche la satane virgule

for(i = 0; i < 2; i++) //Pour deux fois (Dixieme, centieme)
  {
   if(i == 0)          // Pour les dixiemes
     {
      usiDecimalesTemp = usiLesDecimales /  10;
     }
   if(i == 1)          // Pour les centiemes
     {
      usiDecimalesTemp = usiLesDecimales - (10 * usiDecimalesTemp) ;
     }

   switch(usiDecimalesTemp) // Affiche un caractere correspondant a l'unite
     {                      // float lue
      case 0:
         Lettre('0');
      break;

      case 1:
         Lettre('1');
      break;

      case 2:
         Lettre('2');
      break;

      case 3:
         Lettre('3');
      break;

      case 4:
         Lettre('4');
      break;

      case 5:
         Lettre('5');
      break;

      case 6:
         Lettre('6');
      break;

      case 7:
         Lettre('7');
      break;

      case 8:
         Lettre('8');
      break;

      case 9:
         Lettre('9');
      break;
     }
  }
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
