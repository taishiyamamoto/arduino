/*int latchPin = 8;  // 74HC595のST_CPへ
int clockPin = 12; // 74HC595のSH_CPへ
int dataPin = 11;  // 74HC595のDSへ*/

int latchPin = 2;  // 74HC595のST_CPへ
int clockPin = 4; // 74HC595のSH_CPへ
int dataPin = 3;  // 74HC595のDSへ

byte data[]= {B00000000,B00000001};
byte temp;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  int cnt=0;
  // LED1からLED8までを順に光らせます
  for(int i=0;i<1;i++){
    temp=data[0];
    data[0]=data[1];
    data[1]=temp;
   for (int j = 0; j < 8; j++) {
     // 送信中のlatchPinはグランド(LOW)レベル
     digitalWrite(latchPin, LOW);
     // シフト演算を使って点灯するLEDを選択しています
     shiftOut(dataPin, clockPin, LSBFIRST,(data[0]<<j) );
     shiftOut(dataPin, clockPin, LSBFIRST,(data[1]<<j) );
     // 送信終了後latchPinをHIGHにする
    digitalWrite(latchPin, HIGH);
    delay(100);
   }
  }
}
