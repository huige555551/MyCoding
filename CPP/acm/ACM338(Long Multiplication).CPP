#include<stdio.h>
#include<string.h>

#define MAX 22

void str_rev(char *p)
{
	char s[MAX]={0};
	int i,j;

	for(i=strlen(p)-1,j=0; i>=0; j++,i--)
	{
		s[j]=p[i];
	}

	for(i=0; s[i]; i++)
	{
		p[i]=s[i];
	}
}


void big_multiplication(char *s1,char *s2)
{
	char ans[2*MAX]={0};
	char M[MAX][MAX]={0};
	int i,j,c,l1,l2,l3,L,line,num1,num2;

	str_rev(s1);
	str_rev(s2);

	l1=strlen(s1);
	l2=strlen(s2);

	for(i=0; i<l2; i++)
	{
		num2=s2[i]-'0';
		c=0;

		for(j=0; j<l1; j++)
		{
			num1=s1[j]-'0';

			M[i][j]=num1*num2+c;
			ans[i+j]+=num1*num2;

			if(ans[i+j]>9)
			{
				c = M[i][j]/10;
				M[i][j] = M[i][j]%10;

				ans[i+j+1]+=ans[i+j]/10;
				ans[i+j]%=10;
			}
			else{
				c=0;
			}
		}
		if(c){
			M[i][j]=c;
		}
	}

	/*making string with trailing 0*/
	for(i=0; i<l2; i++)
	{
		for(j=0; j<l1+1; j++)
		{
			M[i][j]+='0';
		}
	}

	for(i=0; i<(l1+l2); i++)
	{
		ans[i]+='0';
	}

	/*reversing string*/
	for(i=0; i<l2; i++)
	{
		str_rev(M[i]);
	}

	str_rev(ans);
	str_rev(s1);
	str_rev(s2);

	/*delet the front 0*/
	for(i=0; i<l2; i++)
	{
		while(M[i][0]=='0')
		{
			for(j=0; j<(l1+1); j++)
			{
				M[i][j]=M[i][j+1];
			}
		}
	}

	while(ans[0]=='0')
	{
		for(i=0; i<(l1+l2); i++)
		{
			ans[i]=ans[i+1];
		}
	}

	if(!strcmp(ans,""))
	{
		strcpy(ans,"0");
	}

	line=0;
	for(i=0; i<l2; i++)
	{
		if( strcmp(M[i],"") )
		{
			line+=1;
		}
	}

	l3=strlen(ans);
	L=l1 > l2 ? l1 : l2;

	/*printing string*/

	if(!strcmp(ans,"0"))
	{
		for(i=L; i>l1; i--)
			printf(" ");
		printf("%s\n",s1);

		for(i=L; i>l2; i--)
			printf(" ");
		printf("%s\n",s2);

		for(i=0; i<L; i++)
			printf("-");
		printf("\n");

		for(i=L; i>1; i--)
			printf(" ");
		printf("0\n");
	}
	else if(line==1)
	{
		for(i=l3-l1; i>0; i--)
			printf(" ");
		printf("%s\n",s1);

		for(i=l3-l2; i>0; i--)
			printf(" ");
		printf("%s\n",s2);

		for(i=l3-L; i>0; i--)
			printf(" ");

		for(i=0; i<L; i++)
			printf("-");
		printf("\n");

		printf("%s\n",ans);
	}
	else
	{
		for(i=l3-l1; i>0; i--)
			printf(" ");
		printf("%s\n",s1);

		for(i=l3-l2; i>0; i--)
			printf(" ");
		printf("%s\n",s2);

		for(i=l3-L; i>0; i--)
			printf(" ");

		for(i=0; i<L; i++)
			printf("-");
		printf("\n");

		for(i=0; i<l2; i++)
		{
			if(strcmp(M[i],""))
			{
				for(j=0; j < (l3 - strlen(M[i]) - i ); j++)
					printf(" ");

				printf("%s\n",M[i]);
			}
		}

		for(i=0; i<l3; i++)
			printf("-");
		printf("\n");

		printf("%s\n",ans);
	}

}

int main()
{
	char s1[MAX],s2[MAX];

	while(scanf("%s %s",s1,s2)==2)
	{
		big_multiplication(s1,s2);

		printf("\n");
	}

	return 0;
}