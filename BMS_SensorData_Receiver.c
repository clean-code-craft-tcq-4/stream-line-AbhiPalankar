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
