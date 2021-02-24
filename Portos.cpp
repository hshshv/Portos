#include "Portos.h"

Portos::Portos(int TxPin, int RxPin)
{
  TX = TxPin;
  RX = RxPin;
}

bool Portos::Aveilable()
{
  return (digitalRead(RX));
}

String Portos::Read()
{
  String LastMessege = "";
  dote();
  int CHAR = 0;
  while (true)
  {
    for (int i = 0; i < 8; ++i)
    {
      LastMessege[CHAR] << 1;
      if (pulseIn(RX, HIGH) > 1.5 * doteInMili)
      {
        ++LastMessege[CHAR];
      }
    }
    if (LastMessege[CHAR] == endingByte)
    {
      return (LastMessege);
    }
  }

}

void Portos::Broadcast(String mes)
{
  digitalWrite(TX, HIGH);
  while (!digitalRead(RX)) {}
  digitalWrite(TX, LOW);
  delay(delayBtwBits);
  for (int i = 0; i < sizeof(mes); ++i)
  {
    for (int Bit = 0; Bit < 8; ++Bit)
    {
      if (mes[i] & 1)
      {
        dash();
      }
      else
      {
        dote();
      }
      mes[i] >> 1;
      delay(delayBtwBits);
    }
  }

  for (int Bit = 0; Bit < 8; ++Bit) //transsmiting ending byte
  {
    if (endingByte & 1)
    {
      dash();
    }
    else
    {
      dote();
    }
    endingByte >> 1;
    delay(delayBtwBits);
  }
}


String Portos::Last()
{
  return (LastMessege);
}

void Portos::dote()
{
  pulse(doteInMili);
}

void Portos::dash()
{
  pulse(2 * doteInMili);
}

void Portos::pulse(int lengthInMicros)
{
  digitalWrite(TX, HIGH);
  delay(lengthInMicros);
  digitalWrite(TX, LOW);
}
