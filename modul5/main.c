#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct Data {
    char nim[15], name[50], class[15],  lecturer[50];

    int x;
};

struct Data Student[100];

int length = 0;

void create(){

    char nim[15], name[50], class[15], lecturer[50];

    printf("=== Create Data ===\n\n");

    printf("Input NIM Praktikan\t\t: IF2021-");
    scanf("%s", nim);fflush(stdin);

    printf("Input Nama Praktikan\t\t: ");
    scanf("%[^\n]s", name);fflush(stdin);

    printf("Input Kelas Pemrograman Dasar\t: Prodas ");
    scanf("%s", class);fflush(stdin);

    printf("Input Nama Dosen Pengampu\t: ");
    scanf("%[^\n]s", lecturer);fflush(stdin);

    int y = 0;

    for (int i = 0; i < length; i++){
        if (strcmp(Student[i].nim, nim) == 0){
            y = 1;
        }
    }

    if (y == 0){
        strcpy(Student[length].nim, nim);
        strcpy(Student[length].name, name);
        strcpy(Student[length].class, class);
        strcpy(Student[length].lecturer, lecturer);

        Student[length].x = 1;

        ++length;
        printf("-------------------------------\n");
        printf("DATA BERHASIL DITAMBAHKAN\n");
        printf("-------------------------------\n");
        system("pause");
    }else{
        printf("-------------------------------\n");
        printf("DATA GAGAL DITAMBAHKAN\n");
        printf("Karna NIM yang di inputkan SUDAH TERDATA\n");
        printf("-------------------------------\n");
        system("pause");
    }

    system("cls");
}

void read(){

    printf("=== List Data ===\n\n");

    int number = 1;

    for (int i = 0; i < length; i++){
        if (Student[i].x == 1){
            printf("== %d ==\n\n", number++);
            printf("NIM Praktikan\t\t: IF2021-%s\n", Student[i].nim);
            printf("Nama Praktikan\t\t: %s\n", Student[i].name);
            printf("Kelas Pemrograman Dasar\t: Prodas %s\n", Student[i].class);
            printf("Dosen Pengampu\t\t: %s\n", Student[i].lecturer);
            printf("\n----------------------\n\n");
        }
    }
    system("pause");
    system("cls");
}

void edit(){

    char nim[15];
    int cek = 0;

    printf("=== Update Data ===\n\n");

    goNIM:
    printf("Masukkan NIM Praktikan yang Ingin di Edit Datanya = IF2021-");
    scanf("%s", nim); fflush(stdin);

    for(int i = 0; i < length; i++){
        if(Student[i].x == 1 && strcmp(Student[i].nim, nim) == 0){
            printf("\n");
            printf("Nama Baru\t\t: ");
            scanf("%[^\n]s", Student[i].name);fflush(stdin);

            printf("Kelas Baru\t\t: Prodas ");
            scanf("%s", Student[i].class);fflush(stdin);

            fflush(stdin);
            printf("Dosen Pengampu Baru\t: ");
            scanf("%[^\n]s", Student[i].lecturer);fflush(stdin);

            printf("---------------------");
            printf("\nDATA BERHASIL DI EDIT");
            printf("\n---------------------\n");
            cek = 1;
        }
    }

    if(cek == 0){
        printf("---------------------");
        printf("\nDATA TIDAK DITEMUKAN");
        printf("\n---------------------\n");
        goto goNIM;
    }

    system("pause");
    system("cls");
}

void delete(){

    char nim[15];
    int cek = 0;

    printf("=== Delete Data ===\n\n");

    goNIM2:
    printf("Masukkan NIM Praktikan yang ingin di Delete Data nya : IF2021-");
    scanf("%s", nim);

    for (int i = 0; i < length; i++){
        if (Student[i].x == 1 && strcmp(Student[i].nim, nim) == 0){

            Student[i].x = 0;
            printf("------------------------");
            printf("\nDATA BERHASIL DIHAPUS");
            printf("\n----------------------\n");
            cek = 1;
        }
    }

    if( cek == 0 ){
        printf("------------------------");
        printf("\nDATA TIDAK DITEMUKAN");
        printf("\n----------------------\n");
        goto goNIM2;
    }

    system("pause");
    system("cls");
}

void search(){

    char nim[15];
    int cek = 0;

    printf("=== Search Data ===\n\n");

    goNIM3:
    printf("Masukkan NIM Praktikan : IF2021-");
    scanf("%s", nim); fflush(stdin);

    for (int i = 0; i < length; i++){
        if (Student[i].x == 1 && strcmp(Student[i].nim, nim) == 0){
            printf("\n");
            printf("NIM Praktikan\t\t: IF2021-%s\n", Student[i].nim);
            printf("Nama Praktikan\t\t: %s\n", Student[i].name);
            printf("Kelas Pemrograman Dasar\t: Prodas %s\n", Student[i].class);
            printf("Dosen Pengampu\t\t: %s\n", Student[i].lecturer);
            cek = 1;
        }
    }

    if(cek == 0 ){
        printf("-------------------------");
        printf("\nDATA TIDAK DITEMUKAN");
        printf("\n---------------------\n");
        goto goNIM3;
    }

    system("pause");
    system("cls");
}

int main(void){

    int menu;

    goMenu:
    system("cls");
    printf("Sistem Pendataan Akun I-Lab Infotech\n\n");
    printf("=== Pilihan Menu ===\n\n");
    printf("1. Create Data.\n");
    printf("2. Show Data.\n");
    printf("3. Update Data.\n");
    printf("4. Delete Data.\n");
    printf("5. Search Data.\n");
    printf("6. Exit.\n\n");

    printf("Masukkan Pilihan : ");
    scanf("%d", &menu);
    system("cls");

    switch (menu){
    case 1:
        create();
        break;
    case 2:
        read();
        break;
    case 3:
        edit();
        break;
    case 4:
        delete();
        break;
    case 5:
        search();
        break;
    case 6:
        printf("=== Exit ===\n\n");
        return 0;
        break;
    default:
        printf("SALAH INPUT\n"); 
        system("pause");
        break;
    }

    goto goMenu;
}
