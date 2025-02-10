#include "pico/stdlib.h"
#include "hardware/pwm.h"

// Definições dos pinos
#define SERVO_PIN 22
#define LED_PIN   12

// Configurações para PWM
#define PWM_FREQ 50          // 50 Hz (período de 20ms)
#define PWM_WRAP 19999       // Contagem de 0 a 19999 = 20000 ticks (20ms)

// Posições do servo (em µs)
#define SERVO_POS_0   500    // Aproximadamente 0°
#define SERVO_POS_90  1470   // Aproximadamente 90°
#define SERVO_POS_180 2400   // Aproximadamente 180°

// Configurações para a movimentação suave
#define SERVO_STEP    5      // Incremento de 5µs
#define STEP_DELAY_MS 10     // Atraso de 10ms entre os incrementos

// Função para definir o pulso (duty cycle) do servo
void set_servo_pwm(uint pulse_width_us) {
    pwm_set_gpio_level(SERVO_PIN, pulse_width_us);
}

// Função para definir o brilho do LED (0 a PWM_WRAP)
void set_led_pwm(uint brightness) {
    pwm_set_gpio_level(LED_PIN, brightness);
}

int main() {
    stdio_init_all();
    
    // Configura os pinos para função PWM
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    gpio_set_function(LED_PIN, GPIO_FUNC_PWM);
     
    // Obtenha os números dos slices PWM dos pinos
    uint servo_slice = pwm_gpio_to_slice_num(SERVO_PIN);
    uint led_slice   = pwm_gpio_to_slice_num(LED_PIN);
    
    // Configure o divisor para que cada tick seja de 1µs
    pwm_set_clkdiv(servo_slice, 125.0f);
    pwm_set_clkdiv(led_slice, 125.0f);
    
    // Configure o wrap para obter um período de 20ms
    pwm_set_wrap(servo_slice, PWM_WRAP);
    pwm_set_wrap(led_slice, PWM_WRAP);
    
    // Habilite os slices PWM
    pwm_set_enabled(servo_slice, true);
    pwm_set_enabled(led_slice, true);

    // **Setup inicial**: Define posições fixas antes da movimentação infinita
    set_servo_pwm(SERVO_POS_180);
    set_led_pwm(PWM_WRAP);
    sleep_ms(5000);

    set_servo_pwm(SERVO_POS_90);
    set_led_pwm(PWM_WRAP / 2);
    sleep_ms(5000);

    set_servo_pwm(SERVO_POS_0);
    set_led_pwm(0);
    sleep_ms(5000);

    // **Movimentação contínua entre 0° e 180°**
    while(1) {
        // Suavemente move de 0° para 180°
        for (int pulse = SERVO_POS_0; pulse <= SERVO_POS_180; pulse += SERVO_STEP) {
            set_servo_pwm(pulse);
            uint brightness = (uint)(((float)(pulse - SERVO_POS_0) / (SERVO_POS_180 - SERVO_POS_0)) * PWM_WRAP);
            set_led_pwm(brightness);
            sleep_ms(STEP_DELAY_MS);
        }

        // Suavemente move de 180° para 0°
        for (int pulse = SERVO_POS_180; pulse >= SERVO_POS_0; pulse -= SERVO_STEP) {
            set_servo_pwm(pulse);
            uint brightness = (uint)(((float)(pulse - SERVO_POS_0) / (SERVO_POS_180 - SERVO_POS_0)) * PWM_WRAP);
            set_led_pwm(brightness);
            sleep_ms(STEP_DELAY_MS);
        }
    }

    return 0;
}
