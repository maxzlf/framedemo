#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "frame.h"

#define PROVIDER_LIMIT 100
#define CONSUMER_LIMIT 100

static PF_PROVIDER g_apfProviders[PROVIDER_LIMIT];
static PF_CONSUMER g_apfConsumers[CONSUMER_LIMIT];
static unsigned int g_uiProviderCount = 0;
static unsigned int g_uiConsumerCount = 0;

void Frame_Register_Provider(PF_PROVIDER pfProvider)
{
    assert(NULL != pfProvider);
    assert(PROVIDER_LIMIT - 1 > g_uiProviderCount);

    g_apfProviders[g_uiProviderCount] = pfProvider;
    g_uiProviderCount ++;

    return;
}

void Frame_Register_Consumer(PF_CONSUMER pfConsumer)
{
    assert(NULL != pfConsumer);
    assert(CONSUMER_LIMIT - 1 > g_uiConsumerCount);

    g_apfConsumers[g_uiConsumerCount] = pfConsumer;
    g_uiConsumerCount ++;

    return;
}

void Frame_Start(void)
{
    unsigned int uiProviderIndex = 0;
    unsigned int uiConsumerIndex = 0;

    for (uiConsumerIndex = 1; uiConsumerIndex < g_uiConsumerCount; uiConsumerIndex++ )
    {
      printf("consumer %u : ", uiConsumerIndex);
      g_apfConsumers[uiConsumerIndex]();
      printf("\n");
      printf("----------------------------------------");
      printf("\n");
      for(uiProviderIndex = 0; uiProviderIndex < g_uiProviderCount; uiProviderIndex++)
      {
	if (0 == (uiProviderIndex % uiConsumerIndex) )
	  {
	    printf("provider %u : ", uiProviderIndex);
	    g_apfProviders[uiProviderIndex]();
	    printf("\n");
	  }
      }
      printf("\n");
    }
    
}

