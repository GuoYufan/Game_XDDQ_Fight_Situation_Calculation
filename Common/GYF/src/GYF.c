#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define DEBUG printf("---debug位置---\n行号:%d\n文件名:<%s>",__LINE__,__FILE__);getchar();

//extern short 第几场;

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


short in_interval(float number, float begin, float end)
{
	/*
	printf("<short in_interval()>:参数接收到的随机数%g:参数接收到的区间左%g:参数接收到的区间右%g:在区间内%d\n",
		number,begin,end,begin <= number && number <= end);
	*/
	return begin <= number && number <= end;
}


char **GYF_strsplit(char *input_str, int *number)
{
	// 防止第二次进入该函数不从storage[0]开始存，而是从上一次的[*number]开始存。造成[0]是只开辟了地址没有存值的，是(null)的。
	*number=0;
	
	// printf("输入字符串内容：%s 存放输入字符串的地址：%p",input_str,input_str);getchar();
	// printf("存放元素数量的地址及内容：%p %d\n",number,*number);
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
	
	/*
	if (第几场>1){
		printf("number:%d\n",*number);
		printf("storage[%d]:%s\n",*number-1,storage[*number-1]);
		printf("storage[0]:%s\n",storage[0]);
		DEBUG}
	*/

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
