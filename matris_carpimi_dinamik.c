/* 
 * File:   main.c
 * Author: BMB
 *
 * Created on 24 Eylül 2013 Salı, 13:35
 */

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

/*
 * 
 */

void matris_olustur_dinamik(int ***dizi,int satir,int sutun){
    int i,j;
    *dizi=(int**)malloc(satir*sizeof(int*));
    for(i=0; i<satir; i++) 
         (*dizi)[i]=(int*)malloc(sutun*sizeof(int));
    
    srand(time(NULL));
    for(i=0; i<satir; i++)
        for(j=0; j<sutun; j++)
           (*dizi)[i][j]=rand()%10; 
           
}

void matris_yaz_dinamik(int **dizi,int satir,int sutun){
    int i,j;
    for(i=0; i<satir; i++){
        for(j=0; j<sutun; j++) printf("%4d ",*(*(dizi+i)+j));
        printf("\n");
    }
}

void matris_carpimi_dinamik(int **A,int A_satir, int A_sutun,
                           int **B, int B_satir, int B_sutun,
                           int **C, int C_satir, int C_sutun){
    
    
    int i,j,k;
    if(A_sutun!=B_satir){
        printf("Carpim matrislerinin boyutlari uyusmuyor!!!");
        return;
    }
    else if(A_satir!=C_satir || B_sutun!=C_sutun){
        printf("Sonuc matrisinin boyutlari carpan matrislere uymuyor!!!\n");
        return;
    }
    else{
        for(i=0; i<A_satir; i++)
            for(j=0; j<B_sutun; j++){
                C[i][j]=0;
                for(k=0; k<A_sutun; k++)
                    C[i][j]=C[i][j]+A[i][k]*B[k][j];
                    
            }   
    }
}

int main(int argc, char** argv) {
    int **A,**B,**C;
    matris_olustur_dinamik(&A,5,6);
    matris_olustur_dinamik(&B,6,7);
    matris_olustur_dinamik(&C,5,7);
    printf("--- A matrisi ----\n");
    matris_yaz_dinamik(A,5,6);
    printf("--- B matrisi ----\n");
    matris_yaz_dinamik(B,6,7);
    printf("--- C matrisi ----\n");
    matris_yaz_dinamik(C,5,7);
    matris_carpimi_dinamik(A,5,6,B,6,7,C,5,7);
    printf("---- C=A*B matrisi ----\n");
    matris_yaz_dinamik(C,5,7);
    
    
    return (EXIT_SUCCESS);
}

