 // Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 
 
Servo xservo, yservo;  // create servo object to control a servo 
 
int xpot = 0;  // analog pin used to connect the potentiometer
int ypot = 1;
int buttonpin = 2; //digital pin used to connect button
int xval, yval, xanal, yanal, pleft, pright, pup, pdown, pcenter;    // variable to read the value from the analog pin
int buttonval = 1; 
int ledpin = 13;
int pleftpin = 3;
int prighpin = 4;
int puppin = 5;
int pdownpin = 6;
int pcenterpin = 7;

 
void setup() 
{ 
  xservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  yservo.attach(10);
  pinMode(buttonpin, INPUT);
  pinMode(ledpin, OUTPUT);
  pinMode(pleftpin, INPUT);
  pinMode(prighpin, INPUT);
  pinMode(puppin, INPUT);
  pinMode(pdownpin, INPUT);
  pinMode(pcenterpin, INPUT);
} 
 
void loop() 
{ 
  //manual overide reset button
  buttonval = digitalRead(buttonpin);
  if (buttonval==1)  
  {
     digitalWrite(ledpin, HIGH);
     xval = 90;
     yval = 90;
  }  
  
  //joystick control
  digitalWrite(ledpin, LOW);
  xanal = analogRead(xpot);            // reads the value of the potentiometer (value between 0 and 1023) 
  if (xanal > 800)
    xval = xval + 2;
  if (xanal < 200)
    xval = xval - 2;
  yanal = analogRead(ypot);
  if (yanal > 800)
    yval = yval + 2;
  if (yanal < 200)
    yval = yval - 2;
    
  //phone based control
  pleft = digitalRead(pleftpin);
  pright = digitalRead(prightpin);
  pup = digitalRead(puppin);
  pdown = digitalRead(pdownpin);
  pcenter = digitalRead(pcenterpin);
  
  if (pleft==1)
    xval = xval - 2;
  if (pright==1)
    xval = xval + 2;
  if (pdown==1)
    yval = yval - 2;
  if (pup==1)
    yval = yval + 2; 
  if (pcenter==1)
   {
    xval = 90;
   yval = 90;
   } 
  
  //anti-overflow stuff  
  if (xval < 2)
    xval = xval + 2;
  if (xval > 178)
    xval = xval - 2;
  if (yval < 2)
    yval = yval + 2;
  if (yval > 178)
    yval = yval - 2;
  
  //write to servos
  xservo.write(xval);                  // sets the servo position according to the scaled value 
  delay(50);
  yservo.write(yval);
  delay(50);                           // waits for the servo to get there 
  
} 
