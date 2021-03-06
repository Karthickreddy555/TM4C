//----------------------------------------------------------------------------
// FILE         : SYSTICK.H
// FILE VERSION : 1.0
// PROGRAMMER   : Karthick
//----------------------------------------------------------------------------
// REVISION HISTORY
//----------------------------------------------------------------------------
//
// 1.0, YYYY-MM-DD, Karthick
//   - Initial release
//
//----------------------------------------------------------------------------
// INCLUSION LOCK
//----------------------------------------------------------------------------

#ifndef SYSTICK_H_
#define SYSTICK_H_

//----------------------------------------------------------------------------
// INCLUDE FILES
//----------------------------------------------------------------------------

#include <stdint.h>
#include <stdbool.h>

//----------------------------------------------------------------------------
// FUNCTION PROTOTYPES
//----------------------------------------------------------------------------

void SYSTICK_Init( void );
void SYSTICK_Delay( uint32_t uiDelay );

#endif // SYSTICK_H_

//----------------------------------------------------------------------------
// END SYSTICK.H
//----------------------------------------------------------------------------
