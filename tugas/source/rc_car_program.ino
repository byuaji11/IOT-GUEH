#include <SoftwareSerial.h>

// Pin 2 Arduino ke TX HC-06, Pin 3 Arduino ke RX HC-06
SoftwareSerial bluetooth(2, 3); 

const int motorKiriMaju =  4;
const int motorKiriMundur = 5;
const int motorKananMaju =  6;
const int motorKananMundur = 7;

char dataDiterima; 

void setup() {
  bluetooth.begin(9600);
  Serial.begin(9600);
  Serial.println("Sistem Mobil RC Serial Siap...");

  pinMode(motorKiriMaju, OUTPUT);
  pinMode(motorKiriMundur, OUTPUT);
  pinMode(motorKananMaju, OUTPUT);
  pinMode(motorKananMundur, OUTPUT);
  
  matikanMotor(); 
}

void loop() {
  if (bluetooth.available() > 0) {
    dataDiterima = bluetooth.read();
    
    // Mengikuti karakter standar tombol aplikasi
    switch(dataDiterima) {
      case 'F': maju(); break;
      case 'B': mundur(); break;
      case 'L': belokKiri(); break;
      case 'R': belokKanan(); break;
      case 'S': matikanMotor(); break;
    }
  }
}

void maju() {
  digitalWrite(motorKiriMaju, HIGH);   digitalWrite(motorKiriMundur, LOW);
  digitalWrite(motorKananMaju, HIGH);  digitalWrite(motorKananMundur, LOW);
}
void mundur() {
  digitalWrite(motorKiriMaju, LOW);    digitalWrite(motorKiriMundur, HIGH);
  digitalWrite(motorKananMaju, LOW);   digitalWrite(motorKananMundur, HIGH);
}
void belokKiri() {
  digitalWrite(motorKiriMaju, LOW);    digitalWrite(motorKiriMundur, HIGH);
  digitalWrite(motorKananMaju, HIGH);  digitalWrite(motorKananMundur, LOW);
}
void belokKanan() {
  digitalWrite(motorKiriMaju, HIGH);   digitalWrite(motorKiriMundur, LOW);
  digitalWrite(motorKananMaju, LOW);    digitalWrite(motorKananMundur, HIGH);
}
void matikanMotor() {
  digitalWrite(motorKiriMaju, LOW);    digitalWrite(motorKiriMundur, LOW);
  digitalWrite(motorKananMaju, LOW);    digitalWrite(motorKananMundur, LOW);
}

