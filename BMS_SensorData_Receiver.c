#include <stdio.h>
#include "BMS_SensorData_Receiver.h"

int ReadBatteryTemp[5];
int ReadBatterySoc[5];
int arrNumbers[5] = {0};

int pos = 0;
int BatteryTempAvg = 0;
int BatterySocAvg = 0;
long sum = 0;

int len = sizeof(arrNumbers) / sizeof(int);
int count = sizeof(ReadBatteryTemp) / sizeof(int);

void ReadBatteryParameter(int min,int max,int *ReadBatteryTemp,int *ReadBatterySoc)
{
    printf("**************Read Sensor Data**************\n");
    if(ReadBatteryTemp!=NULL)
    {
        for(int i = min;i<max;i++)
        {
        printf("Read Battery Temprature Sensor data:%d,Read Battery SOC Sensor data:%d\n",ReadBatteryTemp[i],ReadBatterySoc[i]);
        }
    }
}

int Simple_Moving_Avg(int *arrNumbers, long *sum, int pos, int len, int nextNum)
{
  *sum = *sum - arrNumbers[pos] + nextNum;
   arrNumbers[pos] = nextNum;
  return *sum / len;
}

void Calculate_Avg(int *ReadBatteryTemp,int *ReadBatterySoc)
{
    for(int i = 0; i < count; i++)
    {
    BatteryTempAvg = Simple_Moving_Avg(arrNumbers, &sum, pos, len, ReadBatteryTemp[i]);
    BatterySocAvg = Simple_Moving_Avg(arrNumbers, &sum, pos, len, ReadBatterySoc[i]);
    printf("The Battery Temprature Average is %d,The Battery SOC Average %d\n", BatteryTempAvg,BatterySocAvg);
    pos++;
    if (pos >= len)
        {
            pos = 0;
        }
    }
}
