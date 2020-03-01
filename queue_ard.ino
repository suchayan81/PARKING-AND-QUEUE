#include "Queue.h"

Queue<char> queue = Queue<char>(5);

void setup() 
{
  Serial.begin(9600);
}

void loop()
  {
  while(Serial.available()) 
  {
    queue.push(Serial.read());
  }

  Serial.print(millis() / 1000);
  Serial.print(": ");
  int count = queue.count();
  if (count > 0) {
    Serial.print("Found ");
    Serial.print(count);
    Serial.print(" cars.. '");
    Serial.print(queue.pop());
    Serial.print("cars just entered the queue");
    Serial.print(queue.front());
    Serial.print(" cars standing  at the front");
    Serial.print(queue.back());
    Serial.print(" cars standing at the back '");
    Serial.print(queue.peak());
    Serial.println("'.");
  } else {
    Serial.println("no movement of cars"); 
  }
  Serial.print("Stop the car");
  delay(5000);
}
