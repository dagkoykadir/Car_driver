#ifndef EV_CONTROL_H
#define EV_CONTROL_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// Voltaj aralığı
#define MIN_VOLTAGE 0.5
#define MAX_VOLTAGE 4.5

// ADC Maksimum değeri (örnek: 12-bit ADC kullanımı için 4095)
#define ADC_MAX 4095
#define ADC_MIN 0

// Gaz pedalı veri yapısı
typedef struct {
    float sensor1_voltage;
    float sensor2_voltage;
    uint8_t pedal_position; // 0-100 arası gaz seviyesi
} PedalData_t;

// Fonksiyon prototipleri
void read_pedal_data(PedalData_t* pedal);
bool validate_pedal_data(PedalData_t* pedal);
uint8_t calculate_throttle(PedalData_t* pedal);
void send_to_motor(uint8_t throttle);
void process_pedal_input();
float read_adc_sensor(int sensor_id);

#endif // EV_CONTROL_H