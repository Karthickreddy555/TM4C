//----------------------------------------------------------------------------
// FILE         : PCF8574A.H
// FILE VERSION : 1.0
// PROGRAMMER   : Programmer Name
//----------------------------------------------------------------------------
// REVISION HISTORY
//----------------------------------------------------------------------------
//
// 1.0, YYYY-MM-DD, Programmer Name
//   - Initial release
//
//----------------------------------------------------------------------------
// INCLUSION LOCK
//----------------------------------------------------------------------------

#ifndef PCF8574A_H_
#define PCF8574A_H_

//----------------------------------------------------------------------------
// INCLUDE FILES
//----------------------------------------------------------------------------

#include <stdint.h>
#include <stdbool.h>

#include "i2c.h"

//----------------------------------------------------------------------------
// MACROS
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// STRUCTURES
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// FUNCTION PROTOTYPES
//----------------------------------------------------------------------------

void    PCF8574A_Init( void );
void    PCF8574A_Read( uint8_t uiSA, uint8_t* puiData );
void    PCF8574A_Write( uint8_t uiSA, uint8_t* puiData );

//----------------------------------------------------------------------------
// CONSTANTS
//----------------------------------------------------------------------------

// Slave Address
#define PCF8574A_SA 0x38

// P7 = 1: LED4
// P6 = 1: LED5
// P5 = 1: LED6
// P4 = 0: Not Used (Reserved 1)
// P3 = 0: Not Used (Reserved 2)
// P2 = 1: PB6
// P1 = 1: PB5
// P0 = 1: PB4

#define PCF8574A_LED4 0x80
#define PCF8574A_LED5 0x40
#define PCF8574A_LED6 0x20
#define PCF8574A_RES2 0x10
#define PCF8574A_RES1 0x08
#define PCF8574A_PB6  0x04
#define PCF8574A_PB5  0x02
#define PCF8574A_PB4  0x01

#define PCF8574A_OUTPUTS ( PCF8574A_LED4 | PCF8574A_LED5 | PCF8574A_LED6 | PCF8574A_RES1 | PCF8574A_RES2 )
#define PCF8574A_INPUTS ( PCF8574A_PB6 | PCF8574A_PB5 | PCF8574A_PB4 )

#define PCF8574A_CONFIG ( PCF8574A_OUTPUTS | PCF8574A_INPUTS )

#endif // PCF8574A_H_

//----------------------------------------------------------------------------
// END PCF8574A.H
//----------------------------------------------------------------------------
