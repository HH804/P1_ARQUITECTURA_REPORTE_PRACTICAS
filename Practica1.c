void main()
{
    // Configurar puertos B, C, D y E como salida
    TRISB = 0; // Todo el puerto B como salida
    TRISC = 0;
    TRISD = 0;
    TRISE = 0;

    while(1)
    {
        // Encender todos los pines conectados a LEDs
        PORTB = 0b00000011; // Enciende RB0 y RB1
        PORTC = 0b00001100; // Enciende RC2 y RC3
        PORTD = 0b00110000; // Enciende RD4 y RD5
        PORTE = 0b00000011; // Enciende RE0 y RE1

        delay_ms(500); // Espera medio segundo

        // Apagar todos los pines conectados a LEDs
        PORTB = 0;
        PORTC = 0;
        PORTD = 0;
        PORTE = 0;

        delay_ms(500); // Espera medio segundo
    }
}