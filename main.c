#include "frame.h"
#include "providers.h"
#include "consumers.h"


int main()
{
  Provider_Init();
  Consumer_Init();
  Frame_Start();

  return 0;
}
