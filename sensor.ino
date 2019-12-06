int TriggerPIN1 = D3;
int EchoPIN1 = D4;
int TriggerPIN2 = D6;
int EchoPIN2 = D7;

void setup () {
  pinMode(TriggerPIN1,OUTPUT);
  pinMode(EchoPIN1,INPUT);
  
  pinMode(TriggerPIN2,OUTPUT);
  pinMode(EchoPIN2,INPUT);
  
  Serial.begin(9600); 
}

void loop(){  
  digitalWrite(TriggerPIN1,LOW);
  delayMicroseconds(2);
  digitalWrite(TriggerPIN1,HIGH);
  delayMicroseconds(2);
  digitalWrite(TriggerPIN1,LOW);

  long timedelay = pulseIn(EchoPIN1,HIGH);
  int distance_cm = timedelay / 58;
  int distance1 = 0.0343 * (timedelay/2);

//  if (distance_cm < 70) {
  if (distance1 < 70) {

    Serial.print("Sensor 1 : ");
//    Serial.println(distance_cm);  
    Serial.println(distance1);  

  }
  

  delayMicroseconds(2);

  digitalWrite(TriggerPIN2,LOW);
  delayMicroseconds(2);
  digitalWrite(TriggerPIN2,HIGH);
  delayMicroseconds(2);
  digitalWrite(TriggerPIN2,LOW);

  long td = pulseIn(EchoPIN2,HIGH);
  int distance_cm_b = td / 58;
  int distance2 = 0.0343 * (td/2);

//  if (distance_cm_b < 70) {
  if (distance2 < 70) {

    Serial.print("Sensor 2 : ");
//    Serial.println(distance_cm_b);  
    Serial.println(distance2);  

  }
  
}
