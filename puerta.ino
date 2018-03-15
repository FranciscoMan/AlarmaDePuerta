//En este codigo, para el proposito de mantener al arduino en modo de ahorro de energia se importa la libreria LowPower
//la cual nos ayudara con dicha tarea. El arduino permanecera dormido (modo de ahorro de energia) hasta que se
//genere una interrupccion y lo despierte para seguir con su funcionalidad.
//Es necesario descargar y agregar la libreria LowPoder, por ejemplo de: https://www.arduinolibraries.info/libraries/low-power

#include "LowPower.h"
//este pin ira conectado a la parte positiva del zumbador
int zumbador = 8;          
//este pin a la parte positiva del REED Swtich
 int puerta=9;
//este Pin al boton
 int boton = 10;
//este pin a la misma parte positiva del REED Switch
 int wakeUpPin = 2;

void setup()
   {
 //En esta seccion del codigo configuramos los pines a modo de soportar las entradas o salidas a leer
      pinMode( wakeUpPin, INPUT );
      pinMode(puerta,INPUT_PULLUP);                 
  pinMode(zumbador,OUTPUT);     
  pinMode(boton,INPUT_PULLUP);
 //esta instruccion es una interrupccion de arduino, funciona ingresando como primer argumento el pin sobre el cual
 //se va a generar la interrupccion; En un arduino UNO los pins que pueden hacer eso son el 2 o el 3, por lo que usamos el 2
 //el siguiente parametro es una funcion que se ejecutara al momento de la interrupccion, nosotros tenemos un metodo que no hace nada
 //sólo con el propocito de no modificar la sintaxis, ya que está es la recomendada.
 //por ultimo argumento es un parametro RISING que significa que al momento de leer un aumento en el voltage se ejecute la instruccion
 //existen más parametros como CHANGE, LOW o HIGH pero este fue el adecuado para el ejemplo
  attachInterrupt( digitalPinToInterrupt(wakeUpPin), Despertar, RISING);
 //Ya creada la iterrupccion procedemos a poner a dormir al arduino con la siguiente linea, indicandole que duerma para siempre
 //con el parametro SLEEP_FOREVER (o hasta que suceda una interrupccion por hardware como la nuestra)
       LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF); 
   }
//hecho lo anterior no se ejecutara el loop() sino hasta que se de la interrupccion
void loop()
 //cuando se de la interrupccion la ejecucion del codigo continua sin problemas, ya ahora dentro del loop()
   {   
       //este metodo lo que hace es retirar la interrupcion con la espera de que no nos cause conflicto
       detachInterrupt(wakeUpPin); 
       //cc
      //lo primero es leer la puerta para saber si está abierta
       int x = digitalRead(puerta);
    //si se encuentra abierta sonamos la alarma
      if(x==HIGH){
        digitalWrite(zumbador,HIGH);
       //luego verificamos el boton
        int y = digitalRead(boton);
       //si es presionado detenemos la alarma por 5 seg
        if(y==HIGH){
          digitalWrite(zumbador,LOW);
          delay(5000);
        }
      }else{
       //si la puerta no está abierta apagamos la alarma (en caso de que estuviese encendida) y volvemos a dormir, sin antes
       //crear la interrupccion que despertará al arduino
      digitalWrite(zumbador,LOW);
      attachInterrupt( digitalPinToInterrupt(wakeUpPin), Despertar, RISING);
       LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF); 
      }
   }
//este metodo Despertar() es el metodo sin instrucciones que mencione anteriormente
void Despertar() 
   {     
        

   }
//cabe destacar que al mover la puerta se le pasa corriente al pin 2 y se ejecuta la interrupcion, que lo primero que leeria
//seria que la puerta se encuentra abierta.
