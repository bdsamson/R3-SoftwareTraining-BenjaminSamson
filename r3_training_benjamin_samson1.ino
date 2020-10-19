//Arduino pins used for the switches
#define S1 3
#define S2 2
#define S3 8
#define S4 9

//initializing switches' states
int s1state = HIGH;
int s2state = HIGH;
int s3state = HIGH;
int s4state = HIGH;

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(S1, INPUT_PULLUP);
  pinMode(S2, INPUT_PULLUP);
  pinMode(S3, INPUT_PULLUP);
  pinMode(S4, INPUT_PULLUP);
}

void loop()
{
  
  
  s1state = digitalRead(S1);
  s2state = digitalRead(S2);
  s3state = digitalRead(S3);
  s4state = digitalRead(S4);
  
  int sensorValue = analogRead(A0);
  //for checking voltage coming from potentiometer
  float voltage = sensorValue*(5.0/1023.0);
  float pwm = sensorValue;
  //Serial.println(voltage);
  //Serial.println(s1state);
  
  analogWrite(11,pwm/4);
  
  if(s1state == HIGH && s2state == LOW && s3state == LOW && s4state == LOW){
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(4,HIGH);
  }  
  else if(s1state == LOW && s2state == HIGH && s3state == LOW && s4state == LOW){
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(4,LOW);
  }
  else if(s1state == LOW && s2state == LOW && s3state == HIGH && s4state == LOW){
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(5,LOW);
  digitalWrite(4,HIGH);
  }
  else if(s1state == LOW && s2state == LOW && s3state == LOW && s4state == HIGH){
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(4,LOW);
  }
  else{
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
  }
  //for checking the states of the switches
  Serial.print("S1: "); 
  Serial.println(s1state);
  Serial.print("S2: "); 
  Serial.println(s2state);
  Serial.print("S3: "); 
  Serial.println(s3state);
  Serial.print("S4: "); 
  Serial.println(s4state);
  delay(5000);
 }