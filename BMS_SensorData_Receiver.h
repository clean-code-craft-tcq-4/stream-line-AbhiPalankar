#define NO_OF_SAMPLES 5
extern float SMATemperature;
extern float Temperature[NO_OF_SAMPLES];
extern float SMASOC;
extern float SOC[NO_OF_SAMPLES];
extern float SMAChargeRate;
extern float ChargeRate[NO_OF_SAMPLES];

void CalculateMinValue(float data, float* Min);
void CalculateMaxValue(float data, float* Max);
void CalculateSMA();
