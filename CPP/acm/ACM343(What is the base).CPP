#include<stdio.h>
#include<string.h>
#include<math.h>

int digit_value(char c)
{
	if( (c>='0') && (c<='9') ) return c-'0';
	else if((c>='A') && (c<='Z')) return c-'A'+10;

	return -1;
}

int max_digit(char *z)
{
	int i,k,max=0;

	for(i=0; z[i]; i++)
	{
		k = digit_value(z[i]);
		if(max<k)
		{
			max=k;
		}
	}

	return max;
}

long long value(char *x,int base)
{
	int i,l=strlen(x)-1;
	long long val=0;

	for(i=strlen(x)-1; i>=0; i--)
	{
		val=val+digit_value(x[i])*pow(base,l-i);
	}

	return val;
}

void main()
{
	char x[50],y[50];
	int i,j,done,min_base_x,min_base_y;
	long long value_x,value_y;

	/*freopen("343.in","r",stdin);*/

	while(scanf("%s %s",x,y)==2)
	{
		min_base_x = max_digit(x)+1;
		min_base_y = max_digit(y)+1;

		if(min_base_x<2) min_base_x=2;
		if(min_base_y<2) min_base_y=2;

		for(i=min_base_x; i<=36; i++)
		{
			value_x = value(x,i);
			done=0;

			for(j=min_base_y; j<=36; j++)
			{
				value_y = value(y,j);
				if(value_x == value_y)
				{
					printf("%s (base %d) = %s (base %d)\n",x,i,y,j);
					done=1;
					break;
				}
			}

			if(done) break;
		}
		if(!done)
			printf("%s is not equal to %s in any base 2..36\n",x,y);
	}
}