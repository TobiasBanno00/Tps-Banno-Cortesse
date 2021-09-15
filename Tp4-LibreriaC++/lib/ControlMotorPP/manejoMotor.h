#ifndef manejoMotor_H
#define manejoMotor_H
#include <Arduino.h>

class manejoMotor
{

public:
  manejoMotor();               //Constructor para asignar pines que conectan con el driver.
  manejoMotor(int A, int B, int C,int D);

  void una_bobina(float numDeVueltas);    //Activa de a 1 bobina.
  void dos_bobinas(float numDeVueltas);  //Activa de a 2 bobinas.
  void medio_paso(float numDeVueltas);   //Activa 1 bobina, luego las 2 y asi..
  void limpieza();                  //Pone todas las bobinas en bajo.

  private:
  int IN1, IN2, IN3, IN4;  // variable para los puertos de salida que manejarán las bobinas.
  int tiempo = 10;   	  	// Tiempo de cargar entre cada bobina, no debe ser menor a 10 ms.

};

#endif



