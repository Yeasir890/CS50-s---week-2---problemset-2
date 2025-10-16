#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool only_digits(string s);

int main(int argc, string argv[])
{
    // Check for correct number of arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Validate that key contains only digits
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert key to integer
    int key = atoi(argv[1]);

    // Get plaintext from user
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    // Encrypt each character
    for (int i = 0; i < strlen(plaintext); i++)
    {
        char c = plaintext[i];
        if (isupper(c))
        {
            printf("%c", (c - 'A' + key) % 26 + 'A');
        }
        else if (islower(c))
        {
            printf("%c", (c - 'a' + key) % 26 + 'a');
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
}

// Function to check if string contains only digits
bool only_digits(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

