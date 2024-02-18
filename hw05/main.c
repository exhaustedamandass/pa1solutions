#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct review{
    int year, month, day;
    int rating;
    char str[4096];
};

struct blockReview{
    int startIndex, endIndex;
    int* m_ratings;
    double avgRating;
    int countRatings;
    int nRatings;
};

struct Interval{
    int startIndex, endIndex;
    double avgRating;
    int median;
    double diffavgmedian;
};

int isleapyear(int year){
  if((year % 4==0 && year%100 !=0) || (year%400==0 && year%4000!=0)){
    return 1;    
  }else{
    return 0;
  }
}
int is31days(int m){
        if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 1;
        return 0;
}
int isValidSub(int year, int month, int day){
  if(year < 1800 || year > 3000 || month < 1 || month > 12 || day < 1|| (is31days(month) && day > 31 && month != 2) || (isleapyear(year) && month == 2 && day > 29) || (!isleapyear(year) && month == 2 && day > 28) || (!is31days(month) && day > 30 && month != 2)){
    return 0;
  }
  return 1;
}
int isInValid(int y2, int y1, int m2, int m1, int d2, int d1){
    if (y1 == y2 && m1 == m2 && d1 == d2)
    {
        return -1;
    }
    if(y1 > y2 || (y1 == y2 && m1 > m2) || (y1 == y2 && m1 == m2 && d1 > d2)){
        return 1;
        //false case
    }
    return 0;
    //true case
}
int daysmonth( int y, int m){
  switch (m)
  {
  case 2:
    return 28 + isleapyear(y);
    break;
  default:
    return 30 + is31days(m);
    break;
  }
}

struct review* increaseArraySizeReview(struct review *arr, int *n) {
    *n += 10;   
    struct review *newArr = (struct review*)realloc(arr, *n * sizeof(struct review));
    return newArr;
}
int* increaseArraySizeRating(int *arr, int *n){
    *n += 10;   
    int* newArr = (int*)realloc(arr, *n * sizeof(int));
    return newArr;
}

struct blockReview* increaseArraySizeBlock(struct blockReview* arr, int *n) 
{
    *n += 10;
    struct blockReview* newArr = (struct blockReview*)realloc(arr, (*n) * sizeof(struct blockReview));
    return newArr;
}

void insertSorted(int arr[], int *size, int num) {
    int i = *size - 1;
    //printf("num %d, size %d\n", num, *size);
    while (i >= 0 && arr[i] > num) {
        arr[i + 1] = arr[i];
        i--;
    }

    arr[i + 1] = num;
    (*size)++;
}
int getMedian1(int arr[], int n){
    if(n % 2 == 0){
        return arr[(n/2) - 1];
    }
    return arr[(n/2)];
}

int getMedian2(int ar1[], int ar2[], int n, int m)
{
    int i = 0; 
    int j = 0;
    int count;
    int m1 = -1, m2 = -1;
    for (count = 0; count <= (m + n) / 2; count++) {
        m2 = m1;
        if (i != n && j != m) {
            m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
        }
        else if (i < n) {
            m1 = ar1[i++];
        }
        else {
            m1 = ar2[j++];
        }
    }
    if ((m + n) % 2 == 1) {
        return m1;
    }
    else {
        return m2;
    }
}

int compareDoubles(double a, double b, double epsilon) {
    return fabs(a - b) < epsilon;
}
int compareEndDates(struct review *arr, int index1, int index2){
    if(isInValid(arr[index1].year, arr[index2].year, arr[index1].month, arr[index2].month, arr[index1].day, arr[index2].day)){
        return -1;        
    }
    if(arr[index1].year == arr[index2].year && arr[index1].month == arr[index2].month && arr[index1].day == arr[index2].day){
        return 0;
    }
    return 1;
}
int compareDates(int y1, int y2, int m1, int m2, int d1, int d2) {
    if (y1 == y2 && m1 == m2 && d1 == d2) {
        return 0;
    } else if (y1 > y2 || (y1 == y2 && m1 > m2) || (y1 == y2 && m1 == m2 && d1 > d2)) {
        return 1;
    } else {
        return -1;
    }
}


