#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char input[MAX_LENGTH];
    
    printf("Welcome to Nucleo! (type 'quit' to exit):\n");
    
    while(1) {
        printf("::> ");
        fgets(input, MAX_LENGTH, stdin);
        
        // remove newline character
        input[strcspn(input, "\n")] = '\0';
        
        if(strcmp(input, "quit") == 0) {
            //return 0;
            break;
        }
        /*
        if(strcmp(input, "exit") == 0) {
          // return 0;
          break; }
        }
        */
        //printf("command not found: %s\n", input);
        printf("shell:command %s not found",input);
    }
    
    return 0;
}