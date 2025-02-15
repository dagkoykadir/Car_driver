#include "ev_control.h"

// Pedal verisinin geçerli olup olmadığını kontrol et
bool validate_pedal_data(PedalData_t* pedal) {
    if (pedal == NULL) return false;

    // Sensör farkı belirli bir aralığı aşarsa hata verir
    float difference = pedal->sensor1_voltage - pedal->sensor2_voltage;
    if (difference < -0.2 || difference > 0.2) {
        printf("Sensörlerde uyumsuzluk tespit edildi!");
        return false;
    }

    return true;
}