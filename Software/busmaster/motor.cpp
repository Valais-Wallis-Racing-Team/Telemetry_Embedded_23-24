/* This file is generated by BUSMASTER */
/* VERSION [1.2] */
/* BUSMASTER VERSION [3.2.2] */
/* PROTOCOL [CAN] */

/* Start BUSMASTER include header */
#include <Windows.h>
#include <CANIncludes.h>
/* End BUSMASTER include header */


/* Start BUSMASTER global variable */
STCAN_MSG tx;
int power;
int angularSpeed;
int carSpeed;
/* End BUSMASTER global variable */


/* Start BUSMASTER Function Prototype  */
GCC_EXTERN void GCC_EXPORT OnTimer_motorTmr_5( );
/* End BUSMASTER Function Prototype  */

/* Start BUSMASTER Function Wrapper Prototype  */
/* End BUSMASTER Function Wrapper Prototype  */


/* Start BUSMASTER generated function - OnTimer_motorTmr_5 */
void OnTimer_motorTmr_5( )
{
/* TODO */
    power= rand()%5000 + 55000;
    angularSpeed= rand()%5 + 80;
    carSpeed= rand()%5 + 78;
    tx.id=0x18;
    tx.dlc=8;
    tx.data[0]=power >> 8;
    tx.data[1]=power;
    tx.data[2]=angularSpeed >> 8;
    tx.data[3]=angularSpeed;
    tx.data[4]=carSpeed >> 8;
    tx.data[5]=carSpeed;
    tx.data[6]=0;
    tx.data[7]=0;
    SendMsg(tx);
}/* End BUSMASTER generated function - OnTimer_motorTmr_5 */
