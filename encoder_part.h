
#ifndef encoder_part_h
#define encoder_part_h

#include <Wire.h>
#include <ESP32Encoder.h>

ESP32Encoder encoder;

int32_t encoderValue = 0;
int32_t encoderValue_old = 0;
//int32_t raw_delta = 0;
int32_t encoderDelta = 0;
int32_t encoderValueAmplified = 0;
int32_t encoderDeltaAmplified = 0;

int encoderPin1 = 15;
int encoderPin2 = 17;

void encoderChanged(int dir);

void encoderSetup()
{
    ESP32Encoder::useInternalWeakPullResistors=true;
    encoder.attachSingleEdge(encoderPin1, encoderPin2);
	//encoder.attachHalfQuad(encoderPin1, encoderPin2);
	encoder.setCount(1);
    //encoder.resumeCount();
}

int32_t power(int32_t base, int32_t p)
{
    int32_t res = 1;
    for(int i = 0; i<p; i++)
        res*=base;
    return res;
}

float power(float base, int32_t p, int32_t max)
{
    float res = 4;
    for(int i = 0; i<p; i++)
    {
        res*=base;
        if(res > max)
            return res;
    }
    return res;
}

uint32_t encoderLastUpdated = 0;

int32_t amplifyer(int32_t i)
{
    uint32_t time = millis();

    if(!i) return 0;

    int sign = i>0?1:-1;

    uint32_t timeDelta = time - encoderLastUpdated;
    encoderLastUpdated = time;
    if(!timeDelta)
        return i;

    float velocity = float(abs(i))/(timeDelta);
    // + "" + String()

    if(velocity < 0.025)
        return sign;

    float res = sign*power(1.2f, int32_t(velocity*67), 100);

    //Serial.println(String(velocity, '\004') + " " + String(abs(i))+ " " + String(timeDelta) + " power " + String(int32_t(velocity*67)) + " res " + String(res, '\004'));

    return int32_t(res);

/*
    if(velocity < 0.03)
        return sign*2;
    if(velocity < 0.04)
        return sign*3;
    if(velocity < 0.2)
        return sign*10;
    return sign*100;
*/
    //return sign*power(2, min(6, abs(i)));
}

int lastButtonState = LOW;
long lastDebounceTime = 0;
int debounceDelay = 50;
int buttonState = LOW;

void resetEncoder()
{
    encoder.setCount(0);
    encoderValue = 0;
    encoderValue_old = 0;
}

void encoderLoop()
{
    encoderValue_old = encoderValue;
    encoderValue = -encoder.getCount();
    //encoderValue = encoder.getCount()/2;
    encoderDelta = encoderValue - encoderValue_old ;

    encoderDeltaAmplified = amplifyer(encoderDelta);
    encoderValueAmplified += encoderDeltaAmplified;

    if(encoderDelta != 0)
    {
        encoderChanged(encoderDelta);
    }

    //Serial.println(" encoder loop finished");
}

#endif
