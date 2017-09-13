//**Quick Instructions**//

//This is the c file for Quiz3.
//Insert your code and documentation as described in the
//software design lecture.  
//Only insert code in between your group number and before
//the next group number for each section.  
//Do not delete any text.


//**Begin File**//

//descriptions************

//Our task is to setup pins and create the SendLatch() functions

// We srote the setup pins function to accomodate a user's input for port and pin number

// That port and pin is then set up inside of a switch statement

// The SendLatch() function sets the correct pin to a low state and holds it for 50 microseconds

// It does thie in an empty for loop that runs 405 times.
//group1

//group2

//group3

//group4

//group5

//group6



//external variables *********

//group1

//group2

//group3

//group4

//group5

//group6


//includes************

#include "module.h"

//defines************
													//ring has 60 leds*
//group1
#include "project.h"
//group2

//group3

//group4

//group5

//group6

//structs************

//group1

//group2

//group3

//group4

//group5

//group6


//global variables ************


//group1
char WSPort = 'F';
uint8_t WSPin = 0;

//group2

//group3

//group4

//group5

//group6

//private prototypes ************

//group1

void SetupPins(char Port, uint8_t Pin)
{
	WSPort = Port;
	WSPin = Pin + 1;
	
	switch(WSPort)
	{
		case 'A':
		{
			SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOA; // activate port A
			delay = SYSCTL_RCGC2_R;								// allow time for clock to stabilize
			GPIO_PORTA_CR_R = Pin;								// allow changes to Pin
			GPIO_PORTA_AMSEL_R = 0x00;						// disable analog on Pin
			GPIO_PORTA_DIR_R |= Pin;    					// make Pin output
			GPIO_PORTA_AFSEL_R &= ~0x0F; 					// regular port function 
			GPIO_PORTA_DEN_R |= 0x0F;    					// enable digital I/O on Pin
		}
		break;
		
		case 'B':
		{
			SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOB; // activate port B
			delay = SYSCTL_RCGC2_R;      					// allow time for clock to stabilize
			GPIO_PORTB_CR_R = Pin;								// allow changes to Pin
			GPIO_PORTB_AMSEL_R = 0x00;						// disable analog on Pin
			GPIO_PORTB_DIR_R |= Pin;    					// make Pin output
			GPIO_PORTB_AFSEL_R &= ~0x0F; 					// regular port function 
			GPIO_PORTB_DEN_R |= 0x0F;    					// enable digital I/O on Pin
		}
		break;
		
		case 'C':
		{
			SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOC; // activate port C
			delay = SYSCTL_RCGC2_R;      					// allow time for clock to stabilize
			GPIO_PORTC_CR_R = Pin;								// allow changes to Pin
			GPIO_PORTC_AMSEL_R = 0x00;						// disable analog on Pin
			GPIO_PORTC_DIR_R |= Pin;    					// make Pin output
			GPIO_PORTC_AFSEL_R &= ~0x0F; 					// regular port function 
			GPIO_PORTC_DEN_R |= 0x0F;    					// enable digital I/O on Pin
		}
		break;
		
		case 'D':
		{
			SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF; // activate port D
			delay = SYSCTL_RCGC2_R;      					// allow time for clock to stabilize
			GPIO_PORTD_CR_R = Pin;								// allow changes to Pin
			GPIO_PORTD_AMSEL_R = 0x00;						// disable analog on Pin
			GPIO_PORTD_DIR_R |= Pin;    					// make Pin output
			GPIO_PORTD_AFSEL_R &= ~0x0F; 					// regular port function 
			GPIO_PORTD_DEN_R |= 0x0F;    					// enable digital I/O on Pin
		}
		break;
		
		case 'E':
		{
			SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF; // activate port E
			delay = SYSCTL_RCGC2_R;      					// allow time for clock to stabilize
			GPIO_PORTE_CR_R = Pin;								// allow changes to Pin
			GPIO_PORTE_AMSEL_R = 0x00;						// disable analog on Pin
			GPIO_PORTE_DIR_R |= Pin;    					// make Pin output
			GPIO_PORTE_AFSEL_R &= ~0x0F; 					// regular port function 
			GPIO_PORTE_DEN_R |= 0x0F;    					// enable digital I/O on Pin
		}
		break;
		
		case 'F':
		{
			SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF; // activate port F
			delay = SYSCTL_RCGC2_R;      					// allow time for clock to stabilize
			GPIO_PORTF_CR_R = Pin;								// allow changes to Pin
			GPIO_PORTF_AMSEL_R = 0x00;						// disable analog on Pin
			GPIO_PORTF_DIR_R |= Pin;    					// make Pin output
			GPIO_PORTF_AFSEL_R &= ~0x0F; 					// regular port function 
			GPIO_PORTF_DEN_R |= 0x0F;    					// enable digital I/O on Pin
		}
		break;
	}
	
	return;
}
void SendLatch()
{

switch(WSPort)
{
	case 'A':
		GPIO_PORTA_DATA_R &= ~WSPin; //Set Port A Pin to zero
	break;
	
	case 'B':
		GPIO_PORTB_DATA_R &= ~WSPin; //Set Port B Pin to zero
	break;
	
	case 'C':
		GPIO_PORTC_DATA_R &= ~WSPin; //Set Port C Pin to zero
	break;
	
	case 'D':
		GPIO_PORTD_DATA_R &= ~WSPin; //Set Port D Pin to zero
	break;
	
	case 'E':
		GPIO_PORTE_DATA_R &= ~WSPin; //Set Port E Pin to zero
	break;
	
	case 'F':
		GPIO_PORTF_DATA_R &= ~WSPin; //Set Port F Pin to zero
	break;
}
	
	// Assume 16 MHz clock source
	// 16 MHz clock requires 800 clock cycles to last 50 microseconds (16,000,000 cycles/ses) * (50 * 10^-6 sec) = 800 cycles
	// For loop looping 400 times allows for 800 instructions (one check and one addition per loop)
	// Additional 5 added on for safe measures
	for(int i = 0; i < 405; i++);
	
	return;
}


//group2

//group3

//group4

//group5

//group6

//code ************

//group1

//group2

//group3

//group4

//group5

//group6
