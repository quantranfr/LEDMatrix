#include <PxMatrix.h>
#include <Ticker.h>

// Pins for LED MATRIX
#define P_LAT 16
#define P_A 5
#define P_B 4
#define P_C 15
#define P_D 12
#define P_E 0
#define P_OE 2

#define matrix_width 64
#define matrix_height 32

Ticker display_ticker;
PxMATRIX display(64, 32, P_LAT, P_OE, P_A, P_B, P_C, P_D);

// This defines the 'on' time of the display is us. The larger this number,
// the brighter the display. If too large the ESP will crash
uint8_t display_draw_time=30; //30-70 is usually fine

// ISR for display refresh
void display_updater()
{
  display.display(display_draw_time);
}

void display_update_enable(bool is_enable)
{
  if (is_enable)
    display_ticker.attach(0.004, display_updater);
  else
    display_ticker.detach();
}                          

void setup() {
  Serial.begin(9600);
  // Define your display layout here, e.g. 1/8 step, and optional SPI pins begin(row_pattern, CLK, MOSI, MISO, SS)
  display.begin(16);
  //display.begin(8, 14, 13, 12, 4);

  // Set the time in microseconds that we pause after selecting each mux channel
  // (May help if some rows are missing / the mux chip is too slow)
  // MY CASE: WITHOUT THIS THERE WILL BE SOME MISSING LINES
  display.setMuxDelay(1,1,1,1,1);

  // Set the brightness of the panels (default is 255)
  display.setBrightness(50);

  display.clearDisplay();
  display_update_enable(true);

  delay(3000);
}

void scroll_text(uint8_t ypos, unsigned long scroll_delay, String text, uint8_t colorR, uint8_t colorG, uint8_t colorB)
{
    uint16_t text_length = text.length();
    display.setTextWrap(false);  // we don't wrap text so it scrolls nicely
    display.setTextSize(1);
    display.setRotation(0);
    display.setTextColor(display.color565(colorR,colorG,colorB));

    // Asuming 5 pixel average character width
    for (int xpos=matrix_width; xpos>-(matrix_width+text_length*5); xpos--)
    {
      display.setTextColor(display.color565(colorR,colorG,colorB));
      display.clearDisplay();
      display.setCursor(xpos,ypos);
      display.println(text);
      delay(scroll_delay);
      yield();

      // This might smooth the transition a bit if we go slow
      // display.setTextColor(display.color565(colorR/4,colorG/4,colorB/4));
      // display.setCursor(xpos-1,ypos);
      // display.println(text);

      delay(scroll_delay/5);
      yield();

    }
}

void loop() {
  String text;
  text = "Only English text can be correctly shown.";
  scroll_text(20,60,text,96,96,250);
  display.clearDisplay();

  delay(1000);
}
