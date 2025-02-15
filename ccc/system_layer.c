#include "ev_control.h"
#include <stdio.h>

// Simüle edilmiş ADC okuma fonksiyonu
float read_adc_sensor(int sensor_id) {
    // Gerçek sistemde ADC donanımından veri okunur
    if (sensor_id == 1) return 3.9; // Örnek voltaj
    if (sensor_id == 2) return 4.0; // Örnek voltaj
    return 0.0;
}

// Motor sürücüye hız komutu gönderen fonksiyon
void send_to_motor(uint8_t throttle) {
    printf("[MOTOR] Gaz Pedalı Seviyesi: %d%%\n", throttle);
}

