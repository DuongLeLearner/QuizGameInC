/*
 ============================================================================
 Name        : Quiz3.c
 Author      : Duong
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXCHAR 1000
#define MAXQUIZNO 15

int readQuiz() {
	char *quesArray[15];

	char quesString;
	int i = 0;

    FILE *fp;
    char str[MAXCHAR];
    char* filename = "G:\\Soft\\Pleiades2\\pleiades\\workspace\\Quiz\\src\\Question.txt";

    fp = fopen(filename, "r");

    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }

    while (fgets(str, MAXCHAR, fp) != NULL) {
    	printf("%s", str);
//    	strcpy(a[i],str);
    	i++;
    }
    printf("\n%s", quesArray[2]);
    fclose(fp);

	return 0;
}

char quesArray[MAXQUIZNO][MAXCHAR];
char answer[1000];char end_char;
char* LastcharDel(char* string);
char getAnswer(char string[1000]);

int createQuiz() {

	strcpy(quesArray[0], "1.Hệ mặt trời có bao nhiêu hành tinh?-A.1 B.2 C.3 D.8-D");
	strcpy(quesArray[1], "2.Lá cây nào có thể dùng để hút?-A.Sắn B.Cần C.Đu đủ D.Mọi loại lá-B");
	strcpy(quesArray[2], "3.Ai là youtuber cá nhân có nhiều subs nhất?-A.Khá Bảnh B.Rất Bảnh C.Pewdiepie D.PewPew-C");
	strcpy(quesArray[3], "4.Yasuo là nhân vật trong game nào?-A.GTA B.Fortnite C.LoL D.Boom-C");
	strcpy(quesArray[4], "5.Nhân vật chính trong phim Ma Trận tên gì?-A.Mopheus B.Neo C.Smith D.Wolf-B");
	strcpy(quesArray[5], "6.Kẻ thù truyền kiếp của Batman là ai?-A.Joker B.Dr.Freeze C.Poison Ivy D.Crocodile-B");
	strcpy(quesArray[6], "7.Mario là sản phẩm của hãng nào?-A.Sony B.Square Enix C.Nintendo D.Capcom-C");

	return 0;
}

char* LastcharDel(char* string) {
    int i = 0;
    while(string[i] != '\0') {
        i++;
    }
    string[i-1] = '\0';
    string[i-2] = '\0';
    return string;
}

char getAnswer(char string[1000]) {
    printf("AAA");
    strncpy(answer, string, sizeof(string));
    printf("%s", answer);
    printf("%llu", sizeof(string));
    printf("BBB");
    end_char = answer[strlen(answer)-1];
    printf("%s",end_char);
    return end_char;
}

int main() {
   char *strAnswer = malloc(4);
   int quesNo;
   quesNo = 0;
   createQuiz();

   while(quesNo < MAXQUIZNO) {
	   LastcharDel(quesArray[quesNo]);
	   printf("\nCâu số: %d\n", quesNo + 1);
	   printf("%s",quesArray[quesNo]);
	   setbuf(stdout, NULL);
	   printf("\n(Nhập exit để thoát)Nhập câu trả lời: ");
//	   scanf("%[^\n]%*c", strAnswer);
	   fgets(strAnswer, 256, stdin);
	   printf("%s", strAnswer);
	   quesNo+=1;
	   if(strcmp(strAnswer, "exit") == 1) {
		   printf("\nDFFF");
		   break;
	   }
	   printf("\n%d", strcmp(strAnswer, "exit"));
	   printf("\n%d\n",quesNo);
   }

   return 0;
}
