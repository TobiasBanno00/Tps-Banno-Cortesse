#include <Arduino.h>
#include "../include/manejoMotor.h"


void manejoMotor:: una_bobina(int IN1,int IN2,int IN3,int IN4,float numDeVueltas)
{
  int paso [4][4] =		// matriz  con la secuencia de pasos.
  {
    {1, 0, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 1}
  };

  float numDePasos=numDeVueltas*512;  //2048 pasos=1 vuelta, dividido 4 bobinas son 512 pasos  por vuelta.

  if (numDeVueltas<0)       // si el num de vueltas es negativo  convertimos la variable num de pasos en positivo ya que esta la usamos para el for
  {                         // que controla las vueltas que tiene que dar el motor, por ende no nos importa el signo
    numDePasos=numDePasos*-1;
  }
  
  for (int i = 0; i < numDePasos; i++)	
  {
    if (numDeVueltas>0) 
    {
      for (int i = 0; i < 4; i++)		// bucle recorre la matriz de a una fila por vez
      {					
        digitalWrite(IN1, paso[i][0]);	
        digitalWrite(IN2, paso[i][1]);
        digitalWrite(IN3, paso[i][2]);
        digitalWrite(IN4, paso[i][3]);
        delay(tiempo);
      }
    }
    if (numDeVueltas<0) 
    {
      for (int i = 0; i < 4; i++)		// bucle recorre la matriz de a una fila por vez SENTIDO INVERSO
      {					
        digitalWrite(IN1, paso[i][3]);	
        digitalWrite(IN2, paso[i][2]);
        digitalWrite(IN3, paso[i][1]);
        digitalWrite(IN4, paso[i][0]);
        delay(tiempo);
      }
    }
  }
}

void manejoMotor::dos_bobinas(int IN1, int IN2, int IN3,int IN4,float numDeVueltas)
{
  int paso [4][4] =		// matriz  con la secuencia de pasos
  {
    {1, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 1, 1},
    {1, 0, 0, 1}
  };

  float numDePasos=numDeVueltas*512; //2048 pasos=1 vuelta, dividido 4 bobinas son 512 pasos  por vuelta

  if (numDeVueltas<0)       
  {                        
    numDePasos=numDePasos*-1;
  }

   for (int i = 0; i < numDePasos; i++)	
  {
    if (numDeVueltas>0) 
    {
      for (int i = 0; i < 4; i++)		// bucle recorre la matriz de a una fila por vez
      {					
        digitalWrite(IN1, paso[i][0]);	
        digitalWrite(IN2, paso[i][1]);
        digitalWrite(IN3, paso[i][2]);
        digitalWrite(IN4, paso[i][3]);
        delay(tiempo);
      }
    }
    if (numDeVueltas<0) 
    {
      for (int i = 0; i < 4; i++)		// bucle recorre la matriz de a una fila por vez SENTIDO INVERSO
      {					
        digitalWrite(IN1, paso[i][3]);	
        digitalWrite(IN2, paso[i][2]);
        digitalWrite(IN3, paso[i][1]);
        digitalWrite(IN4, paso[i][0]);
        delay(tiempo);
      }
    }
  }
}

void manejoMotor::medio_paso(int IN1, int IN2, int IN3,int IN4,float numDeVueltas)

{
      
 int paso [8][4] =		// matriz con la secuencia de pasos
{
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};

float numDePasos=numDeVueltas*512; //2048 pasos=1 vuelta, dividido 4 bobinas son 512 pasos  por vuelta

   if (numDeVueltas<0)      
  {                         
    numDePasos=numDePasos*-1;
  }

  for (int i = 0; i < numDePasos; i++)	
  {
    if (numDeVueltas>0) 
    {
      for (int i = 0; i < 8; i++)		// bucle recorre la matriz de a una fila por vez
      {					
        digitalWrite(IN1, paso[i][0]);	
        digitalWrite(IN2, paso[i][1]);
        digitalWrite(IN3, paso[i][2]);
        digitalWrite(IN4, paso[i][3]);
        delay(tiempo);
      }
    }
    if (numDeVueltas<0) 
    {
      for (int i = 0; i < 8; i++)		// bucle recorre la matriz de a una fila por vez SENTIDO INVERSO
      {					
        digitalWrite(IN1, paso[i][3]);	
        digitalWrite(IN2, paso[i][2]);
        digitalWrite(IN3, paso[i][1]);
        digitalWrite(IN4, paso[i][0]);
        delay(tiempo);
      }
    }
  }
}

void manejoMotor::limpieza(int IN1, int IN2, int IN3,int IN4)
{
    digitalWrite(IN1, LOW);	
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}