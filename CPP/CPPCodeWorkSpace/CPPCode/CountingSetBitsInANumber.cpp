#include <stdio.h>

int CoutSetBits(int Num)
{

	for(int count=0; Num; Num >>= 1)
	{
		if (Num & 1) 
		{
			printf("1");
			count++;
		}
		else
		{
			printf("0");
		}

	}
	return count;
}

int CoutSetBits2(int Num)
{

	for(int count =0; Num; count++)
	{	
    	Num &= Num -1;
	}
	return count;
}


//negative number cannot be print like this
//bcoz
//1 = 0000 0001
//0 = 0000 0000 
//-1= 1111 1111 
//-2= 1111 1110
//-3= 1111 1101
void printBits(int num)
{
	if(!num)
		return;
	else
	{
		printBits(num>>1);
		if(num&1)
			printf("1");
		else
			printf("0");

		return;
	}
}

template<class T>
void printBits2(T num)
{
	T bytes = sizeof(num);

	for(T i=8*bytes-1; i>=0; i--)
	{
		if(num & 1<<i)
			printf("1");
		else printf("0");
	}
}

void main()
{
	int i;
	
	i=CoutSetBits(6);	
	i=CoutSetBits2(1);	

	printf("\n%d\n",i);

	//printBits(-127);
	printBits2<char>(-2);
	printf("\n");

}
