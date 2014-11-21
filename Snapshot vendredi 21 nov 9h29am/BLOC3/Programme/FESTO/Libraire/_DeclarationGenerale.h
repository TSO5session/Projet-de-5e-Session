
// ***************** FICHIER: _DECLARATIONGENERALE.H 
//
//  DEFINITION GENERALE POUR UN PROJET
//
//  Application realisee avec Keil 3.6
//
//  AUTEUR : DANIEL BRETON
//  DATE CREATION :    2099-03-30		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
// *****************************************************************************
// CHOIX DU TYPE DE COMPILATEUR
//
    #define KEIL_COMPILATEUR
//
//
// *****************************************************************************
                                                                           


#include "TypeCible.h"
#include "ConversionKeilToIAR.h"


#ifndef DECLARATIONGENERALEH
  #define DECLARATIONGENERALEH


// *****************************************************************************
//
//                            DEFINITION DE MOT CLE
//
// *****************************************************************************
#define ACTIF   1              //
#define INACTIF 0              //

#define ON      1              //
#define OFF     0              //
#define VRAI    1              //
#define FAUX    0              //

#define ACK     0              //
#define NOACK   1              //

#define HIGH    1
#define LOW     0

#define COMPLETE 1
#define INCOMPLETE 0
#define LARGEUR  20
#define HAUTEUR  4

#define PASADRESSE 0
#define ADR8BIT    1
#define ADR16BIT   2

#define BROCHE_MCP2515_CS P1_7
#define SCK  P1_6
#define MISO P1_4
#define MOSI P1_5
//******************************************************************************

// *****************************************************************************
//
//                            DEFINITION DE TYPE
//
// *****************************************************************************
 
#ifndef NULL
  #define NULL    0  
#endif

  
typedef  unsigned char UC ;
typedef  unsigned int  UI ;
typedef  unsigned short int USI ;
typedef  unsigned short     US ; 
typedef  unsigned short int UINT16 ;
typedef  unsigned int UINT;

#endif // #ifndef _DECLARATIONGENERALEH


// *****************************************************************************
//
//                            DEFINITION DE Structure
//
// *****************************************************************************
#ifndef STRUC
 #define STRUC
struct STHorlogeHMS
 {
   
   UC ucHeure;
   UC ucMinute;
   UC ucSeconde;
 
 };

struct STHorlogeJMA
 {

  UC ucJour;
  UC ucMois;
  UC ucAnnee;
 
 };

union UNHorlogeHMS
 {
   struct STHorlogeHMS stHeure;
   UC ucTab[3];
 
 };

 
  struct STNibble8bit   //Structure qui separe un octet en 2 nibble
   {
     UC ucBit0a3 :4;
     UC ucBit4a7 :4; 

   };
 struct STNibble16bit  //Structure qui separe un mot de 16bit en 4 nibble
   {


     UI ucBit0a3 :4;
     UI ucBit4a7 :4;
     UI ucBit8a11 :4;
    UI ucBit12a15 :4; 

   };
 struct STOctet16bit  //Structure qui separe un mot de 16bit en 2 octet
   {
     UC ucBas ; 
     UC ucHaut ;
        
   };
  union UNMot8bitNibble            // union entre la structure qui separe 
   {                               //un octet en 2 nibble avec un octet
     struct STNibble8bit stNibble;
     UC ucOctet;     

   };
  union UNMot16bit                    //Union entre Structure qui separe un                              
   {                                  //mot de 16bit en 2 octet , une structure 
     struct STOctet16bit stOctet16bit;//qui separe un mot de 16 bit en 4 nibble
     struct STNibble16bit stNibble16bit;//Et un mot de 16 bit
     UINT16 uiWord;
   };



 struct STBitOctet //Champ de bit qui separe un octet en 8 bit 
  {
    UC ucBit0 : 1;
    UC ucBit1 : 1;
    UC ucBit2 : 1;
    UC ucBit3 : 1;
    UC ucBit4 : 1;
    UC ucBit5 : 1;
    UC ucBit6 : 1;
    UC ucBit7 : 1;
   
  
  };
union UNOctetBit //Union entre champ de bit qui separe octet en 8 et un octet
 {
 
   struct STBitOctet stBitOctet;
   UC ucOctet;
 
 
 };
#endif
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@




