#include "Include.h"



 void *const bootfunc[]={
	(void *)BSP_IntVectSet,		                //0
	(void *)Boot_SysReset,		                //1
	(void *)Boot_ResetUsart,		            //2    
	(void *)Boot_UsartSend,		                //3
	(void *)Boot_UsartGet,                      //4
    (void *)Boot_UsartClrBuf,	                //5
	(void *)Boot_EraseUsrFlash,	                //6
	(void *)Boot_ProgramUsrFlash,	            //7
	(void *)Boot_UpdateProgram,	                //8
	(void *)debug_led_on,                       //9
	(void *)debug_led_off,                      //10
	(void *)app_enroll_tick_hdl,                //11
	(void *)Get_ParaFrmBoot,                    //12
	(void *)boot_get_ver,                       //13
	(void *)TA_GetCommand,                      //14
	(void *)Command_Process,                    //15
	(void *)get_usart_interrupt_flg,                    //16
	0
};

__asm void exit_bios(uint32 func,uint32 addr)
{
	bx r1
}





int main(void)
{
    uint8 status;
    Boot_ResetSysClk(1,1);	
    Boot_RCC_Config();
    Boot_NVIC_Config();
    BSP_IntInit(); 
    Boot_IoInit();
    Boot_UsartInit();
    SysTick_Init(TICKS_13US);

#if 0
    Boot_UsartSend("syx",3);
    Command_Process();  
    while(1)
    {
        if(get_usart_interrupt_flg())
        {
            Boot_UsartGet(&status,1, 1);
            Boot_UsartSend(&status,1);

        }
       
    }
#endif
    if(TA_Check_Signature()==TA_SUCCESS)
    {
        exit_bios((uint32)bootfunc,APP_PROG_START+1);// FOR thumb-2 启动应用程序*/
        Command_Process();
    }
            

    return 0;    


}

