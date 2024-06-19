#include <SPI.h>
#include <SoftwareSerial.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <String.h>              
#define RED1 2
#define RED2 3
#define RED3 4
#define RED4 6
#define RED5 7
#define RED6 8
#define RED7 9
#define RED8 10
#define RED9 11
#define RED10 12
#define BLUE1 13
#define BLUE2 22
#define BLUE3 23
#define BLUE4 24
#define GREEN5 25
#define GREEN6 26
#define GREEN7 27
#define GREEN8 28
#define GREEN9 29
#define GREEN10 30
#define pinservoent 31
#define pinservosai 32
#define SS_PIN 53 //SDA = SS
#define RST_PIN 5
#define LDRP A0
#define LDR1 A1
#define LDR2 A2
#define LDR3 A3
#define LDR4 A4
#define LDR5 A5
#define LDR6 A6
#define LDR7 A7
#define LDR8 A8
#define LDR9 A9
#define LDR10 A10
#define LDRent A11
#define LDRsai A12
Servo servoent, servosai;
MFRC522 rfid(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27,20,4);
int blue1, blue2, blue3, blue4, green5, green6, green7, green8, green9, green10;
int x, c, v, n, r;
String conteudo;
void setup()
{
  SPI.begin(); //incia spi bus
  Serial.begin(9600);
  rfid.PCD_Init();
  lcd.init();
  lcd.backlight();
  lcd.begin(20, 4);
  servoent.attach(pinservoent);
  servosai.attach(pinservosai);
  pinMode(RED1,OUTPUT);
  pinMode(RED2,OUTPUT);
  pinMode(RED3,OUTPUT);
  pinMode(RED4,OUTPUT);
  pinMode(RED5,OUTPUT);
  pinMode(RED6,OUTPUT);
  pinMode(RED7,OUTPUT);
  pinMode(RED8,OUTPUT);
  pinMode(RED9,OUTPUT);
  pinMode(RED10,OUTPUT);
  pinMode(BLUE1,OUTPUT);
  pinMode(BLUE2,OUTPUT);
  pinMode(BLUE3,OUTPUT);
  pinMode(BLUE4,OUTPUT);  
  pinMode(GREEN5,OUTPUT);
  pinMode(GREEN6,OUTPUT);
  pinMode(GREEN7,OUTPUT);
  pinMode(GREEN8,OUTPUT);
  pinMode(GREEN9,OUTPUT);
  pinMode(GREEN10,OUTPUT);  
  pinMode(LDR1,OUTPUT);
  pinMode(LDR2,OUTPUT);
  pinMode(LDR3,OUTPUT);
  pinMode(LDR4,OUTPUT);
  pinMode(LDR5,OUTPUT);
  pinMode(LDR6,OUTPUT);
  pinMode(LDR7,OUTPUT);
  pinMode(LDR8,OUTPUT);
  pinMode(LDR9,OUTPUT);
  pinMode(LDR10,OUTPUT);
  pinMode(LDRP,OUTPUT);
  pinMode(LDRent,OUTPUT);
  pinMode(LDRsai,OUTPUT);
  pinMode(pinservoent, OUTPUT);
  pinMode(pinservosai, OUTPUT);
}

