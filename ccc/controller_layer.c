#include "ev_control.h"

// Gaz pedalı konumunu belirleme
uint8_t calculate_throttle(PedalData_t* pedal) {
    if (pedal == NULL) return 0;

    // İki sensörün ortalama voltajını hesapla
    float average_voltage = (pedal->sensor1_voltage + pedal->sensor2_voltage) / 2;

    // Voltajı pedal konumuna çevir (0-100 aralığında)
    uint8_t throttle = (uint8_t)((average_voltage - MIN_VOLTAGE) / (MAX_VOLTAGE - MIN_VOLTAGE) * 100);

    // Güvenlik için sınırları belirle
    if (throttle > 100) throttle = 100;
    if (throttle < 0) throttle = 0;

    // Pedal pozisyonunu struct içinde güncelle
    pedal->pedal_position = throttle;

    return throttle;
}