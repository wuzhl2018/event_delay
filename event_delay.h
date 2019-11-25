
#ifndef __EVEN_DELAY__H__
#define __EVEN_DELAY__H__
 
	#include "main.h"
	
	#define EVENT_MAX_NUM 10
	
	typedef	void (*event_type)(void *);
	typedef struct
	{
		event_type event;
		void *Point;
		u16 DelayTime;
		u16 Time;
		u16 Run;
	}EventDelay_TypeDef;
	
	extern void Event_Add(event_type event,void *point,u16 time);
	extern void Event_TimeTick(void);
	extern void Event_Run(void);
 
#endif
