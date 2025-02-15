#include "ev_control.h"


void delay(int ms)
{
    for (int i = 0; i < ms; i++);
}

int main() {

    while (1) {
        process_pedal_input();
        delay(100);
    }

    return 0;
}