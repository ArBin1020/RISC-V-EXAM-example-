int count = 0; // 外部中斷次數
void setup(){
  Serial.begin(9600); // 啟動串列埠
  pinMode(BT1, INPUT_PULLUP); // 設定 D2(INT0)為輸入有提升電阻
  attachInterrupt(BT1, disp_count, FALLING); // 致能外部中斷腳、函數及負緣
}
void loop(){
} // 主程式此時可進行其它工作，同時等待 INT0 外部中斷
void disp_count(){ // INT0 中斷服務程式
  unsigned int dly;
  noInterrupts(); // 停止中斷
  dly = 50000;
  while (dly--); // 延時，防止機械彈跳
  while (!digitalRead(BT1)); // 等待放開鍵
  dly = 50000;
  while (dly--); // 延時，防止機械彈跳
  Serial.print("you have pressed ");
  Serial.print(count++);// 中斷次數遞加送到串列埠顯示
  Serial.println(" times");
  interrupts(); // 恢復中斷
}
