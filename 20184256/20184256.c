#include <stdio.h>
#include <string.h>

struct date
{
    int year;
    int month;
    int day;
};

struct rep
{
    char name [20];
    struct date day;
    int gender;
    char address [30];
    int phone;
};

typedef struct rep set;

void swap(set strarr[], int j);
void printlist(set strarr[]);
void namesort(set strarr[], int select);
void birthsort(set strarr[], int select);
int numbofmember;


int main()
{
    
    set rep1, rep2, rep3, rep4, rep5, rep6, rep7, rep8, rep9, rep10;
    struct rep strarr[10] = {rep1, rep2, rep3, rep4, rep5, rep6, rep7, rep8, rep9, rep10};
    
    printf("몇 명의 주소를 입력하시겠습니까? : ");
    scanf("%d",&numbofmember);
    
    for (int i=0; i<numbofmember; i++)
    {
        printf("%d번째 사람의 이름    : ", i+1);              scanf("%s", strarr[i].name);
        printf("%d번째 사람의 생년월일 (yyyy mm dd) : ", i+1);              scanf("%d %d %d", &strarr[i].day.year, &strarr[i].day.month, &strarr[i].day.day);
        fflush(stdin);
        printf("%d번째 사람의 성별 (남 1/ 여 2) : ", i+1);     scanf("%d", &strarr[i].gender);
        printf("%d번째 사람의 주소 : ", i+1);                 scanf("%s", strarr[i].address);
        printf("%d번째 사람의 전화번호 : ", i+1);              scanf("%d", &strarr[i].phone);
        
        printf("이름     생년월일           성별   주소                       전화번호\n");
        printf("%-8s%4d년 %2d월 %2d일   %s    %-25s   0%-d\n", strarr[i].name, strarr[i].day.year, strarr[i].day.month, strarr[i].day.day, (strarr[i].gender == 1)? "남" : "여", strarr[i].address, strarr[i].phone);
        fflush(stdin);
    }
    
    // 출력
    
    printf("-- origin  --\n");
    printlist(strarr);
    
    printf("\n-- sort by name (down) --\n");
    namesort(strarr,-1);
    printlist(strarr);
    
    printf("\n-- sort by birth (up) --\n");
    birthsort(strarr, 1);
    printlist(strarr);
    
    return 0;
}

// main 종료

void printlist(set strarr[])    // 출력
{
    printf("이름     생년월일           성별   주소                  전화번호\n");
    for (int i = 0; i < numbofmember; i++)
    {
        printf("%-8s%4d년 %2d월 %2d일   %s    %30s   0%d\n", strarr[i].name, strarr[i].day.year, strarr[i].day.month, strarr[i].day.day, (strarr[i].gender == 1)? "남" : "여", strarr[i].address, strarr[i].phone);
    }
}

void swap(set strarr[],int j)   // 바꾸는 함수
{
    set address;
    
    address = strarr[j];
    strarr[j] = strarr[j-1];
    strarr[j-1] = address;
}

void namesort(set strarr[], int select) // 이름으로 정렬 [ select 값으로 오르내림차순 선택가능 ]
{
    for(int i = 0; i < numbofmember; i++)
    {
        if (select >0)      //오름차순
        {
            for(int j = i; j > 0 && ((strcmp(strarr[j-1].name, strarr[j].name) >0)? 1 : 0); j--)
            {
                swap(strarr,j);
            }
        }
        else                //내림차순
        {
            for(int j = i; j > 0 && ((strcmp(strarr[j-1].name, strarr[j].name) <0)? 1 : 0); j--)
            {
                swap(strarr,j);
            }
        }
    }
}


void birthsort(set strarr[], int select)    // 생년월일로 정렬 [ select 값으로 오르내림차순 선택가능 ]
{
    for(int i = 0; i < numbofmember; i++)
    {
        for(int j = i; j>0; j--)
        {
            if((select > 0)? strarr[j-1].day.year > strarr[j].day.year : strarr[j-1].day.year < strarr[j].day.year)         // select 값에 따라 오름차순 / 내림차순 결정 : 년
            {
                swap(strarr,j);
                continue;
            }
            else if (strarr[j-1].day.year == strarr[j].day.year)
            {
                if((select > 0)? strarr[j-1].day.month > strarr[j].day.month : strarr[j-1].day.month < strarr[j].day.month) // 월
                {
                    swap(strarr,j);
                    continue;
                }
                
                else if (strarr[j-1].day.month == strarr[j].day.month)
                {
                    if((select > 0)? strarr[j-1].day.day > strarr[j].day.day : strarr[j-1].day.day < strarr[j].day.day)     // 일
                    {
                        swap(strarr,j);
                        continue;
                    }
                }
            }
        }
    }
}
