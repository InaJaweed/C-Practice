#include <stdio.h>

// Define maximum length for input string
#define MAX_LEN 100

// Define the set of punctuation characters to be removed
const char punctuations[] = ".,!?;:\"'()[]{}<>-@#$%^&*_+=|\\/~`";

// Function to calculate the length of a string
size_t StringLen(const char* str) {
    size_t count = 0;
    while(str[count] != '\0') {
        count++;
    }
    return count;
}

// Function to reverse a string in place
void StringReverse(char* str) {
    size_t len = StringLen(str);
    if(len > 0) {
        for(size_t i = 0; i < len / 2; i++) {
            char temp = str[i];
            str[i] = str[len - 1 - i];
            str[len - 1 - i] = temp;
        }
    }
}

// Function to check if a character is a punctuation mark
int is_punctuation(char ch, const char* punct) {
    for(int i = 0; punct[i] != '\0'; i++) {
        if(ch == punct[i]) {
            return 1;
        }
    }
    return 0;
}

// Function to remove punctuation from a string
void remove_punctuation(char* str, const char* punct, char* punctRem) {
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if(!is_punctuation(str[i], punct)) {
            punctRem[j++] = str[i];
        }
    }
    punctRem[j] = '\0';
}

// Function to convert a string to lowercase
void lowercase(char* str) {
    while(*str != '\0') {
        if(*str >= 65 && *str <= 90) {  // ASCII values for 'A' to 'Z'
            *str += 32;  // Convert to corresponding lowercase letter
        }
        str++;
    }
}

// Function to remove spaces from a string
char* removeSpace(char* str) {
    size_t non_space_count = 0;
    for(size_t i = 0; str[i] != '\0'; i++) {
        if(str[i] != ' ') {
            str[non_space_count] = str[i];
            non_space_count++;
        }
    }
    str[non_space_count] = '\0';
    return str;
}

// Function to check if two strings are identical
int strPali(const char* str1, const char* str2) {
    while(*str1 != '\0' && *str2 != '\0') {
        if(*str1 != *str2) {
            return 0;
        }
        str1++;
        str2++;
    }
    return (*str1 == '\0' && *str2 == '\0');
}

int main(void) {
    char userInput[MAX_LEN];
    char punctRemoved[MAX_LEN];

    printf("Enter a string: ");
    
    // Read user string input
    if(fgets(userInput, MAX_LEN, stdin) != NULL) {
        // Calculate string length
        size_t len = StringLen(userInput);
        // Remove newline character if present
        if(len > 0 && userInput[len - 1] == '\n') {
            userInput[len - 1] = '\0';
            len--;
        }
        printf("--------------------\n");    
        // Print Original String to user
        printf("Original String: %s\n", userInput);
        
        /*
            Functions to remove white space, convert all characters to lowercase,
            and then remove punctuations
        */
        lowercase(removeSpace(userInput));  // Remove white space and convert to lowercase
        remove_punctuation(userInput, punctuations, punctRemoved);  // Remove punctuation and add it punctRemoved array
        remove_punctuation(punctRemoved, punctuations, userInput);  // Remove punctuation from oringal string
        StringReverse(punctRemoved);  // Reverse the string

        printf("String After Modification: %s\n", punctRemoved);
        printf("Original String Modified: %s\n", userInput);

        // Check if the original modified string is a palindrome
        int isPali = strPali(userInput, punctRemoved);
        if(isPali) {
            printf("The string is a palindrome\n");
        } else {
            printf("The string is NOT a palindrome\n");
        }
    }

    return 0;
}
