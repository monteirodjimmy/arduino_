#define led_red 10
int blinkDelay = 500;
int LEDState = LOW;

void setup() {
  Serial.begin(9600); //Define a velocidade de comunicação
  pinMode(led_red,OUTPUT);
  digitalWrite(led_red,LOW);

}

void loop() {
  if(Serial.available() > 0){
    int time = Serial.parseInt();
  
    if ((time >= 100) && (time <= 1000)){
      blinkDelay = time;
    }else{
      Serial.println("This value is not availeble");
    }
  }

   if (LEDState == LOW){
    LEDState = HIGH;
  }else{
    LEDState = LOW;
  }

  digitalWrite(led_red,LEDState);
  delay(blinkDelay);
  //blink the Led
  //delay(from the Serial)
  // condicionla entre 100 - 1000 

}
