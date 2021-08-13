#include <avr/io.h>

char received[];
char letterIndex = 0;
void SPI_write();
void SPI_setup();


int main(void){
    //other set se inputs by default
    DDRB |= 1 << PB1;   //MISO
    SPI_setup();
    while(1){
        SPI_read;
    }
}

void SPI_read(){
    if(USIOIF){
        received[letterIndex] = USIBR;  //store the received data
        letterIndex++;
        USISR |= 1<<USIOIF; //clean the overflow flag
    }
}

void SPI_setup(){
    USICR |= 1 << USIWM0;   //Three-wire mode (SPI)
    USICR |= 1 << USICS0;   //External clock source, positive edge
}