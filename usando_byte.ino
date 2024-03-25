
#define LED_PIN 11
byte pwmValue;

void setup() {
  // put your setup code here, to run once:
    pinMode(LED_PIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(LED_PIN,pwmValue);
  pwmValue++;
  delay(5);
}
