// rootfs/usr/src/neoinit/init.c
// This file is part of Nucleo Pseudo-operating-system(POS)
// Made by Diabloblanko
/*
 _   _           ___       _ _   
| \ | | ___  ___|_ _|_ __ (_) |_ 
|  \| |/ _ \/ _ \| || '_ \| | __|
| |\  |  __/ (_) | || | | | | |_ 
|_| \_|\___|\___/___|_| |_|_|\__|
*/
//#include <stdlib.h>
//#include <bits/getopt_core.h>
//#include <cmath.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>
#define VERSION 1

int version() {
    printf(
    " _   _           ___       _ _         NeoInit V1\n"
    "| \\ | | ___  ___|_ _|_ __ (_) |_       Written by DiabloBlanko\n"
    "|  \\| |/ _ \\/ _ \\| || '_ \\| | __|      Build :: x86_64-nucleo-neoinit-v1-b1\n"
    "| |\\  |  __/ (_) | || | | | | |_ \n"
    "|_| \\_|\\___|\\___/___|_| |_|_|\\__|\n");
    return 0; }
void gethelp() {
    printf(
        "NeoInit Usage::\n"
        "-v                  :: Print version and exit\n"
        //"force   OR -f       :: Force starting init. Not recommended to run!\n"
        "-h                  :: Print this page\n"
        "Service Managing::\n"
        "NOTE::Service is other binary! Not part of NeoInit binary!\n"
        "service start <service-to-start>\n"
        "Put binary to etc/neoinit/bin to autostart it!\n"); }

int main(int argc, char** argv) {
    /**
    if( argv[1] == "version" || argv[1] == "-v") { version(); }
    if( argv[1] == "help" || argv[1] == "-h")    { gethelp(); }
    */
    int c;
    while ((c = getopt (argc, argv, "vh")) != -1)
        switch(c) {
            case 'v':
                version();
                break;
            case 'h':
                gethelp(); 
                break;
            case '?':
                if (optopt == 'c') {
                    fprintf(stderr, "Requires an argument.\n");
                    }
                
                else if (isprint (optopt))
                    fprintf (stderr, "Unknown option `-%c'.\n", optopt);
                else
                    fprintf (stderr,
                    "Unknown option character `\\x%x'.\n",
                    optopt);
                return 1;
        default:
            gethelp(); }
    }