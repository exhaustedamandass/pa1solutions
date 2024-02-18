#include <stdio.h>
#include <stdlib.h>


int isDuplicate = 0;

typedef struct{
    char* original;
    char* processed;
    size_t length;
}Word;
size_t tolowermine(size_t value){
    if(value >= 65 && value <= 90){
        return (value + 32);
    }
    return value;
}
void swap(Word *xp, Word *yp)
{
    Word temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int compareNew(const Word* word1, const Word* word2){
    size_t firstLength = word1->length - 1;
    size_t secondLength = word2->length - 1;
    char *tempa1 = word1->processed;
    char *tempa2 = word1->processed;
    char *tempb1 = word2->processed;
    char *tempb2 = word2->processed;
    int isNextWord1 = 0;
    int isNextWord2 = 0;
    while( ((*tempa1) != '\0' || (*tempb2) != '\0') && ((*tempb1) != '\0' || (*tempa2) != '\0')  ){
        if(!isNextWord1){
            if((*tempa1) == '\0'){
                isNextWord1 = 1;
            }
        }
        if(!isNextWord2){
            if((*tempb1) == '\0'){
                isNextWord2 = 1;
            }
        }
        if(isNextWord1 && isNextWord2){
            if( (*tempb2) < (*tempa2) ){
                return 1;
            }
            if( (*tempa2) < (*tempb2) ){
                return 0;
            }
            tempb2++;
            tempa2++;
        }else if(isNextWord1){
            if( (*tempb2) < (*tempb1) ){
                return 1;
            }
            if( (*tempb1) < (*tempb2) ){
                return 0;
            }
            tempb1++;
            tempb2++;
        }else if(isNextWord2){
            if( (*tempa1) < (*tempa2) ){
                return 1;
            }
            if( (*tempa2) < (*tempa1) ){
                return 0;
            }
            tempa1++;
            tempa2++;
        }else{
            if( (*tempa1) < (*tempb1) ){
                return 1;
            }
            if( (*tempb1) < (*tempa1) ){
                return 0;
            }
            tempa1++;
            tempb1++;
        }
    }
    if((*tempb2)  == '\0' && (*tempa2) == '\0' && firstLength == secondLength){
        isDuplicate = 1;
        return 0;
    }
        return (firstLength > secondLength) ? 0 : 1;

}
void merge(Word* arr, size_t l, size_t m, size_t r) {
    size_t i, j, k;
    size_t n1 = m - l + 1;
    size_t n2 = r - m;

    Word* L = (Word*)malloc(n1 * sizeof(Word));
    Word* R = (Word*)malloc(n2 * sizeof(Word));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (!compareNew(&L[i], &R[j])) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(Word* arr, size_t l, size_t r) {
    if (l < r) {
        size_t m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}


int main(){
    printf("Words:\n");
    int ch;
    size_t countWords = 0;
    size_t capacityWords = 100;
    Word* words = (Word*)malloc(capacityWords * sizeof(Word));
    while(EOF!=(ch=fgetc(stdin))){
        if(ch == ' ' || ch == '\n' || ch == '\t'){
            continue;
        }
        size_t countIndex = 0;
        size_t currentWordCapacity = 5000;
        words[countWords].original = (char*)malloc(currentWordCapacity * sizeof(char));
        words[countWords].processed = (char*)malloc(currentWordCapacity * sizeof(char));
        words[countWords].original[countIndex] = ch;
        words[countWords].processed[countIndex] = tolowermine(ch);
        countIndex++;
        while (EOF!=(ch=fgetc(stdin)) && ch != ' ' && ch != '\n' && ch != '\t')
        {
            words[countWords].original[countIndex] = ch;
            words[countWords].processed[countIndex] = tolowermine(ch);
            countIndex++;
            if(countIndex + 2 >= currentWordCapacity){
                currentWordCapacity *= 2;
                words[countWords].original = (char*)realloc(words[countWords].original, currentWordCapacity * sizeof(char));
                words[countWords].processed = (char*)realloc(words[countWords].processed, currentWordCapacity * sizeof(char));
            }
        }
        words[countWords].processed[countIndex] = '\0';
        words[countWords].original[countIndex] = '\0';
        countIndex++;
        words[countWords].length = countIndex;
        countWords++;
        if(countWords + 2 >= capacityWords){
            capacityWords *= 2;
            words = (Word*)realloc(words, capacityWords * sizeof(Word));
        }
    }
    if(countWords == 0){
        printf("Invalid input.\n");
        free(words);
        return 0;
    }
    mergeSort(words, 0, countWords - 1);
    if(isDuplicate){
        printf("Invalid input.\n");
        for (size_t i = 0; i < countWords; i++)
        {
            free(words[i].original);
            free(words[i].processed);
        }
        free(words);
        return 0;
    }
    int wordLength = 0;
    int sum = 0;
    for (size_t i = 0; i < countWords; i++)
    {
        wordLength = words[i].length - 1;
        if(wordLength > 80 && sum == 0){
            printf("%s\n", words[i].original);
            sum = 0;
            continue;
        }
        if(wordLength > 80){
            if(sum == 0){
                printf("%s\n", words[i].original);
                sum = 0;
                continue;
            }else if(sum != 0){
                printf("\n%s\n", words[i].original);
                sum = 0;
                continue;
            }
        }else{
            if(sum == 0){
                printf("%s", words[i].original);
                sum = wordLength;
                continue;
            }else if(sum != 0 && sum + wordLength + 1 <= 80){
                printf(" %s", words[i].original);
                sum += (wordLength + 1);
                continue;
            }else if(sum != 0 && sum + wordLength + 1 > 80){
                printf("\n%s", words[i].original);
                sum=wordLength;
                continue;
            }
        }
    }
    if(sum != 0){
        printf("\n");
    }
    for (size_t i = 0; i < countWords; i++)
        {
            free(words[i].original);
            free(words[i].processed);
        }
        free(words);
    return 0;
}