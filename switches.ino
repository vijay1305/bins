
int m1a=7;
int m1b=0;
int m2a=A0;
int m2b=A5;
int val = 0;

#define sw1 1
#define sw2 2
#define sw3 3
#define sw4 4


void setup()
{
pinMode(m1a,OUTPUT);
pinMode(m1b,OUTPUT);
pinMode(m2a,OUTPUT);
pinMode(m2b,OUTPUT);
pinMode(sw1,INPUT);
pinMode(sw2,INPUT);
pinMode(sw3,INPUT);
pinMode(sw4,INPUT);
digitalWrite(m1a,LOW);
digitalWrite(m1b,LOW);
digitalWrite(m2a,LOW);
digitalWrite(m2b,LOW);

}
void loop()
{
 val=digitalRead(sw1);
 if (val == LOW)
{
digitalWrite(m1a,HIGH);
digitalWrite(m1b,LOW);
digitalWrite(m2a,HIGH);
digitalWrite(m2b,LOW);

}
val=digitalRead(sw2);
if (val == LOW)
{
digitalWrite(m1a,LOW);
digitalWrite(m1b,HIGH);
digitalWrite(m2a,LOW);
digitalWrite(m2b,HIGH);

}
val=digitalRead(sw3);
if (val == LOW)
{
digitalWrite(m1a,HIGH);
digitalWrite(m1b,LOW);
digitalWrite(m2a,LOW);
digitalWrite(m2b,HIGH);

}
val=digitalRead(sw4);
if (val == LOW)
{
digitalWrite(m1a,LOW);
digitalWrite(m1b,HIGH);
digitalWrite(m2a,HIGH);
digitalWrite(m2b,LOW);
}
}

