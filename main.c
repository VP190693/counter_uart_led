#include<reg51.h>
#include<stdio.h>
#include <math.h>  
#include <stdlib.h>

sbit LED_STATUS=P2^1;
sbit LED_BLINK=P2^0;
sbit K4_START=P3^3;
sbit K3_STOP=P3^2;

void Delay(unsigned int a);
void UsartConfiguration();
char* itoa(int num, char* buffer, int base);


void main()
{
unsigned int counter=0;
unsigned int i,j;	
unsigned char count[10];	
	
	
//P3=0xFF;
UsartConfiguration();	
	while(1)
{
    LED_BLINK=0;
		Delay(2000);
		LED_BLINK=1;
		Delay(2000);
	
	while(!(P3&(1<<3))){
LED_STATUS=0; 
	
		while(1){
		
			for(i=0;i<100;i++){
      LED_BLINK=0;
		Delay(2000);
		LED_BLINK=1;
		Delay(2000);
				SBUF='c';
			while(!TI);
			TI=0;
			SBUF='o';
			while(!TI);
			TI=0;
			SBUF='u';
			while(!TI);
			TI=0;
			SBUF='n';
			while(!TI);
			TI=0;
			SBUF='t';
			while(!TI);
			TI=0;
			SBUF='=';
			while(!TI);
			TI=0;
			
			
       SBUF='O';
			while(!TI);
			TI=0;
			SBUF='N';
			while(!TI);
			TI=0;
			itoa(counter, count, 10);
			
			for(j=0;j<2;j++){
			SBUF=count[j];
			while(!TI);
			TI=0;
				
			}
			
			
			
			while(!(P3&(1<<2))){
			LED_STATUS=1;
				while(1){
        LED_BLINK=0;
		Delay(2000);
		LED_BLINK=1;
		Delay(2000);
					SBUF='c';
			while(!TI);
			TI=0;
			SBUF='o';
			while(!TI);
			TI=0;
			SBUF='u';
			while(!TI);
			TI=0;
			SBUF='n';
			while(!TI);
			TI=0;
			SBUF='t';
			while(!TI);
			TI=0;
			SBUF='=';
			while(!TI);
			TI=0;
			
			
       SBUF='O';
			while(!TI);
			TI=0;
			SBUF='F';
			while(!TI);
			TI=0;
			SBUF='F';
			while(!TI);
			TI=0;
			itoa(counter, count, 10);
			
			for(j=0;j<2;j++){
			SBUF=count[j];
			while(!TI);
			TI=0;
			}
			
			if(!(P3&(1<<3))){
			break;
			}
			Delay(2000);
			}
			break;
}
counter++;
Delay(2000);
	}
	counter=0;
	if(!(P3&(1<<2))){
	LED_STATUS=1;		
	break;
			}
}

	
	}
 


}
    
}


void UsartConfiguration()
{
	SCON=0X50;			
	TMOD=0X20;			
  TH1=0XF3;				
	TL1=0XF3;
	ES=1;						
	EA=1;						
	TR1=1;					
}

char* itoa( int num, char* buffer, int base)   
{  
 int current = 0;  
 int num_digits = 0; 
	if (num == 0) {  
buffer[current++] = '0';  
buffer[current] = '\0';  
return buffer;  
}  
 
if (num < 0) {  
if (base == 10) {  
num_digits ++;  
buffer[current] = '-';  
current ++;  
num *= -1;  
}  
else  
return NULL;  
}  
num_digits += (int)floor(log(num) / log(base)) + 1;  
while (current < num_digits)   
{  
int base_val = (int) pow(base, num_digits-1-current);  
int num_val = num / base_val;  
 char value = num_val + '0';  
buffer[current] = value;  
current ++;  
num -= base_val * num_val;  
}  
buffer[current] = '\0';  
return buffer;  
}  

void Delay(unsigned int a)
{
	unsigned char b;
	for(;a>0;a--)
	{
		for(b=113;b>0;b--);
	}
}