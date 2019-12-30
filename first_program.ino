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
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  
  digitalWrite(enA,SPEED);
  digitalWrite(enB,SPEED);
}

void loop() {
 //  int potValue = 255 ;// analogRead(A0); // Read potentiometer value
  // int pwmOutput = map(1023, 0, 1023, 0 , 255); // Map the potentiometer value from 0 to 255
  // analogWrite(enA, pwmOutput); // Send PWM signal to L298N Enable pin

  // Read button - Debounce
  // if (digitalRead(button) == true) {
    //pressed = !pressed;
  //}
  // while (digitalRead(button) == true);
  delay(20);

  // If button is pressed - change rotation direction
  //if (pressed == true  & rotDirection == 0) {
    //digitalWrite(in1, HIGH);
    //digitalWrite(in2, LOW);
    //rotDirection = 1;
    //delay(20);
  //}  
  // If button is pressed - change rotation direction
  //if (pressed == false & rotDirection == 1) {
    //digitalWrite(in1, LOW);
    //digitalWrite(in2, HIGH);
    //rotDirection = 0;
    //delay(20);
  //}
}
