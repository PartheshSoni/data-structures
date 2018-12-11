#include <stdio.h>

void matmul(int n1, int m1,int mat1[][m1], int n2, int m2, int mat2[][m2]){
    int multiply[n1][m2];
    int c, d, k, sum=0;
      for (c = 0; c < n1; c++) {
      for (d = 0; d < m2; d++) {
        for (k = 0; k < n2; k++) {
          sum = sum + mat1[c][k]*mat2[k][d];
        }

        multiply[c][d] = sum;
        sum = 0;
      }
    }
    int choice;
    printf("/nEnter the choice of display of matrix:\n1. Row Major\n2. Column Major\nCode: ");
    scanf("%d", &choice);
    if(choice==1){
            printf("The result of multiplication...\n");
        for(c=0; c<n1; c++){
            for(d=0; d<m2; d++){
                printf("%d ", multiply[c][d]);
            }
            printf("\n");
        }
    }
    else{
        printf("The result of multiplication...\n");
        for(c=0; c<m2; c++){
            for(d=0; d<n1; d++){
                printf("%d ", multiply[c][d]);
            }
            printf("\n");
        }
    }
}


void main(){
    int n1, m1;
    printf("Enter the dimension of 1st matrix(A).(eg. 3 7): ");
    scanf("%d %d", &n1, &m1);
    int n2, m2;
    printf("Enter the dimension of 2nd matrix(B): ");
    scanf("%d %d", &n2, &m2);
    int mat1[n1][m1], mat2[n2][m2];
    printf("\nEnter the contents of first matrix: \n");
    int i, j;
    for(i=0; i<n1; i++){
        for(j=0; j<m1; j++){
            printf("Row %d X Column %d: ", i+1, j+1);
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("\nEnter the contents of second matrix: \n");

    for(i=0; i<n2; i++){
        for(j=0; j<m2; j++){
            printf("Row %d X Column %d: ", i+1, j+1);
            scanf("%d", &mat2[i][j]);
        }
    }
    int code;
    printf("\nSelect the choice of multiplication...\n1. AXB\n2. BXA\nCode: ");
    scanf("%d", &code);
    switch(code){
    case 1:
        if(m1==n2){//n1Xm1 n2Xm2
            matmul(n1, m1, mat1, n2, m2, mat2);
        }
        else{
            char choice;
            if(m1==m2||n1==n2){
            printf("\nThe given matrices are not multipliable. Do you want to transpose any one matrix for multiplication?(Y/n)");
            scanf("%c", choice);
            if(choice=='Y'||choice=='y')
            if(m1==m2){
                printf("\nOkay. Transposing Matrix A and performing the operation...");
                int temp=n1;
                n1=m1;
                m1=temp;
                int bufferA[n1][m1];
                for(i=0; i<n1; i++){
                    for(j=0; j<m1; j++){
                        bufferA[i][j]=mat1[j][i];
                    }
                }
                matmul(n1, m1, bufferA, n2, m2, mat2);
            }
            else{
                printf("\nOkay. Transposing Matrix B and performing the operation...");
                int temp=n2;
                n2=m2;
                m2=temp;
                int bufferB[n2][m2];
                for(i=0; i<n2; i++){
                    for(j=0; j<m2; j++){
                        bufferB[i][j]=mat2[j][i];
                    }
                }
                matmul(n1, m1, mat1, n2, m2, bufferB);
            }
        }
        else{
            printf("\nSorry, multiplication is impossible for the given matrices.\n");
        }
        }
        break;
    case 2:
        if(m2==n1){//n2Xm2 n1Xm1
            matmul(n2, m2, mat2, n1, m1, mat1);
        }
        else{
            if(n2==n1||m2==m1){

                printf("\nThe matrices in the given form are not multipliable. Do you want to transpose any one matrix and multiply?(Y/n): ");
                char choice;
                scanf("%c", &choice);
                if(choice=='Y'||choice=='y')
                if(n2==n1){
                printf("\nOkay. Transposing Matrix B and performing the operation...");
                int temp=n2;
                n2=m2;
                m2=temp;
                int bufferB[n2][m2];
                for(i=0; i<n2; i++){
                    for(j=0; j<m2; j++){
                        bufferB[i][j]=mat2[j][i];
                    }
                }
                matmul(n2, m2, bufferB, n1, m1, mat1);
            }
            else{
                printf("\nOkay. Transposing Matrix A and performing the operation...");
                 int temp=n1;
                n1=m1;
                m1=temp;
                int bufferA[n1][m1];
                for(i=0; i<n1; i++){
                    for(j=0; j<m1; j++){
                        bufferA[i][j]=mat1[j][i];
                    }
                }
                matmul(n2, m2, mat2, n1, m1, bufferA);
            }
        }
        else{
            printf("\nSorry, multiplication is impossible for the given matrices.\n");
        }
        }
        break;
    default:
        printf("Please enter the valid choice next time.");
        break;
            }


        }



