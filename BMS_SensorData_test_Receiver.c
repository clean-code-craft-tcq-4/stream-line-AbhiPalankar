#include <stdio.h>
#include <assert.h>
#include "BMS_SensorData_Receiver.h"

void testCalculateMinValue()
{
  float data = 4;
  float Min = 6;
  CalculateMinValue(data, &Min);
  assert(Min == 4);
   
  data = 7;
  Min = 6;
  CalculateMinValue(data, &Min);
  assert(Min == 6);
}

int main()
{
  testCalculateMinValue();
  testCalculateMaxValue();
  
  
}



