#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random password
void generatePassword(char *password, int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+";
    int charsetSize = sizeof(charset) - 1;

    srand((unsigned int)time(NULL));

    for (int i = 0; i < length; ++i) {
        int randomIndex = rand() % charsetSize;
        password[i] = charset[randomIndex];
    }

    password[length] = '\0'; // Null-terminate the string
}

int main() {
    int passwordLength;
    
    // Get password length from the user
    printf("Enter the length of the password: ");
    scanf("%d", &passwordLength);

    // Check for valid password length
    if (passwordLength <= 0) {
        printf("Invalid password length. Please enter a positive integer.\n");
        return 1;
    }

    // Allocate memory for the password
    char *password = (char *)malloc((passwordLength + 1) * sizeof(char));

    if (password == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    // Generate the password
    generatePassword(password, passwordLength);

    // Display the generated password
    printf("Generated Password: %s\n", password);

    // Free allocated memory
    free(password);

    return 0;
}
