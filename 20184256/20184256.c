#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    char gender [10];
    char address [30];
    int phone;
};

typedef struct rep set;

void swap(set * strarr[], int j);
void printlist(set * strarr[]);
void namesort(set * strarr[], int select);
void birthsort(set * strarr[], int select);
int numbofmember;


int main()
{
    
    printf("입력할 명세서의 개수를 입력하시오 : ");
    scanf("%d",&numbofmember);
    
    struct rep **strarr;
    strarr = malloc (sizeof(struct rep *) * numbofmember);
    
    for (int i = 0; i < numbofmember; i++)
    {
        strarr[i] = malloc(sizeof(struct rep));
    }
    
    printf("명세서 입력 요령 : [NAME YYYY/MM/DD (man or woman) PHONENUMBER]\n");
    
    
    for (int i=0; i<numbofmember; i++)
    {
        printf("개별명세 입력 %d :",i+1);
        scanf("%s %d/%d/%d %s %d", strarr[i]->name,&strarr[i]->day.year, &strarr[i]->day.month, &strarr[i]->day.day, strarr[i]->gender,&strarr[i]->phone);
        
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

void printlist(set * strarr[])    // 출력
{
    printf("이름     생년월일           성별   전화번호\n");
    for (int i = 0; i < numbofmember; i++)
    {
        printf("%-8s%4d년 %2d월 %2d일   %s    0%d\n", strarr[i]->name, strarr[i]->day.year, strarr[i]->day.month, strarr[i]->day.day, (strcmp(strarr[i]->gender,"man") == 0)? "남" : "여",  strarr[i]->phone);
    }
}

void swap(set * strarr[],int j)   // 바꾸는 함수
{
    set * address;
    
    address = strarr[j];
    strarr[j] = strarr[j-1];
    strarr[j-1] = address;
}

void namesort(set * strarr[], int select) // 이름으로 정렬 [ select 값으로 오르내림차순 선택가능 ]
{
    for(int i = 0; i < numbofmember; i++)
    {
        if (select >0)      //오름차순
        {
            for(int j = i; j > 0 && ((strcmp(strarr[j-1]->name, strarr[j]->name) >0)? 1 : 0); j--)
            {
                swap(strarr,j);
            }
        }
        else                //내림차순
        {
            for(int j = i; j > 0 && ((strcmp(strarr[j-1]->name, strarr[j]->name) <0)? 1 : 0); j--)
            {
                swap(strarr,j);
            }
        }
    }
}


void birthsort(set * strarr[], int select)    // 생년월일로 정렬 [ select 값으로 오르내림차순 선택가능 ]
{
    for(int i = 0; i < numbofmember; i++)
    {
        for(int j = i; j>0; j--)
        {
            if((select > 0)? strarr[j-1]->day.year > strarr[j]->day.year : strarr[j-1]->day.year < strarr[j]->day.year)         // select 값에 따라 오름차순 / 내림차순 결정 : 년
            {
                swap(strarr,j);
                continue;
            }
            else if (strarr[j-1]->day.year == strarr[j]->day.year)
            {
                if((select > 0)? strarr[j-1]->day.month > strarr[j]->day.month : strarr[j-1]->day.month < strarr[j]->day.month) // 월
                {
                    swap(strarr,j);
                    continue;
                }
                
                else if (strarr[j-1]->day.month == strarr[j]->day.month)
                {
                    if((select > 0)? strarr[j-1]->day.day > strarr[j]->day.day : strarr[j-1]->day.day < strarr[j]->day.day)     // 일
                    {
                        swap(strarr,j);
                        continue;
                    }
                }
            }
        }
    }
}
