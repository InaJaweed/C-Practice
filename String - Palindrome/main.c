/*
Description:
Write a program that checks if a given string is a palindrome. A palindrome is a string that reads the same forwards and backwards (ignoring spaces, punctuation, and case).

*/

#include <stdio.h>

#define MAX_LEN 100
const char punctuations[] = ".,!?;:\"'()[]{}<>-@#$%^&*_+=|\\/~`";

size_t StringLen(const char* str){
    size_t count = 0;
    while(str[count] != '\0'){
        count++;
    }

    return count;
}

void StringReverse(char* str){
    size_t len = StringLen(str);
    if(len > 0){
        for(size_t i = 0; i < len / 2; i++){
            char temp = str[i];
            str[i] = str[len - 1 - i];
            str[len - 1 - i] = temp;
        }
    }
}

// Function to check if a character is punctuation
int is_punctuation(char ch, const char* punct){
    for(int i = 0; punct[i] != '\0'; i++){
        if(ch == punct[i]){
            return 1;
        }
    }
    return 0;
}

// Function to remove punctuation
void remove_punctuation(char* str, const char* punct, char* punctRem){
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++){
        if(!is_punctuation(str[i], punct)){
            punctRem[j++] = str[i];
        }
    }

    punctRem[j] = '\0';
}

// Function to get string to lowercase
void lowercase(char* str){
    while(*str != '\0'){
        if(*str >= 65 && *str <= 90){
            *str += 32;
        }
        str++;
    }
}

char* removeSpace(char* str){
    size_t non_space_count = 0;

    for(size_t i = 0; str[i] != '\0'; i++){
        if(str[i] != ' '){
            str[non_space_count] = str[i];
            non_space_count++;
        }
    }
    str[non_space_count] = '\0';
    return str;
}

int strPali(const char* str1, const char* str2){
    while(*str1 != '\0' && *str2 != '\0'){
        if(*str1 != *str2){
            return 0;
        }

        str1++;
        str2++;
    }

    return (*str1 == '\0' && *str2 == '\0');
}

int main(void){
    char userInput[MAX_LEN];
    char punctRemoved[MAX_LEN];

    printf("Enter a string: ");
    
    // Read user string input
    if(fgets(userInput, MAX_LEN, stdin) != NULL){
        // Calculate string length
        size_t len = StringLen(userInput);
        // Remove new character line if present 
        if(len > 0 && userInput[len - 1] == '\n'){
            userInput[len - 1] = '\0';
            len--;
        }
        printf("--------------------\n");    
        // Print Original String to user
        printf("Original String: %s\n", userInput);
        
        /*
            Functions to remove white space and then make sure all char is lowercase, and then remove punctuations
        */
        lowercase(removeSpace(userInput)); // Remove WhiteSpace and Make all char lowercase
        remove_punctuation(userInput, punctuations, punctRemoved); // remove punctuation
        remove_punctuation(punctRemoved, punctuations, userInput); // remove punctuation
        StringReverse(punctRemoved); // Reverse String

        printf("String After Modification: %s\n", punctRemoved);
        printf("Original String Modified: %s\n", userInput);
        int isPali = strPali(userInput, punctRemoved);

        if(isPali){
            printf("The string is a palindrome\n");
        }else{
            printf("The string is NOT a palindrome\n");
        }

    }

    return 0;
}
