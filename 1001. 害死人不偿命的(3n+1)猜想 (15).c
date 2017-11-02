#include <stdio.h>

int main()
{
	int n,i,step=0;
	scanf("%d",&n);
	
	while(n != 1){
		n = n%2 ? (3*n+1)/2 : n/2;
		step++;
	}
	
	printf("%d\n",step);
	return 0;
}