void mergeArrays(int arr1[], int arr2[], int n1,
                             int n2)
{
    int i = n1 - 1, j = n2 - 1, k = n1 + n2 - 1;
    while (i >= 0 && j >= 0) {
        if (arr1[i] > arr2[j]) {
            arr1[k--] = arr1[i--];
        } else {
            arr1[k--] = arr2[j--];
        }
    }
    while (j >= 0) {
        arr1[k--] = arr2[j--];
    }
}

struct Interval findInterval(struct blockReview* arr, int *n, int k, struct review* reviewsArr){
    struct Interval intervalres;
    intervalres.avgRating = 0;
    intervalres.endIndex = -1;
    intervalres.startIndex = -1;
    intervalres.median = 0;
    intervalres.diffavgmedian = -2147483648;
    for (int i = 0; i <= (*n); i++)
    {
        if(k > arr[i].countRatings){
            continue;
        }
        int mediantmp = getMedian1(arr[i].m_ratings, arr[i].countRatings);
        double diffavgmedian = fabs(mediantmp - arr[i].avgRating);
        if(intervalres.diffavgmedian < diffavgmedian){
            intervalres.avgRating = arr[i].avgRating;
            intervalres.startIndex = arr[i].startIndex;
            intervalres.endIndex = arr[i].endIndex;
            intervalres.diffavgmedian = diffavgmedian;
            intervalres.median = mediantmp;
        }else if(compareDoubles(intervalres.diffavgmedian, diffavgmedian, 1e-9)){
                int ret = compareDates(reviewsArr[intervalres.endIndex].year, reviewsArr[arr[i].endIndex].year, reviewsArr[intervalres.endIndex].month, reviewsArr[arr[i].endIndex].month, reviewsArr[intervalres.endIndex].day, reviewsArr[arr[i].endIndex].day);
                if(ret == -1 ){
                    intervalres.avgRating = arr[i].avgRating;
                    intervalres.startIndex = arr[i].startIndex;
                    intervalres.endIndex = arr[i].endIndex;
                    intervalres.diffavgmedian = diffavgmedian;
                    intervalres.median = mediantmp; 
                }else if(ret == 0){
                    if((intervalres.endIndex - intervalres.startIndex + 1) < arr[i].countRatings){
                        intervalres.avgRating = arr[i].avgRating;
                        intervalres.startIndex = arr[i].startIndex;
                        intervalres.endIndex = arr[i].endIndex;
                        intervalres.diffavgmedian = diffavgmedian;
                        intervalres.median = mediantmp; 
                    }
                }
            }
    }
    //printf("intervalres avg : %lf, end : %d , start : %d , median : %d, diff : %lf\n", intervalres.avgRating, intervalres.endIndex, intervalres.startIndex, intervalres.median, intervalres.diffavgmedian);
    for (int i = 0; i < (*n); i++) 
    {
        int* firstarr = (int*)calloc(arr[i].countRatings, sizeof(int));
        for (int j = 0; j < arr[i].countRatings; j++)
        {   
            firstarr[j] = arr[i].m_ratings[j];
        }
        int size = arr[i].countRatings;
        double average = arr[i].avgRating;
        for (int j = i + 1; j <= (*n); j++)
        {
            if(j > i + 1){
                firstarr = (int*)realloc(firstarr, (size + arr[j-1].countRatings)*sizeof(int));
                mergeArrays(firstarr, arr[j-1].m_ratings, size, arr[j-1].countRatings);
                size += arr[j-1].countRatings;
            }
            average = ((average * size)+(arr[j].avgRating * arr[j].countRatings))/(size + arr[j].countRatings);
            if(size + arr[j].countRatings < k){
                continue;
            }
            int mediantmp = getMedian2(firstarr, arr[j].m_ratings, size, arr[j].countRatings);
            double diffavgmedian = fabs(mediantmp - average);
            if(intervalres.diffavgmedian < diffavgmedian){
                intervalres.avgRating = average;
                intervalres.startIndex = arr[i].startIndex;
                intervalres.endIndex = arr[j].endIndex;
                intervalres.diffavgmedian = diffavgmedian;
                intervalres.median = mediantmp;
            }else if(compareDoubles(intervalres.diffavgmedian, diffavgmedian, 1e-9)){
                int ret = compareDates(reviewsArr[intervalres.endIndex].year, reviewsArr[arr[j].endIndex].year, reviewsArr[intervalres.endIndex].month, reviewsArr[arr[j].endIndex].month, reviewsArr[intervalres.endIndex].day, reviewsArr[arr[j].endIndex].day);
                if(ret == -1 ){
                    intervalres.avgRating = average;
                    intervalres.startIndex = arr[i].startIndex;
                    intervalres.endIndex = arr[j].endIndex;
                    intervalres.diffavgmedian = diffavgmedian;
                    intervalres.median = mediantmp; 
                }else if(ret == 0){
                    if((intervalres.endIndex - intervalres.startIndex + 1) < size + arr[j].countRatings){
                        intervalres.avgRating = average;
                        intervalres.startIndex = arr[i].startIndex;
                        intervalres.endIndex = arr[j].endIndex;
                        intervalres.diffavgmedian = diffavgmedian;
                        intervalres.median = mediantmp; 
                    }
                }
            }
        }
        free(firstarr);
    }
    return intervalres;
}

