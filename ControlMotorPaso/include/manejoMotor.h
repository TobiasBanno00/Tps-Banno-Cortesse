#include <Arduino.h>
#define manejoMotor_H

class manejoMotor
{

public:
  void una_bobina(int IN1, int IN2, int IN3,int IN4, float numDeVueltas);    //Activa de a 1 bobina.
  void dos_bobinas(int IN1, int IN2, int IN3,int IN4, float numDeVueltas);  //Activa de a 2 bobinas.
  void medio_paso(int IN1, int IN2, int IN3,int IN4, float numDeVueltas);   //Activa 1 bobina, luego las 2 y asi..
  void limpieza(int IN1, int IN2, int IN3,int IN4);                         //Pone todas las bobinas en bajo.

  private:
  int tiempo = 10;   		// Tiempo de cargar entre cada bobina, no debe ser menor a 10 ms.
};



