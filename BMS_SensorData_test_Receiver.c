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

void testCalculateSMA()
{
   float SumOfTemperature, AvgOfTemperature = 0 ;
   float SumOfSOC, AvgOfSOC = 0 ;
   float SumOfChargeRate, AvgOfChargeRate = 0;

    for (int i=0; i< NO_OF_SAMPLES; i++)
    {
       Temperature[i] = i;
       SOC[i] = 1.5*i;
       ChargeRate[i] = (float)i/NO_OF_SAMPLES;
    
       SumOfTemperature += Temperature[i];
       SumOfSOC += SOC[i];
       SumOfChargeRate += ChargeRate[i];
    }
  
  AvgOfTemperature =  SumOfTemperature/NO_OF_SAMPLES;
  AvgOfSOC         =  SumOfSOC/NO_OF_SAMPLES;
  AvgOfChargeRate  =  SumOfChargeRate/NO_OF_SAMPLES;

  CalculateSMA();
  
  assert(SMA_Temperature == AvgOfTemperature);
  assert(SMA_SOC = AvgOfSOC);
  assert(SMA_ChargeRate == AvgOfChargeRate);

int main()
{
  testCalculateMinValue();
  testCalculateMaxValue();
  testCalculateSMA();
  
  
}



