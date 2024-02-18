#include <stdio.h>

int main(void){
    int x;
    float y;
    char c;
    printf("ml' nob:\n");
    if(scanf("%d", &x) == 1){
        if(x > 8 || x < 0 ){
            printf("Qih mi' %d\n", x);
            return 0;
        }else {
            if(!feof(stdin) && (scanf("%f", &y) == 1 || scanf("%c", &c) == 1 )){
                printf("bIjatlh 'e' yImev\n");
                return 0;
            }
            printf("Qapla'\n");
            switch (x)
            {
            case 0:
                printf("noH QapmeH wo' Qaw'lu'chugh yay chavbe'lu' 'ej wo' choqmeH may' DoHlu'chugh lujbe'lu'.\n");
                break;
            case 1:
                printf("bortaS bIr jablu'DI' reH QaQqu' nay'.\n");
                break;
            case 2:
                printf("Qu' buSHa'chugh SuvwI', batlhHa' vangchugh, qoj matlhHa'chugh, pagh ghaH SuvwI''e'.\n");
                break;
            case 3:
                printf("bISeH'eghlaH'be'chugh latlh Dara'laH'be'.\n");
                break;
            case 4:
                printf("qaStaHvIS wa' ram loS SaD Hugh SIjlaH qetbogh loD.\n");
                break;
            case 5:
                printf("Suvlu'taHvIS yapbe' HoS neH.\n");
                break;
            case 6:
                printf("Ha'DIbaH DaSop 'e' DaHechbe'chugh yIHoHQo'.\n");
                break;
            case 7:
                printf("Heghlu'meH QaQ jajvam.\n");
                break;
            case 8:
                printf("leghlaHchu'be'chugh mIn lo'laHbe' taj jej.\n");
                break;
            default:
                break;
            }
        }
    }else{
        printf("Neh mi'\n");
        return 0;
    }
    return 0;
}