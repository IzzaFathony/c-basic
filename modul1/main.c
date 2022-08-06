#include <stdio.h>

int main() {
    int progdas, kalkulus, pti, orkom;
    float rata;
    
    printf("Masukkan Nilai Progdas\t: ");
    scanf("%d", &progdas);
    printf("Masukkan Nilai Kalkulus\t: ");
    scanf("%d", &kalkulus);
    printf("Masukkan Nilai PTI\t\t: ");
    scanf("%d", &pti);
    printf("Masukkan Nilai Orkom\t: ");
    scanf("%d", &orkom);
    
    rata = (progdas + kalkulus + pti + orkom) / 4;
    
    if(rata >= 75) {
        printf("LULUS");
    } else {
        printf("TIDAK LULUS");
    }

    return 0;
}