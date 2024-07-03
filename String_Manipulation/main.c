/*
    Write a program that takes a string as input and prints the following:

    1. The original string.
    2. The string in reverse.
    3. The length of the string.

    Example:
    Input: "Hello, World!"
    Output:
    Original: Hello, World! ✅
    Reversed: !dlroW ,olleH ✅
    Length: 13 ✅
*/

#include <stdio.h>

#define MAX_LEN 100

// Function to calculate the length of a string
size_t StringLen(const char *str){
    size_t count = 0;

    while(str[count] != '\0'){
        count++;
    }
    return count;
}

// Function to reverse a string
void StringReverse(char *str){
    size_t len = StringLen(str);
    if(len > 0){
        for(size_t i = 0; i < len / 2; i++){
            char temp = str[i];
            str[i] = str[len - 1 - i];
            str[len - 1 - i] = temp;
        }
    }
}

int main(void){

    char userInput[MAX_LEN];
    printf("Enter a string: ");
    // Read the input string
    if(fgets(userInput, MAX_LEN, stdin) != NULL){
        // Calculate the length of the input string
        size_t len = StringLen(userInput);
        // Remove new line character if present
        if(len > 0 && userInput[len - 1] == '\n'){
            userInput[len - 1] = '\0';
            len--;
        }
        // Print original string
        printf("Original: %s\n", userInput);
        // Calling the reverse string function
        StringReverse(userInput);
        // Print reversed string
        printf("Reversed: %s\n", userInput);
        // Print the length of the string
        printf("Length: %zu\n", len);

    }else{
        // Error message if input fails
        perror("Error reading input");
    }

    return 0;
}