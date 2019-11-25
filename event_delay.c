#include "main.h"
#include "event_delay.h"

EventDelay_TypeDef Event[EVENT_MAX_NUM];
u8 event_num = 0;
/*添加功能和延时*/
void Event_Add(event_type event,void *point,u16 time)
{
	if(event_num < EVENT_MAX_NUM)
	{
		Event[event_num].event = event;
		Event[event_num].DelayTime = time;
		Event[event_num].Time = time;
		Event[event_num].Point = point;
		event_num++;
	}
}
/*定时调用*/
void Event_TimeTick(void)
{
	static u8 event_num_now = 0;
	Event[event_num_now].Time--;
	if(Event[event_num_now].Time == 0)
	{
		Event[event_num_now].Run++;
		event_num_now++;
		if(event_num_now >= event_num)
			event_num_now = 0;
		Event[event_num_now].Time = Event[event_num_now].DelayTime;
	}
}
/*主循环运行*/
void Event_Run(void)
{
	for(u16 i = 0;i < event_num;i++){
		if(Event[i].Run){
			Event[i].Run --;
			Event[i].event(Event[i].Point);
		}
	}
}
