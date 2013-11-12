#include<stdio.h>
#include<math.h>

void main()
{
	int divisor,max_divisor,total_divisor,count;
	long int i,u,l,num,temp_num,m;

	scanf("%d",&count);

	for(count; count>0; count--)
	{
		scanf("%ld %ld",&u,&l);

		max_divisor=0;
		for(num=u; num<=l; num++)
		{
			temp_num=num;
			total_divisor=1;

			for(i=2; i<=sqrt(temp_num); i++)
			{
				divisor=1;

				while(!(temp_num%i))
				{
					divisor++;
					temp_num/=i;
				}

				total_divisor*=divisor;
			}

			if(temp_num!=1)
				total_divisor*=2;

			if(total_divisor>max_divisor)
			{
				max_divisor=total_divisor;
				m=num;
			}
		}

		printf("Between %ld and %ld, %ld has a maximum of %d divisors.\n",u,l,m,max_divisor);
	}
}

/*
let 170:
1st prime factor:2,5,17
so its total_divisors:(1+1)*(1+1)*(1+1)=8

so we set divisor=1 at first.it indicate the extra 1.
look carefully at :: i<=sqrt(num)

in case of 170:
170/2=85;
85/5=17;

after this total_divisor=4;
but to accout 17 we set condition :if(temp_num!=1) total_divisor*=2;

note::a number can have prime factors less than sqrt(num) or
one prime factor greater than that. In this case it is 17.
sqrt(85)=9.21956


	  ****** MISTAKE:******
i first used i<=sqrt(num);  but it takes valuable time.
it should be i<sqrt(temp_num);
*/
