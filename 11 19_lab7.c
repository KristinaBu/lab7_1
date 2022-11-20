

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

char d[] = "hello world";
char k[] = "good night";

//khoor {svph

void char_to_int(char* c) {
    *c = (int)*c;
}
void int_to_char(int* c) {
    *c = (char)*c;
}
/*
int code(int sdvig, int chb, int posit) {
    for (int ch = 0;ch <= chb;ch=ch+1) {
        char c = d[posit+ch];
        char_to_int(&c);
        c = c + sdvig;
        int_to_char(&c);
        printf("%c", c);

    }
    printf("\n");
    return 0;
}
*/

int main() {
    setlocale(LC_ALL, "Russian");

    int n = sizeof(k) - 1;
    int slovo = 0, kolvoSl=0,ksdvig=0,kolvoBu = 0;
    int *masSdvig=calloc(kolvoSl,sizeof(int)); //массив, в котором будут храниться сдвиги

 //побуквенно считываем ключ
    for (int i = 0;i < n;i++) {
        char vk = k[i];
        if (vk == ' ') { // граничный символ меж словами
            kolvoSl++;
            ksdvig = slovo/128;
            printf("sl %d sgv %d bukv %d\n",slovo, ksdvig,kolvoBu);
            masSdvig=realloc (masSdvig, kolvoSl*sizeof(int)); //изменяем длину массива для добавления сдвига
            masSdvig[kolvoSl-1]=ksdvig;
            slovo = 0;
            kolvoBu = 0;

        }
        else {
            char_to_int(&vk);
            slovo += vk;
            kolvoBu++;
            if(i == n-1){ //последний символ, конец строки
                kolvoSl++;
                ksdvig = (int)slovo/128;
                printf("sl %d sdv %d bukv %d\n",slovo, ksdvig,kolvoBu);
                masSdvig=realloc (masSdvig, kolvoSl*sizeof(int));//изменяем длину массива для добавления сдвига
                masSdvig[kolvoSl-1]=ksdvig;

                slovo = 0;
                kolvoBu = 0;
            }
        }
    }

    printf("mass sdv\n");
    for(int schet=0;schet<kolvoSl;schet++){
        printf("%d ",masSdvig[schet]);
    }
    printf("\n\nd\n");


    n=sizeof(d)-1;
    slovo = 0;
    kolvoBu = 0;
    for(int j=0;j<n;j++){
        char vd = d[j];
        if (vd == ' ') { // граничный символ меж словами
            printf("d sl %d bukv %d\n",slovo,kolvoBu);
            slovo = 0;
            kolvoBu = 0;

        }
        else {
            char_to_int(&vd);
            slovo += vd;
            kolvoBu++;
            if(j == n-1){ //последний символ, конец строки
                printf("d sl %d bukv %d\n",slovo, kolvoBu);
                slovo = 0;
                kolvoBu = 0;
            }
        }
    }
    return 0;
}




