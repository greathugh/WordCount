#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int getChar(FILE *fp);
int getWord(FILE *fp);
int main(int argc,char*argv[]){
	FILE *fp;
	int number;
	char string;
    if(argc==3){
		fp = fopen(argv[2],"r"); 
		if(fp == NULL){
			printf("无法打开\n");
			exit(1);
		} 
		    if(!strcmp(argv[1],"-c")){
		        number = getChar(fp);
		     	printf("字符数：%d\n",number);
		    }
		
		    else if(!strcmp(argv[1],"-w")){
			    number = getWord(fp);
			    printf("单词数：%d\n",number); 
		   }
	}
	else {
		printf("无法读取，请重新输入\n");
	}
	
} 

int getChar(FILE *fp){
	char ch;
	int number=0;
	while((ch=fgetc(fp))!=EOF)
			number++;
	}
	return number;
}

int getWord(FILE *fp){
	int flag=0;
	int number=0;
	char ch;
	while(feof(fp)==0)
    {
        ch = fgetc(fp);
        if(ch==' '||ch==',')
            flag=0;
        else if(flag==0)
        {
            flag=1;
            number++;
        }
    }
    return number;
}
