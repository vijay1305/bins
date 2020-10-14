int m1a=7;
int m1b=0;
int m2a=A0;
int m2b=A5;
#define sw 2


void setup()
{
pinMode(m1a,OUTPUT);
pinMode(m1b,OUTPUT);
pinMode(m2a,OUTPUT);
pinMode(m2b,OUTPUT);
pinMode(sw,INPUT);

}
void loop()
{
 if(digitalRead(sw)==LOW)
{
  digitalWrite(m1a,LOW);
digitalWrite(m1b,HIGH);
digitalWrite(m2a,LOW);
digitalWrite(m2b,HIGH);

}
else if(digitalRead(sw)==HIGH)
{
digitalWrite(m1a,HIGH);
digitalWrite(m1b,LOW);
digitalWrite(m2a,HIGH);
digitalWrite(m2b,LOW);


}}
