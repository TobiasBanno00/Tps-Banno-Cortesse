#include <Arduino.h>
#include "manejoMotor.h"

#define A  8		      	// IN1 de modulo controlador.
#define B  9		      	// IN2 de modulo controlador.
#define C  10		      	// IN3 de modulo controlador.
#define D  11		       	// IN4 de modulo controlador.
#define PulGiro 2       //Pulsador que cambia el giro del motor.
#define PulModo 3       //Pulsador que cambia el modo de giro del motor.

float Vueltas=0.01;     //Vueltas que dará el motor, le ponemos valores chicos para que no quede por mucho tiempo dentro del for de la libreria.
int valorAnteriorG=0;    //Valor para pulsador giro.
int valorAnteriorM=0;    //Valor para pulsador modo.
int modo=0;             // Variable que almacenara 0 al 2 para entrar al case.
unsigned long T0=0;     //Variable que almacena millis, usado en PulGiro.
unsigned long T1=0;     //Variable que almacena millis, usado en PulModo.

manejoMotor motor1;   //definimos la clase como motor1
void cambioGiro();    //Funcion que usaremos en la interrupcion cuando queramos cambiar el giro.
void cambioModo();    //Funcion que usaremos en la interrupcion cuando queramos cambiar el modo.

void setup() {
  pinMode(A, OUTPUT);		// Pines que conectan al driver, como salida.
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);

  pinMode(PulGiro, INPUT);   //Pines de pulsadores como entrada.
  pinMode(PulModo, INPUT);

  attachInterrupt(digitalPinToInterrupt(2),cambioGiro,FALLING); //definimno la interrupcion giro
  attachInterrupt(digitalPinToInterrupt(3),cambioModo,FALLING);  //definimno la interrupcion modo

  Serial.begin(9600);
}

void loop() 
{
  switch (modo)
    {
    case 0:
    motor1.una_bobina(A,B,C,D,Vueltas);
    break;

    case 1:
    motor1.dos_bobinas(A,B,C,D,Vueltas);
    break;

    case 2:
    motor1.medio_paso(A,B,C,D,Vueltas);
    break;
  } 
}

void cambioGiro()
{
  int valorPul=digitalRead(PulGiro);         //Le definimos a la variable el valor actual del pulsador.

  if ((valorPul == HIGH) && (valorAnteriorG == LOW))
  {
    if(millis()>(T0+300))      //INTENTO DE ANTIRREBOTE
    {
      Vueltas=Vueltas*-1;        //cambiamos el giro del motor.
      Serial.println("CAMBIO GIRO");
      T0=millis();
    }
  }
    valorAnteriorG=valorPul;
}

void cambioModo()
{
    int valorPul=digitalRead(PulModo);  //Le definimos a la variable el valor actual del pulsador.
    
  if ((valorPul == HIGH) && (valorAnteriorM == LOW))
  {
    if(millis()>(T1+300))      //INTENTO DE ANTIRREBOTE
    {
      if(modo<2)      
      {
      modo++;       //cambiamos el modo del motor.
      }
      else 
      {
        modo=0;
      }
      Serial.println(modo);
      T1=millis();
    }
  }
    valorAnteriorM=valorPul;
}
  








