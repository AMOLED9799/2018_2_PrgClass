#include <stdio.h>
#include <string.h>

char * File2Str(char * originfilename);
void CountLine(char * FileStr);
void CountWord(char * FileStr);
void CountChar(char * FileStr);
void changeAlphabet(char * filename1, char * filename2);

int main(int argc, char ** argv)
{
    if (argc < 1)
    {
        printf("잘못된 Argument입력입니다\n");
        printf("프로그램을 종료합니다\n");
        return 0;
    }
    // 파일 명 교환 준비
    char * originfilename = malloc(sizeof(argv[1]) * sizeof(char));         // 원래 파일 명
    strcpy(originfilename, argv[1]);
    char * str4filename = strtok(argv[1], ".");
    strcat(str4filename, ".rev");                                           // 바뀐 파일 명 (.rev)
    argv[1] = originfilename;
    
    char * FileStr = File2Str(originfilename);              // File 을 FileStr에 문자열 형태로 저장
    
    // printing
    
    printf("받아온 파일 : %s\n\n", argv[1]);
    CountLine(FileStr);
    CountWord(FileStr);
    CountChar(FileStr);
    
    changeAlphabet(originfilename, str4filename);
    printf("\n%s 파일의 대소문자를 바꾸어 %s파일로 저장하였습니다.\n", originfilename, str4filename);
    
    return 0;
}



char * File2Str(char * originfilename)
{
    FILE * fp = fopen(originfilename, "r");                                 // 파일 열고
    
    if (fp == NULL)
    {
        printf("실패, 종료\n");
        return NULL;
    }
    
    fseek(fp, 0, SEEK_END);
    char * tempfile = (char *) malloc(sizeof(char) * (ftell(fp) + 1));
    fseek(fp, 0, SEEK_SET);
    {                                   // Block 내에서 파일 전체를 tempfile 문자열에 넣는 작업을 하여
        int i = 0;                      // Strtok를 사용할 준비를 한다.
        while (!(feof(fp)))
        {
            tempfile[i++] = fgetc(fp);  // 문자열에 넣어 분리를 시도
        }
        tempfile[i] = '\n';             // 마지막에는 NULL
    }
    
    return tempfile;
}

void CountLine(char * FileStr)
{
    int count = 0;
    int index = 0;
    
    while(FileStr[index] != NULL)
    {
        if(FileStr[index] == '\n')     // \n 개행문자를 기준으로 세아림
        {
            count++;
        }
        index++;
    }
    
    printf("Linecount : %d\n",count);
}

void CountWord(char * FileStr)
{
    int count = 0;
    int index = 0;
    int set = 1;
    char tempchar;
    
    while((tempchar = FileStr[index]) != NULL)
    {
        if((tempchar == '\'') || (((tempchar >= 'A') && (tempchar <= 'Z')) || ( (tempchar >= 'a') && (tempchar <= 'z'))))       // 알파벳 또는 어퍼스트롤피가 나왔을 경우 set
        {
            set = 1;
        }
        else
        {
            if(set == 1)                        // set인 상태에서 알파벳이나 어퍼스트롤피가 나오지 않는 경우 ( 띄어쓰기, 구두점, 개행문자 등의 문장부호 ) -> 숫자는 단어로 고려하지 않았음
            {
                set = 0;
                count ++;
            }
        }
        index ++;
    }
    
    printf("Wordcount : %d\n",count);
}

void CountChar(char * FileStr)
{
    int count = 0;
    int index = 0;
    char tempchar;
    
    while((tempchar = FileStr[index]) != NULL)
    {
        // 개행문자 또는 공백은 character로 읽어들이지 않는다.
        if(!(tempchar == '\n' || tempchar == ' '))
        {
            count++;
        }
        index ++;
    }
    
    printf("Charcount : %d\n",count);
    
}

void changeAlphabet(char * filename1, char * filename2)
{
    FILE * fp;
    FILE * fp2;
    
    fp = fopen(filename1, "r");
    fp2 = fopen(filename2, "w");
    
    if (fp == NULL)
    {
        printf("실패, 종료\n");
        return;
    }
    else
    {
        char tempcharacter = NULL;
        
        while ((tempcharacter = fgetc(fp)) != EOF)
        {
            if ('A' <= tempcharacter && 'Z' >= tempcharacter)
            {
                fputc(tempcharacter + 32, fp2);
            }
            else if ('a' <= tempcharacter && 'z' >= tempcharacter)
            {
                fputc(tempcharacter - 32, fp2);
            }
            else
            {
                fputc(tempcharacter, fp2);
            }
        }
    }
    
    fclose(fp);
    fclose(fp2);
}
