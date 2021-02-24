/*I have not tested it yet!*/

#include "Portos.h"

Portos ComLine(4, 5); //TX, RX
void setup() 
{
    Serial.begin(9600);
}

void loop() 
{
  if(ComLine.Aveilable())
  {
    Serial.print("A new messege is coming: ");
    Serial.print(ComLine.Read());
  }
  if("you want to" != "broadcast")
  {
    ComLine.Broadcast(ComLine.Last());
  }
}
