//----------------------------------------------------------------------------
// FILE         : SYSTICK.C
// FILE VERSION : 1.0
// PROGRAMMER   : Karthick S
//----------------------------------------------------------------------------
// REVISION HISTORY
//----------------------------------------------------------------------------
//
// 1.0, YYYY-MM-DD, Karthick S
//   - Initial release
//
//----------------------------------------------------------------------------
// MODULE DESCRIPTION
//----------------------------------------------------------------------------
//
// Controls the system LED.
//
//----------------------------------------------------------------------------
// INCLUDE FILES
//----------------------------------------------------------------------------

#include "global.h"
#include "hwdefs.h"
#include "systick.h"

//----------------------------------------------------------------------------
// EXTERNAL REFERENCES
//----------------------------------------------------------------------------

extern uint32_t g_uiSYSFLAGS;

//----------------------------------------------------------------------------
// FUNCTION : SYSTICK_IntHandler( void )
// PURPOSE  : Handles the system tick interrupt
//----------------------------------------------------------------------------

void SYSTICK_IntHandler( void )
{
    // Check if a system tick timeout occurred
    if( HWREG( NVIC_ST_CTRL ) & ( 1 << 16 ) )
    {
        // Flag a system tick event
        g_uiSYSFLAGS |= ( 1 << SYSFLAGS_SYS_TICK );
    }

    return;
}

//----------------------------------------------------------------------------
// FUNCTION : SYSTICK_Init( void )
// PURPOSE  : Initialize the system tick
//----------------------------------------------------------------------------

void SYSTICK_Init( void )
{
    // Configure STRELOAD value
    HWREG( NVIC_ST_RELOAD ) = ( 80000 - 1 );

    // Clear the STCURRENT register
    HWREG( NVIC_ST_CURRENT ) = 0;

    // Enable the System Timer (SysTick) by configuring STCTRL
    HWREG( NVIC_ST_CTRL ) = 0x07;

    return;
}

//----------------------------------------------------------------------------
// FUNCTION : SYSTICK_Delay( uint32_t uiDelay )
// PURPOSE  : Delays for a number of milliseconds
//----------------------------------------------------------------------------

void SYSTICK_Delay( uint32_t uiDelay )
{
    do
    {
        if( g_uiSYSFLAGS & ( 1 << SYSFLAGS_SYS_TICK ) )
        {
            g_uiSYSFLAGS &= ~( 1 << SYSFLAGS_SYS_TICK );
            uiDelay--;
        }
    } while( uiDelay );

    return;
}

//----------------------------------------------------------------------------
// END SYSTICK.C
//----------------------------------------------------------------------------
