#include <stdio.h>

int main(){
    printf("Values:\n");
    int nums[250000];
    int count = 0;
    int tmp;
    int min = __INT_MAX__;
    int max = -2147483648;
    int isValid = 0;
    while(scanf("%d", &tmp) == 1){
        //printf("count is %d is feof %d\n", count, feof(stdin));
        if(count >= 250000){
            printf("Invalid input.\n");
            return 0;            
        }
        if(!isValid){
            if(tmp < min) min = tmp;
            else if(tmp >= min) isValid = 1;
        }
        if(tmp > max) max = tmp;
        nums[count] = tmp;
        count++;
    }
    if(!feof(stdin)){
        printf("Invalid input.\n");
        return 0;
    }
    if(count <= 1){
        printf("Invalid input.\n");
        return 0;
    }
    if(!isValid){
        printf("Does not exist.\n");
        return 0;
    }
    int tonums[250000];
    for (int i = 0; i < count-1; i++)
    {
        int temp = 0;
        for (int j = count-1; j > i; j--)
        {
            if(nums[i] <= nums[j]){
                temp = j;
                break;
            }
        }
        tonums[i] = temp;
        
    }
    int max_seq = 0;
    int resulting [250000][2];
    int countresulting = 0;
    //if its equal to longest 
    //if its more than longest
    //if its less than longest
    for (int i = 0; i < count; i++)
    {
        if(tonums[i] == 0) continue;
        if(tonums[i] - i == max_seq){
            resulting[countresulting][0] = i;
            resulting[countresulting][1] = tonums[i];
            countresulting++;
        }
        else if(tonums[i] - i > max_seq){
            countresulting = 0;
            resulting[countresulting][0] = i;
            resulting[countresulting][1] = tonums[i];
            max_seq = tonums[i] - i;
            countresulting++;
        }
    }
    max_seq++;
    for (int i = 0; i < countresulting; i++)
    {
        printf("%d: %d - %d\n", max_seq, resulting[i][0], resulting[i][1]);
    }
    printf("Answers: %d\n", countresulting);
    
    
    

}