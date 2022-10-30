#include <stdio.h>
#include "BMS_SensorData_Receiver.h"



void  CalculateMinValue(float data, float* Min)
{
   if (data < *Min)
   {
     *Min = data;
   }
   else
   {
     /*Do nothing*/
   }
}


void  CalculateMaxValue(float data, float* Max)
{
   if (data > *Max)
   {
     *Max = data;
   }
   else
   {
     /*Do nothing*/
   }
}

void CalculateSMA ()
{
  float SumOfTemperature = 0;
  float SumOfSOC = 0;
  float SumOfChargeRate = 0;
    for (int i = 0; i < NO_OF_SAMPLES; i++)
    {
      SumOfTemperature += Temperature[i];
      SumOfSOC += SOC[i];
      SumOfChargeRate += ChargeRate[i];
    }
  SMATemp       = SumOfTemperature/NO_OF_SAMPLES;
  SMASOC        = SumOfSOC/NO_OF_SAMPLES;
  SMAChargeRate = SumOfChargeRate/NO_OF_SAMPLES;
}
