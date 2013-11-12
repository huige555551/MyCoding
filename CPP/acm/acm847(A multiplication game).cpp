#include<stdio.h>

void main()
{
	long long n;

	while(scanf("%lld",&n)!=EOF)
	{
		if(n>1 && n<=9) printf("Stan wins.");
		else if(n<=18) printf("Ollie wins.");
		else if(n<=162) printf("Stan wins.");
		else if(n<=324) printf("Ollie wins.");
		else if(n<=2916) printf("Stan wins.");
		else if(n<=5832) printf("Ollie wins.");
		else if(n<=52488) printf("Stan wins.");
		else if(n<=104976) printf("Ollie wins.");
		else if(n<=944784) printf("Stan wins.");
		else if(n<=1889568) printf("Ollie wins.");
		else if(n<=17006112) printf("Stan wins.");
		else if(n<=34012224) printf("Ollie wins.");
		else if(n<=306110016) printf("Stan wins.");
		else if(n<=612220032) printf("Ollie wins.");
		else printf("Stan wins.");

		printf("\n");
	}
}
/*
1*9=9 stan win (thinking min , then max no. that ollie can have){10-18 obviously ollie win.the are best player never can do fault so}
but 2*9=18 porjonto ollie win
but 18*9=162 stan win
*/