void setup() {
for(int i=0;i<=15;i++){
  if(i==3){ //D3腳位連接到蜂鳴器 如果讓他輸出會一直叫
   }
  else{
      pinMode(i,OUTPUT);
    }
  }
}

void loop() {
for(int i=0;i<=15;i++){
  if(i%2==1){
    digitalWrite(i, LOW);
    }
  else{
    digitalWrite(i, HIGH);
    }
  }
delay(1000);
for(int i=0;i<=13;i++){
  if(i%2==1){
    digitalWrite(i, HIGH);
    }
  else{
    digitalWrite(i, LOW);
    }
  }
delay(1000);
for(int i=13;i>=0;i-- ){
  digitalWrite(i, HIGH);
}
for(int i=13;i>=0;i-- ){
digitalWrite(i, LOW);
delay(600);
digitalWrite(i, HIGH);
  }
}
