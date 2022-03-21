cmake_minimum_required(VERSION 3.21)
project(PracticaRedesAngelVictor)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(
        Sesion0
        EleccionInterfaz.cpp
        EleccionInterfaz.h
        EnvioMensajesTramas.cpp
        EnvioMensajesTramas.h
        ImpresionMensajesSistema.cpp
        ImpresionMensajesSistema.h
        kbhit.h
        linkLayer.h
        lista.h
        Sesion0.cpp EnvioCarInteractivo.h EnvioCarInteractivo.cpp)
target_link_libraries(Sesion0 pcap)
target_link_libraries(Sesion0 ${CMAKE_SOURCE_DIR}/linkLayer.a)