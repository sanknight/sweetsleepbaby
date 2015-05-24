// these constants describe the pins. They won't change:
int motorPin = 3;
int a=4;
int b=5;
int c=6;
int d=7;
const int groundpin = 18;             // analog input pin 4 -- ground
const int powerpin = 19;              // analog input pin 5 -- voltage
const int ax = A3;                  // x-axis of the accelerometer
const int ay = A2;                  // y-axis
const int az = A1;                  // z-axis (only on 3-axis models)
int azm;
void setup()
{
  // initialize the serial communications:
  Serial.begin(9600);
   pinMode(motorPin,INPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(az, INPUT);
  
  // Provide ground and power by using the analog inputs as normal
  // digital pins.  This makes it possible to directly connect the
  // breakout board to the Arduino.  If you use the normal 5V and
  // GND pins on the Arduino, you can remove these lines.
  pinMode(groundpin, OUTPUT);
  pinMode(powerpin, OUTPUT);
  digitalWrite(groundpin, LOW); 
  digitalWrite(powerpin, HIGH);
}

void loop()
{
  // print the sensor values:
//  Serial.print(analogRead(ax));
  // print a tab between values:
 // Serial.print("\t");
//  Serial.print(analogRead(ay));
  // print a tab between values:
 // Serial.print("\t");
 // Serial.print(analogRead(az));
  azm = analogRead(az);
  Serial.println();
  // delay before next reading:
  //delay(100);
  if (azm>360 && azm<400)
  {
    digitalWrite(a,HIGH);
    digitalWrite(b,LOW);
    delay(1000);
    digitalWrite(a,LOW);
    digitalWrite(b,HIGH);
    delay(1000);
    digitalWrite(a,HIGH);
    digitalWrite(b,LOW);
    delay(1000);
  }
}