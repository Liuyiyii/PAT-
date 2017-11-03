/*
1004. 成绩排名 (20)

读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。

输入格式：每个测试输入包含1个测试用例，格式为

  第1行：正整数n
  第2行：第1个学生的姓名 学号 成绩
  第3行：第2个学生的姓名 学号 成绩
  ... ... ...
  第n+1行：第n个学生的姓名 学号 成绩
  
其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。

输出格式：对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有1空格。

输入样例：

3

Joe Math990112 89
Mike CS991301 100
Mary EE990830 95

输出样例：

Mike CS991301
Joe Math990112
*/

//代码
#include <stdio.h>
int main(){
	struct student{
		int score;
		char name[15];
		char number[15];
	}stu[1000];
	
	int n,i,max,min;
	int maxscore = -1;
	int minscore = 101;
	
	scanf("%d",&n);
	
	for(i = 0; i < n; i++){
		scanf("%s %s %d",&stu[i].name, &stu[i].number, &stu[i].score);
		if(stu[i].score < minscore){
			minscore = stu[i].score; 
			min = i;
		}
		if(stu[i].score > maxscore){
			maxscore = stu[i].score; 
			max = i;
		}

	}
	
	printf("%s %s\n",stu[max].name,stu[max].number);
	printf("%s %s",stu[min].name,stu[min].number);

	return 0;	
}

//错误代码 第二个测试点没过,判断方法过于繁琐
#include <stdio.h>
int main(){
	char name[15],number[15];
	int score;
	int n;
	char maxname[15], maxnumber[15], minname[15], minnumber[15];
	int maxscore = 0, minscore = 0;
	scanf("%d",&n);
	int i = 2; 
	
	while(n--){
		scanf("%s %s %d",name, number, &score);
		--i;
		if(score == 0 || score < minscore){   //之后正常比较 
			strcpy(minname,name);
			strcpy(minnumber,number);
			minscore = score;
		}
		else if(score > maxscore && i == 0){  //第二次大于第一次，第一次给min,第二次给max 
			strcpy(minname,maxname);
			strcpy(minnumber,maxnumber);
			minscore = maxscore;
			strcpy(maxname,name);
			strcpy(maxnumber,number);
			maxscore = score;
		}
		else if(score < maxscore && i == 0){  //第二次小于第一次，赋给min 
			strcpy(minname,name);
			strcpy(minnumber,number);
			minscore = score;
		}
		else if(score > maxscore){  //第一次输入和之后的最大值给Max 
			strcpy(maxname,name);
			strcpy(maxnumber,number);
			maxscore = score;
		}
		else if(score < maxscore && score < maxscore){
			continue;
		}
	}
	
	printf("%s %s\n",maxname,maxnumber);
	printf("%s %s",minname,minnumber);
	 
	return 0;
} 
