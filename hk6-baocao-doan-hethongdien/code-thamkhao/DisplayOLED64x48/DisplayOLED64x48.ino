/* 
 * Chuong trinh hien thi text len OLED 64x48 - I2C adress = 0x3C
 * Thu vien can cai dat:
 * 1. https://github.com/mcauser/Adafruit_SSD1306/tree/esp8266-64x48
 * 2. https://github.com/adafruit/Adafruit-GFX-Library
 */

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 0

#define SSD1306_LCDHEIGHT 48
#if (SSD1306_LCDHEIGHT != 48)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

Adafruit_SSD1306 display(OLED_RESET);

void setup(){
  // Khoi tao voi dia chi I2C 0x3C (loai OLED 64x48) 
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay(); // Xoa bo nho
}


void loop(){
  //Cho hien thi chu va so len OLED
  for (int i = 0; i<20; i++){
    display.setTextSize(1);         // Kich thuoc cua text duoc hien thi
    display.setTextColor(WHITE);    // Mau sach cua text   
    display.setCursor(0,0);         // Vi tri cua con tro: (x, y) = (column, row)
    display.print("n:");            // Dua chu hoac so muon hien thi vao trong bo nho cua OLED
    display.println(i);    
    display.display();              // Hien thi chu hoac so dua dua vao bo nho cua OLED
    delay(2000);
    display.clearDisplay();         // Xoa bo nho cu
  }
}
