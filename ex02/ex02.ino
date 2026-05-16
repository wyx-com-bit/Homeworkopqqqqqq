
const int ledPin = 4;          
unsigned long previousMillis = 0;  
const long interval = 1000;    
bool ledState = LOW;           

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
 
  unsigned long currentMillis = millis();

 
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  // 更新上一次切换时间
    ledState = !ledState;            // 翻转LED状态
    digitalWrite(ledPin, ledState);  
  }
}