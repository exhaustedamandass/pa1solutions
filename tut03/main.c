#include <stdio.h>

int validateinput(int hour, int minute, int second, int millisecond){
    if( hour < 0 || hour > 23 ||
     minute > 59 || minute < 0 ||
      second < 0 || second > 59 ||
       millisecond < 0 || millisecond > 999){
        return 0;
    }
    return 1;
}
int operatefractions(int *milliseconds){
    if(*milliseconds != 0){
        if(*milliseconds < 10 ){
            *milliseconds*=100;
        }else if(*milliseconds < 100){
            *milliseconds*=10;
        }
    }
    
}
int turntolongnum(int hour, int minute, int second, int millisecond){
    //2,147,483,647
    return ((hour * 3600000) + (minute * 60000) + (second * 1000) + millisecond);
}


int main(void){
    printf("Enter time t1:\n");
    int timestamp1, timestamp2;
    int hour1, minute1, second1, millisecond1, hour2, minute2, second2, millisecond2;
    if(scanf(" %d : %d : %d , %d ", &hour1, &minute1, &second1, &millisecond1) == 4){
        if(validateinput(hour1, minute1, second1, millisecond1)){
            operatefractions(&millisecond1);
            timestamp1 = turntolongnum(hour1, minute1, second1, millisecond1);
        }else{
            printf("Invalid input.\n");
            return 0;
        }
    }else{
            printf("Invalid input.\n");
            return 0;
    }
    printf("Enter time t2:\n");
    if(scanf(" %d : %d : %d , %d ", &hour2, &minute2, &second2, &millisecond2) == 4){
        if(validateinput(hour2, minute2, second2, millisecond2)){
            operatefractions(&millisecond2);
            timestamp2 = turntolongnum(hour2, minute2, second2, millisecond2);
        }else{
            printf("Invalid input.\n");
            return 0;
        }
    }else{
        printf("Invalid input.\n");
        return 0;
    }
    if(timestamp1 > timestamp2) {
        printf("Invalid input.\n");
        return 0;
    }
    timestamp2 -= timestamp1;
    
    printf("Duration: %2d:%02d:%02d,%03d\n", (timestamp2 / 3600000 ), ((timestamp2 % 3600000) / 60000), (((timestamp2 % 3600000) % 60000) / 1000), (timestamp2 % 1000));

    return 0;
}