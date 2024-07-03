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

size_t StringLen(const char *str){
    size_t count = 0;

    while(str[count] != '\0'){
        count++;
    }
    return count;
}

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

    if(fgets(userInput, MAX_LEN, stdin) != NULL){
        size_t len = StringLen(userInput);
        if(len > 0 && userInput[len - 1] == '\n'){
            userInput[len - 1] = '\0';
            len--;
        }
        printf("Original: %s\n", userInput);
        StringReverse(userInput);
        printf("Reversed: %s\n", userInput);
        printf("Length: %zu\n", len);

    }else{
        perror("Error reading input");
    }

    return 0;
}
