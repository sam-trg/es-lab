#include <LPC17xx.h>

unsigned int delay,count=0,Switchcount=0,j;
unsigned int Disp[16]={0x000003f0,0x00000060,0x000005b0,0x000004f0,0x00000660,0x000006d0,0x000007d0,0x000007f0,0x000006f0,0x00000770,0x000007c0,0x00000390,0x000005e0,0x00000790,0x00000710};
#define ALLDISP 0x00180000
#define DATAPORT 0x00000ff0
int main(void)
{
LPC_PINCON->PINSEL0 =0x00000000;
LPC_PINCON->PINSEL1=0x00000000;
LPC_GPIO0->FIODIR = 0x00180ff0;

while(1)
{
LPC_GPIO0->FIOSET |= ALLDISP;
LPC_GPIO0->FIOCLR =0x00000ff0;
LPC_GPIO0->FIOSET =Disp[Switchcount];

 for(j=0;j<3;j++)
 for(delay=0;delay<3000000;delay++);
 Switchcount++;
 if(Switchcount ==0x10)
 {
 Switchcount =0;
 LPC_GPIO0->FIOCLR = 0x00180ff0;
 }}}
