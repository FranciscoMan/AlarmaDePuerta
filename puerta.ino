
#include "LowPower.h"

int zumbador = 8;          
 int puerta=9;
 int boton = 10;
 int wakeUpPin = 2;

void setup()
   {
      pinMode( wakeUpPin, INPUT );
      pinMode(puerta,INPUT_PULLUP);                 
  pinMode(zumbador,OUTPUT);     
  pinMode(boton,INPUT_PULLUP);
  attachInterrupt( digitalPinToInterrupt(wakeUpPin), Despertar, RISING);
       LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF); 
   }
void loop()
   {   
       
       detachInterrupt(wakeUpPin); 
       //cc
       int x = digitalRead(puerta);
      if(x==HIGH){
        digitalWrite(zumbador,HIGH);
        int y = digitalRead(boton);
        if(y==HIGH){
          digitalWrite(zumbador,LOW);
          delay(5000);
        }
      }else{
      digitalWrite(zumbador,LOW);
      attachInterrupt( digitalPinToInterrupt(wakeUpPin), Despertar, RISING);
       LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF); 
      }
   }

void Despertar() 
   {     
        

   }
