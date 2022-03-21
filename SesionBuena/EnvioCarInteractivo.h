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
#ifndef PRACTICAREDESANGELVICTOR_ENVIOCARINTERACTIVO_H
#define PRACTICAREDESANGELVICTOR_ENVIOCARINTERACTIVO_H

using namespace std;

void EnvioInteractivo(interface iface, char caracter, unsigned char MACsrc[], unsigned char MACdest[], unsigned char type[]);

#endif //PRACTICAREDESANGELVICTOR_ENVIOCARINTERACTIVO_H
