cmake_minimum_required(VERSION 3.23)
project(Proyecto_clion)

set(CMAKE_CXX_STANDARD 17)

add_executable(Proyecto_clion PR/CBanco.h PR/CDebito.h PR/CMenu.h PR/CMenu.cpp PR/CMovimientos.h PR/CPersonas.h PR/CPrestamos.h PR/CTarjetas.h PR/Funciones.h PR/main.cpp PR/libgame.cpp PR/libgame.h
        )
