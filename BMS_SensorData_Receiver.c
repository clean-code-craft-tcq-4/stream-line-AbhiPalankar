#include <stdio.h>
#include "BMS_SensorData_Receiver.h"
float Min_Temp = 0;
float Max_Temp = 0;
float SMA_Temp = 0;
float Temperature[NO_OF_SAMPLES] = {0};
float Min_StateOfCharge = 0;
float Max_StateOfCharge = 0;
float SMA_StateOfCharge = 0;
float SOC[NO_OF_SAMPLES] = {0};
float Min_ChargingRate = 0;
float Max_ChargingRate = 0;
float SMA_ChargingRate = 0;
float ChargeRate[NO_OF_SAMPLES] = {0};


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

void  ReadBMSParametersfromConsole()
{
  float Temp, StateOfCharge, ChargingRate;
  char Buffer[30];
  fgets(Buffer,30,stdin);
  for (int i=0; i<50; i++)
  {
    ReadFromConsole(&Temp, &StateOfCharge, &ChargingRate);
   
    CalculateMinValue(Temp, &Min_Temp);
    CalculateMaxValue(Temp, &Max_Temp);
  
    CalculateMinValue(StateOfCharge, &Min_StateOfCharge);
    CalculateMaxValue(StateOfCharge,  &Max_StateOfCharge);

    CalculateMinValue(ChargingRate, &Min_ChargingRate);
    CalculateMaxValue(ChargingRate, &Max_ChargingRate);

    CalculateSMA();
    PrintMinMaxSMA();
  }
}

void ReadFromConsole(float* Temp, float* StateOfCharge, float* ChargingRate)
{
  ReadParameters(Temp, StateOfCharge, ChargingRate);
  
  for(int i = 0; i<NO_OF_SAMPLES-1; i++)
  {
    Temperature[i] = Temperature[i+1];
    SOC[i] = SOC[i+1];
    ChargeRate[i] = ChargeRate[i+1];
  }
  
  /*Inserting the latest data into the last element of array*/
  Temperature[NO_OF_SAMPLES-1] = *Temp;
  SOC[NO_OF_SAMPLES-1] = *StateOfCharge;
  ChargeRate[NO_OF_SAMPLES-1] = *ChargingRate;
    
  return;
}

int PrintMinMaxSMA()
{
    printf("Temp: Min = %f, Max = %f, SMA = %f\n", Min_Temp, Max_Temp, SMA_Temp);
    printf("StateOfCharge: Min = %f, Max = %f, SMA = %f\n", Min_StateOfCharge, Max_StateOfCharge, SMA_StateOfCharge);
    printf("ChargingRate: Min = %f, Max = %f, SMA = %f\n\n", Min_ChargingRate, Max_ChargingRate, SMA_ChargingRate);
  
  return 1;
}

int ReadParameters(float* Temp, float* StateOfCharge, float* ChargingRate)
{
  char dummy;
  
  return scanf("%f%c%f%c%f", Temp, &dummy, StateOfCharge, &dummy, ChargingRate);
}
