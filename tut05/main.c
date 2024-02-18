#include <stdio.h>

int main(){
    double x1 = 0.0, x2 = 0.0;
    char c = '\0', c2 = '\0';
    printf("Type formula:\n");
    if(scanf("%lf %c %lf %c", &x1, &c, &x2, &c2) != 4 || (c != '-' && c != '+' && c != '/' && c != '*') || c2 != '='){
        printf("Invalid input.\n");
        return 0;
    }
    if(c == '/' && x2 == 0){
        printf("Invalid input.\n");
        return 0;
    }
    double result = 0;
    switch (c)
    {
    case '+':
        result = x1 + x2;
        break;
    case '-':
        result = x1 - x2;
        break;
    case '*':
        result = x1 * x2;
        break;
    case '/':
        result = x1 / x2;
        break;
    default:
        break;
    }
    if((long long int)result % 100 == 0 && result > 100){
        printf("%.1e\n", result);
    }else if(c == '/'){
        if(result > 10){
            printf("%.0f\n", result);
        }else{
        printf("%lld\n", (long long int)result);
        }
    }else{
        printf("%g\n", result);
    }
    return 0;
}
