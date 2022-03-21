#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include "linkLayer.h"
#include "stdio_ext.h"


using namespace std;

//Imprime por pantalla las interfaces disponibles
void MostrarInterfaces(pcap_if_t *avail_ifaces,int iposInterfaz, int interfaces[8]);

//Imprime por pantalla la MAC de la Interfaz
void printMAC(interface_t iface);
//Igual que antes pero pasando solo la MAC
void printMAC2(unsigned char mac[6]);

void saltoLinea();