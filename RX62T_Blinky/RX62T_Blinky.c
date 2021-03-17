// Developed by Vincent Claes
// cteq.eu

#include "iodefine.h"
void init(void);
void timer( unsigned long timer_set );
void led_out_m( unsigned char led );
void led_out( unsigned char led );

unsigned long   cnt0;
unsigned long   cnt1;

void main(void)
{
	char leds = 1;
	int i=0;
    init();
    while(1) {
    	for(i=0;i<4;i++){
    		led_out_m(leds);
    		timer(100);
    		leds = leds<<1;
    	};
    	for(i=0;i<4;i++){
    	    led_out_m(leds);
    	    timer(100);
    	    leds = leds>>1;
    	};
    }
}

/***********************************************************************/
/* RX62T Initialization                                                */
/***********************************************************************/
void init(void)
{
    // System Clock
    SYSTEM.SCKCR.BIT.ICK = 0;               //12.288*8=98.304MHz
    SYSTEM.SCKCR.BIT.PCK = 1;               //12.288*4=49.152MHz
    PORTA.DR.BYTE  = 0x0f;                  //CN:PA5-PA4
                                            //PA3:LED3(o)
                                            //PA2:LED2(o)
                                            //PA1:LED1(o)
                                            //PA0:LED0(o)
    PORTA.DDR.BYTE = 0x3f;                  //CN:PA5-PA0
    // Compare match timer
    MSTP_CMT0 = 0;                          //CMT Release module stop state
    MSTP_CMT2 = 0;                          //CMT Release module stop state

    ICU.IPR[0x04].BYTE  = 0x0f;             //CMT0_CMI0 Priority of interrupts
    ICU.IER[0x03].BIT.IEN4 = 1;             //CMT0_CMI0 Permission for interrupt
    CMT.CMSTR0.WORD     = 0x0000;           //CMT0,CMT1 Stop counting
    CMT0.CMCR.WORD      = 0x00C3;           //PCLK/512
    CMT0.CMCNT          = 0;
    CMT0.CMCOR          = 96;               //1ms/(1/(49.152MHz/512))
    CMT.CMSTR0.WORD     = 0x0003;           //CMT0,CMT1 Start counting
}

/***********************************************************************/
/* Interrupt                                                           */
/***********************************************************************/
#pragma interrupt Excep_CMT0_CMI0(vect=28)
void Excep_CMT0_CMI0(void)
{
    cnt0++;
    cnt1++;

}

/***********************************************************************/
/* Timer unit                                                          */
/* Arguments: timer value, 1 = 1 ms                                    */
/***********************************************************************/
void timer( unsigned long timer_set )
{
    cnt0 = 0;
    while( cnt0 < timer_set );
}
/***********************************************************************/
/* LED control in MCU board                                            */
/* Arguments: Switch value, LED0: bit 0, LED1: bit 1. 0: dark, 1: lit  */
/*                                                                     */
/***********************************************************************/
void led_out_m( unsigned char led )
{
    led = ~led;
    PORTA.DR.BYTE = led & 0x0f;
   /*PORTA.DR.BIT.B0 = 0x01;
    PORTA.DR.BIT.B1 = 0x01;
    PORTA.DR.BIT.B2 = 0x00;
   */

}
