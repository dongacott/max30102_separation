#include "HT66F2390.h"
typedef	unsigned char	u8;
typedef	char			s8;
typedef	unsigned short	u16;
typedef	short			s16;
typedef	unsigned long	u32;
typedef	long			s32;

#define	 SCLC		_pfc3
#define	 SDAC		_pfc2
#define	 SCL		_pf3
#define	 SDA		_pf2
#define	 SDAPU		_pfpu2
#define	 DeviceID		0b1010111<<1     //max30102�˸m��}

#define	 SEGPort	_pg
#define  SEGPortC	_pgc
#define	 ScanPort	_pe
#define	 ScanPortC	_pec

void max30102_initialization(); 
int max30102_beatavg();
int fin_avg=0;



void main()
{
	
	_wdtc=0b10101111;
	SDAPU=1;

	//-----------------------------------
	SEGPort=0; SEGPortC=0;				//�W��SEGPort����X�ݩ�
	ScanPort=0; ScanPortC=0;				//�W��SEGPort����X�ݩ�
	
	//timer enable
	_ptm0c0=0b11001000;                     //0:run,1:pause; 100:32000Hz; 1:on(���O���bon)
	_ptm0c1=0b11000001;                     //11:timer mode; 00000:�S�Ψ�; 1:A������k�X
	_ptm0al=0b00100000;                     //���W32
	_ptm0ah=0b00; 
	_ptm0ae=1; _mf0e=1; _emi=1;             //�P��timer
	

	max30102_initialization();              //max30102����?

	
    while(1)
    {    	  	
		fin_avg=max30102_beatavg();
		Delaymszz(100);
		
    }

}