/* 
 * File:   main.c
 * Author: dtomazini
 *
 * Created on 4 de Novembro de 2014, 18:17
 */

#include <stdio.h>
#include <stdlib.h>
#include <p18f97j60.h>
#include "../XEEPROM.h"

#pragma config WDT=OFF, FOSC2=ON, FOSC=HSPLL, ETHLED=ON, XINST=OFF//HSPLL


/*
 * 
 */
void main(void) {

    unsigned int c;
    BYTE *p;
    BYTE teste[10]={'d','a','n','i','e','l'};
    BYTE lido[10]={0,0,0,0,0,0,0,0,0,0};

    LED_RUN_TRIS=0;

    LED_RUN_IO=1;
    
    XEEInit();

    XEEBeginWrite(0x0000);
    for ( c = 0; c < 32768; c++ )
    {
        XEEWrite(0x00);
    }
    XEEEndWrite();

    XEEBeginWrite(0x0000);
    for ( c = 0; c < sizeof(teste); c++ )
    {
        XEEWrite(teste[c]);
    }
    XEEEndWrite();

    Nop();

    XEEBeginRead(0x0000);
    for ( c = 0; c < sizeof(teste); c++ )
            lido[c] = XEERead();
    XEEEndRead();
    
    while(1)
    {
        LED_RUN_IO ^= 1;
    }
    
}

