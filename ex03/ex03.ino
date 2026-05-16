// ex03: 非阻塞 SOS 信号灯 (millis() 实现, 无delay)
// 标准摩斯码：S(三短) + O(三长) + S(三短)
const int LED_PIN = 2;  // 板载LED

// 时间参数 (毫秒)
const unsigned long SHORT = 200;    // 短亮
const unsigned long LONG = 600;     // 长亮
const unsigned long INTERVAL = 200; // 间隔
const unsigned long LETTER = 500;   // 字母间隔
const unsigned long END = 2000;     // 一轮结束间隔

unsigned long lastTime = 0;
int step = 0;
bool ledStatus = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  unsigned long now = millis();
  handleSOS(now);
  digitalWrite(LED_PIN, ledStatus);
}

void handleSOS(unsigned long now) {
  if (now - lastTime < getDelay(step)) return;

  ledStatus = !ledStatus;
  lastTime = now;
  step++;

  if (step > 17) step = 0; // 循环播放
}

// 获取每一步的延时时间
unsigned long getDelay(int s) {
  switch(s) {
    case 0: return SHORT;   // 短亮
    case 1: return INTERVAL;// 灭
    case 2: return SHORT;
    case 3: return INTERVAL;
    case 4: return SHORT;
    case 5: return LETTER;  // S结束

    case 6: return LONG;    // 长亮
    case 7: return INTERVAL;
    case 8: return LONG;
    case 9: return INTERVAL;
    case 10: return LONG;
    case 11: return LETTER; // O结束

    case 12: return SHORT;  // 短亮
    case 13: return INTERVAL;
    case 14: return SHORT;
    case 15: return INTERVAL;
    case 16: return SHORT;
    case 17: return END;    // 一轮结束
    default: return 100;
  }
}