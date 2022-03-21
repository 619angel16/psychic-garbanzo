#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include "linkLayer.h"
#include "stdio_ext.h"


using namespace std;

bool validarNumero(int Vector [],int numero);

void elegirInterfaz(pcap_if_t *avail_ifaces,int interfaces[8], interface_t &iface );