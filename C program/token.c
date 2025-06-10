#include <stdio.h>
#include <string.h>

int main() {
    // Example input line (this can be read from a file, too)
    char line[] = "John Doe Sales 5000.00";

    // Using strtok to split the line by spaces
    char* token = strtok(line, " "); // Split the first token (before the first space)

    // Process the tokens
    while (token != NULL) {
        printf("Token: %s\n", token); // Print each token (word)
        
        // Get the next token
        token = strtok(NULL, " ");
    }

    return 0;
}
