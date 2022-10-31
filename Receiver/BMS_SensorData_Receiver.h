#define NO_OF_SAMPLES 5
extern float Min_Temp;
extern float Max_Temp;
extern float Min_StateOfCharge;
extern float Max_StateOfCharge;
extern float Min_ChargingRate;
extern float Max_ChargingRate;
extern float SMATemperature;
extern float Temperature[NO_OF_SAMPLES];
extern float SMASOC;
extern float SMATemp;
extern float SOC[NO_OF_SAMPLES];
extern float SMAChargeRate;
extern float ChargeRate[NO_OF_SAMPLES];

void CalculateMinValue(float data, float* Min);
void CalculateMaxValue(float data, float* Max);
void CalculateSMA();
int ReadParameters(float* temperature, float* StateOfCharge, float* ChargingRate);
void ReadFromConsole(float* temperature, float* StateOfCharge, float* ChargingRate);
int PrintMinMaxSMA();
void ReadBMSParametersfromConsole();
