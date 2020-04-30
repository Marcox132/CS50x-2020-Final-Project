#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Global Variables
string key;
string plainText;

// Custom Functions
string getText(void);
string substituteText(string text);

// Main Function
int main(int argc, string argv[])
{
    // Handles the command-line arguments
    if (argc == 2)
    {
        if (strlen(argv[1]) == 26)
        {
            key = argv[1];
            for (int i = 0; i < strlen(argv[1]); i++)
            {
                if (isalpha(argv[1][i]))
                {
                    key[i] = argv[1][i];
                }
                else
                {
                    printf("Key must only contain alphabetic characters\n");
                    return 1;
                }
            }
            for (int i = 0; i < strlen(key); i++)
            {
                for (int j = i + 1; j < strlen(key); j++)
                {
                    if (key[i] == key[j])
                    {
                        printf("Key must not contain repeated characters\n");
                        return 1;
                    }
                }
            }
        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Prompts the user for the plaintext
    getText();
    // Uses the substitution cipher to encrypt the text
    substituteText(plainText);
    // Prints the cipheredtext
    printf("ciphertext: %s\n", plainText);
    // Tells that the program ran successfully
    return 0;
}

// Function that prompts for the plaintext
string getText(void)
{
    plainText = get_string("plaintext: ");
    return plainText;
}

// Function that uses the substitution cipher
string substituteText(string text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                plainText[i] = toupper(key[plainText[i] - 65]);
            }
            if (islower(text[i]))
            {
                plainText[i] = tolower(key[plainText[i] - 97]);
            }
        }
    }
    return plainText;
}