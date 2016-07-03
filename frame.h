#ifndef _FRAME_H_
#define _FRAME_H_

typedef void (*PF_PROVIDER)(void);
typedef void (*PF_CONSUMER)(void);

void Frame_Register_Provider(PF_PROVIDER pfProvider);
void Frame_Register_Consumer(PF_CONSUMER pfConsumer);

void Frame_Start(void);

#endif
