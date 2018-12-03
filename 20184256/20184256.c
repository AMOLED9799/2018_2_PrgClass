#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int value;
    struct node *next;
};

struct node * crtnode(int value)                                // 생성한 노드에 넣을 값 파라미터로 입력받기
{
    struct node * current = malloc(sizeof(struct node));
    current->value = value;
    current->next = NULL;
    
    return current;
}

struct node * appnode(struct node * HEAD, struct node * current) // tail 노드의 next 자리에 current 노드의 주소값을 넣어줄 예정
{
    struct node * pointing = HEAD;
    
    if(pointing == NULL)
    {
        
        pointing = HEAD;
        return current;
    }
    
    else
    {
        while(pointing->next != NULL)
            pointing = pointing->next;
        
        pointing->next = current;
    }
    
    return HEAD;
}

int prtnode(struct node * HEAD, int index)         // 맨 앞에서부터 printing, times : 0이면 끝까지, 0이 아니면 그 위치
{
    struct node * pointing = HEAD;
    
    if(pointing == NULL)
    {
        printf("자료없음\n");
        return 0;
    }
    
    if(index == 0)
    {
        int count=0;
        
        do    {
            printf("%d  ",pointing->value);
            pointing = pointing->next;
            count++;
        } while(pointing != NULL);
        
        return count;
    }
    
    else
    {
        int count=0;
        do    {
            pointing = pointing->next;
            count++;
        } while(pointing != NULL);
        
        pointing = HEAD;
        for(int i=0; i<count/2; i++)
        {
            pointing = pointing->next;
        }
        
        return pointing->value;
    }
}

void reverseprtnode(struct node * HEAD, int numbofvalue)
{
    for(int i=numbofvalue; i>0; i--)
    {
        struct node * pointing = HEAD;
        
        for(int j=0; j<i-1; j++)
        {
            pointing = pointing->next;
        }
        printf("%d  ",pointing->value);
    }
    puts("");
}

struct node * rmvoddnode(struct node * HEAD, int oddoreven)
{
    struct node * pointing1 = HEAD;
    struct node * pointing2 = pointing1->next;
    struct node * pointing3 = NULL;
    
    HEAD = pointing1->next;       //맨 앞은 따로
    
    free(pointing1);
    pointing1 = HEAD;
    pointing3 = pointing1;
    
    while(1)
    {
        pointing1 = pointing3;
        pointing2 = pointing1->next;
        pointing3 = pointing2->next;
        
        free(pointing2);
        pointing1->next = pointing3;
        
        if(pointing3 == NULL || pointing3->next == NULL)
            break;
    }
    
    if(oddoreven == 1)
    {
        
    }
    
    return HEAD;
}

int main()
{
    struct node * HEAD = NULL;
    struct node * currentnode;
    int tempvalue;
    
    printf("정수형 자료를 입력받습니다\n");
    
    while(1)
    {
        printf("자료 입력 : ");
        scanf("%d",&tempvalue);
        
        if(getchar() == EOF)
        {
            printf("X -- EOF입력\n");
            break;
        }
        
        currentnode = crtnode(tempvalue);
        HEAD = appnode(HEAD, currentnode);
    }
    
    
    
    // 출력 섹션
    int count;
    // 순서대로 출력
    printf("\n자료를 출력합니다 ********************* \n");
    printf("입력자료를 순서대로 출력합니다\n");
    count = prtnode(HEAD,0);
    
    // 입력된 자료의 개수 출력
    printf("\n자료의 개수는 %d개 입니다\n", count);
    
    // 중간 위치에 있는 값 출력
    printf("\n중간 자료의 값은 %d 입니다\n", prtnode(HEAD,1));
    
    // 입력자료를 역순으로 출력
    printf("\n입력받은 자료를 역순으로 출력합니다 ******** \n");
    reverseprtnode(HEAD, count);
    
    // 입력자료 중 홀수번째 자료는 삭제
    printf("\n홀수번째 자료는 삭제합니다 ************** \n");
    printf("\n남은 자료를 출력합니다 \n");
    prtnode(rmvoddnode(HEAD,count%2),0);
    
    printf("\n프로그램 종료 \n");
    return 0;
    
}
