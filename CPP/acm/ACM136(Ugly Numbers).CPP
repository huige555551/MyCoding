#include<stdio.h>
#include<time.h>

#define MAX 1500
#define MIN(a,b) a<b?a:b;

/*if i declare a[] here then there is no problem*/
/*TIPS:..:SO ALWAYS DECLARE ARRAY AS GLOBAL*/
/*FOR USING 13-14 DIGIT USE DOUBLE*/
double a[MAX];

void main()
{
	/*freopen ("output1.txt", "w", stdout);*/

	int i,j;
	double min,current;
	/*STRANGE*//*if i use long or long long ,it will not work.i have to use double.by using double i can print 13-14digit easily(300 000 000 000 00)*/
	/*if i declare a[] here then it cannot work in TC but will get AC in acm*/
	/*double a[MAX];*/

	a[0]=1;

	for(i=0; i<MAX; i++)
	{
		current=a[i];
		min=3000000000;  /*i can use 300 000 000 000 00*/

		for(j=i; ( (j>=0) && (5*a[j]>current) ); j--)
		{
			if(2*a[j]>current)
				min=MIN(min,2*a[j]);

			if(3*a[j]>current)
				min=MIN(min,3*a[j]);

			min=MIN(min,5*a[j]);
		}

		a[i+1]=min;
		/*printf ("\n%.0lf", a[i]);*/
	}
	/*
	   if i not print '.', i will get WA instead of PE.
	   and if i not use '\n', i will get PE.RIDICULOUS.
	*/
	printf("The 1500'th ugly number is %.0lf.\n",a[1499]);
}

/*
first 1.
multiply it by 2,3,5.
get the minimum and it will be the second ugly.2.

then
2 and 1 are multiplied by 2,3,5.
get the minimum and it will be the third.3.

then
3,2 and 1 are multiplied by 2,3,5.
get the minimum and it will be the fourth.4.

then
.......
...........

to calculate the minimum number,
there used a huge number min=300 000 000 000 00;
*/