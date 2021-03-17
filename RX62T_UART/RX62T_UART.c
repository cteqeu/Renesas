// Developed by Vincent Claes
// cteq.eu
// printf_lib from : https://github.com/miguelangelo78

// Please read the hardware manual ;-)

// Special registers for UART are:
// SMR  (Serial Mode Register)
// BRR  (Bit Rate Register)
// SCR  (Serial Control Register)
// TDR  (Transmit Data Register)
// SSR  (Serial Status Register)
// RDR  (Recieve Data Register)
// SCMR (Smart Card Mode Register)
// SEMR (Serial Extended Mode Register)

#include "iodefine.h"
#include "machine.h"
#include "stdio.h"
#include "printf_lib.h"

void init(void);
void timer( unsigned long timer_set );
void led_out_m( unsigned char led );
void led_out( unsigned char led );
unsigned char receive_data(void);
void transmit_data(unsigned char data);
void init_SCI2(void);

unsigned long   cnt0;
unsigned long   cnt1;

void main(void)
{
	int i=0;
	int counter = 0;
    char    c;
    init();
    init_sci1_printf( SPEED_9600 );
    setpsw_i();
    printf("Demo application using UART\n");
    while(1){
    	i = get_sci1( &c );
    	switch(c){
    		case 'x':
    		case 'X':
    			counter = counter +1;
    			printf("We Received char 'X' or 'x' %d times\n",counter);
    			break;
    		default:
    			break;
    	}

    };
}

/***********************************************************************/
/* RX62T Initialization                                                */
/***********************************************************************/
void init( void )
{
    // System Clock
    SYSTEM.SCKCR.BIT.ICK = 0;               //12.288*8=98.304MHz
    SYSTEM.SCKCR.BIT.PCK = 1;               //12.288*4=49.152MHz

    // Port I/O Settings
    PORT1.DDR.BYTE = 0x03;                  //P10:LED2 in motor drive board

    PORT2.DR.BYTE  = 0x08;
    PORT2.DDR.BYTE = 0x1b;                  //P24:SDCARD_CLK(o)
                                            //P23:SDCARD_DI(o)
                                            //P22:SDCARD_DO(i)
                                            //CN:P21-P20
    PORT3.DR.BYTE  = 0x01;
    PORT3.DDR.BYTE = 0x0f;                  //CN:P33-P31
                                            //P30:SDCARD_CS(o)
    //PORT4:input                           //sensor input
    //PORT5:input
    //PORT6:input

    PORT7.DDR.BYTE = 0x7e;                  //P76:LED3 in motor drive board
                                            //P75:forward reverse signal(right motor)
                                            //P74:forward reverse signal(left motor)
                                            //P73:PWM(right motor)
                                            //P72:PWM(left motor)
                                            //P71:PWM(servo motor)
                                            //P70:Push-button in motor drive board
    PORT8.DDR.BYTE = 0x07;                  //CN:P82-P80
    PORT9.DDR.BYTE = 0x7f;                  //CN:P96-P90
    PORTA.DR.BYTE  = 0x0f;                  //CN:PA5-PA4
                                            //PA3:LED3(o)
                                            //PA2:LED2(o)
                                            //PA1:LED1(o)
                                            //PA0:LED0(o)
    PORTA.DDR.BYTE = 0x3f;                  //CN:PA5-PA0
    PORTB.DDR.BYTE = 0xff;                  //CN:PB7-PB0
    PORTD.DDR.BYTE = 0x07;                  //PD7:TRST#(i)
                                            //PD5:TDI(i)
                                            //PD4:TCK(i)
                                            //PD3:TDO(o)
                                            //CN:PD2-PD0
    PORTE.DDR.BYTE = 0x1b;                  //PE5:SW(i)
                                            //CN:PE4-PE0

    // MTU3_3 MTU3_4 PWM mode synchronized by RESET
    MSTP_MTU            = 0;                //Release module stop state
    MTU.TSTRA.BYTE      = 0x00;             //MTU Stop counting

    MTU3.TCR.BYTE   = 0x23;                 //ILCK/64(651.04ns)
    MTU3.TCNT = MTU4.TCNT = 0;              //MTU3,MTU4TCNT clear
    //MTU3.TGRA = MTU3.TGRC = PWM_CYCLE;      //cycle(16ms)
    //MTU3.TGRB = MTU3.TGRD = SERVO_CENTER;   //PWM(servo motor)
    MTU4.TGRA = MTU4.TGRC = 0;              //PWM(left motor)
    MTU4.TGRB = MTU4.TGRD = 0;              //PWM(right motor)
    MTU.TOCR1A.BYTE = 0x40;                 //Selection of output level
    MTU3.TMDR1.BYTE  = 0x38;                 //TGRC,TGRD buffer function
                                            //PWM mode synchronized by RESET
    MTU4.TMDR1.BYTE  = 0x00;                 //Set 0 to exclude MTU3 effects
    MTU.TOERA.BYTE  = 0xc7;                 //MTU3TGRB,MTU4TGRA,MTU4TGRB permission for output

    MTU.TSTRA.BYTE  = 0x40;                 //MTU0,MTU3 count function
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
   /* PORTA.DR.BIT.B0 = 0x01;
    PORTA.DR.BIT.B1 = 0x01;
    PORTA.DR.BIT.B2 = 0x00;
   */

}
