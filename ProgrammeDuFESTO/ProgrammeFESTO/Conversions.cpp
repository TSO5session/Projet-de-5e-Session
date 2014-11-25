// **************************Conversions.cpp
// Auteur:       Vincent Chouinard
// Date:         20 juillet 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:
// *****************************************************************************
#include "_DeclarationGenerale.h"  // Raccourcis de programmation & variables
#include "Conversions.h"               // Fichier de definitions du clavier
///// Initialise les variables statiques.
char *Conversion :: StringFinal = NULL;

//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
Conversion :: Conversion(void)
{

}

//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
Conversion :: Conversion(UC ucParametre)
{

}

// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
Conversion :: ~Conversion(void)
{

}

void Conversion :: StringAdder(char cNumber)
{
  
}

const char Conversion :: FloatToString (float fInputFloat)
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
         StringAdder('0');
      break;

      case 1:
         StringAdder('1');
      break;

      case 2:
         StringAdder('2');
      break;

      case 3:
         StringAdder('3');
      break;

      case 4:
         StringAdder('4');
      break;

      case 5:
         StringAdder('5');
      break;

      case 6:
         StringAdder('6');
      break;

      case 7:
         StringAdder('7');
      break;

      case 8:
         StringAdder('8');
      break;

      case 9:
         StringAdder('9');
      break;
     }
   }

StringAdder('.'); // Affiche la satane virgule

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
         StringAdder('0');
      break;

      case 1:
         StringAdder('1');
      break;

      case 2:
         StringAdder('2');
      break;

      case 3:
         StringAdder('3');
      break;

      case 4:
         StringAdder('4');
      break;

      case 5:
         StringAdder('5');
      break;

      case 6:
         StringAdder('6');
      break;

      case 7:
         StringAdder('7');
      break;

      case 8:
         StringAdder('8');
      break;

      case 9:
         StringAdder('9');
      break;
     }
  }
return(*StringFinal);
}





UC Conversion :: ASCIItoHEX(UC ASCIItoConvert)
{
UC ConvertedToHEX = 0;

switch(ConvertedToHEX)
    {
     case '0':
      ConvertedToHEX = 0x30;
     break;

     case '1':
      ConvertedToHEX = 0x31;
     break;

     case '2':
      ConvertedToHEX = 0x32;
     break;

     case '3':
      ConvertedToHEX = 0x33;
     break;

     case '4':
      ConvertedToHEX = 0x34;
     break;

     case '5':
      ConvertedToHEX = 0x35;
     break;

     case '6':
      ConvertedToHEX = 0x36;
     break;

     case '7':
      ConvertedToHEX = 0x37;
     break;

     case '8':
      ConvertedToHEX = 0x38;
     break;

     case '9':
      ConvertedToHEX = 0x39;
     break;

     case 'A':
      ConvertedToHEX = 0x41;
     break;

     case 'B':
      ConvertedToHEX = 0x42;
     break;
     
     case 'C':
      ConvertedToHEX = 0x43;
     break;

     case 'D':
      ConvertedToHEX = 0x44;
     break;

     case 'E':
      ConvertedToHEX = 0x45;
     break;

     case 'F':
      ConvertedToHEX = 0x46;
     break;

     case 'G':
      ConvertedToHEX = 0x47;
     break;

     case 'H':
      ConvertedToHEX = 0x48;
     break;

     case 'I':
      ConvertedToHEX = 0x49;
     break;

     case 'J':
      ConvertedToHEX = 0x4A;
     break;

     case 'K':
      ConvertedToHEX = 0x4B;
     break;

     case 'L':
      ConvertedToHEX = 0x4C;
     break;

     case 'M':
      ConvertedToHEX = 0x4D;
     break;

     case 'N':
      ConvertedToHEX = 0x4E;
     break;

     case 'O':
      ConvertedToHEX = 0x4F;
     break;

     case 'P':
      ConvertedToHEX = 0x50;
     break;

     case 'Q':
      ConvertedToHEX = 0x51;
     break;

     case 'R':
      ConvertedToHEX = 0x52;
     break;

     case 'S':
      ConvertedToHEX = 0x53;
     break;

     case 'T':
      ConvertedToHEX = 0x54;
     break;

     case 'U':
      ConvertedToHEX = 0x55;
     break;

     case 'V':
      ConvertedToHEX = 0x56;
     break;

     case 'W':
      ConvertedToHEX = 0x57;
     break;

     case 'X':
      ConvertedToHEX = 0x58;
     break;

     case 'Y':
      ConvertedToHEX = 0x59;
     break;

     case 'Z':
      ConvertedToHEX = 0x5A;
     break;     
   }

return(ConvertedToHEX);
}

