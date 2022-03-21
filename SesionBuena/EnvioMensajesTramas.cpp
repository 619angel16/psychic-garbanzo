#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include "linkLayer.h"
#include "stdio_ext.h"
#include "EnvioMensajesTramas.h"

void EnviarCaracter(interface_t iface, unsigned char data, unsigned char MACsrc[], unsigned char MACdest[], unsigned char tipo[]) {

    unsigned char *car = (unsigned char *) malloc(1 * sizeof(char));
    unsigned char *trama;
    car[0] = data;

    trama = BuildFrame(MACsrc, MACdest, tipo, car);

    SendFrame(&iface, trama, 1);

    free(trama);
    free(car);

}

char recibirCaracter(interface_t iface) {
    char dato;
    apacket_t trama = ReceiveFrame(&iface);
    const unsigned char *paquete = trama.packet;

    if (paquete != NULL) {

        dato = paquete[14];

        return dato;
    }
    return 0;
}




