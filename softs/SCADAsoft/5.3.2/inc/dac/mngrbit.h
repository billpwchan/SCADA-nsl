#ifndef __scCMngrBit__
#define __scCMngrBit__

/******************************************************************************/
/*                                                                            */
/*  FILE             : DacComDevice.h                                         */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : Wed Dec 29 15:09:04 1999                               */
/*  LANGUAGE         : C++                                                    */
/*............................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                         */
/*  All rights reserved.                                                      */
/*                                                                            */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/*............................................................................*/
/*  OVERVIEW                                                                  */
/*                                                                            */
/*............................................................................*/
/*  CONTENTS                                                                  */
/*                                                                            */
/******************************************************************************/
// IDENTIFICATION:
// $Id: $
//
// HISTORY:
// $Log: $

class scCMngrBit
{
public:
  inline scCMngrBit();
  inline virtual ~scCMngrBit() ;

  inline unsigned char CreateOneBitMask( unsigned char i_Pos );
  inline unsigned char CreateMask( unsigned char i_Start,
                                   unsigned char i_Lg );

  inline unsigned char ShiftToRight( unsigned char i_Byte,
                                     unsigned char i_Start,
                                     unsigned char i_NbBit );
  inline unsigned char ShiftToLeft( unsigned char i_Byte,
                                    unsigned char i_Start,
                                    unsigned char i_NbBit );
  inline unsigned char GetOneBit( unsigned char i_Byte,
                                  unsigned char i_Start,
                                  unsigned char i_NbBit );
  unsigned short GetBits( const unsigned char* i_pByte,
			  unsigned char* o_pResu,
			  unsigned short i_Start,
			  unsigned short i_NbBit );

  inline unsigned char SetBit( unsigned char i_Byte,
                        unsigned char i_Position );
  inline unsigned char UnsetBit( unsigned char i_Byte,
                          unsigned char i_Position );
  void PutBit( unsigned char *io_pByte,
               unsigned char i_Bit,
               unsigned short i_Pos );

  inline unsigned char ConvertByteToBitVector( unsigned char i_Byte,
                                               unsigned char *o_pResu );
  unsigned short ConvertByteVectorToBitVector( unsigned char *i_pByte,
                                               unsigned short i_Lg,
                                               unsigned char *o_pResu );

  inline void AfficheBinaire( unsigned char i_Byte );
  void AfficheVecteur( const unsigned char *i_pByte,
                       unsigned short i_Lg );
  //void RigthShift(const unsigned char *i_pByte, unsigned short i_Lg, unsigned short shift);
  //void LeftShift(const unsigned char *i_pByte, unsigned short i_Lg, unsigned short shift);

};

///////////////////////////////////////////////////////////
//
//            inline functions
//
//////////////////////////////////////////////////////////

scCMngrBit::scCMngrBit()
{
}

scCMngrBit::~scCMngrBit()
{
}

unsigned char scCMngrBit::CreateOneBitMask( unsigned char i_Pos )
{
  // 0 <= i_Pos <= 7
  //printf( "CreateOneBitMask(%d) returns %d\n", i_Pos, 1 << i_Pos );
  return ( 1 << i_Pos );
}

unsigned char scCMngrBit::CreateMask( unsigned char i_Start,
                                      unsigned char i_Lg )
{
  unsigned char Mask = 0 ;
  unsigned char i ;

  for( i=0; i<i_Lg; i++ )
  {
    Mask |= CreateOneBitMask( i_Start + i );
  }
  //printf( "CreateMask( %d, %d ) returns %d\n", i_Start, i_Lg, Mask );
  return Mask ;
}

unsigned char scCMngrBit::ShiftToRight( unsigned char i_Byte,
                                        unsigned char i_Start,
                                        unsigned char i_NbBit )
{
  // 0 <= i_Start <= 7
  unsigned char Resu ;

  if( ( i_Start + i_NbBit ) > 8 )
    {
      return( i_Byte >> i_Start ) ;
    }
  else
    {
      Resu = i_Byte << ( 8 - ( i_Start + i_NbBit ) );
      return( Resu >> ( 8 - i_NbBit ) );
    }
}

unsigned char scCMngrBit::ShiftToLeft( unsigned char i_Byte,
                                       unsigned char i_Start,
                                       unsigned char i_NbBit )
{
  // 0 <= i_Start <= 7
  unsigned char Resu ;

  Resu = i_Byte >> i_Start ;
  return( Resu << ( 8 - i_NbBit ) );
}

unsigned char scCMngrBit::GetOneBit( unsigned char i_Byte,
                                     unsigned char i_Start,
                                     unsigned char i_NbBit )
{
  unsigned char Mask = 0 ;

  Mask = CreateMask( i_Start, i_NbBit );
  //printf( "GetOneBit( %hd, %hd ) uses mask %hd\n",
  //i_Start, i_NbBit, Mask );

  return i_Byte & Mask ;
}

unsigned char scCMngrBit::SetBit( unsigned char i_Byte,
                                  unsigned char i_Position )
{
  unsigned char Mask ;

  Mask = CreateOneBitMask( i_Position ) ;
  //printf( "SetBit( %d, %d ) = %d\n", i_Byte, i_Position, i_Byte | Mask );
  return( i_Byte | Mask );
}

unsigned char scCMngrBit::UnsetBit( unsigned char i_Byte,
                                    unsigned char i_Position )
{
  unsigned char Mask ;

  Mask = CreateOneBitMask( i_Position ) ;
  return i_Byte & ~Mask ;
}

unsigned char scCMngrBit::ConvertByteToBitVector
                    ( unsigned char i_Byte,
                      unsigned char *o_pResu )
{
  unsigned char i ;

  for( i=0; i<8; i++ )
  {
    o_pResu[i] = ShiftToRight( i_Byte, i, 1 );
  }
  return( 8 );
}

void scCMngrBit::AfficheBinaire( unsigned char i_Byte )
{
  unsigned char Resu ;
  unsigned char i ;

  for( i=8; i>0; i-- )
  {
    Resu = ShiftToRight( i_Byte, i-1, 1 );
    printf( "%hd", Resu );
  }
  printf( "\n" );
}

#endif // __scCMngrBit__
