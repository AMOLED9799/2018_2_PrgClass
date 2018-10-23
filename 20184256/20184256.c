#include <stdio.h>

int rfibo(int);
int sfibo(int);

int main()
{
    for(int i=3; i<=45; i++)
    {
        if(i%2 == 0)    //짝수
        {
            sfibo(i);       //실행만
        }
        else            //홀수
        {
            printf("rfibo(%d) = %d\n",i,rfibo(i));
            printf("sfibo(%d) = %d\n",i,sfibo(i));
        }
    }
}

int rfibo(int n)    //recursive
{
    if(n <= 1)
        return n;
    else
        return rfibo(n-1) + rfibo(n-2);
}

int sfibo(int n)    //static variable
{
    static int numb1 = 1;
    static int numb2 = 1;
    int result = numb1 + numb2;
    
    numb1 = numb2;
    numb2 = result;
    
    return result;
}

