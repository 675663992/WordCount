#include<stdio.h>
#include<cstring>

// 定义单行字符的最大长度
const int MAX = 1e3;
FILE *fp;

int CountWords()
{
	int cntWords = 0;
	// s用于临时存储文件中取出的字符串中单行字符
	char s[MAX];
	//用sep记录分割字符串的标识符（遇到空格和逗号分割两个字符串）
	char sep[3] = " ,";
	// 一行一行的读取文件中的信息
	while((fgets(s,sizeof(s),fp))!=NULL){
		// 调用分割函数strtok，按照sep中的符号对字符串进行划分
		char *token = strtok(s,sep);
		while(token != NULL){
			// 每划分一次单词数+1
			cntWords ++;
			// 从上一次分割的结尾继续下一次划分
			token = strtok(NULL,sep);
		}
	}
	
	return cntWords;
}
int CountChar()
{
	int cntChar = 0;
	// s用于临时存储文件中取出的字符串中单行字符
	char s[MAX];
	while((fgets(s,sizeof(s),fp))!=NULL){
		cntChar += strlen(s);
	}
	return cntChar;
}

// argv 存储从命令行获取的字符串
int main(int argc, char *argv[])
{
	// cntWords计数单词数量，cntChar计数字符数量
	int cntWords = 0,cntChar = 0;
	fp = fopen("input.txt","r");
	if((fp = fopen(argv[2],"r")) == NULL){
		printf("获取文件失败！");
	}else{
		if(argv[1][1] == 'w'){ 
			// 统计单词数
			cntWords = CountWords();
			printf("单词数：%d\n",cntWords);
		}else{
			//统计字符数
			cntChar = CountChar();
			printf("字符数：%d\n",cntChar);
		}
	}
	fclose(fp);
	return 0;
}