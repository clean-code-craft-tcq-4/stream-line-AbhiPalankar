#include <assert.h>
#include "BMS_SensorData_Sender.h"

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
}
