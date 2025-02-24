#include <stdio.h>
#include "pico/stdlib.h"
//#include "hardware/i2c.h"

#define LED_RED 13
#define LED_BLUE 12
#define LED_GREEN 11
#define BUTTON_A 5
#define BUTTON_B 6
#define BUZZER 10

int main()
{
    stdio_init_all();

    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);

    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE,GPIO_OUT);

    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
  
    gpio_init(BUTTON_A);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_pull_up(BUTTON_A);

    gpio_init(BUTTON_B);
    gpio_set_dir(BUTTON_B, GPIO_IN);
    gpio_pull_up(BUTTON_B);

    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);

    void buzzer(){

        gpio_put(BUZZER, true);
        sleep_ms(1000); 
        gpio_put(BUZZER, false);
    };


    while (true) {

    
    buzzer();
    gpio_put(LED_RED, true);
    sleep_ms(10000);
    gpio_put(LED_RED,false);
    
    buzzer();
    gpio_put(LED_GREEN, true);
    sleep_ms(10000);
    gpio_put(LED_GREEN,false);

    buzzer();
    gpio_put(LED_BLUE, true);
    sleep_ms(10000);
    gpio_put(LED_BLUE,false);
 
      sleep_ms(200);   
    }

    return 0;
}