int main ( void )
{
    int nReviews = 10;
    int tmpyear, tmpyearprev = 0,  tmpmonth, tmpmonthprev = 0, tmpday, tmpdayprev = 0,  numReviews;
    double tmpRating;
    char tmp;
    char name[4097];
    int countReviews = 0;
    struct review* reviews = (struct review*)calloc(nReviews, sizeof(struct review));

    int nBlocks = 10;
    int countBlock = 0;
    struct blockReview* blocks = (struct blockReview*)calloc(nBlocks, sizeof(struct blockReview));

    blocks[0].nRatings = 10;
    blocks[0].avgRating = 0;
    blocks[0].m_ratings = (int*)calloc(blocks[0].nRatings, sizeof(int)); 
    blocks[0].startIndex = -1;
    blocks[0].endIndex = -1;
    blocks[0].countRatings = 0;
    printf("Reviews:\n");
    while(scanf(" %c ", &tmp) == 1){
        if(tmp == '+'){
            if(scanf(" %d - %d - %d %lf %4096s ", &tmpyear, &tmpmonth, &tmpday, &tmpRating, name ) != 5 || tmpRating < 1 || !isValidSub(tmpyear, tmpmonth, tmpday)){
                printf("Invalid input.\n");
                free(reviews);
                return 0;    
            }
            if(countReviews >= 1){
                int res;
                if((res = isInValid(tmpyear, tmpyearprev, tmpmonth, tmpmonthprev, tmpday, tmpdayprev)) == 1){
                    printf("Invalid input.\n");
                    free(reviews);
                    for (int i = 0; i < countBlock; i++)
                    {
                        free(blocks[i].m_ratings);
                    }
                    free(blocks);
                    return 0;
                }
                if(res == -1){
                    struct review reviewtmp; 
                    reviewtmp.year = tmpyear;
                    reviewtmp.month = tmpmonth;
                    reviewtmp.day = tmpday;
                    reviewtmp.rating = tmpRating;
                    strcpy(reviewtmp.str, name);
                    reviews[countReviews] = reviewtmp;
                    blocks[countBlock].endIndex = countReviews;
                    insertSorted(blocks[countBlock].m_ratings, &blocks[countBlock].countRatings, tmpRating);
                    blocks[countBlock].avgRating = ((blocks[countBlock].avgRating * (blocks[countBlock].countRatings - 1)) + tmpRating)/blocks[countBlock].countRatings;
                    if(blocks[countBlock].countRatings + 2 == blocks[countBlock].nRatings){
                        blocks[countBlock].m_ratings = increaseArraySizeRating(blocks[countBlock].m_ratings, &blocks[countBlock].nRatings);
                    }

                    if(countReviews + 2 > nReviews){
                        reviews = increaseArraySizeReview(reviews, &nReviews);
                    }
                }else{
                    countBlock++;
                    struct review reviewtmp; 
                    reviewtmp.year = tmpyear;
                    reviewtmp.month = tmpmonth;
                    reviewtmp.day = tmpday;
                    reviewtmp.rating = tmpRating;
                    strcpy(reviewtmp.str, name);
                    blocks[countBlock].nRatings = 10;
                    reviews[countReviews] = reviewtmp;
                    blocks[countBlock].avgRating = tmpRating;
                    blocks[countBlock].m_ratings = (int*)calloc(blocks[countBlock].nRatings, sizeof(int)); 

                    blocks[countBlock].m_ratings[0] = tmpRating;

                    blocks[countBlock].startIndex = countReviews;
                    blocks[countBlock].endIndex = countReviews;
                    blocks[countBlock].countRatings = 1;
                    if(countBlock + 2 > nBlocks){
                        blocks = increaseArraySizeBlock(blocks, &nBlocks);
                    }
                }
            }else{
                struct review reviewtmp; 
                reviewtmp.year = tmpyear;
                reviewtmp.month = tmpmonth;
                reviewtmp.day = tmpday;
                reviewtmp.rating = tmpRating;
                strcpy(reviewtmp.str, name);
                reviews[countReviews] = reviewtmp;
                blocks[0].avgRating = tmpRating;
                blocks[0].startIndex = 0;
                blocks[0].endIndex = 0;
                blocks[0].m_ratings[0] = tmpRating;
                blocks[0].countRatings = 1;
            }
            countReviews++;
            tmpdayprev = tmpday;
            tmpmonthprev = tmpmonth;
            tmpyearprev = tmpyear;
        }else if(tmp == '?'){
            if(scanf(" %d ", &numReviews) != 1 || countReviews == 0 || numReviews <=0 ){
                printf("Invalid input.\n");
                free(reviews);
                for (int i = 0; i < countBlock; i++)
                {
                    free(blocks[i].m_ratings);
                }
                free(blocks);
                return 0;
            }
            if(numReviews > countReviews){
                printf("No interval.\n");
            }else{
                struct Interval res = findInterval(blocks, &countBlock, numReviews, reviews);    
                printf("%d-%02d-%d - %d-%02d-%d: %lf %d\n", reviews[res.startIndex].year, reviews[res.startIndex].month, reviews[res.startIndex].day, reviews[res.endIndex].year, reviews[res.endIndex].month, reviews[res.endIndex].day, res.avgRating, res.median);
                for (int i = res.startIndex; i <= res.endIndex; i++)
                {
                    printf("  %d: %s\n", reviews[i].rating, reviews[i].str );
                }
            }
        }else if(tmp == '#'){
            if(scanf(" %d ", &numReviews) != 1 || countReviews == 0 || numReviews <=0 ){
                printf("Invalid input.\n");
                for (int i = 0; i < countBlock; i++)
                {
                    free(blocks[i].m_ratings);
                }
                free(blocks);
                free(reviews);
                return 0;
            }
            if(numReviews > countReviews){
                printf("No interval.\n");
            }
            struct Interval res = findInterval(blocks, &countBlock, numReviews, reviews);    
            printf("%d-%02d-%d - %d-%02d-%d: %lf %d\n", reviews[res.startIndex].year, reviews[res.startIndex].month, reviews[res.startIndex].day, reviews[res.endIndex].year, reviews[res.endIndex].month, reviews[res.endIndex].day, res.avgRating, res.median);
        }else{
            printf("Invalid input.\n");
            for (int i = 0; i < countBlock; i++)
            {
                free(blocks[i].m_ratings);
            }
            free(blocks);
            free(reviews);
            return 0;
        }
    }
    for (int i = 0; i < countBlock; i++)
    {
        free(blocks[i].m_ratings);
    }
    free(blocks);
    
    
    free(reviews);
}
