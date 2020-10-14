int m1a=0;
int m1b=7;
void setup()
{
pinMode(m1a,OUTPUT);
pinMode(m1b,OUTPUT);

}
void loop()
{digitalWrite(m1a,HIGH);
digitalWrite(m1b,LOW);
delay(1000);
digitalWrite(m1a,LOW);
digitalWrite(m1b,HIGH);

delay(1000);

}
