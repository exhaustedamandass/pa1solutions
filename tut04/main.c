#include <stdio.h>

int countDigits(int number) {
    int count = 0;

    // Handle the case where the number is 0 separately
    if (number == 0) {
        return 1;
    }

    // Handle negative numbers by making them positive temporarily
    if (number < 0) {
        number = -number;
    }

    while (number > 0) {
        number = number / 10;
        count++;
    }

    return count;
}



int main(void){
    
    printf("Limit:\n");
    int n;
    if(scanf("%d", &n) != 1 || n <= 0){
        printf("Invalid input.\n");
        return 0;
    }
    int max_digit = countDigits(n * n);
    for (int i = 0; i < max_digit; i++)
    {
        printf(" ");
    }
    printf("|");
    for (int i = n; i > 0; --i)
    {
        printf("%*d", (max_digit+1), i);
    }
    printf("\n");
    for (int i = 0; i < max_digit; i++)
    {
        printf("-");
    }
    printf("+");
    
    for (int i = n; i > 0; i--)
    {
        for(int j = 0; j < (max_digit + 1); j ++){
            printf("-");
        }
    }
    printf("\n");
    for (int i = 1; i <= n ; i++)
    {
        printf("%*d|", max_digit, i);
        for (int j = n; j > i-1; j--)
        {
            printf("%*d", (max_digit+1), (i*j));
        }
        printf("\n");
        
    }
    
    
    
    
    /*
    int width = 4; // Set the desired width here

    int number = 42; // The integer you want to print

    printf("%*d\n", width, number);
*/
    
    /*
    printf("")
    max_digit += 1;
    for(int i = 1; i < 0; --i){
        
    } 
*/

    return 0;
}
