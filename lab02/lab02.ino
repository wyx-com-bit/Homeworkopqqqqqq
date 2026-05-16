// 定义LED引脚，Arduino板载LED通常是13号引脚
const int ledPin = 2;

void setup() {
  // 设置LED引脚为输出模式
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // 发送SOS求救信号
  sendSOS();
  
  // 信号发送完毕后等待2秒，再重复发送
  delay(2000);
}

// 发送SOS信号函数：三短、三长、三短
void sendSOS() {
  // 字母S：短闪3次
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);  // 点亮LED
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