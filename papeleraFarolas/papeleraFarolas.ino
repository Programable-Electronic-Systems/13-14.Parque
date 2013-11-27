#define ECHOPIN 4                            // Pin to receive echo pulse
#define TRIGPIN 5                            // Pin to send trigger pulse
//int LDR = 1;
//int val;
//float resul=0;
int LED = 7;
int distance;
int cont = 0; 
boolean activado=false;
String c = "La papelera esta llena en estos momentos";
char entrada;
int LDR = A1;
float val = 0;
float resul=0;
int LEDfarola = 9;

void setup()
{
  Serial.begin(9600);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(LEDfarola, OUTPUT);
}

void loop()
{
  distanciaPapelera();
//  if(Serial.available()>0){ 
//      entrada=Serial.read();
//       Serial.write(entrada);
//  }
   if(distance<=45)
   {
      cont=cont+1;
      if(cont>=10)
      {
        digitalWrite(LED, HIGH);
        if(!activado)
        {
           Serial.println(c);
           activado= true;
        }
       } 
   }
   else
   {
       cont=0;
       digitalWrite(LED, LOW);
       activado= false;
   }
    val = analogRead(LDR);
    resul=val/4;
   if((255-resul)<130.00)
  {
    analogWrite(LEDfarola, 0.00);
  }
  else
  {
    analogWrite(LEDfarola,(255-resul)*2);
  }  

}


void distanciaPapelera(){
  
  digitalWrite(TRIGPIN, LOW);                   // Set the trigger pin to low for 2uS
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);                  // Send a 10uS high to trigger ranging
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);                   // Send pin low again
  distance = pulseIn(ECHOPIN, HIGH);        // Read in times pulse
  distance= distance/58;                        // Calculate distance from time of pulse
  delay(500);           
}
