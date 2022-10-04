void setup() {
pinMode(LED_RED,OUTPUT);

}

void loop() {

  delay(3000);
  digitalWrite(LED_RED,LOW);
  digitalWrite(LED_GREEN,HIGH);
  digitalWrite(LED_BLUE,HIGH);
  delay(3000);
  digitalWrite(LED_RED,HIGH);
  digitalWrite(LED_GREEN,LOW);
  digitalWrite(LED_RED,HIGH);
  delay(3000);
  digitalWrite(LED_RED,HIGH);
  digitalWrite(LED_GREEN,HIGH);
  digitalWrite(LED_BLUE,LOW);

}
