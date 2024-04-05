#include <xc.h>
#include "main.h"
unsigned char min,sec;
void __interrupt() isr(void)
{
    static unsigned int count = 0;
    
    if (TMR2IF == 1)
    {    
        if (++count == 2000) // 1sec
        {
            count = 0;
            if (sec>0)
            {
                sec--;
            }
            else if(sec==0 && min>0)
            {
                min--;
                sec=59; 
            }
            
           
        }
        
        TMR2IF = 0;
    }
    
}