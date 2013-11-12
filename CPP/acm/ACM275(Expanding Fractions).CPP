#include<stdio.h>
#include<string.h>

int gcd(int x,int y)
{
	int dividend,divisor,remainder=1,gcd;

	dividend=x>y?x:y;
	divisor=x>y?y:x;

	while(remainder)
	{
		remainder=dividend%divisor;

		dividend=divisor;
		divisor=remainder;
	}

	return dividend;
}

void main()
{
	int a,b,temp_a;
	int g,i,j,found,x,ans;
	int digit[3001],temp[3001];

	while(scanf("%d%d",&a,&b)==2)
	{
		if(a==0 &&b ==0) break;

		memset(digit,0,sizeof(digit));
		memset(temp,0,sizeof(temp));

		temp_a=a;

		if(a!=0)
		{
			printf(".");

			g=gcd(a,b);
			a=a/g; b=b/g;

			a=a%b;


			found=0;
			for(i=0; i<3001; i++)
			{
				a=a*10;
				digit[i]=a/b;
				temp[i]=a%b;

				a=a%b;
				if(a==0)break;

				for(j=0; j<i; j++)
				{
					if(temp[j]==temp[i])
					{
						found=1;
						break;
					}
				}

				if(found) break;
			}

			if(found)
			{
				ans=i-j;

				if(j==0 && digit[i]==digit[j])
				{
					i--;
				}

				for(x=0; x<=i; x++)
				{
					if(x==49)printf("\n");
					if(x>49 && !((x+1)%50))printf("\n");
					printf("%d",digit[x]);
				}
				printf("\nThe last %d digits repeat forever.\n",ans);
			}
			else
			{
				for(x=0; x<=i; x++)
				{
					printf("%d",digit[x]);
				}
				printf("\nThis expansion terminates.\n");
			}


		}
		if(temp_a==0)
		{
			printf(".0\n");
			printf("This expansion terminates.\n");
		}
		printf("\n");
	}
}