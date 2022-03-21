
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include "linkLayer.h"
#include "stdio_ext.h"


using namespace std;

//Envia un caracter 
void EnviarCaracter(interface_t iface, unsigned char data,unsigned char MACsrc[],
unsigned char MACdest[],unsigned char tipo[]);

//Recibe los caracteres enviados
char recibirCaracter(interface_t iface);



