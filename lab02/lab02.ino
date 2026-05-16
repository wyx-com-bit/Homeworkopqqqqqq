
const int ledPin = 4;

void setup() {

  pinMode(ledPin, OUTPUT);
}

void loop() {
  // 发送SOS求救信号
  sendSOS();
  
  // 信号发送完毕后等待2秒，再重复发送
  delay(2000);
}


void sendSOS() {
  // 字母S：短闪3次
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);  
    delay(200);                   // 短亮200ms
    digitalWrite(ledPin, LOW);   // 熄灭LED
    delay(200);                   // 短灭200ms
  }
  
  delay(500);  // 字母之间间隔500ms
  
  // 字母O：长闪3次
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);  // 点亮LED
    delay(600);                   // 长亮600ms
    digitalWrite(ledPin, LOW);   // 熄灭LED
    delay(200);                   // 短灭200ms
  }
  
  delay(500);  // 字母之间间隔500ms
  
  // 字母S：短闪3次
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);  // 点亮LED
    delay(200);                   // 短亮200ms
    digitalWrite(ledPin, LOW);   // 熄灭LED
    delay(200);                   // 短灭200ms
  }
}