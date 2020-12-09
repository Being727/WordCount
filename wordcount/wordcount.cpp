
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[])
{

	char ch='g';               //初始化一个字符，g为随意赋值，不是空值即可
	char filename[80];         //文件名定义为字符
    FILE *fp; 
	strcpy(filename,argv[2]);  //将输入的第三个参数复制给filename
	fp=fopen(filename,"r");    //以只读方式打开文件名为filename的文件，指针指向第一个字符
	int cnt=0;
	if(strcmp(argv[1],"-c")==0)   //如果第二个参数是-c，执行统计字符个数的操作
	{
		while(!feof(fp))            //当文件未结束时，执行以下
		{
			ch=fgetc(fp);           //获取fp指针的字符，赋值给变量
			cnt++;
			
		}
		printf("字符数：%d\n",--cnt);   //由于统计了最后一个换行符，所以输出的cnt需要减一
		 
	}
	else
	{
		if(strcmp(argv[1],"-w")==0)         //如果第二个参数是-w
		{
			
			int is_word = 0;                                               //用于记录字符是否处于单词中
			while (!feof(fp))                                    //如果不是文件结尾 (ch = fgetc(fp)) != EOF
			{
				ch=fgetc(fp);
				if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))     //判断 如果是字母
				{         
					if(is_word==0)
					{
						cnt++;                                           //如果is_word是0的状态，计数才加一，防止两个空格的情况
					    is_word = 1;              //记录处在单词状态
			
					}
				
				}
				else 
					is_word = 0;                    //记录不处于单词状态
			}
			printf("单词数：%d\n",cnt);
		}
	}
	return 0;
}
	
