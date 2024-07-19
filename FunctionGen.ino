#include <Arduino.h>

int dacPin = 25;
int adcPin = 35;
int k = 0;
int v1 = 0;
int v2 = 0;
int v3 = 0;
int amp = 2;
int wave = 2;
int dfreq = 2;

void sinusoidal(float freq,float amp){
  // Function to generate the sinusoidal wave.
  for(int n = 0;n < 99;n = n+1)
  {
    dacWrite(dacPin, int(128 + 128*sin(2*PI*freq*n)));
    int adcVal = analogRead(adcPin);
    Serial.println(adcVal*amp);
    delay(100);
  }
  return;
}

void square(int amp,int dfreq){
  for(int i=0;i<20*dfreq/2;i++)
  {
    dacWrite(dacPin, 255);
    int adcVal = analogRead(adcPin);
    Serial.println(adcVal*amp/2);
    delay(5);
  }
  for(int i=0;i<20*dfreq/2;i++)
  {
    dacWrite(dacPin, 0);
    int adcVal = analogRead(adcPin);
    Serial.println(adcVal);
    delay(5);
  }
  
}

void triangular(int amp,int dfreq){
  int ref = int(256/20);
  for(int i=0;i<20*dfreq/2;i++)
  {
    dacWrite(dacPin, i*ref);
    int adcVal = analogRead(adcPin);
    Serial.println(adcVal*amp/2);
  }


  for(int i=19*dfreq/2; i >= 0; i--)
  {
    dacWrite(dacPin, i*ref);
    int adcVal = analogRead(adcPin);
    Serial.println(adcVal*amp/2);
  }
}

void sawtooth(int amp,int dfreq){
  int ref1 = int(256/20);
  int ref2 = int(256/10);
  for(int i=0;i<20*dfreq/2;i++)
  {
    dacWrite(dacPin, i*ref1);
    int adcVal = analogRead(adcPin);
    Serial.println(adcVal*amp/2);
  }


  for(int i=9*dfreq/2; i >= 0; i--)
  {
    dacWrite(dacPin, i*ref2);
    int adcVal = analogRead(adcPin);
    Serial.println(adcVal*amp/2);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(4,INPUT);
  pinMode(15,INPUT);
  pinMode(13,INPUT);
  dacWrite(25,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  v1 = touchRead(4);
  if(v1<60)
  {
    amp++;
    amp = amp%4;
    delay(500);
  }

  v3 = touchRead(13);
  if(v3<60)
  {
    dfreq++;
    dfreq = dfreq%4;
    delay(500);
  }

  v2 = touchRead(15);
  if(v2<60)
  {
    wave++;
    wave = wave%4;
    delay(500);
  }
  if(wave==0)
  {
    sinusoidal(0.2,amp/2);
  }
  else if(wave==1)
  {
    square(amp,dfreq);
  }
  else if(wave==2)
  {
    triangular(amp,dfreq);
  }
  else if(wave==3)
  {
    sawtooth(amp,dfreq);
  }
  //sinusoidal(0.2,amp/2);
  //square(amp);
  //triangular(amp);
  //sawtooth();
  //Serial.println(amp);
  //Serial.println(dfreq);
}
