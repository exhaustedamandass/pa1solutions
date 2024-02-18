#include <stdio.h>

int GCD(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return GCD(b % a, a); 
} 

int LCM(int a, int b) 
{ 
    return (a * b) 
        / GCD(a, b); 
} 
int findlcm(int arr[], int n)
{
    // Initialize answer
    int ans = arr[0];
 
    for (int i = 1; i < n; i++)
        ans = (((arr[i] * ans)) /
                (GCD(arr[i], ans)));
 
    return ans;
}
int GCDArray(int arr[], int size){
    int result = arr[0];
    for (int i = 0; i < size; i++)
    {
        result = GCD(arr[i], result);
        if(result == 1){
            return 1;
        }
    }
    return result;
    
}
int checkPairwiseCoPrime(int A[], int n) 
{ 
    // Initialize variables 
    int prod = 1; 
    int lcm = 1; 
 
    // Iterate over the array 
    for (int i = 0; i < n; i++) { 
 
        // Calculate product of 
        // array elements 
        prod *= A[i]; 
 
        // Calculate LCM of 
        // array elements 
        lcm = LCM(A[i], lcm); 
    } 
    // If the product of array elements 
    // is equal to LCM of the array 
    if (prod == lcm) 
        return 1;
    else
        return 0;
} 
int mypow(int power){
    int result = 1;
    for (int i = 0; i < power; i++)
    {
        result *= 2;
    }
    return result;
    
}

long long int chineseTheorem(int num[], int rem[], int k) 
{ 
    int x = 1;
    while (1) 
    { 
        int j; 
        for (j=0; j<k; j++ ) 
            if (x%num[j] != rem[j]) 
               break; 
          if (j == k) 
            return x; 
          x++; 
    } 
  
    return x; 
} 
int main(void){
    printf("Messages:\n");
    char c;
    int messages[10][2];
     for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 2; j++) {
            messages[i][j] = 0;
        }
    }
    int counter = 0;
    int containsPipe = 0;
    //int pulse1 = 0, pulse2 = 0;
    //int message1 = 0, message2 = 0;
    int isMessage = 0;
    int anyLetters = 0;
    while(scanf("%c", &c) == 1){
        if(c == '\n'){
            if(!containsPipe){
                printf("Invalid input.\n");
                return 0;
            }
            if(anyLetters == 0){
                printf("Invalid input.\n");
                return 0;
            }
            anyLetters = 0;
            isMessage = 0;
            containsPipe = 0;
            counter++;
            continue;
        }
        if(c == '|'){
            if(containsPipe == 0){
                containsPipe = 1;
                isMessage = 1;
                continue;
            }else{
                printf("Invalid input.\n");
                return 0;
            }
        }
        if(c > 122 || c < 97){
            printf("Invalid input.\n");
            return 0;
        }else{
            anyLetters = 1;
        }
        int value = c - 97;
        value = mypow(value);
        if(isMessage){
            messages[counter][1] += value;
        }else{
            messages[counter][0] += value;
        }
        /*
        if(counter == 1){
            if (isMessage)
            {
                message2 += value;
            }
            else
            {
                pulse2 += value;
            }
        }else{
            if (isMessage)
            {
                message1 += value;
            }
            else
            {
                pulse1 += value;
            }
        }*/
    }
    if (counter <= 1)
    {
        printf("Invalid input.\n");
            return 0;
    }
    
    if(counter == 2){
        if(messages[0][0] == 0 || messages[0][1] == 0 || messages[1][0] == 0 || messages[1][1] == 0  ){
            printf("Synchronized in: 0\n");
            return 0;
        }
    }
    
    
    int num[10];
    int rem[10];
    for (int i = 0; i < counter; i++) 
    {
        num[i] = messages[i][0] + messages[i][1];
        rem[i] = messages[i][0];
    }
    for (int i = 0; i < counter; i++)
    {
        printf("num %d rem %d\n", num[i], rem[i]);
    }
    int gcd = GCDArray(num, counter); 

    for (int i = 0; i < counter; i++)
    {
        for (int j = i + 1; j < counter; j++)
        {
            int diff = rem[i] - rem[j];
            if(diff % gcd != 0){
                printf("Never synchronizes.\n");
               return 0;
            }
        }
    }
    if(checkPairwiseCoPrime(num, counter) == 1){
        printf("Synchronized in: %lld\n", chineseTheorem(num, rem , counter));
    }else{ 
        printf("here\n");
        int max = num[0];
        int maxrem = rem[0];
        for (int i = 1; i < counter; i++)
        {
            if(num[i] > max){
                max = num[i];
                maxrem = rem[i];
            }
        }
        int lcm = findlcm(num, counter);
        printf("lcm %d\n", lcm);
        printf("max num %d rem %d\n", max, maxrem);
        
        int i = 0;
        for (int k = 0; k < 15; k++)
        {
            /* code */
        
        
            int total = max * i + maxrem;
            printf("%d\n", total);
            int isSolution = 1;
            for (int j = 0; j < counter; j++) {
                printf("num %d  rem %d  j %d\n", num[j], rem[j], i);
                if ((total - rem[j]) % num[j] != 0) {
                    isSolution = 0;
                    break; 
                }
            }
            if (isSolution) {
                printf("Synchronized in: %d\n", total);
                return 0;
            }
            i++;
        }
        
    }
    



    return 0;
}
