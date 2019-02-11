
#include <FastLED.h>

#define LED_PIN_L     3
#define LED_PIN_R     6
#define LED_PIN_M     9
#define LED_PIN_LM    13

#define NUM_LEDS_L    39  
#define NUM_LEDS_R    50
#define NUM_LEDS_M    100
#define NUM_LEDS_LM   30

#define SNAKE_LENGTH  3

CRGB leds_L[NUM_LEDS_L];
CRGB leds_R[NUM_LEDS_R];
CRGB leds_M[NUM_LEDS_R];
CRGB leds_LM[NUM_LEDS_LM];


void setup() {
  // put your setup code here, to run once:
   FastLED.addLeds<WS2812, LED_PIN_L, GRB>(leds_L, NUM_LEDS_L);
   FastLED.addLeds<WS2812, LED_PIN_R, GRB>(leds_R, NUM_LEDS_R);
   FastLED.addLeds<WS2812, LED_PIN_M, GRB>(leds_M, NUM_LEDS_M);
   FastLED.addLeds<WS2812, LED_PIN_LM, GRB>(leds_LM, NUM_LEDS_LM);
}
void loop() {
  colorShift(1);
}

int colShift = 0;
bool add;
void colorShift(int spd)
{
  if(colShift <= 0)
  {
    add = true; 
  }else if(colShift >= 255)
  {
    add = false;
  }
  if(add)
  {
   colShift += spd; 
  }else
  {
    colShift -= spd;
  }
    CRGB newCol = CRGB(0, 0, colShift);
    setAll(newCol);
    delay(spd * 50);
}
void setAllSide(int strip, CRGB col)
{
  if(strip == 0)
  {
    for(int i = 0; i < NUM_LEDS_L; i++)
    {
      leds_L[i] = col;
    }
  }
  if(strip == 1)
  {
    for(int i = 0; i < NUM_LEDS_R; i++)
    {
      leds_R[i] = col;
    }
  }
  FastLED.show();
}
void setAll(CRGB col)
{
  for(int i = 0; i < NUM_LEDS_L; i++)
  {
    leds_L[i] = col;
  }
  for(int j = 0; j < NUM_LEDS_R; j++)
  {
    leds_R[j] = col;
  }
  for(int k = 0; k < NUM_LEDS_M; k++)
  {
    leds_M[k] = col;
  }
  for(int l = 0; l < NUM_LEDS_LM; l++)
  {
    leds_LM[l] = col;
  }
  FastLED.show();
}
void setEveryGap(int gap, CRGB col_F, CRGB col_S)
{
  for(int i = 0; i < NUM_LEDS_L; i++)
  {
    if(i % gap == 0)
    {
      leds_L[i] = col_F;
    }else
    {
      leds_L[i] = col_S;
    }
  }
  for(int i = 0; i < NUM_LEDS_R; i++)
  {
    if(i % gap == 0)
    {
      leds_R[i] = col_F;
    }else
    {
      leds_R[i] = col_S;
    }
  }
    for(int i = 0; i < NUM_LEDS_M; i++)
  {
    if(i % gap == 0)
    {
      leds_M[i] = col_F;
    }else
    {
      leds_M[i] = col_S;
    }
  }

  FastLED.show();
}

void snake(CRGB strip[], CRGB col_P, CRGB col_S)
{
  setAllSide(strip, col_P);
  FastLED.show();
  for(int i = 0; i < sizeof(strip); i++)
  {
      if(i - 1 != -1)
      {
        strip[i - 1] = col_S;
      }if(!(i + 1 > sizeof(strip)))
      {
        strip[i + 1] = col_S; 
      }
      strip[i] = col_S;
      FastLED.show();
      delay(2500);
  }
}
