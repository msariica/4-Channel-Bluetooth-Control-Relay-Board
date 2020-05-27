
#include <SoftwareSerial.h>     // bluetooth modülü için seri haberleşme başlatıldı

SoftwareSerial bluetooth(0,1);  // rx, tx 

// röle pinlerini tanımlıyoruz

#define rly1 8
#define rly2 9
#define rly3 10
#define rly4 11

String data = "";  //data değişkenini başlatıyoruz

void setup() {
  Serial.begin(9600);    // seri monitörün baud hızını ayarlama
  bluetooth.begin(9600); // bağlı bluetooth modülünün baud hızını ayarlama

  pinMode(rly1, OUTPUT);
  pinMode(rly2, OUTPUT);
  pinMode(rly3, OUTPUT);
  pinMode(rly4, OUTPUT);
}

void loop() {         
  while(bluetooth.available()) {  // Bluetooth'un bir şey alıp almadığını kontrol edin
    char c = bluetooth.read();    
    data += c;
    delay(10);
  }
  if (data.length() > 0) {        // veri uzunluğunun sıfırdan büyük olup olmadığını kontrol edin
    Serial.print(F("Received data: "));
    Serial.println(data);         // alınan verileri seri monitöre yazdıralım
    if(data == 'A'){              
    digitalWrite(rly1, HIGH);// veriler büyük A ise röle 1 i aç
    Serial.println("Role1 Acık");
    }
    else if(data == 'a'){
      digitalWrite(rly1, LOW);// veriler küçük a ise röle 1 i kapat
      Serial.println("Role1 Kapali");
    }
    else if(data == 'B'){
      digitalWrite(rly2, HIGH);
      Serial.println("Role2 Acık");
    }
    else if(data == 'b'){
      digitalWrite(rly2, LOW);
      Serial.println("Role2 Kapali");
    }
    else if(data == 'C'){
      digitalWrite(rly3, HIGH);
       Serial.println("Role3 Acık");
    }
    else if(data == 'c'){
      digitalWrite(rly3, LOW);
      Serial.println("Role3 Kapali");
    }
    else if(data == 'D'){
      digitalWrite(rly4, HIGH);
       Serial.println("Role4 Acık");
    }
    else if(data == 'd'){
      digitalWrite(rly4, LOW);
      Serial.println("Role4 Kapali"); 
    }
    
   
    data = "";  
  }
}
