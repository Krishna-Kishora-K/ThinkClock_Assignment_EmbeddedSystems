#include <stdio.h>
#include "pico/stdlib.h"

#define LED_PIN     15   
#define BUTTON_PIN  14   

bool check_button_edge(bool *last_state) {
    bool s = gpio_get(BUTTON_PIN); 
    if (s != *last_state) {
        sleep_ms(20);              
        s = gpio_get(BUTTON_PIN);
    }
    bool pressed_edge = (s == 0 && *last_state == 1); 
    *last_state = s;
    return pressed_edge;
}

int main() {
    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN); 

    bool reversed = false;
    bool last_button_state = gpio_get(BUTTON_PIN);

    while (true) {
        int seq[3] = {10, 20, 30};
        if (reversed) {
            int tmp = seq[0]; seq[0] = seq[2]; seq[2] = tmp;
        }

        for (int phase = 0; phase < 3; ++phase) {
            int blinks = seq[phase];
            int period_ms = 60000 / blinks; 

            for (int b = 0; b < blinks; b++) {
                if (check_button_edge(&last_button_state)) {
                    reversed = !reversed;
                    goto restart; 
                }

                gpio_put(LED_PIN, 1);
                sleep_ms(period_ms / 2);

                if (check_button_edge(&last_button_state)) {
                    reversed = !reversed;
                    goto restart;
                }

                gpio_put(LED_PIN, 0);
                sleep_ms(period_ms / 2);
            }
        }
    restart:
        continue; 
    }
}
