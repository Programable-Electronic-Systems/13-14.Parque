#define ECHOPIN 2                            // Pin to receive echo pulse
#define TRIGPIN 3                            // Pin to send trigger pulse
//int LDR = 1;
//int val;
//float resul=0;
int LED = 7;
int distance;
int cont = 0; 

void setup(){
  Serial.begin(9600);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(LED, OUTPUT);

}

void loop(){
 
  distanciaPapelera();
  
   if(distance<=45)
   {
      cont=cont+1;
      if(cont>=10)
      {
        digitalWrite(LED, HIGH);
      } 
      
   }
   else
   {
       cont=0;
       digitalWrite(LED, LOW);
   }
   
  
   Serial.println(distance); 
  // delay(100);
  
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
