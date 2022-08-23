int buttonState = 0;
const int buttonPin = 6;
int data;
const int ledPin =LED_BUILTIN;  //arduino mega üzerindeki ledi yakar. 
void setup() 
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}
void loop() 
{
 if(Serial.available())
 {
  
  data = Serial.read();
  if(data==49) {
    digitalWrite(ledPin,HIGH);
  }
  else if(data==50){
    digitalWrite(ledPin,LOW);
  }
  else if (data==51)
  {
    Serial.print(data-48);
    for (int i=0; i<3; i++) {    
    digitalWrite(ledPin,HIGH);
    delay(400);
    digitalWrite(ledPin,LOW);
    delay(400);
    }
  }
  else if (data==52)
  {
  }
  else if (data==53)
  {
    Serial.print("Butona basılmaya hazır");
      int counter=0;
      while(1){
        buttonState = digitalRead(buttonPin);
    if (buttonState==HIGH){
      counter++;
      
      Serial.println(counter);
      while(buttonState == HIGH){ /* Butona basili olduğu surece bekle */
     buttonState = digitalRead(buttonPin); /* Butonun durumunu kontrol et */
   }
   delay(10);
    }
    }
    
    }
}
}
