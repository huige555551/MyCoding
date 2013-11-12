#include<iostream>
using namespace std;

//f(num) = first_digit * f(power-1) + f(remainder) + t

//power: while(power*10 < num) power*=10;
//first_digit = num/power;
//remainder = num%power;
//t = |if(first_digit > 2) then 100
//	  |if(first_digit ==2) then remainder+1
//	  |else 0

int num2s(int n)
{
	//base case
	if(n==0) return 0;

	// 513 into 5 * 100 + 13. [Power = 100; First = 5; Remainder = 13]
	int power = 1;
	while(power*10 < n) power*=10;

	int first_digit = n/power;
	int remainder = n%power;

	//count 2s from first digit
	int t=0;
	if(first_digit>2) t = power;
	else if (first_digit==2) t = remainder + 1;

	//count 2s from all other digits
	int num1 = first_digit * num2s(power-1) + t;
	int num2 = num2s(remainder);

	return num1+num2;
}

int count2sI(int num) {
	int countof2s = 0, digit = 0;
	int j = num, seendigits=0, position=0, pow10_pos = 1;

	/* maintaining this value instead of calling pow() is an 6x perf
	* gain (48s -> 8s) pow10_posMinus1. maintaining this value
	* instead of calling Numof2s is an 2x perf gain (8s -> 4s).
	* overall > 10x speedup */

	while (j > 0) 
	{
		digit = j % 10;
		int pow10_posMinus1 = pow10_pos / 10;
		countof2s += digit * position * pow10_posMinus1;

		/* we do this if digit <, >, or = 2
		* Digit < 2 implies there are no 2s contributed by this
		* digit.
		* Digit == 2 implies there are 2 * numof2s contributed by
		* the previous position + num of 2s contributed by the
		* presence of this 2 */

		if (digit == 2) 
		{
			countof2s += seendigits + 1;
		}
		/* Digit > 2 implies there are digit * num of 2s by the prev.
		* position + 10^position */

		else if(digit > 2) 
		{
			countof2s += pow10_pos;
		}

		seendigits = seendigits + pow10_pos * digit;
		pow10_pos *= 10;
		position++;
		j = j / 10;
	}
	return(countof2s);
}

void main()
{
	//cout << getDigit(258, 2) << endl;
	//for(int i=0; i<550; i++)
		//cout << i << "->" << num2s(i) << endl;

	cout << num2s(513) << endl;
	cout << count2sI(513) << endl;
}