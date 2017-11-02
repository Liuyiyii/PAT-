读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。 

输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10100。

输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。 

输入样例：

1234567890987654321123456789

输出样例：

yi san wu

代码:
#include <stdio.h>
#include <string.h>

int main()
{
	int i;
	int sum = 0;
	char n, ch, s[100];
	char num[10][5] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	memset(s,'0',sizeof(s));
	
	while((ch = getchar()) != '\n')
		sum += (ch - '0');
	sprintf(s, "%d", sum);
	for(i = 0; s[i] != '\0'; i++){
		if(i > 0)
			printf(" ");
		printf("%s",num[s[i]-'0']);
	}
	return 0;
}
