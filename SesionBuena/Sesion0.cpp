//============================================================================
// ----------- PRACTICAS DE FUNDAMENTOS DE REDES DE COMUNICACIONES -----------
// ---------------------------- CURSO 2021/22 --------------------------------
// ----------------------------- SESION1.CPP ---------------------------------
//------------------------Angel Luis Peña Orrego------------------------------
//---------------------Victor Nicolai Tellez Barroso--------------------------
//============================================================================


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include "linkLayer.h"
#include "stdio_ext.h"
#include "EleccionInterfaz.h"
#include "EnvioMensajesTramas.h"
#include "ImpresionMensajesSistema.h"
#include "EnvioCarInteractivo.h"

using namespace std;

int main() {

    int numeroInterfaz;
    int iposInterfaz = 0;
    int interfaces[8];

    interface_t iface;
    pcap_if_t *avail_ifaces = NULL;

    char caracter;
    unsigned char EModo;
    unsigned char MACsrc[6] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    unsigned char MACdest[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    unsigned char typeM[2] = {0x49, 0x01};
    unsigned char typeS[2] = {0x49, 0x02};


    printf("\n----------------------------\n");
    printf("------ SESION 2 - FRC ------\n");
    printf("----------------------------\n");

    MostrarInterfaces(avail_ifaces, iposInterfaz, interfaces);
    elegirInterfaz(avail_ifaces, interfaces, iface);
    int puerto = OpenAdapter(&iface);
    if (puerto == 0) {
        cout << "Abierto bien" << endl;


        //Impresion de la MAC Interfaz Obtenida
        printMAC(iface);
        cout << endl;
        cin >> EModo;
//        __fpurge(stdin);
        bool auxiliar;
        apacket_t respuesta;
        unsigned char *peticion;

        //Modo Maestro
        if (EModo == 49) {

            peticion = BuildHeader(iface.MACaddr, MACdest, typeM);
            SendFrame(&iface, peticion, 0);
            cout << "He llegado al SendFrame" << endl;
            while (!auxiliar) {
                cout << "whileee" << endl;
                respuesta = ReceiveFrame(&iface);
                if (respuesta.packet != nullptr) {
                    cout << "he pasado el if bien " << endl;
                    if (respuesta.packet[12] == typeS[0] && respuesta.packet[13] == typeS[1]) {
                        cout << "Este if tambien guay" << endl;
                        for (int i = 0; i < 6; i++) {
                            MACdest[i] = respuesta.packet[i + 6];
                            printf("MAC Destino / esclavo %x :", iface.MACaddr[i]);
                        }
                        auxiliar = true;
                        cout << "Esclavo encontrado a piramidear" << endl;
                        free(peticion);
                    }
                }
            }
        }
        //Modo Esclavo
        if (EModo == 50) {
            while (!auxiliar) {
                respuesta = ReceiveFrame(&iface);
                const unsigned char *paquete = respuesta.packet;
                cout << "Estoy en while mira mama" << endl;
                if (paquete != nullptr) {
                    cout << "Comprobando..." << endl;
                    if (respuesta.packet[12] == typeM[0] && respuesta.packet[13] == typeM[1]) {
                        cout << "MAC destino / maestro: ";
                        for (int i = 0; i < 6; i++) {
                            MACdest[i] = respuesta.packet[i + 6];
                            printf("MAC Destino / esclavo %x :", iface.MACaddr[i]);
                        }
                        auxiliar = true;
                    }
                    peticion = BuildHeader(iface.MACaddr, MACdest, typeS);
                    SendFrame(&iface, peticion, 0);
                    free(peticion);
                }
            }
        }
    } else {
        cout << "Error puerto";
        return 1;
    }
    CloseAdapter(&iface);
    //EnvioInteractivo(iface, caracter, MACsrc, MACdest, type);
    return 0;
}
