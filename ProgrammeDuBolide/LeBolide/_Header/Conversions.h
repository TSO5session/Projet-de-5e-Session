// **************************Conversions.h
// Auteur:       Vincent Chouinard
// Date:         20 juillet 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:
// *****************************************************************************
#include "DeclarationGenerale.h"  // Raccourcis de programmation & variables

#ifndef CONVERSIONSH
  #define CONVERSIONSH

class Conversion //: public CLAutreClasse
{
public:
   Conversion(void);            // ***Constructeur par defaut
   Conversion(UC ucParametre);  // ***Constructeur initialisateur
  ~Conversion(void);            // ***Destructeur

   UC         HEXtoASCII    (UC HEXtoConvert);   //         Convert.HEXtoASCII(0x44);
   UC         ASCIItoHEX    (UC ASCIItoConvert); //ASCII  = Convert.ASCIItoHEX('B');
   const char FloatToString (float fInputFloat); //String = Convert.FloatToString(131.74);  
   
protected:

private:
   void StringAdder(char cNumber);
   static char *StringFinal;      // Pour pointeur sur tableau de char. 
};
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
