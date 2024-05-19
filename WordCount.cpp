#include<stdio.h>
#include<cstring>

const int MAX = 1e3;

// argv 存储从命令行获取的字符串
int main(int argc, char *argv[])
{
	FILE *fp;
	char s[MAX];
	int cntWords = 0,cntChar = 0;
	fp = fopen("input.txt","r");
	if((fp = fopen(argv[2],"r")) == NULL){
		printf("获取文件失败！");
	}else{
		if(argv[1][1] == 'w'){ // 统计单词数
			char sep[3] = " ,";	//分割字符串（用空格和逗号分割）
			while((fgets(s,sizeof(s),fp))!=NULL){
				char *token = strtok(s,sep);
				while(token != NULL){
					cntWords++;
					token = strtok(NULL,sep); //默认还是上次未分割完的字符串
				}
			}
			printf("单词数：%d\n",cntWords);
		}else{ //统计字符数
			while((fgets(s,sizeof(s),fp))!=NULL){
				cntChar += strlen(s);
			}
			printf("字符数：%d\n",cntChar);
		}
	}
	return 0;
}