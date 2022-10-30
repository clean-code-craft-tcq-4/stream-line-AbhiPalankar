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
void testCalculateMaxValue()
{
  float data = 3;
  float Max = 8;
  CalculateMaxValue(data, &Max);
  assert(Max == 8);
  
  data = 7;
  Max = 8;
  CalculateMaxValue(data, &Max);
  assert(Max == 8);  
}

int main()
{
  testCalculateMinValue();
  testCalculateMaxValue();
  
  
}



