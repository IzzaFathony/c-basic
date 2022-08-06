#include <stdio.h>
#include <stdlib.h>

int main(void) {

    char repeat;
    int all_total, pay, less_pay, main, total1, total2, total3, total_item, total_menu, option, repeated = 1, wrong_menu;

    while (repeated == 1) {
        all_total = 0;
        total1 = 0, total2 = 0, total3 = 0;
        printf("~~~~~ WARUNG MOZZA ~~~~~\n\n");
        printf("Silakan dipilih MENUnya kak :\n\n");
        printf("No.\tNama Menu\tHarga\n");
        printf("1.\tNasi Pecel\tRp15.000\n");
        printf("2.\tNasi Goreng\tRp10.000\n");
        printf("3.\tEs Jeruk\tRp2.500\n\n");

        printf("Silakan memasukkan jumlah menu yang ingin dipesan : ");
        scanf("%d", &total_menu);

        printf("\n");

        for (int i = 1; i <= total_menu; i++) {
            wrong_menu:
            printf("==============================\n");
            printf("Silakan pilih menu ke-%d : ", i);
            scanf("%d", &option);
            switch (option) {
                case 1:
                    printf("Anda memilih Nasi Pecel \n\n");
                    printf("Masukkan jumlah pesanan : ");
                    scanf("%d", &total_item);
                    printf("Jumlah : %d Nasi Pecel \n", total_item);
                    printf("------------------------------\n");
                    printf("Total Harga : %d \n\n", total1 += 15000*total_item);
                    all_total = total1;
                    break;
                case 2:
                    printf("Anda memilih Nasi Goreng \n\n");
                    printf("Masukkan jumlah pesanan : ");
                    scanf("%d", &total_item);
                    printf("Jumlah : %d Nasi Goreng\n", total_item);
                    printf("------------------------------\n");
                    printf("Total Harga : %d \n\n", total2 += 10000*total_item);
                    all_total = total2;
                    break;
                case 3:
                    printf("Anda memilih Es Jeruk \n\n");
                    printf("Masukkan jumlah pesanan : ");
                    scanf("%d", &total_item);
                    printf("Jumlah : %d Es Jeruk\n", total_item);
                    printf("------------------------------\n");
                    printf("Total Harga : %d \n\n", total3 += 2500*total_item);
                    all_total = total3;
                    break;
                default:
                    printf("Menu yang anda masukkan tidak ditemukan\n");
                    goto wrong_menu;
            }
        }

        do {
            printf("==============================\n");
            printf("Grand Total\t: %d\n", all_total);
            printf("Bayar\t\t: ");
            scanf("%d", &pay);
            
            if (pay >= all_total) {
                printf("Kembali\t\t: %d \n", pay - all_total);
                less_pay = 1;
            } else {
                printf("Maaf, uang anda tidak cukup\n");
                less_pay = 0;
            }
            printf("==============================\n\n");
        } while (less_pay == 0);

        printf("Apakah anda ingin menggunakan aplikasi kembali? (Y/N) : ");
        scanf(" %c", &repeat);

        if(repeat == 'y') {
            repeated = 1;
        } else {
            repeated = 0;
        }
    }

    return 0;
}