#include <stdio.h>


int validateinput(int hour, int minute){
    if( hour < 0 || hour > 23 ||
     minute > 59 || minute < 0){
        return 0;
    }
    return 1;
}

int turntominutes(int hour, int minute){
    return (hour * 60 + minute);
}

int isavailable(int arrival1, int departure1, int arrival2, int departure2){
    int difference = arrival2 - arrival1;
    if(difference > 0){
        if(difference <= 180) {
            return 1;
        }
        if(difference > 1260 ){
            int to_departure = departure2 - arrival1 - 5;
            if(to_departure >= 0 && to_departure < difference){
                return 1;
            }
        }
        if(arrival1 + 5 == departure2) {
            return 1;
        }
        return 0;
    }else{
        if(((arrival1 + 5) <= departure2)  || difference < -1260){
            return 1;
        }
        return 0;
    }
    return 0;
}


int main(void){
    
    int timestamps[6];
    int hour, minute;
    for (size_t i = 0; i < 6; i++)
    {
        switch (i)
        {
        case 0:
            printf("Train A arrival time:\n");
            break;
        case 1:
            printf("Train A departure time:\n");
            break;
        case 2:
            printf("Train B arrival time:\n");
            break;
        case 3:
            printf("Train B departure time:\n");
            break;
        case 4:
            printf("Train C arrival time:\n");
            break;
        case 5:
            printf("Train C departure time:\n");
            break;
        default:
            break;
        }
        if(scanf("%d:%d", &hour, &minute) != 2 || validateinput(hour, minute) != 1){
            printf("Invalid input.\n");
            return 0;
        }
        timestamps[i] = turntominutes(hour, minute);
    }

    int ab = 0, ac = 0, ba = 0, bc = 0, ca = 0, cb = 0;
    if(isavailable(timestamps[0], timestamps[1], timestamps[2], timestamps[3])){
        ab = 1;
    }
    if(isavailable(timestamps[0], timestamps[1], timestamps[4], timestamps[5])){
        ac = 1;
    }
    if(isavailable(timestamps[2], timestamps[3], timestamps[0], timestamps[1])){
        ba = 1;
    }
    if(isavailable(timestamps[2], timestamps[3], timestamps[4], timestamps[5])){
        bc = 1;
    }
    if(isavailable(timestamps[4], timestamps[5], timestamps[2], timestamps[3])){
        cb = 1;
    }
    if(isavailable(timestamps[4], timestamps[5], timestamps[0], timestamps[1])){
        ca = 1;
    }
    if(ab == 1 && ac == 1){ printf("Can change to both B and C from A.\n");}
    else if(ab == 0 && ac == 0){printf("No changes available from train A.\n");}
    else if(ab == 1 && ac == 0){printf("Can change to B from A.\n");}
    else{ printf("Can change to C from A.\n");}

    if(ba == 1 && bc == 1){ printf("Can change to both A and C from B.\n");}
    else if(ba == 0 && bc == 0){printf("No changes available from train B.\n");}
    else if(ba == 1 && bc == 0){printf("Can change to A from B.\n");}
    else{printf("Can change to C from B.\n");}

    if(ca == 1 && cb == 1){ printf("Can change to both A and B from C.\n");}
    else if(ca == 0 && cb == 0){printf("No changes available from train C.\n");}
    else if(ca == 1 && cb == 0){printf("Can change to A from C.\n");}
    else{printf("Can change to B from C.\n");}
    



    

    


    
    
    return 0;
}