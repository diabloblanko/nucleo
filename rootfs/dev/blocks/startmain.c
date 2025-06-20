#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Name = startmain::RInit.Service");
    sleep(3);
    system("./rootfs/usr/src/rinit/shell");
}