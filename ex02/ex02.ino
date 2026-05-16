
const int ledPin = 2;          // 板载LED引脚
unsigned long previousMillis = 0;  // 记录上一次状态切换的时间
const long interval = 1000;     // 闪烁间隔1000ms（1Hz）
bool ledState = LOW;            // LED当前状态

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // 获取当前系统运行时间
  unsigned long currentMillis = millis();

  // 当间隔时间到达时，切换LED状态
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  // 更新上一次切换时间
    ledState = !ledState;            // 翻转LED状态
    digitalWrite(ledPin, ledState);  // 写入新状态
  }
}