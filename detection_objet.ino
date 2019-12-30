//moteur droit
# define dir1PinA 2
# define dir2PinA 7
# define speedPinA 5
//moteur gauche
# define dir1PinB 4
# define dir2PinB 8
# define speedPinB 3
//Radar
# define trigger 9
# define eccho 10
//leds
# define led_rouge 5
# define led_orange 4
# define led_verte 3
//Variables
int dir= 0;
int var_tourner =0;
int *pointeur;
int *pointeur2;
 
 
 
void radar(int*);
void avancer();
void reculer(int*);
void tourner(int*);
 
 
void setup()
{
  Serial.begin(9600);
  pinMode(trigger,OUTPUT);
  pinMode(led_rouge,OUTPUT);
  pinMode(led_orange,OUTPUT);
  pinMode(led_verte,OUTPUT);
  pinMode(eccho,INPUT);
  pinMode(dir1PinA, OUTPUT);
  pinMode(dir2PinA, OUTPUT);
  pinMode(speedPinA, OUTPUT);
  pinMode(dir1PinB, OUTPUT);
  pinMode(dir2PinB, OUTPUT);
  pinMode(speedPinB, OUTPUT);
  pointeur=&dir;
  pointeur2=&var_tourner;
  
}
 
void loop()
{
 
  radar(pointeur);
  analogWrite(speedPinA, 200); // vitesse fixée arbitrairement
  analogWrite(speedPinB, 200);
  
  
  
  if (dir == 0) 
  {
    avancer();
  } 
  if(dir == 1 && var_tourner == 0)
  {
     reculer(pointeur2);
  }
  
  if(var_tourner == 1)
  {
     tourner(pointeur2);
  }
 
}
 
 
void radar(int* pointeur)
{
  long lecture_eccho;
  long distance;
  
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  lecture_eccho=pulseIn(eccho,HIGH);
  distance=lecture_eccho/58;
  
  if(distance < 20.0)
  {
    digitalWrite(led_rouge,HIGH);
    digitalWrite(led_orange,LOW);
    digitalWrite(led_verte,LOW);
    *pointeur=0;
  }
  
  if(distance > 20.0 && distance < 40.0)
  {
    digitalWrite(led_rouge,LOW);
    digitalWrite(led_orange,HIGH);
    digitalWrite(led_verte,LOW);
    *pointeur=0;
  }
  
  if(distance > 40.0)
  {
    digitalWrite(led_rouge,LOW);
    digitalWrite(led_orange,LOW);
    digitalWrite(led_verte,HIGH);
    *pointeur=1;
  }
  
  delay(10);
}
 
void reculer(int* pointeur2)
{
    digitalWrite(dir1PinA, LOW);
    digitalWrite(dir2PinA, HIGH);
    digitalWrite(dir1PinB, LOW);
    digitalWrite(dir2PinB, HIGH);
    //delay(500);
    *pointeur2=1;
  
}
    
void tourner(int* pointeur2)
{
  analogWrite(speedPinA, 255); 
  analogWrite(speedPinB, 255);
    digitalWrite(dir1PinA, LOW);
    digitalWrite(dir2PinA, HIGH);
    digitalWrite(dir1PinB, HIGH);
    digitalWrite(dir2PinB, LOW);
 
    delay(1500);
    *pointeur2=0;
}
 
void avancer()
{
    digitalWrite(dir1PinA, HIGH);
    digitalWrite(dir2PinA, LOW);
    digitalWrite(dir1PinB, HIGH);
    digitalWrite(dir2PinB, LOW);
}
