int LDR = 1;
float val = 0;
float resul=0;
int LED = 3;

void setup() {
  Serial.begin(9600);
   pinMode(LDR, OUTPUT); 
}

void loop() {
 val = analogRead(LDR);
 resul=val/4;
 if(resul<=22.00)
 {
   resul=1.00;
 }
 if(resul>=10
 0.00)
 {
   resul=255.00;
 }

 analogWrite(LED, -resul);
 Serial.println(resul);
 delay(100);
}


