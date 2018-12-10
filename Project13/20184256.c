#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>

void CountLine(char * filename)
{
	FILE * fp;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("실패, 종료\n");
		return;
	}
	else
	{
		int LineCount = 0;
		char tempsentence[1000];

		while (!feof(fp))
		{
			fgets(tempsentence, sizeof(tempsentence), fp);
			LineCount++;
		}
		printf("Linecount : %d\n", LineCount);
	}
	fclose(fp);
}

void CountWord(char * filename)
{
	FILE * fp;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("실패, 종료\n");
		return;
	}
	else
	{
		int WordCount = 0;
		char tempword[30];

		while (!feof(fp))
		{
			fscanf(fp, " %s", tempword);
			WordCount++;
		}
		printf("Wordrcount : %d\n", WordCount);
	}
	fclose(fp);

}

void CountChar(char * filename)
{
	FILE * fp;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("실패, 종료\n");
		return;
	}
	else
	{
		int CharacterCount = 0;
		char tempcharacter = NULL;

		while (!feof(fp))
		{
			tempcharacter = fgetc(fp);
			// putchar(tempcharacter);
			CharacterCount++;
		}
		printf("Wordrcount : %d\n", CharacterCount);
	}
	fclose(fp);
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

int main(int argc, char ** argv)
{


	char * originfilename = malloc(sizeof(argv[1]) * sizeof(char));
	strcpy(originfilename, argv[1]);

	char * str4filename = strtok(argv[1], ".");
	strcat(str4filename, ".rev");
	argv[1] = originfilename;

	CountLine(originfilename);
	CountWord(originfilename);
	CountChar(originfilename);

	changeAlphabet(originfilename, str4filename);
	printf("%s 파일의 대소문자를 바꾸어 %s파일로 저장하였습니다\n", originfilename, str4filename);
	
	return 0;
}