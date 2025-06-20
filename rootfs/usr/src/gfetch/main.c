#include <stdio.h>
#include <stdlib.h>
#include "../../os-release.h"

#define LOGO "         \n"\
             "         \n"\
             "         \n"\
             "         \n"\
             "         \n"\
             "         \n"\
             "           "
#define GOBACK "\033[6A\033[100D"
#define PAD "\033[15C"

int main(void) {
  fputs(LOGO, stdout);
  fputs(GOBACK, stdout);
  printf(PAD"\033[32mOS\033[0m: "OS_VERSION"\n");
  printf(PAD"\033[32mKernel\033[0m: "KERNEL_VERSION"\n");
  printf(PAD"\033[32mHost\033[0m: "); fflush(stdout); system("cat etc/hostname.fetch");
  printf(PAD"\033[32mShell\033[0m: "OS_SHELL"\n");
  printf(PAD"\033[32mTerminal\033[0m: "); fflush(stdout); system("echo $TERM");
  fputs("\n"PAD, stdout);
  for (char i = 1; i <= 7; i++) {
    printf("\033[4%dm   ", i);
  }
  fputs("\033[0m\n"PAD, stdout);
  for (char i = 1; i <= 7; i++) {
    printf("\033[10%dm   ", i);
  }
  puts("\033[0m");
  return 0;
}
