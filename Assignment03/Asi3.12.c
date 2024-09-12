//Write a program to accept integer values of base and index 

#include<stdio.h>

int main()
{
	int base;
	int index;
	printf("enter base:");
	scanf("%d",&base);
	printf("enter index:");
	scanf("%d",&index);
	int c=base;
	for(int i=2;i<=index;i++)
	{
		base*=c;
		printf("%d\n ",base);
	}
	return 0 ;
	}
