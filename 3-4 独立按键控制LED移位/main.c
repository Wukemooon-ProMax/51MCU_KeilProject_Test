#include <REGX52.H>
void Delay(unsigned int xms);

unsigned char LEDNum;
    
void main()
{
    P2=~0x01;//1111 1110
    while(1)
    {
        if(P3_1==0)
        {
            Delay(20);
            while(P3_1==0);
            Delay(20);
            
            LEDNum++;
            if (LEDNum>=8)
                LEDNum=0;
            P2=~(0x01<<LEDNum);
        }
        if(P3_0==0)
        {
            Delay(20);
            while(P3_0==0);
            Delay(20);
            
            if (LEDNum==0)
                LEDNum=7;
            else
                LEDNum--;
            P2=~(0x01<<LEDNum);
        }
    }
}

void Delay(unsigned int xms)
{
	unsigned char data i, j;
    while(xms)
    {
        i = 2;
        j = 199;
        do
        {
            while (--j);
        } while (--i);
        xms--;
    }
}
