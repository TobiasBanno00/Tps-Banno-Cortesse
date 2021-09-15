#include <Arduino.h>
#include "../lib/ControlMotorPP/manejoMotor.h"

#define A  8		      	// IN1 de modulo controlador.
#define B  9		      	// IN2 de modulo controlador.
#define C  10		      	// IN3 de modulo controlador.
#define D  11		       	// IN4 de modulo controlador.
#define PulGiro 2       //Pulsador que cambia el giro del motor.
#define PulModo 3       //Pulsador que cambia el modo del motor.

float Vueltas=0.01;     //Vueltas que dará el motor, le ponemos valores chicos para que no quede por mucho tiempo dentro del for de la libreria.
int valorAnteriorG=0;    //Valor para pulsador giro.
int valorAnteriorM=0;    //Valor para pulsador modo.
int modo=0;             // Variable que almacenara 0 al 2 para entrar al case.
unsigned long T0=0;     //Variable que almacena millis, usado en PulGiro.
unsigned long T1=0;     //Variable que almacena millis, usado en PulModo.

manejoMotor motor1(A,B,C,D);   //definimos la clase como motor1 y le pasamos al constructor los pines de salida 
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

  Serial.begin(9600); //inicializamos puerto serial
}

void loop() 
{
  switch (modo)
    {
    case 0:
    motor1.una_bobina(Vueltas);
    break;

    case 1:
    motor1.dos_bobinas(Vueltas);
    break;

    case 2:
    motor1.medio_paso(Vueltas);
    break;
  } 
}

void cambioGiro()
{
  int valorPul=digitalRead(PulGiro);         //Le definimos a la variable el valor actual del pulsador.

  if ((valorPul == HIGH) && (valorAnteriorG == LOW))
  {
    if(millis()>(T0+300))      //ANTIRREBOTE
    {
      Vueltas=Vueltas*-1;        //cambiamos el giro del motor.
      T0=millis();
      Serial.println("CAMBIO GIRO");
    }
  }
    valorAnteriorG=valorPul;
}

void cambioModo()
{
    int valorPul=digitalRead(PulModo);  //Le definimos a la variable el valor actual del pulsador.
    
  if ((valorPul == HIGH) && (valorAnteriorM == LOW))
  {
    if(millis()>(T1+300))      //ANTIRREBOTE
    {
      if(modo<2)      
      {
      modo++;       //cambiamos el modo del motor.
      }
      else 
      {
        modo=0;
      }
      T1=millis();
      Serial.print("CAMBIO MODO NUM: ");
      Serial.println(modo);
    }
  }
    valorAnteriorM=valorPul;
}
  








