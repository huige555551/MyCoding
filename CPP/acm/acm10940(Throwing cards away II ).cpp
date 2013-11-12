#include<stdio.h>
#include<math.h>
//it is josephus problem
void main()
{
	long i,v,f,n,ans;

	while(scanf("%ld",&n)==1)
	{
		if(n==0) break;

		else if(n==1) printf("1\n");
		
		else
		{
			for(i=0;i<20;i++)
			{ 
				v=pow(2,i); 
		
				if(n<=v) break; 		 
			} 
	
			f=pow(2,i-1); 

			ans=n-f;

			printf("%ld\n",ans*2);
		}
	}
}