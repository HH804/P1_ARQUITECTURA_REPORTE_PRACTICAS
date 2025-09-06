// Retardo variable en microsegundos usando bloques constantes
void delay_us_var(unsigned int us) {
    while (us >= 50) { Delay_us(50); us -= 50; }   // bloques grandes para eficiencia
    while (us >= 10) { Delay_us(10); us -= 10; }
    while (us > 0)   { Delay_us(1);  us--; }
}

void main() {
    unsigned short angulo;
    unsigned int pulso, bajo;
    unsigned short i;

    TRISB = 0b00000000; // PORTB como salida
    PORTB = 0;

    while(1) {
        // Subir 0° -> 180° en pasos de 10°
        for(angulo = 0; angulo <= 180; angulo += 10) {
            pulso = 500 + (angulo * 11);   // 0°=500us, 180°~2500us
            bajo  = 20000 - pulso;         // completa el período de 20 ms (50 Hz)

            for(i = 0; i < 50; i++) {      // ~1 s manteniendo la posición
                PORTB.F0 = 1;
                delay_us_var(pulso);
                PORTB.F0 = 0;
                delay_us_var(bajo);
            }

            Delay_ms(2000);                // 2 s entre posiciones
        }

        // Bajar 180° -> 0° en pasos de 20°
        for(angulo = 180; angulo >= 20; angulo -= 20) {
            pulso = 500 + (angulo * 11);
            bajo  = 20000 - pulso;

            for(i = 0; i < 50; i++) {
                PORTB.F0 = 1;
                delay_us_var(pulso);
                PORTB.F0 = 0;
                delay_us_var(bajo);
            }

            Delay_ms(2000);
        }

        // Asegura 0°
        pulso = 500;
        bajo  = 20000 - pulso;
        for(i = 0; i < 50; i++) {
            PORTB.F0 = 1;
            delay_us_var(pulso);
            PORTB.F0 = 0;
            delay_us_var(bajo);
        }
        Delay_ms(2000);
    }
}
