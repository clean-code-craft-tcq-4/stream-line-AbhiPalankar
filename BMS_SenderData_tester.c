#include <assert.h>
#include "BMS_SensorData_Sender.h"
#include "BMS_SensorData_Receiver.h"

int sampleValue[5] = {1,2,3,4,5};
int sampleValue1[5] = {1,2,3,4,5};

void Tester(){
	BatteryParameters BatteryParam;
	status retStatus = NOT_OK;

	generateSenderData(&BatteryParam);
	assert(BatteryParam.temperature[20] <= TEMP_MAX);
	assert(BatteryParam.temperature[1] >= TEMP_MIN);
	assert(BatteryParam.soc[49] <= SOC_MAX);
	assert(BatteryParam.soc[15] >= SOC_MIN);

	displaySenderData(&retStatus, BatteryParam);
	assert( retStatus == OK);

	retStatus = sendBatteryParameters();
	assert( retStatus == OK);
}

int main(void) {
	sendBatteryParameters();
	Tester();
	ReadBatteryParameter(0,5,sampleValue,sampleValue1);
    Calculate_Avg(sampleValue,sampleValue1);
}
