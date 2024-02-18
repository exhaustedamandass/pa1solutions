#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point2D{
    int x;
    int y;
    int radius;
    int cantrack;
};

int isPointWithinRadius(int x1, int y1, int x2, int y2, int radius) {
    // Calculate the distance between the two points using the distance formula
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    // Check if the distance is less than or equal to the radius
    if (distance <= radius) {
        return 1; // Point is within the radius
    } else {
        return 0; // Point is outside the radius
    }
}


struct point2D* increaseArraySize(struct point2D *arr, int *n) {
    struct point2D *newArr = (struct point2D*)realloc(arr, (*n + *n) * sizeof(struct point2D));
    *n += *n;   
    return newArr;
}

int main(void){
    int nTargets = 5;
    int nRadars = 5;
    struct point2D* targets = (struct point2D*)calloc(nTargets, sizeof(struct point2D));
    struct point2D* radars = (struct point2D*)calloc(nRadars, sizeof(struct point2D));
    int countTargets = 0;
    int countRadars = 0;
    double tempdoublex = 0, tempdoubley = 0, tempdoubleradius = 0;
    char tempchar; 
    printf("List of targets and radars:\n");
    while(scanf(" %c ", &tempchar) == 1){
        if(tempchar != 'R' && tempchar != 'T'){
            if(feof(stdin)){
                break;
            }
            free(targets); 
            free(radars);
            printf("Invalid input.\n");
            return 0;
        }
        if(tempchar == 'R'){
           if(scanf("%lf %lf %lf", &tempdoublex, &tempdoubley, &tempdoubleradius) != 3 || tempdoubleradius <= 0 ||
           tempdoublex != (int)tempdoublex || tempdoubley != (int)tempdoubley || tempdoubleradius != (int)tempdoubleradius){
                free(targets); 
                free(radars);
                printf("Invalid input.\n");
                return 0;
           } 
        }else{
            if(scanf("%lf %lf", &tempdoublex, &tempdoubley) != 2 || tempdoublex != (int)tempdoublex || tempdoubley != (int)tempdoubley){
                free(targets); 
                free(radars);
                printf("Invalid input.\n");
                return 0;
            }
        }
        if(tempchar == 'R'){
            radars[countRadars].x = (int)tempdoublex;
            radars[countRadars].y = (int)tempdoubley;
            radars[countRadars].radius = (int)tempdoubleradius;
            radars[countRadars].cantrack = 0;
            countRadars++;
            //printf("count radar %d total %d\n", countRadars, nRadars);
            if(countRadars + 2 == nRadars){
                radars = increaseArraySize(radars, &nRadars);
            }
        }else{
            targets[countTargets].x = (int)tempdoublex;
            targets[countTargets].y = (int)tempdoubley;
            targets[countTargets].cantrack = 0;
            targets[countTargets].radius = 0;
            countTargets++;
            //printf("count target %d total %d\n", countTargets, nTargets);
            if(countTargets + 2 == nTargets){
                targets = increaseArraySize(targets, &nTargets);
            }
        }
    }
    printf("Coverage:\n");
    for (int i = 0; i < countRadars; i++)
    {
        for (int j = 0; j < countTargets; j++)
        {
            if(isPointWithinRadius(radars[i].x, radars[i].y, targets[j].x,
            targets[j].y, radars[i].radius ) == 1){
                radars[i].cantrack++;
            }
        }
        printf("Radar #%d: %d\n", i, radars[i].cantrack);
    }
    free(targets); 
    free(radars);
    

}
