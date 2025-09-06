void main() {
    // Configurar puertos como salida
    TRISB = 0x00;  // Puerto B como salida
    TRISC = 0x00;  // Puerto C como salida
    TRISD = 0x00;  // Puerto D como salida
    TRISE = 0x00;  // Puerto E como salida

    while(1) {
        // Secuencia 1: 1 0 1 0 1 0 1 0
        PORTB.F0 = 1;
        PORTB.F1 = 0;
        PORTC.F2 = 1;
        PORTC.F3 = 0;
        PORTD.F4 = 1;
        PORTD.F5 = 0;
        PORTE.F0 = 1;
        PORTE.F1 = 0;
        Delay_ms(1000);

        // Secuencia 2: 1 1 0 0 1 1 0 0
        PORTB.F0 = 1;
        PORTB.F1 = 1;
        PORTC.F2 = 0;
        PORTC.F3 = 0;
        PORTD.F4 = 1;
        PORTD.F5 = 1;
        PORTE.F0 = 0;
        PORTE.F1 = 0;
        Delay_ms(1000);

        // Secuencia 3: 0 1 1 1 0 1 1 1
        PORTB.F0 = 0;
        PORTB.F1 = 1;
        PORTC.F2 = 1;
        PORTC.F3 = 1;
        PORTD.F4 = 0;
        PORTD.F5 = 1;
        PORTE.F0 = 1;
        PORTE.F1 = 1;
        Delay_ms(1000);

        // Secuencia 4: 1 1 1 1 0 0 0 0
        PORTB.F0 = 1;
        PORTB.F1 = 1;
        PORTC.F2 = 1;
        PORTC.F3 = 1;
        PORTD.F4 = 0;
        PORTD.F5 = 0;
        PORTE.F0 = 0;
        PORTE.F1 = 0;
        Delay_ms(1000);

        // Secuencia 5: 0 1 0 1 0 1 0 1
        PORTB.F0 = 0;
        PORTB.F1 = 1;
        PORTC.F2 = 0;
        PORTC.F3 = 1;
        PORTD.F4 = 0;
        PORTD.F5 = 1;
        PORTE.F0 = 0;
        PORTE.F1 = 1;
        Delay_ms(1000);
    }
}
