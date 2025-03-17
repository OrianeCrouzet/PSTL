#include <stdio.h>
#include <stdlib.h>

#define BLOCKS_WIDTH 10   // 10 blocks wide
#define BLOCKS_HEIGHT 3   // 3 blocks high
#define BLOCK_SIZE 1      // 1 byte represents one block (since each byte is 7 bits for each block)
#define BYTES_TO_READ 30  // 30 bytes for 10 blocks wide and 3 blocks high

unsigned char* load_screen_data(const char* filename) {
    FILE *file = fopen(filename, "rb");  // Open file in binary mode
    if (file == NULL) {
        perror("Failed to open file");
        return NULL;
    }

    // Check the file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    printf("File size: %ld bytes\n", file_size);

    // Ensure the file has enough data
    if (file_size < BYTES_TO_READ) {
        fprintf(stderr, "Error: File doesn't contain enough data.\n");
        fclose(file);
        return NULL;
    }

    // Allocate memory to store 30 bytes of screen data (first screen's data)
    unsigned char* screen_data = (unsigned char*) malloc(BYTES_TO_READ);
    if (screen_data == NULL) {
        perror("Failed to allocate memory");
        fclose(file);
        return NULL;
    }

    // Seek to the starting point in the file (for the first screen's data)
    fseek(file, 0, SEEK_SET);  // Adjust as needed based on where the data actually starts

    // Read the 30 bytes (the first screen's block data)
    size_t bytes_read = fread(screen_data, 1, BYTES_TO_READ, file);
    if (bytes_read != BYTES_TO_READ) {
        fprintf(stderr, "Failed to read the full screen data. Expected 30 bytes, but read %zu bytes.\n", bytes_read);
        free(screen_data);
        fclose(file);
        return NULL;
    }

    fclose(file); // Close the file after reading
    return screen_data; // Return the loaded screen data
}

void display_screen(unsigned char* screen_data) {
    if (screen_data == NULL) {
        return;
    }

    // Iterate through each block (3 rows of 10 blocks each)
    for (int row = 0; row < BLOCKS_HEIGHT; row++) {
        for (int col = 0; col < BLOCKS_WIDTH; col++) {
            // Each byte corresponds to one block (7 pixels)
            int byte_index = row * BLOCKS_WIDTH + col;
            unsigned char byte = screen_data[byte_index];

            // Display each block as 7 pixels wide
            for (int bit = 0; bit < 7; bit++) {
                // Check if the pixel is set (using the bit mask)
                if (byte & (1 << (6 - bit))) {
                    printf("##"); // Block is "on" (black)
                } else {
                    printf("  "); // Block is "off" (white)
                }
            }
            printf(" "); // Space between blocks
        }
        printf("\n");
    }
}

int main() {
    const char* filename = "LEVEL0"; // Change this to your actual file path
    unsigned char* screen_data = load_screen_data(filename);
    
    if (screen_data != NULL) {
        display_screen(screen_data); // Display the first screen
        free(screen_data); // Free the allocated memory after usage
    }
    
    return 0;
}