UC Conversion :: HEXtoASCII(UC HEXtoConvert)
{
UC ConvertedToAscii = 0;

if((HEXtoConvert >= 0x41) && (HEXtoConvert <= 0x5A)) // Si l'hex est une lettre majuscule
  {
   switch(HEXtoConvert)
    {
     case 0x41:
      ConvertedToAscii = 'A';
     break;

     case 0x42:
      ConvertedToAscii = 'B';
     break;

     case 0x43:
      ConvertedToAscii = 'C';
     break;

     case 0x44:
      ConvertedToAscii = 'D';
     break;

     case 0x45:
      ConvertedToAscii = 'E';
     break;

     case 0x46:
      ConvertedToAscii = 'F';
     break;

     case 0x47:
      ConvertedToAscii = 'G';
     break;

     case 0x48:
      ConvertedToAscii = 'H';
     break;

     case 0x49:
      ConvertedToAscii = 'I';
     break;

     case 0x4A:
      ConvertedToAscii = 'J';
     break;

     case 0x4B:
      ConvertedToAscii = 'K';
     break;

     case 0x4C:
      ConvertedToAscii = 'L';
     break;

     case 0x4D:
      ConvertedToAscii = 'M';
     break;

     case 0x4E:
      ConvertedToAscii = 'N';
     break;

     case 0x4F:
      ConvertedToAscii = 'O';
     break;

     case 0x50:
      ConvertedToAscii = 'P';
     break;

     case 0x51:
      ConvertedToAscii = 'Q';
     break;

     case 0x52:
      ConvertedToAscii = 'R';
     break;

     case 0x53:
      ConvertedToAscii = 'S';
     break;

     case 0x54:
      ConvertedToAscii = 'T';
     break;

     case 0x55:
      ConvertedToAscii = 'U';
     break;

     case 0x56:
      ConvertedToAscii = 'V';
     break;

     case 0x57:
      ConvertedToAscii = 'W';
     break;

     case 0x58:
      ConvertedToAscii = 'X';
     break;

     case 0x59:
      ConvertedToAscii = 'Y';
     break;

     case 0x5A:
      ConvertedToAscii = 'Z';
     break;
  }
}

if((HEXtoConvert >= 0x61) && (HEXtoConvert <= 0x7A)) // Si l'hex est une lettre minuscule
  {
   switch(HEXtoConvert)
    {
     case 0x61:
      ConvertedToAscii = 'a';
     break;

     case 0x62:
      ConvertedToAscii = 'b';
     break;

     case 0x63:
      ConvertedToAscii = 'c';
     break;

     case 0x64:
      ConvertedToAscii = 'd';
     break;

     case 0x65:
      ConvertedToAscii = 'e';
     break;

     case 0x66:
      ConvertedToAscii = 'f';
     break;

     case 0x67:
      ConvertedToAscii = 'g';
     break;

     case 0x68:
      ConvertedToAscii = 'h';
     break;

     case 0x69:
      ConvertedToAscii = 'i';
     break;

     case 0x6A:
      ConvertedToAscii = 'j';
     break;

     case 0x6B:
      ConvertedToAscii = 'k';
     break;

     case 0x6C:
      ConvertedToAscii = 'l';
     break;

     case 0x6D:
      ConvertedToAscii = 'm';
     break;

     case 0x6E:
      ConvertedToAscii = 'n';
     break;

     case 0x6F:
      ConvertedToAscii = 'o';
     break;

     case 0x70:
      ConvertedToAscii = 'p';
     break;

     case 0x71:
      ConvertedToAscii = 'q';
     break;

     case 0x72:
      ConvertedToAscii = 'r';
     break;

     case 0x73:
      ConvertedToAscii = 's';
     break;

     case 0x74:
      ConvertedToAscii = 't';
     break;

     case 0x75:
      ConvertedToAscii = 'u';
     break;

     case 0x76:
      ConvertedToAscii = 'v';
     break;

     case 0x77:
      ConvertedToAscii = 'w';
     break;

     case 0x78:
      ConvertedToAscii = 'x';
     break;

     case 0x79:
      ConvertedToAscii = 'y';
     break;

     case 0x7A:
      ConvertedToAscii = 'z';
     break;
  }
}

if((HEXtoConvert >= 0x30) && (HEXtoConvert <= 0x39)) // Si l'hex est un chiffre
  {
switch(HEXtoConvert)
    {
     case 0x30:
      ConvertedToAscii = '0';
     break;

     case 0x31:
      ConvertedToAscii = '1';
     break;

     case 0x32:
      ConvertedToAscii = '2';
     break;

     case 0x33:
      ConvertedToAscii = '3';
     break;

     case 0x34:
      ConvertedToAscii = '4';
     break;

     case 0x35:
      ConvertedToAscii = '5';
     break;

     case 0x36:
      ConvertedToAscii = '6';
     break;

     case 0x37:
      ConvertedToAscii = '7';
     break;

     case 0x38:
      ConvertedToAscii = '8';
     break;

     case 0x39:
      ConvertedToAscii = '9';
     break;
  }
}
return(ConvertedToAscii);
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
