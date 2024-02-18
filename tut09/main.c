#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char *str) {
    int len = strlen(str);
    int i, j;
    int is_sensetive = 1;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        while (isspace(str[i]) && i < j) i++;
        while (isspace(str[j]) && i < j) j--;
        if(is_sensetive){
            if(str[i] != str[j]){
                is_sensetive = 0;
            }
        }
        if(!is_sensetive){
            if (tolower(str[i]) != tolower(str[j])) {
                return 0; 
            }
        }
    }
    if(is_sensetive){
        return 2;
    }
    return 1; 
}

int main() {
    char input[8192];
    printf("Enter string:\n");
    while (1) {
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; 
        }
        if (input[0] == '\n') {
            printf("Invalid input.\n");
            return 0;
        }
        if(strcspn(input, "\n") == strlen(input)){
            printf("Invalid input.\n");
            return 0;
        }
        input[strcspn(input, "\n")] = '\0';
        int onlyWhitespace = 1;
        for (size_t i = 0; i < strlen(input); i++) {
            if (!isspace(input[i])) {
                onlyWhitespace = 0;
                break;
            }
        }
        if (onlyWhitespace) {
            printf("Invalid input.\n");
            return 0;
        }
        int ret;
        if ((ret = isPalindrome(input)) == 2) {
            printf("String is a palindrome (case-sensitive).\n");
        } else if(ret){
            printf("String is a palindrome (case-insensitive).\n");
        }else {
            printf("String is not a palindrome.\n");
        }
    }

    return 0;
}
