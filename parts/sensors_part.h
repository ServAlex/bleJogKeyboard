
#ifndef sensors_part_h
#define sensors_part_h

#include <Wire.h>
#include <Adafruit_SHT31.h>
#include <BH1750FVI.h>
#include "SparkFunCCS811.h"
/*
advanced voltage reading
#include <driver/adc.h>
#include "esp_adc_cal.h"
*/

// HDC1080 another temp and humidity sensor
//#include "ClosedCube_HDC1080.h"
//ClosedCube_HDC1080 hdc1080;
//double temperature2 = 0;
//double humidity2 = 0;

// battery voltage
#define ADC_PIN         34
int vref = 1100;
const float voltageMin = 3.2;
const float voltageMax = 4.19;
float battery_voltage = 0.f;
float battery_percentage = 0.f;

// sht31 temperature, humidity
Adafruit_SHT31 sht31 = Adafruit_SHT31();
float temperature = 0;
float humidity = 0;

// BH1750FVI light sensor
// Create the Lightsensor instance
//BH1750FVI LightSensor(BH1750FVI::k_DevModeContHighRes);
BH1750FVI LightSensor(BH1750FVI::k_DevModeContLowRes);
uint16_t lux = 0;
int lux_index = 0;

int intensity_min = 8;
int intensity_max = 60;

// CCS811 co2 and volotiles sensor
//#define CCS811_ADDR 0x5B //Default I2C Address
#define CCS811_ADDR 0x5A //Alternate I2C Address
CCS811 co2Sensor(CCS811_ADDR);
int co2 = 0;
int tvoc = 0;

struct SensorsConfig
{
	bool co2_active = false;
	bool voltage_active = false;
	bool temperature_humidity_active = false;
	bool light_active = false;
} sensorsConfig;


void sensorsSetup(SensorsConfig config)
{
	sensorsConfig = config;

	Wire.begin(); //Inialize I2C Hardware

	if(sensorsConfig.voltage_active)
	{
		/*
		advanced voltage reading
		esp_adc_cal_characteristics_t adc_chars;
		esp_adc_cal_value_t val_type = esp_adc_cal_characterize((adc_unit_t)ADC_UNIT_1, (adc_atten_t)ADC_ATTEN_DB_2_5, (adc_bits_width_t)ADC_WIDTH_BIT_12, 1100, &adc_chars);
		adc1_config_channel_atten(ADC1_CHANNEL_6, ADC_ATTEN_0db);
		adc1_config_width(ADC_WIDTH_12Bit);

		pinMode(14, OUTPUT);
		*/
	}
	if(sensorsConfig.co2_active)
	{
		co2Sensor.begin();
	}
	if(sensorsConfig.temperature_humidity_active)
	{
		sht31.begin(0x44);
	}
	if(sensorsConfig.light_active)
	{
		LightSensor.begin();
	}

	//hdc1080.begin(0x40);
	//hdc1080.setResolution(HDC1080_RESOLUTION_14BIT, HDC1080_RESOLUTION_14BIT);
	//hdc1080.setResolution(HDC1080_RESOLUTION_8BIT, HDC1080_RESOLUTION_8BIT);
}

void pollSensors()
{
	if(sensorsConfig.voltage_active)
	{
		// https://github.com/Xinyuan-LilyGO/TTGO-T-Display/issues/35#issuecomment-749511521
		/*
		advance voltage reading
		digitalWrite(14, HIGH);
		float measurement = (float) analogRead(34);
		digitalWrite(14, LOW);
		*/
/*
		digitalWrite(14, HIGH);
		float measurement = (float) adc1_get_voltage(ADC1_CHANNEL_6);
		digitalWrite(14, LOW);

		float battery_voltage = (measurement / 4095.0) * 7.26;
*/

		uint16_t voltageRaw = analogRead(ADC_PIN);
		battery_voltage = ((float)voltageRaw / 4095.0) * 2.0 * 3.3 * (vref / 1000.0);
		battery_percentage = min(1.f, (battery_voltage-voltageMin)/(voltageMax-voltageMin));
		Serial.print(battery_voltage);
	}

	if(sensorsConfig.temperature_humidity_active)
	{
		temperature = sht31.readTemperature();
		humidity = sht31.readHumidity();

		if(isnan(temperature))
			temperature = 0;

		if(isnan(humidity))
			humidity = 0;
	}

	//temperature2 = hdc1080.readTemperature();
	//humidity2 = hdc1080.readHumidity();

	if(sensorsConfig.light_active)
	{
		lux = LightSensor.GetLightIntensity();
		int normalizer = 5;
		float unscaled_lux = log(lux+normalizer)/log(1.2);
		lux_index = (int)unscaled_lux;
		//lux_index = (int)((unscaled_lux-intensity_min)/(intensity_max - intensity_min)*(SCREEN_HEIGHT - 11));
	}

	if (sensorsConfig.co2_active && co2Sensor.dataAvailable())
	{
		co2Sensor.readAlgorithmResults();
		co2 = co2Sensor.getCO2();
		tvoc = co2Sensor.getTVOC();
		co2Sensor.setEnvironmentalData(humidity, temperature);
	}

	//Serial.println(temperature2);
    //Serial.println(String(temperature) + " - " + String(humidity));
}

#endif