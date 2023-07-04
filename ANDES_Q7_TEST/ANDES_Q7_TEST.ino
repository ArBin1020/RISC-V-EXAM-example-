char ch; // 字元
byte no; // 個數
void setup() {
  Serial.begin(9600); // 設定串列埠的鮑率為 9600 bps
}
void loop(){
  if (Serial.available()){ // 判斷串列埠緩衝區有無資料
    ch = Serial.read(); // 從串列埠緩衝區中讀取一個字元
    if (ch >= '1' && ch <= '9'){// 判斷字元是否介於'1'～'9'之間
      no = ch - '0'; // 將 ASCII 值轉成數值
      Serial.print(no); // 將 no 顯示在 Serial Monitor
      Serial.print(" ");
      for (int i = 0; i < no; i++) // 使用 for 迴圈顯示 no 個*
        Serial.print("*"); // 在 Serial Monitor 中顯示*
      Serial.println(); // 分行
    }
  }
}