void loop()
{
  if(analogRead(LDR1) >= analogRead(LDRP) - 10)
  {
   digitalWrite(BLUE1, HIGH);
   digitalWrite(RED1, LOW);
   blue1 = 1;
  }
  else
  {
   digitalWrite(BLUE1, LOW);
   digitalWrite(RED1, HIGH);
   blue1 = 0;
   r = 0;
  }

  if(analogRead(LDR2) >= analogRead(LDRP) - 10)
  {
   digitalWrite(BLUE2, HIGH);
   digitalWrite(RED2, LOW);
   blue2 = 1;
  }
  else
  {
   digitalWrite(BLUE2, LOW);
   digitalWrite(RED2, HIGH);
   blue2 = 0;
  }

  if(analogRead(LDR3) >= analogRead(LDRP) - 10)
  {
   digitalWrite(GREEN5, HIGH);
   digitalWrite(RED3, LOW);
   green5 = 1;
  }
  else
  {
   digitalWrite(GREEN5, LOW);
   digitalWrite(RED3, HIGH);
   green5 = 0;
  }

if(analogRead(LDR4) >= analogRead(LDRP) - 10)
  {
   digitalWrite(GREEN6, HIGH);
   digitalWrite(RED4, LOW);
   green6 = 1;
  }
  else
  {
   digitalWrite(GREEN6, LOW);
   digitalWrite(RED4, HIGH);
   green6 = 0;
  }

  if(analogRead(LDR5) >= analogRead(LDRP) - 10)
  {
   digitalWrite(GREEN7, HIGH);
   digitalWrite(RED5, LOW);
   green7 = 1;
  }
  else
  {
   digitalWrite(GREEN7, LOW);
   digitalWrite(RED5, HIGH);
   green7 = 0;
  }

  if(analogRead(LDR6) >= analogRead(LDRP) - 10)
  {
   digitalWrite(GREEN8, HIGH);
   digitalWrite(RED6, LOW);
   green8 = 1;
  }
  else
  {
   digitalWrite(GREEN8, LOW);
   digitalWrite(RED6, HIGH);
   green8 = 0;
  }

  if(analogRead(LDR7) >= analogRead(LDRP) - 10)
  {
   digitalWrite(GREEN9, HIGH);
   digitalWrite(RED7, LOW);
   green9 = 1;
  }
  else
  {
   digitalWrite(GREEN9, LOW);
   digitalWrite(RED7, HIGH);
   green9 = 0;
  }

  if(analogRead(LDR8) >= analogRead(LDRP) - 10)
  {
   digitalWrite(GREEN10, HIGH);
   digitalWrite(RED8, LOW);
   green10 = 1;
  }
  else
  {
   digitalWrite(GREEN10, LOW);
   digitalWrite(RED8, HIGH);
   green10 = 0;
  }

  if(analogRead(LDR9) >= analogRead(LDRP) - 10)
  {
   digitalWrite(BLUE4, HIGH);
   digitalWrite(RED9, LOW);
   blue4 = 1;
  }
  else
  {
   digitalWrite(BLUE4, LOW);
   digitalWrite(RED9, HIGH);
   blue4 = 0;
  }

  if(analogRead(LDR10) >= analogRead(LDRP) - 10)
  {
   digitalWrite(BLUE3, HIGH);
   digitalWrite(RED10, LOW);
   blue3 = 1;
  }
  else
  {
   digitalWrite(BLUE3, LOW);
   digitalWrite(RED10, HIGH);
   blue3 = 0;
  }

  x = blue1 + blue2 + blue3 + blue4 + green5 + green6 + green7 + green8 + green9 + green10; //total de vagas disponíveis
  c = blue1 + blue2; //vagas p/ cadeirante disponíveis
  v = blue3 + blue4; //vagas p/ idosos disponíveis
  n = green5 + green6 + green7 + green8 + green9 + green10; //vagas não preferenciais disponíveis
  if (x == 0)
  {
  lcd.setCursor(0,0);
  lcd.print("                 ");
  lcd.setCursor(0,1);
  lcd.print("   ESTACIONAMENTO   ");
  lcd.setCursor(0,2);
  lcd.print("       LOTADO       ");
  lcd.setCursor(0,3);
  lcd.print("                    ");
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.print("Vagas disponiveis");
    lcd.setCursor(0,1);
    lcd.print("cadeirantes: ");
    lcd.print(c);
    lcd.setCursor(14,1);
    lcd.print("    ");
    lcd.setCursor(0,2);
    lcd.print("idosos: ");
    lcd.print(v);
    lcd.setCursor(9,2);
    lcd.print("    ");
    lcd.setCursor(0,3);
    lcd.print("nao preferenciais: ");
    lcd.print(n);
  }

  if((analogRead(LDRent) + 10 < analogRead(LDRP)) && (x != 0))
  {
  servoent.write(0);
  }
  else
  {
  servoent.write(100);
  delay(1000);
  }
  if(analogRead(LDRsai) + 10 > analogRead(LDRP))
  {
  servosai.write(180);
  }
  else
  {
  servosai.write(90);
  delay(1000);
  }
   if (! rfid.PICC_IsNewCardPresent())
  {
    return;
  }
  if (! rfid.PICC_ReadCardSerial())
  {
    return;
  }
 
   conteudo = "";
   

  for (byte i = 0; i < rfid.uid.size; i++)
  {
    rfid.uid.uidByte[i] < 0x10 ? " 0" : " ";
    rfid.uid.uidByte[i], HEX;
    conteudo.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
    conteudo.concat(String(rfid.uid.uidByte[i], HEX));
  }

  if(conteudo.substring(1) == "29 51 04 98")
  {
    Serial.println("Veículo não autorizado estacionado na vaga A1");
  }
  else
  {
    Serial.println("OK");
  }
}
