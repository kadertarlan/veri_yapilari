/* 
 * File:   main.c
 * Author: BMB
 *
 * Created on 24 Eylül 2013 Salı, 13:00
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void matris_carpimi(int A[][3], int A_satir, int A_sutun,
                    int B[][2], int B_satir,int B_sutun,
                    int C[][2],int C_satir, int C_sutun){
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

void matris_yaz(int A[][2], int satir){
    int i,j;
    for(i=0; i<satir; i++){
        for(j=0; j<2; j++) printf("%3d ",A[i][j]);
        printf("\n");
    }
}

int main(int argc, char** argv) {
    int A[][3]={{1,0,2},{2,1,4},{5,1,0},{0,2,3}};
    int B[][2]={{0,1},{2,4},{3,1}};
    int C[4][2];
    
    matris_carpimi(A,4,3,B,3,2,C,4,2);
    
    matris_yaz(C,4);
    return (EXIT_SUCCESS);
}

