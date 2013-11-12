#include<stdio.h>
#include<stdlib.h>

#define MAX 200

void main()
{
	int n,i,j;
	char num[MAX],l1[MAX],l2[MAX],s1[MAX],s2[MAX],s3[MAX],s4[MAX],s5[MAX];

	/*REALLY AMBIGUOUS STRANGE PECULIAR ABNORMAL_BEHAVIOUR*/
	gets(num);  /*scanf("%d",&n); will not work..its really MYSTERIOUS.....*/
	n=atoi(num);

	while(n>0)
	{
		gets(l1);
		gets(l2);

		for(i=0; l1[i]!='<'; i++)
			s1[i]=l1[i];
		s1[i]=0;

		for(j=0,i++; l1[i]!='>'; j++,i++)
			s2[j]=l1[i];
		s2[j]=0;

		for(j=0,i++; l1[i]!='<'; j++,i++)
			s3[j]=l1[i];
		s3[j]=0;

		for(j=0,i++; l1[i]!='>'; j++,i++)
			s4[j]=l1[i];
		s4[j]=0;

		for(j=0,i++; l1[i]; j++,i++)
			s5[j]=l1[i];
		s5[j]=0;

		printf("%s%s%s%s%s\n",s1,s2,s3,s4,s5);

		for(i=0; l2[i]!='.'; i++)
			s1[i]=l2[i];
		s1[i]=0;

		printf("%s%s%s%s%s",s1,s4,s3,s2,s5);

		printf("\n");

		n--;
	}
}