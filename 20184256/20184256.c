#include <stdio.h>

void indexAddMat(int [][3], int [][3], int [][3]);
void ptrProdMat(int [][3], int [][3], int [][3]);
void printingMatrix(int [][3]);

int main()
{
    int matrix[3][3];
    int resultMatrix[3][3];
    
    // 입력
    printf("3X3 정방행렬의 원소를 입력해주세요\n");
    for(int i=0; i<9; i++)
    {
        printf("[%d][%d] 원소의 값 : ",i/3, i%3);
        scanf("%d",&matrix[i/3][i%3]);
    }
    
    // 연산 + 출력
    indexAddMat(matrix, matrix, resultMatrix);
    
    // 연산 + 출력
    ptrProdMat(matrix, matrix, resultMatrix);
    
    return 0;
}


void indexAddMat(int mat1[][3], int mat2[][3], int result[][3])
{
    for(int row=0; row<3; row++)
    {
        for(int column = 0; column<3; column++)
            result[row][column] = mat1[row][column] + mat2[row][column];
    }
    
    printingMatrix(result);
}

void ptrProdMat(int mat1[][3], int mat2[][3], int result[][3])
{
    int sum = 0;
    
    for(int row=0; row<3; row++) {
        for(int column = 0; column<3; column++) {
            for(int k=0; k<3; k++) {
                sum += *(*(mat1+k)+column) * *(*(mat2 + row)+k);    //곱연산
            }
            *(*( result + row) + column) = sum;                     //result에 값 넣어주기
            sum = 0;
        }
    }
    
    printingMatrix(result);
}

void printingMatrix(int resultMatrix[][3])
{
    printf("\n3X3 정방행렬을 출력합니다\n");
    for(int row=0; row<3; row++)
    {
        for(int column=0; column<3; column++)
            printf("%-5d",resultMatrix[row][column]);
        printf("\n");
    }
}
