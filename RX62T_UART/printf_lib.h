/*======================================*/
/* Symbol definitions                   */
/*======================================*/
#define     SPEED_4800      1           /* Transmission rate 4800bps  */
#define     SPEED_9600      2           /* Transmission rate 9600bps  */
#define     SPEED_19200     3           /* Transmission rate 19200bps */
#define     SPEED_38400     4           /* Transmission rate 38400bps */

/*======================================*/
/* Prototype declaration                */
/*======================================*/
void init_sci1_printf( int sp );
int get_sci1( char *s );
int put_sci1( char r );
