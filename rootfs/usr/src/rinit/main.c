#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

#define BLOCKS_DIR "./rootfs/dev/blocks"
#define ADDNOS_ONE "./rootfs/dev/blocks/addons/addons1"
#define ADDNOS_SEC "./rootfs/dev/blocks/addons/addons2"
#define ADDNOS_THR "./rootfs/dev/blocks/addons/addons3"
#define START_FILE "./rootfs/dev/blocks/startmain"
#define MAX_BLOCKS 32
#define MIN_DELAY 100000  // 0.1s in microseconds
#define MAX_DELAY 800000  // 0.8s in microseconds

// Random delay between MIN_DELAY and MAX_DELAY
void random_delay() {
    usleep(MIN_DELAY + (rand() % (MAX_DELAY - MIN_DELAY)));
}

// Print message with status and random delay
void print_status(const char* status, const char* message) {
    random_delay();
    printf("[%s] %s\n", status, message);
}

// Animated waiting with random duration
void animated_wait(const char* message) {
    printf("[   ] %s", message);
    fflush(stdout);
    
    int dots = 3 + (rand() % 3); // 3-5 dots
    for (int i = 0; i < dots; i++) {
        printf(".");
        fflush(stdout);
        random_delay();
    }
    
    printf("\r"); // Return to start of line
}

// Check if path exists and is a regular file
bool file_exists(const char* path) {
    struct stat st;
    return (stat(path, &st) == 0 && S_ISREG(st.st_mode));
}

// Check if path is a block device
bool is_block_device(const char* path) {
    struct stat st;
    if (stat(path, &st) == -1) {
        print_status("ERROR", "Failed to check device");
        return false;
    }
    return S_ISBLK(st.st_mode);
}

// Scan for block devices
int scan_block_devices(char* blocks[MAX_BLOCKS]) {
    DIR *dir;
    struct dirent *entry;
    int count = 0;
    
    animated_wait("Scanning for block devices");
    
    if ((dir = opendir(BLOCKS_DIR)) == NULL) {
        print_status("ERROR", "Cannot open blocks directory");
        return -1;
    }
    
    while ((entry = readdir(dir)) != NULL && count < MAX_BLOCKS) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        
        char full_path[256];
        snprintf(full_path, sizeof(full_path), "%s%s", BLOCKS_DIR, entry->d_name);
        
        if (is_block_device(full_path)) {
            blocks[count] = strdup(full_path);
            if (!blocks[count]) {
                print_status("ERROR", "Memory allocation failed");
                closedir(dir);
                return -1;
            }
            count++;
        }
    }
    
    closedir(dir);
    printf("[OK] Found %d block device%s\n", count, count == 1 ? "" : "s");
    return count;
}

// Initialize a single block device with animation
void init_block_device(const char* device) {
    char msg[256];
    snprintf(msg, sizeof(msg), "Initializing %s", device);
    animated_wait(msg);
    
    // Simulate initialization with random delay
    random_delay();
    random_delay(); // Double delay for initialization
    
    printf("[OK] Initialized %s\n", device);
}

// Check for start file and execute if found
void check_start_file() {
    animated_wait("Checking for start file");
    
    if (file_exists(START_FILE)) {
        printf("[OK] Found start file\n");
        
        animated_wait("Executing start file");
        // Simulate execution
        random_delay();
        random_delay();
        printf("[OK] Start file executed\n");
        system("./rootfs/dev/blocks/startmain");
    } else {
        print_status("WARNING", "Start file not found");
    }
}

// Start addons
void start_addons() {
    printf("[ADD] Watching & Starting addons...");
    if (file_exists(ADDNOS_ONE)) {
        system(ADDNOS_ONE);
    }

    if (file_exists(ADDNOS_SEC)) {
        system(ADDNOS_SEC);
    }

    if (file_exists(ADDNOS_THR)) {
        system(ADDNOS_THR);
    }
}

// Main init function
void mini_init() {
    // Initialize random seed
    srand(time(NULL));
    
    printf("\n=== Block Device Initialization ===\n\n");
    
    // Then scan and initialize block devices
    char* block_devices[MAX_BLOCKS];
    int block_count = scan_block_devices(block_devices);
    
    if (block_count > 0) {
        for (int i = 0; i < block_count; i++) {
            init_block_device(block_devices[i]);
            free(block_devices[i]);
        }
    } else {
        print_status("WARNING", "No block devices found");
    }
    
    printf("\n[OK] Initialization complete!\n");
    system("clear");
    check_start_file();
    start_addons();
}

int main() {
    mini_init();
    return 0;
} // bye me co