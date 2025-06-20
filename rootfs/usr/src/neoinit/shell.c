#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100

int main() {
    char input[MAX_LENGTH];
    
    printf("NucleoShell v1.\n");
    
    while(1) {
        printf("::> ");
        fgets(input, MAX_LENGTH, stdin);
        
        // remove newline character
        input[strcspn(input, "\n")] = '\0';
        
        if(strcmp(input, "exit") == 0) {
            break;
        }
        
        printf("nucleoshell::Error::Command %s\n not found.", input);
    }
    
    return 0;
}