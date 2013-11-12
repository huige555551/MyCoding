#include<stdio.h>

long a[10002];
long index=1;

void Median()
{
	long t;

	if(index%2!=0)
	{
		t=a[index/2+1];
	}
	else
	{
		t=(a[index/2]+a[index/2+1])/2;
	}

	printf("%ld\n",t);
}

void main()
{
	long i,j,t,sort;

	/*freopen("in.txt","r",stdin);*/

	while(scanf("%d",&a[index])!=EOF)
	{
		if(index==1) printf("%ld\n",a[1]);
		else
		{
			sort=0;

			for(i=1; i<=index-1; i++)
			{
				if(a[index]<a[i])
				{
					sort=1;
					break;
				}
			}
			if(sort)
			{
				t=a[i];
				a[i]=a[index];
				for(j=index; j>i+1; j--)
				{
					a[j]=a[j-1];
				}
				a[i+1]=t;
			}

			Median();
		}
		index++;
	}
}


/*#include <stdio.h>

long a[10000],b[10000];
long index=1;

void shift_up()
{
	long item,i,j;

	j=index;
	i=j/2;
	item=a[index];

	while( (i>0) && (a[i]<item) )
	{
		a[j]=a[i];
		j=i;
		i=j/2;
	}
	a[j]=item;
}

void shift_down(long n)
{
	long item,i,max;

	item=b[1];

	i=1;

	while((2*i)<=n)
	{
		if(2*i+1 <= n)
			max=b[2*i]>b[2*i+1] ? (2*i) : (2*i+1);
		else max=2*i;

		if(item<b[max])
		{
			b[i]=b[max];
			i=max;
		}
		else break;
	}

	b[i]=item;
}

void heap_sort()
{
	long i,t;

	for(i=index; i>=2; i--)
	{
		t=b[i];
		b[i]=b[1];
		b[1]=t;

		shift_down(i-1);
	}
}

void Median()
{
	long t;

	if(index%2!=0)
	{
		t=b[index/2+1];
	}
	else
	{
		t=(b[index/2]+b[index/2+1])/2;
	}

	printf("%ld\n",t);
}

void main()
{
	long i;

	while(scanf("%d",&a[index])!=EOF)
	{
		if(index==1) printf("%ld\n",a[index]);

		else
		{
			shift_up();

			for(i=1; i<=index; i++)
				b[i]=a[i];

			heap_sort();

			Median();
		}
		index++;
	}
}
*/