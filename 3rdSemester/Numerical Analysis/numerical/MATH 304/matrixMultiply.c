#include<stdio.h>
#include<stdlib.h>
int matA[3][3],matB[3][3],result[3][3];
void multiplication(int matA[3][3],int matB[3][3]){
    int row1=3;
    int row2=3;
    int col2=3;
    
    
    for(int i=0;i<row1;i++){
        for(int j=0;j<col2;j++){
            result[i][j]=0;
            for(int k=0;k<row2;k++){
                result[i][j]+=matA[i][k]*matB[k][j];
            }
        }
    }
    printf("multiplication result: \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d  ",result[i][j]);
        }
        printf("\n");
    }


}
int main(){
    // int matA[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    // int matB[3][3]={{4,5,6},{3,2,1},{1,0,1}};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
           matA[i][j]=rand()%10;
           matB[i][j]=rand()%10;
        }
        
    }
    printf("matA:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
          printf("%d ",matA[i][j]);
        }
        printf("\n");
        
    }
     printf("matB:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
          printf("%d ",matB[i][j]);
        }
        printf("\n");
        
    }
     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
           result[i][j]=0;
        }
        
    }
    multiplication(matA,matB);
}