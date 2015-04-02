#include<stdio.h>
int main()
{
	int x=1, y =2 , z[10];
	int *ip,*iq;
	ip = &x;
	
	printf("value of x = %d\n",x);
	printf("value of y = %d\n",y);
	printf("value pointed by ip = %d\n",*ip);
	printf("---------------------------\n");
	y = *ip;
	iq = ip;
	printf("value of x = %d\n",x);
	printf("value of y = %d\n",y);
	printf("value pointed by ip = %d\n",*ip);
	printf("value pointed by iq = %d\n",*iq);

	*ip *= 6;
	++*ip;
	(*ip)++;
	printf("---------------------------\n");
	printf("value of x = %d\n",x);
	printf("value of y = %d\n",y);
	printf("value pointed by ip = %d\n",*iq);
	printf("value pointed by iq = %d\n",*ip);
	return 0;
}
