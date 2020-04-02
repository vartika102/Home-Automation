boolean v[5], s[5], a[5], b[5];
void setup() {
  Serial.begin(9600);
  
  //input from switches
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  
  //input from nodemcu
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
 
  //output to relay
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

  //stores last state
  for(int i = 0; i<5; i++)
  {
    v[i] = 1;//current state
    b[i] = 1;//previos app button state
  }
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  int c = 0;
  //digitalread of switches
  s[0] = digitalRead(2);
  s[1] = digitalRead(3);
  s[2] = digitalRead(4);
  s[3] = digitalRead(5);
  s[4] = digitalRead(6);

  //digialread of nodemcu
  a[0] = digitalRead(A0);
  a[1] = digitalRead(A1);
  a[2] = digitalRead(A2);
  a[3] = digitalRead(A3);
  a[4] = digitalRead(A4);
  
  for(int i = 0; i<5; i++)
  {
    if(s[i]==1)
    {
    v[i] = !v[i];
    c = 1;
    }
    else if(a[i]!=b[i])
    v[i] = a[i];
    
    b[i] = a[i];
  }
  
  analogWrite(7,v[0]);
  analogWrite(8,v[1]);
  analogWrite(9,v[2]);
  analogWrite(10,v[3]);
  analogWrite(11,v[4]);
 
  if(c == 1)
  delay(500);
}
