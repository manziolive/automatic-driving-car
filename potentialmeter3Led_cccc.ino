 int potpin=A0 ;
 int potvalue=0;
 void setup() {
  //   
 pinMode(13,OUTPUT);
 pinMode(12,OUTPUT);
pinMode(11,OUTPUT);
}
 
void loop() {
  // put your main code here, to run repeatedly:
potvalue=analogRead(potpin);
analogWrite(13,potvalue);
analogWrite(12,potvalue);
analogWrite(11,potvalue);
delay(10);
}
