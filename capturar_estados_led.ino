#define led_red 10
#define led_blue 11
#define led_yellow 7
#define button_pin 3
#define LED_PIN_ARRAY_SIZE 3

int LEDBlinkState = 1;

byte LEDPinArray[LED_PIN_ARRAY_SIZE]={led_red, led_blue, led_red};

void setLEDPinModes(){
  for (int i = 0; i < LED_PIN_ARRAY_SIZE; i++){
    pinMode(LEDPinArray[i],OUTPUT);
  }
}

void turnoOffAllLEDs(){
  for(int i =0; i < LED_PIN_ARRAY_SIZE; i++ ){
    digitalWrite(LEDPinArray[i],LOW);
  }
}

void toggleLEDs(){
  if(LEDBlinkState == 1){
      digitalWrite(led_red,HIGH);
      digitalWrite(led_yellow,LOW);
      digitalWrite(led_blue,LOW);
      LEDBlinkState = 2;
    } else if(LEDBlinkState == 2){

      digitalWrite(led_red,LOW);
      digitalWrite(led_yellow,HIGH);
      digitalWrite(led_blue,LOW);

      LEDBlinkState = 3;

    }
    else{
      digitalWrite(led_red,LOW);
      digitalWrite(led_yellow,LOW);
      digitalWrite(led_blue,HIGH);
      LEDBlinkState = 1;
    }

}


void setup() {
  // put your setup code here, to run once:
  pinMode(button_pin, INPUT);
  setLEDPinModes();
  turnoOffAllLEDs();
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(button_pin) == LOW){
    toggleLEDs();
    delay(100);
  }
}
