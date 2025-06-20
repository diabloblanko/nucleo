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
#include <stdlib.h>
#include <stdio.h>
#define VERSION 1

int version() {
    printf(
    " _   _           ___       _ _          NeoInit V1\n"
    "| \\ | | ___  ___|_ _|_ __ (_) |_       Written by DiabloBlanko\n"
    "|  \\| |/ _ \\/ _ \\| || '_ \\| | __|   Build :: x86_64-nucleo-neoinit-v1-b1"
    "| |\\  |  __/ (_) | || | | | | |_ "
    "|_| \\_|\\___|\\___/___|_| |_|_|\\__|");
    return 0; }
void gethelp() {
    printf(
        "NeoInit Help::\n"
        "version OR -v       :: Print version and exit\n"
        "force   OR -f       :: Force starting init. Not recommended to run!\n"
        "help    OR -h       :: Print this page\n"
        "Service Managing::\n"
        "NOTE::Service is other binary! Not part of NeoInit binary!\n"
        "service start <service-to-start>\n"
        "Put binary to etc/neoinit/bin to autostart it!\n"
    ) }

void startservice(char* servicetostart) {
    printf("NeoInit::Services::Starting %s...\n", servicetostart);
    system("%s", servicetostart); }
void startup() {

    startservice("motd");
    startservice("login"); }
int main(int argc, char** argv) {
    if(argv[1] = "force" || argv[1] = "-f") {
        startup();
    }
    else {
    printf("NeoInit::Warning::Never start init in booted system!\n")
    fprintf(stderr, "NeoInit::Error::To start init, use --yes (or -y) flag")
    gethelp(); }
}