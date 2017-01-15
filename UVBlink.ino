/*
Glow in the dark paint illuminator 
*/

int led = 9;           // the PWM pin the LED is attached to
int led2 = 10;         // the PWM pin the LED is attached to

int brightness = 0; // for fade

int blinkWait; // for blink

// the setup routine runs once when you press reset:
void setup()
{
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() 
{
 
  //FADE ON
  for(brightness = 0; brightness < 255; brightness++)
  {
    analogWrite(led, brightness);
    analogWrite(led2, brightness);
    
    delay(30);
    
    if (brightness >= 200)
    {
       break;
    }
  }
  
  //Strobe
  for (blinkWait = 100; blinkWait > 0; blinkWait--)
  {
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(led2, LOW);
    delay(blinkWait);              // wait for a second
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(led2, HIGH);
    delay(blinkWait);              // wait for a second
    
    if (blinkWait <= 0)
    {
       break;
    }
  }

  //ON FOR TIME
  digitalWrite(led, HIGH);
  digitalWrite(led2, HIGH);
  delay(5000);

  //OFF FOR TIME
  digitalWrite(led, LOW);
  digitalWrite(led2, LOW);
  delay(10000);
}


