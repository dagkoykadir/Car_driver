#include "ev_control.h"

// Pedal verisini okuma işlemi
void read_pedal_data(PedalData_t* pedal) {
    pedal->sensor1_voltage = read_adc_sensor(1);
    pedal->sensor2_voltage = read_adc_sensor(2);
}