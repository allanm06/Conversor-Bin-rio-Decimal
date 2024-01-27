#include <LiquidCrystal.h>

//Endereçamento do LCD
#define RS 13
#define EN 12
#define D4 11
#define D5 10
#define D6 9
#define D7 8

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

int valor=0,c1=0,c2=0,c4=0,c8=0,c16=0,c32=0,c64=0,c128=0;

void setup() {
  //Todos os pinos do PORTD como entrada
  DDRD=0;

  //Iniciando o LCD
  lcd.begin(16,1);
}

void loop(){
   //Configuração das teclas
  if((digitalRead(0)==1)and(c1==0)){valor++;c1=1;}
  if((digitalRead(0)==0)and(c1==1)){valor--;c1=0;}

  if((digitalRead(1)==1)and(c2==0)){valor=valor+2;c2=1;}
  if((digitalRead(1)==0)and(c2==1)){valor=valor-2;c2=0;}

  if((digitalRead(2)==1)and(c4==0)){valor=valor+4;c4=1;}
  if((digitalRead(2)==0)and(c4==1)){valor=valor-4;c4=0;}

  if((digitalRead(3)==1)and(c8==0)){valor=valor+8;c8=1;}
  if((digitalRead(3)==0)and(c8==1)){valor=valor-8;c8=0;}

  if((digitalRead(4)==1)and(c16==0)){valor=valor+16;c16=1;}
  if((digitalRead(4)==0)and(c16==1)){lcd.clear();valor=valor-16;c16=0;}

  if((digitalRead(5)==1)and(c32==0)){valor=valor+32;c32=1;}
  if((digitalRead(5)==0)and(c32==1)){lcd.clear();valor=valor-32;c32=0;}

  if((digitalRead(6)==1)and(c64==0)){valor=valor+64;c64=1;}
  if((digitalRead(6)==0)and(c64==1)){lcd.clear();valor=valor-64;c64=0;}

  if((digitalRead(7)==1)and(c128==0)){valor=valor+128;c128=1;}
  if((digitalRead(7)==0)and(c128==1)){lcd.clear();valor=valor-128;c128=0;}
  
lcd.setCursor(0,0);
lcd.print("Decimal:");
lcd.setCursor(10,1);
lcd.print(valor);
}
