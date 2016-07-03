#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "frame.h"

void Consumer0(void)
{
    printf("product of provider 0");
    return;
}

void Consumer1(void)
{
    printf("run consumer 1");
    return;
}

void Consumer2(void)
{
    printf("run consumer 2");
    return;
}

void Consumer3(void)
{
    printf("run consumer 3");
    return;
}

void Consumer4(void)
{
    printf("run consumer 4");
    return;
}

void Consumer5(void)
{
    printf("run consumer 5");
    return;
}

void Consumer6(void)
{
    printf("run consumer 6");
    return;
}

void Consumer_Init()
{
    Frame_Register_Consumer(Consumer0);
    Frame_Register_Consumer(Consumer1);
    Frame_Register_Consumer(Consumer2);
    Frame_Register_Consumer(Consumer3);
    Frame_Register_Consumer(Consumer4);
    Frame_Register_Consumer(Consumer5);
}
