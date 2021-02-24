#include "Arduino.h"

#ifndef Portos_h
#define Portos_h

class Portos
{
  public:
    Portos(int TxPin, int RxPin);
    bool Aveilable();
    String Read();
    void Broadcast(String mes);//messege
    String Last();
  
  private:
    String LastMessege = "";
    int TX;
    int RX;
    void dote();
    void dash();
    void pulse(int lengthInMicros);
    int doteInMili = 1000;
    int delayBtwBits = 100;
    char endingByte = B00000000;
};

#endif
