#include <stdio.h>
#include <string.h>
#include <unistd.h>      // For access(), fork(), exec()
#include <sys/wait.h>    // For wait()
#include <stdlib.h>      // For exit()
#define MAX_LENGTH 100
#define RED "\x1b[31m"
#define RESET "\033[0m"
int main() {
    char input[MAX_LENGTH];
    char path[MAX_LENGTH * 2]; // Allow extra space for path
    
    printf("NucleoShell v1 build2.\n");
    
    while(1) {
        printf("::> ");
        if (!fgets(input, MAX_LENGTH, stdin)) {
            break; 
        }
        
        // Remove newline character
        input[strcspn(input, "\n")] = '\0';
        
        // Skip empty commands
        if (strlen(input) == 0) {
            continue;
        }
        
        if (strcmp(input, "exit") == 0) {
            break;
        }
        
        // Construct absolute path to binary
        snprintf(path, sizeof(path), "./rootfs/bin/%s", input);
        
        // Check if file exists and is executable
        if (access(path, F_OK | X_OK) != -1) {
            pid_t pid = fork();
            
            if (pid == -1) {
                perror("fork");
            } else if (pid == 0) {
                // Child process executes the binary
                execl(path, input, NULL);
                
                // If execl fails
                perror("execl");
                exit(EXIT_FAILURE);
            } else {
                // Parent waits for child to finish
                wait(NULL);
            }
        } else {
            // File doesn't exist or isn't executable
            printf(
                "nucleoshell::"
                RED "Error" RESET
                "::Command not found.\n" );
        }
    }
    
    return 0;
}