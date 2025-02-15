#include "ev_control.h"

// Gaz pedalının verilerini al, işle ve motor sürücüye gönder
void process_pedal_input() {
    PedalData_t pedal;
    read_pedal_data(&pedal);

    if (!validate_pedal_data(&pedal)) {
        printf("Geçersiz pedal verisi, motor komutu gönderilmeyecek!");
        return;
    }

    // Gaz pedalının pozisyonunu hesapla
    uint8_t throttle = calculate_throttle(&pedal);

    // Log kaydı al
    printf("%d\n", pedal.pedal_position);

    // Motor hızını ayarla
    send_to_motor(throttle);
}