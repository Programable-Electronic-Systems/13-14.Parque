int n=0; 
int turno = 1;
int convinacionArray[100];
int respuestaArray[100];

int Leds[] ={6,7,8,9};
int Puls[]={2,3,4,5};

int inputRojo = LOW;
int inputVerde = LOW;
int inputAmarillo = LOW;
int inputAzul = LOW;

int ledRojo=11;
int ledVerde=12;

void nuestraDemoDos()
{
  int aleLed = 0;
  
  int numNumeros = random(0, 5);
  for (int i=0; i<numNumeros; i++)
  {
    parpadeo();
  }
  for (n=0; n<numNumeros; n++)
  {
    aleLed = random(0, 4);
    digitalWrite(Leds[aleLed],HIGH);
    delay(1000);
    digitalWrite(Leds[aleLed],LOW);
    delay(500);
  }
}


void nuestraDemoUno()
{
  for (n=0; n<4; n++)
  {
    digitalWrite(Leds[n],HIGH);
    delay(1000);
    digitalWrite(Leds[n],LOW);
  }
}

void parpadeo()                                   
{
  digitalWrite(ledRojo,HIGH);
  digitalWrite(ledVerde,LOW);
  for(n=0;n<4;n++)
    digitalWrite(Leds[n],HIGH);
  delay(300);
  for(n=0;n<4;n++)
    digitalWrite(Leds[n],LOW);
  delay(300);
}


void pulpo()
{
  int aleLed = 0;
  
  digitalWrite(ledRojo,HIGH);
  digitalWrite(ledVerde,LOW);
  
  for (n=0; n<turno; n++)
  {
    convinacionArray[n] = random(0, 4);
    digitalWrite(Leds[convinacionArray[n]],HIGH);
    delay(1000);
    digitalWrite(Leds[convinacionArray[n]],LOW);
    delay(500);
  }
}

void seta()
{
  digitalWrite(ledRojo,LOW);
  digitalWrite(ledVerde,HIGH);
  for(n=0; n<turno; n++)
  {
    while(digitalRead(Puls[0]) == LOW &&  digitalRead(Puls[1]) == LOW &&  digitalRead(Puls[2]) == LOW &&  digitalRead(Puls[3]) == LOW) { } // do nothing
    inputRojo = digitalRead(Puls[0]);
    inputVerde = digitalRead(Puls[1]);
    inputAmarillo = digitalRead(Puls[2]);
    inputAzul = digitalRead(Puls[3]);
    
    
    if (inputRojo == HIGH)
    {
      digitalWrite(Leds[0], HIGH);
      delay(200);
      digitalWrite(Leds[0], LOW);
      respuestaArray[n]= 0;
      delay(50);
      if (respuestaArray[n]!= convinacionArray[n]) 
      {
        fail();
        break;
      }
    }
    
    if (inputVerde == HIGH)
    {
      digitalWrite(Leds[1], HIGH);
      delay(200);
      digitalWrite(Leds[1], LOW);
      respuestaArray[n]= 1;
      delay(50);
      if (respuestaArray[n]!= convinacionArray[n]) 
      {
        fail();
        break;
      }
    }
    
    if (inputAmarillo == HIGH)
    {
      digitalWrite(Leds[2], HIGH);
      delay(200);
      digitalWrite(Leds[2], LOW);
      respuestaArray[n]= 2;
      delay(50);
      if (respuestaArray[n]!= convinacionArray[n]) 
      {
        fail();
        break;
      }
    }
    
    if (inputAzul == HIGH)
    {
      digitalWrite(Leds[3], HIGH);
      delay(200);
      digitalWrite(Leds[3], LOW);
      respuestaArray[n]= 3;
      delay(50);
      if (respuestaArray[n]!= convinacionArray[n]) 
      {
        fail();
        break;
      }
    }
  }
  success();
  delay(500);
}

void fail(){
  digitalWrite(ledRojo,HIGH);
  digitalWrite(ledVerde,LOW);
  for (int i=0; i<3; i++)
  {
    parpadeo();
  }
  turno = 0;
}

void success(){
  digitalWrite(ledRojo,HIGH);
  digitalWrite(ledVerde,LOW);
  for (int i=0; i<1; i++)
  {
    parpadeo();
  }
}

void setup()
{
  pinMode(ledRojo, OUTPUT); 
  pinMode(ledVerde, OUTPUT); 
  
  for (int i=0; i<2; i++)
  {
    parpadeo();
  }
  for (n=0; n<4; n++)                           
    pinMode(Puls[n], INPUT);
  for (n=0; n<4; n++)                           
    pinMode(Leds[n], OUTPUT);

  for(turno=1; turno<100; turno++)
  {
    pulpo();
    seta();
    delay(2500);
  }
}

void loop()
{
}
