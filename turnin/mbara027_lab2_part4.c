/*	Author: Manuel Barajas
 *  Partner(s) Name: none
 *	Lab Section: 21
 *	Assignment: Lab #2  Exercise #4
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
    DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0x00; PORTC = 0xFF;
    DDRD = 0xFF; PORTD = 0x00;
    /* Insert your solution below */
    while (1) {
	    unsigned char get_porta = PINA; //get pina input
	    unsigned char get_portb = PINB; //get pinb input
	    unsigned char get_portc = PINC; //get pinc input
	    unsigned char portd_temp = 0x00; //set the port for assignement to PORTD later
	    unsigned char total_weight = 0x00; //the total weight of the cart
	    unsigned char diff_A_C = 0x00; //the difference between A and C
	    total_weight = get_porta + get_portb + get_portc;
	    if(total_weight > 140) {
		    portd_temp = portd_temp | 0x01; // sets PD0 to 1 if the total weight exceeds 140kg 
	    }
	    if(get_porta >= get_portc) {
		    diff_A_C = get_porta - get_portc; //if PA is greater than or equal to PC the diffAC = A - C
	    } else {
		    diff_A_C = get_portc - get_porta; // else diffAC = C - A
	    }
	    if(diff_A_C > 80) {
		    portd_temp = portd_temp | 0x02;
	    }
	    PORTD = portd_temp;
	    total_weight = total_weight >> 2; // gets rid of the first two bits so it doesnt remove something at the end when we left shift in the next step
	    total_weight = total_weight << 2; //restores the total weight to be off by three and the first two bits are set to 0
	    PORTD = PORTD | total_weight; //portd is | with total_weight

    }
    return 1;
}
