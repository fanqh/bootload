#ifndef __DK_RFM_h__
#define __DK_RFM_h__
#include "gpio_config.h"


//void RFM69H_Running(u8 mode,u8 WorkStatus,u8 ParaChangeFlag,u8 *TxFlag,u8 *RxFlag,u8 *RSSI);
void RFM69H_Config(void);
u8 RFM69H_RxPacket(uint8* pbuff);
u8 RFM69H_TxPacket(u8* pSend);
void RFM69H_EntryTx(void);
void RFM69H_EntryRx(void);
u8 RFM69H_RxWaitStable(void);
u8 RFM69H_TxWaitStable(void);


int RFM69H_Analysis(void);

#define  nIRQ0			   PBin(2)
#define  TxBuf_Len 		   10 
#define  RxBuf_Len 		   10



#define RFM69H_DATA_LEN	 512

typedef enum
{
	RFM69H_IDLE,
	RFM69H_RECEIVE,
	RFM69H_SEND
}RFM69H_STATE;

typedef enum
{
	IDLE,
	ACTIVING,
	PULSE_HIG,
	PULSE_LOW
}DataState_t;

typedef struct 
{
	uint32 data  : 31;
	uint32 pulse :	1;
}data_t;


typedef struct
{
	uint16 len;
	data_t  buff[RFM69H_DATA_LEN];
}RFM69H_DATA_Type;

typedef	struct
{
	DataState_t         DataState;
	RFM69H_STATE 		State;	   //�շ�״̬
	RFM69H_DATA_Type	Data;	   //�������ݳ���
	volatile uint32	DataTimeCount;

}RFM69H_INFOR;

extern RFM69H_INFOR rfm69h_infor; 

extern unsigned char TxBuf[TxBuf_Len];  
extern unsigned char RxBuf[RxBuf_Len];

#endif







