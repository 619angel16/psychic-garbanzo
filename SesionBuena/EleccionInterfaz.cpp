
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include "linkLayer.h"
#include "stdio_ext.h"
#include "EleccionInterfaz.h"
#include "ImpresionMensajesSistema.h"

using namespace std;
bool validarNumero(int Vector [],int numero){
       bool valido=false;
        for(int i=0;i<8;i++){
            if(Vector[i]==numero)
                valido= true;
        }
return valido;
}

void elegirInterfaz(pcap_if_t *avail_ifaces,int interfaces[8], interface_t &iface ){
bool auxiliar=false;
int numeroInterfaz;
int iposInterfaz=0;

while(!auxiliar){
     printf( "\n Selecione su Interfaz: ");
     //Introducimos el valor numerico correspondiente a la interfaz
     cin>> numeroInterfaz;
        // Comprobamos que la introduccion ha sido correcta
        if(!cin.fail()){
            //Comprobamos que el valor introducido es valido
            if(validarNumero(interfaces,numeroInterfaz)){
                bool find =false;
                iposInterfaz=0;
                avail_ifaces=GetAvailAdapters();
                //Recorremos la lista de interfaces hasta posicionarnos en la interfaz que deseamos
                for(int i=0;i<numeroInterfaz;i++){
                    avail_ifaces=avail_ifaces->next;
                }
                //Impresion de la Informacion de la interfaz selecionada
                printf("\n Interfaz Escogida :");
                printf("%s" ,avail_ifaces->name);
                printf("\n" );
                setDeviceName(&iface,avail_ifaces->name);
                GetMACAdapter(&iface);

                

               


               
                auxiliar=true;
                
            }
            //Prevencion de errores de Interfaces disponibles
            else {
             printf("\n Interfaz no disponible :");
            }

        }
        //Prevencion de errores Introduccion por teclado
        else {
        printf("\n Interfaz no disponible :");
        printf("\n");
        cin.clear();
        cin.ignore();
        }
 }
    
}