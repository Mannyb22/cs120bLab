/*	Author: Manuel Barajas
 *  Partner(s) Name: none
 *	Lab Section: 21
 *	Assignment: Lab #2  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRC= 0xFF; PORTC = 0x00;
    /* Insert your solution below */
    unsigned char cntavail = 0;
    while (1) {
	    cntavail = 0;
	    if (PINA & 0x01) {
		    cntavail += 1; // determines if PA0 has a parked car
	    }
	    if(PINA & 0x02) {
		    cntavail += 1; // determines if PA1 has a parked car
	    }
	    if(PINA & 0x04) {
		    cntavail += 1; //determines if PA2 has a parked car
	    }
	    if(PINA & 0x08) {
		    cntavail += 1; //determines if PA3 has a parked car
	    }
	    cntavail = 4 - cntavail; // determines how many spaces left
	    if (cntavail == 0) {
		    PORTC = 0x80;
	    } else {
		    PORTC = cntavail;
	    }
    }
    return 1;
}
