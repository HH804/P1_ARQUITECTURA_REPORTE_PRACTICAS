void main() {
    TRISB = 0b00000001; // RB0 como entrada, los demás como salida

    while(1){
        if(PORTB.F0 == 1){
            // Secuencia modo normal

            // Paso 1: Semáforo 1 verde, Semáforo 2 rojo
            PORTB.F7 = 0; PORTB.F6 = 0; PORTB.F5 = 1;
            PORTB.F3 = 1; PORTB.F2 = 0; PORTB.F1 = 0;
            Delay_ms(5000); // Verde 5 segundos

            // Paso 2: Semáforo 1 amarillo, Semáforo 2 rojo
            PORTB.F7 = 0; PORTB.F6 = 1; PORTB.F5 = 0;
            PORTB.F3 = 1; PORTB.F2 = 0; PORTB.F1 = 0;
            Delay_ms(2000); // Amarillo 2 segundos

            // Paso 3: Semáforo 1 rojo, Semáforo 2 verde
            PORTB.F7 = 1; PORTB.F6 = 0; PORTB.F5 = 0;
            PORTB.F3 = 0; PORTB.F2 = 0; PORTB.F1 = 1;
            Delay_ms(5000); // Verde 5 segundos

            // Paso 4: Semáforo 1 rojo, Semáforo 2 amarillo
            PORTB.F7 = 1; PORTB.F6 = 0; PORTB.F5 = 0;
            PORTB.F3 = 0; PORTB.F2 = 1; PORTB.F1 = 0;
            Delay_ms(2000); // Amarillo 2 segundos
        }
        else{
            // Modo intermitente
            PORTB.F7 = 1; PORTB.F6 = 0; PORTB.F5 = 0;
            PORTB.F3 = 0; PORTB.F2 = 1; PORTB.F1 = 0;
            Delay_ms(500);

            PORTB.F7 = 0; PORTB.F6 = 0; PORTB.F5 = 0;
            PORTB.F3 = 0; PORTB.F2 = 0; PORTB.F1 = 0;
            Delay_ms(500);
        }
    }
}
