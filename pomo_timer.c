#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "lib\ssd1306.h"
#include "lib\font.h"

#define LED_RED 13
#define LED_BLUE 12
#define LED_GREEN 11
#define BUTTON_A 5
#define BUZZER 10
#define I2C i2c1
#define SDA 14
#define SCL 15

bool DEBOUNCING(){

      if(!gpio_get(BUTTON_A)){

            sleep_ms(50);
            
            if(!gpio_get(BUTTON_A)){
                  return true;
            } 
      } return false;
};

int main()
{
    stdio_init_all();

    i2c_init(I2C, 400 * 1000);
    gpio_set_function(SDA, GPIO_FUNC_I2C);
    gpio_set_function(SCL, GPIO_FUNC_I2C);
    gpio_pull_up(SDA);
    gpio_pull_up(SCL);

    ssd1306_t ssd;
    ssd1306_init(&ssd, WIDTH, HEIGHT, false, 0x3C, I2C);
    ssd1306_config(&ssd);
    ssd1306_send_data(&ssd);
    ssd1306_fill(&ssd, false);
    ssd1306_send_data(&ssd);

void focus(){

      ssd1306_fill(&ssd, false);
      ssd1306_draw_string(&ssd, "TIME TO FOCUS", 20, 30);
      ssd1306_send_data(&ssd);
      gpio_put(LED_BLUE, true);
      sleep_ms(25000);
      gpio_put(LED_BLUE,false);
      gpio_put(BUZZER, true);
      sleep_ms(1000); 
      gpio_put(BUZZER, false);
      ssd1306_fill(&ssd, false);
};
void short_break(){

      ssd1306_fill(&ssd, false);
      ssd1306_draw_string(&ssd, "5 MIN. BREAK", 20, 30);
      ssd1306_draw_string(&ssd, "     II", 15, 48);
      ssd1306_send_data(&ssd);
      gpio_put(LED_GREEN, true);
      sleep_ms(5000);
      gpio_put(LED_GREEN,false);
      gpio_put(BUZZER, true);
      sleep_ms(1000); 
      gpio_put(BUZZER, false); 
      ssd1306_fill(&ssd, false);
};
void long_break(){

      ssd1306_fill(&ssd, false);
      ssd1306_draw_string(&ssd, "10 MIN BREAK", 20, 30);
      ssd1306_draw_string(&ssd, "     II", 15, 48);
      ssd1306_send_data(&ssd);
      gpio_put(LED_RED, true);
      sleep_ms(10000);
      gpio_put(LED_RED,false);
      gpio_put(BUZZER, true);
      sleep_ms(1000); 
      gpio_put(BUZZER, false);
      ssd1306_fill(&ssd, false);
};

    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);

    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE,GPIO_OUT);

    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
  
    gpio_init(BUTTON_A);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_pull_up(BUTTON_A);

    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);

    while (true) {
      
      ssd1306_fill(&ssd, false);
      ssd1306_draw_string(&ssd, "  PRESS A TO ", 8, 10);
      ssd1306_draw_string(&ssd, "   START", 20, 30);
      ssd1306_send_data(&ssd);

      if(DEBOUNCING()){

        focus();
        short_break();
        focus();
        short_break();
        focus();
        long_break();
      
      }
      
      sleep_ms(200);   
    }

    return 0;
}
