#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void input(void *, char *, char *, char );
int in_interval(float, float, float );
char **GYF_strsplit(char *, int *);
void strlower(char *);


// ignore=真值 : 忽略输入异常
// ignore=假值(默认) : 不忽略输入异常
void input(void *number, char *prompt, char *type, char ignore)
{
	// 默认接收浮点型输入
	char *format="%g";
	if (!strcmp(type,"int"))
	{
		format="%d";
	}
	
	while (1)
	{
		printf(prompt);
		scanf(format, number);
		// 万能的清空输入缓冲区，应对任何状况
		if (getchar()!=10)
		{
			while (getchar()!=10);
			if(ignore)break;
			continue;
		}
		break;
	}
}


int in_interval(float number, float begin, float end)
{
	return begin <= number && number <= end;
}



char **GYF_strsplit(char *input_str, int *number)
{
	//printf("%s",input_str);getchar();
	//printf("%p %d\n",number,*number);
	char **storage = malloc(0);

	char *current_start = input_str;
	char *current_end = NULL;
	
	//printf("%d",*(current_start-1)=='\0');getchar();
	while ((current_end = strchr(current_start, ',')) != NULL || strlen(current_start))
	{
		//puts(current_start);
		//if (current_end)puts(current_end);getchar();
		if (current_end == NULL)
		{
			current_end = current_start + strlen(current_start);	// 到字符串末尾
			//printf("null:%d",*current_end=='\0');getchar();
		}

		// 计算子字符串的长度
		int len = current_end - current_start;
		//printf("len:%d\n",len);getchar();

		// 分配足够的空间来存储子字符串
		storage[*number] = malloc(len + 1);
		strncpy(storage[*number], current_start, len);
		storage[*number][len] = '\0';	// 手动添加字符串结尾
		
		//puts(storage[*number]);
		//getchar();
		// 打印每个分割出的字符串
		//printf("str%d: %s\n", *number, storage[*number]);

		// 更新索引和指针位置
		(*number)++;
		//printf("number:%d",*number);getchar();
		//printf("%p %d\n",number,*number);
		current_start = current_end + 1;
		//printf("%c %d",*(current_start-1),*(current_start-1)=='\0');getchar();
		if (*(current_start-1)=='\0') break;
	}

	//printf("%p\n",storage);
	return storage;
}


void strlower(char *word)
{
	char *p=word;
	for (; *p!='\0'; p++)
	{
		*p=tolower(*p);
	}
}