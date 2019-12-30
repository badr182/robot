/*  Arduino DC Motor Control - PWM | H-Bridge | L298N  -  Example 01

    by Dejan Nedelkovski, www.HowToMechatronics.com
*/

#define enA 5
#define in1 7
#define in2 8


#define enB 3
#define in3 4
#define in4 2

// #define button 4
int SPEED = 210;
int rotDirection = 0;
int pressed = false;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // pinMode(button, INPUT);
  // Set initial rotation direction
  // explication par badr akkar  : 
  // in1 = Low et in2 = High : moteur 1 et 2 en avant 
  // si non en arrière 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  // explication par badr akkar  :
  // intialiser le speed  
  digitalWrite(enA,SPEED);
  digitalWrite(enB,SPEED);
}

void loop() {delay(20);
  
}
