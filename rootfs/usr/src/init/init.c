// rootfs/usr/src/neoinit/init.c
// This file is part of Nucleo Pseudo-operating-system(POS)
// Made by Diabloblanko and Maldidev
#include <stdlib.h>
#include <stdio.h>
#include "motd.h" 
#define VERSION 1
void startup() {
    printf("Starting Nucleo 1 \n");
    printf( MOTD )
}
//
int startupain(int argc, char** argv) {
    printf("Hello, World!");
}
