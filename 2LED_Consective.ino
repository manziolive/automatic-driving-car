
int ledYellow=9;
int ledGreen=10;
int ledWhite=11;
int ledBlue=12 ; 
void setup(){ 
pinMode(ledWhite,OUTPUT); 
pinMode(ledYellow,OUTPUT);
pinMode(ledGreen,OUTPUT);
pinMode(ledBlue,OUTPUT);

}

void loop() {
 // put your main code here, to run repeatedly:
digitalWrite(ledYellow,HIGH);
digitalWrite(ledGreen,HIGH);
digitalWrite(ledWhite,LOW);
digitalWrite(ledBlue,LOW);
delay(1000);
digitalWrite(ledWhite,HIGH);
digitalWrite(ledYellow,LOW);
digitalWrite(ledGreen ,LOW);
digitalWrite(ledBlue,HIGH );
delay(1000); 

} 
