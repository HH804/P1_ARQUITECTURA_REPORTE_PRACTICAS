void main (){ 			//función principal
		PORTC=0;
//Se le asigna un LOW al puerto C conformado por los pines 15, 16, 17, 18, 23, 24, 25 y 26 del PIC.
		TRISC=0;
//Se configura todo el puerto C como salida equivale a 0b00000000 (binario), 0x00(hexadecimal).
		while(1){
			PORTC=~PORTC; //aplica un NOT al puerto invirtiendo los valores.
Delay_ms(1000); //Espera un segundo
		}
	}
