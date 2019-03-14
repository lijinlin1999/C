//
//  main.c
//  lab7
//
//  Created by Jack Lee on 8/3/2019.
//  Copyright © 2019 Jack Lee. All rights reserved.
//  edit with Xcode

#include <stdio.h>
#include <stdlib.h>
#define N 51
void matrix_power(int A[][N], int d, int n, int x, int res[][N]);
int main(int argc, const char * argv[]) {
    printf("Please input number:\n");
    int m;
    scanf("%d",&m);
    if(m >50)
    {
        fprintf(stderr,"dimension should not be larger 50");
        exit(1);
    }
    int A[N][N], res[N][N];
    for(int i = 0;i<m;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &(A[i][j]));
        }
    }
    for(int i = 0;i<m;i++){
        for(int j=0;j<m;j++){
            res[i][j] = 0;
        }
    }
    int n,x;
    scanf("%d %d", &n, &x);
    matrix_power(A, m, n, x,res);
    return 0;
}

void matrix_power(int A[][N], int d, int n, int x, int res[][N])
{
    if (n ==0){
        for(int i =0;i<d;i++){
            for(int j=0;j<d;j++){
                if(i==j)
                    printf("1 ");
                else
                    printf("0 ");
            }
            printf("\n");
        }
        return;
    }
    if(n==1){
        for(int i=0;i<d;i++){
            for(int j=0;j<d;j++){
                printf("%d ",A[i][j]%x);
            }
            printf("\n");
        }
        return;
    }
    if (n >= 2){
        for(int i =0;i<d;i++)
            for(int j=0;j<d;j++)
                for(int k =0;k<d;k++)
                    res[i][j] += (A[i][k]%x)*(A[k][j]%x);
    }
    if(n>=3){
        int temp[N][N];
        for(int p=2;p<n;p++){
            for(int i=0;i<d;i++)
                for(int j=0;j<d;j++)
                    temp[i][j] = res[i][j];
            for(int i=0;i<d;i++)
                for(int j=0;j<d;j++)
                    res[i][j]=0;
            for(int i =0;i<d;i++)
                for(int j=0;j<d;j++)
                    for(int k =0;k<d;k++)
                        res[i][j] += (temp[i][k]%x)*(A[k][j]%x);
        }
    }
    for(int i=0;i<d;i++){
        for(int j=0;j<d;j++){
            res[i][j] %= x;
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
}
