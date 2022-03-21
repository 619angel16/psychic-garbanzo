#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include "linkLayer.h"
#include "stdio_ext.h"

using namespace std;

void MostrarInterfaces(pcap_if_t *avail_ifaces,int iposInterfaz, int interfaces[8]){
    
    avail_ifaces=GetAvailAdapters(); 

    while(avail_ifaces!=nullptr){
     //Establecer el numero de la interfaz
     cout<<"["<<iposInterfaz<<"]";
     interfaces[iposInterfaz]=iposInterfaz;
     //Imprimimos todas las interfaces
     printf("%s",avail_ifaces->name);
     printf("\n");
     //Pasamos la sigueinte interfaz
     avail_ifaces=avail_ifaces->next;
     //Aumentamos el numero de la interfaz y la posicion del vector
     iposInterfaz++;    
 }

}

void printMAC2(unsigned char mac[6]){
    printf("\n La MAC origen es :");
                for(int i=0;i<5;i++){
                    printf("%x :",mac[i]);
                }
                 printf("%x :",mac[5]);
}

void saltoLinea(){
    printf("\n");
}

void printMAC(interface_t iface){
    
    printf("\n La MAC origen es :");
                for(int i=0;i<5;i++){
                    printf("%x :",iface.MACaddr[i]);

                }
                 printf("%x :",iface.MACaddr[5]);

}

