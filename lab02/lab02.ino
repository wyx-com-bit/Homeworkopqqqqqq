// 定义LED引脚，ESP32通常板载LED连接在GPIO 2
const int ledPin = 4; 

void setup() {

  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);  
  Serial.println("LED ON");    
  delay(100);                 
  
  digitalWrite(ledPin, LOW);   
  Serial.println("LED OFF");   // 串口输出提示
  delay(1000);                 // 保持1秒
}