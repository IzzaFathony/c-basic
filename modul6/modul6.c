#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>


struct Data{

    char nim[19];
    char name[125];
    char clas[10];
    char dosen[125];
    int status;
};

struct Data user[100];
int length = 0;

void __filterName(char n[]){

    char *token;
    char tmp[125] = "";
    int max = 1;

    token = strtok(n, " ");

    while(token != NULL){

        if(max < 3){
            strcat(tmp, token);
            ++max;
        }else {
            break;
        }
        token = strtok(NULL, " ");
    }

    strcpy(n, tmp);
}

int __filterNim(char n[]){
    int maxNim = 17;
    int lengthNim = strlen(n);

    for(int i = 0; i != 2; i++){
        n[i] = toupper(n[i]);
    }

    if(n[0] != 'I' && n[1] != 'F'){
        return 0;
    }

    if(maxNim != lengthNim){
        return 0;
    }

    for(int i = 0; i < length; i++){
        if(strcmp(user[i].nim, n) == 0 && user[i].status == 1){
            return 1;
        }
    }

    return 2;
}

void __filterClass(char n[]){
    int max = strlen(n);

    for(int i = 0; i < max; i++){
        n[i] = toupper(n[i]);
    }
}

int getIndex(char n[]){
    for(int i = 0; i < length; i++){
        if(strcmp(user[i].nim, n) == 0 && user[i].status == 1){
            return i;
        }
    }

    return -1;

}

void editData(int index){
    printf("[ ] EDIT DATA [ ]\n");
    printf("Masukan Nama    : "); scanf(" %[^\n]s", user[index].name);

    //Filter
    __filterName(user[index].name);
    fflush(stdin);
    printf("Masukan Kelas   : "); scanf(" %[^\n]s", user[index].clas);

    //Filter
    __filterClass(user[index].clas);

    printf("Masukan Dosen   : "); scanf(" %[^\n]s", user[index].dosen);

    printf("========================\n");
    printf("Berhasil menggedit data\n");
}

void __delete(int index){
    user[index].status = 0;
    printf("========================\n");
    printf("Berhasil menghapus data\n");
}

void __save(){
    FILE *fp;

    remove("db.txt");
    fp = fopen("db.txt", "a");

    for(int i = 0; i < length; i++){
        if(user[i].status == 1){
            fprintf(fp, user[i].name);
            fprintf(fp, ",");

            fprintf(fp, user[i].nim);
            fprintf(fp, ",");

            fprintf(fp, user[i].clas);
            fprintf(fp, ",");

            fprintf(fp, user[i].dosen);
            fprintf(fp, ",");
        }
    }

    fclose(fp);
}

void __getData(){
    FILE *fp;
    char tmp[10000];
    char *token;
    int numbering = 1;
    fp = fopen("db.txt", "r");

    fgets(tmp, 10000, fp);

    token = strtok(tmp, ",");

    while(token != NULL){
        if(numbering == 1){
            strcpy(user[length].name, token);
            ++numbering;
        }else  if(numbering == 2){
            strcpy(user[length].nim, token);
            ++numbering;
        }else  if(numbering == 3){
            strcpy(user[length].clas, token);
            ++numbering;
        }else {
            strcpy(user[length].dosen, token);
            user[length].status = 1;
            numbering = 1;
            ++length;
        }

        token = strtok(NULL, ",");
    }
}

int main(){
    int menu;
    int menuSearch;
    int no;
    char nim[19];

     __getData();

    up:

    printf("=== Menu ===\n");
    printf("1. Creat\n");
    printf("2. Show\n");
    printf("3. Search\n");
    printf("4. Exit\n\n");

    printf("Pilih Menu : "); scanf("%d", &menu);

    printf("========================\n");

    switch(menu){
    case 1:
        printf("[ ] CREAT DATA [ ]\n");
        printf("Masukan Nama    : "); scanf(" %[^\n]s", user[length].name);

        //Filter
        __filterName(user[length].name);

        nim:
        printf("Masukan NIM     : "); scanf(" %s", user[length].nim);

        //Filter
        if(__filterNim(user[length].nim) == 0){
            printf("Format nim tidak sesuai!\n");
            Sleep(2000);
            goto nim;
        }else if(__filterNim(user[length].nim) == 1){
            printf("Nim sudah ada!\n");
            Sleep(2000);
            goto nim;
        }

        printf("Masukan Kelas   : "); scanf(" %[^\n]s", user[length].clas);

        //Filter
        __filterClass(user[length].clas);

        printf("Masukan Dosen   : "); scanf(" %[^\n]s", user[length].dosen);

        user[length].status = 1;
        ++length;
        break;
    case 2:
        for(int i = 0; i < length; i++){
            if(user[i].status == 1){
                printf("=== User %d ===\n", ++no);
                printf("Nama       : %s\n", user[i].name);
                printf("NIM        : %s\n", user[i].nim);
                printf("Kelas      : %s\n", user[i].clas);
                printf("Dosen      : %s\n", user[i].dosen);
            }
        }

        no = 0;
        break;
    case 3:
        nims:
        printf("Masukan NIM yang ingin di cari : "); scanf(" %s", nim);
        printf("========================\n");
        //Filter
        if(__filterNim(nim) == 0){
            printf("Format nim tidak sesuai!\n");
            Sleep(2000);
            goto nims;
        }else if(__filterNim(nim) == 1){

            int i = getIndex(nim);
            printf("Nama       : %s\n", user[i].name);
            printf("NIM        : %s\n", user[i].nim);
            printf("Kelas      : %s\n", user[i].clas);
            printf("Dosen      : %s\n", user[i].dosen);
            printf("========================\n");
            printf("1. Edit\n");
            printf("2. Delete\n\n");
            printf("Pilih Menu : "); scanf("%d", &menuSearch);

            switch(menuSearch){
            case 1:
                editData(i);
                break;
            case 2:
                __delete(i);
                break;
            default:
                break;
            }
        }else {
            printf("Nim tidak ditemukan!\n");
            Sleep(2000);
            goto nims;
        }
        break;
    case 4:
        system("cls");
        printf("Menutup program.....\n\n\n");
        __save();
        return 0;
        break;
    default:
        break;
    }

    fflush(stdin);
    printf("========================\n");
    printf("Klik enter untuk kembali ke menu"); getchar();
    system("cls");
    goto up;

}
