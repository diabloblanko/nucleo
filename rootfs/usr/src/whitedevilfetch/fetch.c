#include <stdio.h>
#include "fetch.h"
// Ported from WhiteDevilOS
// Modified by DiabloBlanko
/* WhiteDevilOS License say i should do that
Copyright (c) 2025, diabloblanko 
*/
/*
void whitedevilos() {
    printf(
        "██     ██ ██████   OS       :: WhiteDevilOS" //OSNAME  
        "██     ██ ██   ██  Hostname :: " HOSTNAME "\n"
        "██  █  ██ ██   ██  Kernel   :: "  "\n"
        "██ ███ ██ ██   ██ \n" 
        "███   ███ ██████  \n"); }
// ??????? GIB MENTIONED???!
// https://gibdev.netlify.app/ MENTIONED
void gibos() {
    printf(
        " ██████ OS       :: GibOS\n" 
        "██      Hostname :: " HOSTNAME "\n"
        "██   ███ \n"
        "██    ██ \n" 
        "███████  \n"); 
}  
   */
// Ya skoro vernus, AFK
// COMPILED!
void main() {
    printf( 
    " ▐ ▄  \033[94mOS           \033[0m:: Nucleo\n"
    "•█▌▐█ \033[94mHostname     \033[0m:: " HOSTNAME "\n"
    "▐█▐▐▌ \033[94mKernel       \033[0m:: Nucleo" get_nucversion "\n"
    "██▐█▌\n"
    "▀▀ █▪\n"
    );
}
