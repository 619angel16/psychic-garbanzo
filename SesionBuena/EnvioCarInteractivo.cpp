#include "EnvioCarInteractivo.h"

void EnvioInteractivo(interface iface, char caracter, unsigned char MACsrc[], unsigned char MACdest[],
                      unsigned char type[]) {
    int puerto = OpenAdapter(&iface);

    if (puerto == 0) {
        printf("Puerto Abierto Correctamente");
        saltoLinea();
        printf("Pulse las Teclas a enviar: ");
        unsigned char TPulsada = 0;
        __fpurge(stdin);

        while (TPulsada != 27) {
            caracter = recibirCaracter(iface);
            if (caracter != 0) {
                printf("Caracter Recibido: ");
                printf("%c", caracter);
                saltoLinea();
            }

            if (kbhit()) {
                saltoLinea();
                TPulsada = getch();
                if (TPulsada != 27) {
                    EnviarCaracter(iface, TPulsada, MACsrc, MACdest, type);
                }
            }
        }
    } else {
        printf("Puerto No Abierto");
        saltoLinea();
    }

    CloseAdapter(&iface);
    printf("Adapatador Cerrado");
    saltoLinea();
}