#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
/*int recursion(int* nums, int curr, int arrLength){
    if(curr == 0){
        return 0;
    }
    int result = 2147483647;
    if(nums[0] > curr){
        return result;
    }
    for(int i = arrLength - 1; i >= 0; --i){
        //printf("here\n");
        if(nums[i] <= curr){

            int subResult = recursion(nums, curr - nums[i], arrLength);
            if(subResult != 2147483647 && subResult + 1 < result){
                result = subResult + 1;
            }
        }
    }
    return result;
}*/


int minCoinsMemo(int amount, int coins[], int numCoins, int memo[]) {
    if (amount == 0) {
        return 0;
    }

    if (memo[amount] != -1) {
        return memo[amount];
    }

    int result = INT_MAX;

    for (int i = 0; i < numCoins; i++) {
        if (coins[i] <= amount) {
            int subResult = minCoinsMemo(amount - coins[i], coins, numCoins, memo);
            if (subResult != INT_MAX && subResult + 1 < result) {
                result = subResult + 1;
            }
        }
    }

    // Save the result in the memo table and return it
    memo[amount] = result;
    return result;
}

int recursion(int amount, int coins[], int numCoins) {
    // Initialize memo table with -1 (indicating not calculated)
    int* memo = (int*)malloc(sizeof(int) * (amount+1));
    for (int i = 0; i <= amount; i++) {
        memo[i] = -1;
    }

    // Call the helper function with memoization
    return minCoinsMemo(amount, coins, numCoins, memo);
}


int main(){
    int ret = 0;
    size_t sizeNums = 20;
    int* nums = (int*)malloc(sizeNums * sizeof(int));
    //int* amounts = (int*)malloc(sizeAmounts * sizeof(int));
    size_t countNums = 0;
    int tmp = 0;
    printf("Coins:\n");
    while( (ret = scanf(" %d ", &tmp)) == 1){
        if(tmp < 0){
            printf("Invalid input.\n");    
            return 0;
        }
        if(tmp == 0){
            break;
        }
        nums[countNums] = tmp;
        countNums++;
        if(countNums + 2 >= sizeNums){
            sizeNums *= 2;
            nums = (int*)realloc(nums, sizeNums * sizeof(int));
        }
    }
    if(ret == EOF || countNums == 0){
        printf("Invalid input.\n");
        return 0;
    }
    if(tmp != 0 && ret == 0){
        printf("Invalid input.\n");
        return 0;
    }
    //qsort(nums, countNums, sizeof(int), compare);
    printf("Amounts:\n");
    while( (ret = scanf(" %d ", &tmp)) == 1){
        if(tmp < 0){
            printf("Invalid input.\n");    
            return 0;
        }
        //printf("looking for %d\n", ret);
        int res = recursion(tmp, nums, countNums);
        if(res == INT_MAX){
            printf("= no solution\n");
            continue;
        }
        printf("= %d\n", res);
        /*amounts[countAmounts] = tmp;
        countAmounts++;
        if(countAmounts + 2 >= sizeAmounts){
            sizeAmounts *= 2;
            amounts = (int*)realloc(amounts, sizeAmounts * sizeof(int));
        }*/
    }
    if(ret != EOF && ret == 0){
        printf("Invalid input.\n");
        return 0;
    }/*
    for (size_t i = 0; i < countNums; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    for (size_t i = 0; i < countAmounts; i++)
    {
        printf("%d ", amounts[i]);
    }
    printf("\n");*/
    return 0;
}
