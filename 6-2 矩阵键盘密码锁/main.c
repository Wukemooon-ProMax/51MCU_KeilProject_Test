#include <REGX52.H>
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;
unsigned int Password,Count;

void main()
{
    LCD_Init();
    LCD_ShowString(1,1,"Password:");
    while(1)
    {
        KeyNum=MatrixKey();
        if(KeyNum)
        {
            if(KeyNum<=10)  //如果s1~s10按键按下，输入密码
            {
                if(Count<4)
                {
                Password*=10;          //密码左移一位
                Password+=KeyNum%10;   //获取一位密码
                Count++;
                }
                LCD_ShowNum(2,1,Password,4);  //更新显示
            }
            if(KeyNum==11)  //如果s11按键按下，确认
            {
                if(Password==4536)
                {
                    LCD_ShowString(1,13," OK!");
                    Password=0;
                    Count=0;
                    LCD_ShowNum(2,1,Password,4);
                }
                else
                {
                    LCD_ShowString(1,13,"ERR!");
                    Password=0;
                    Count=0;     
                    LCD_ShowNum(2,1,Password,4);                    
                }
            }
            if(KeyNum==12)  //如果s12按键按下，取消
            {
                LCD_Init();
                Password=0;
                Count=0;
                LCD_ShowString(1,1,"Password:");
            }
        }
    }
}
