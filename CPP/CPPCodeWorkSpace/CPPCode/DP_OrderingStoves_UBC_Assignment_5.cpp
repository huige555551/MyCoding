#include <iostream>
using namespace std;

#define MAX 200

int getMinimum(const int *dynamicTable)
{
	int minValue = MAX;

	for(int order=0; order<=6; order+=1)
	{
		if(dynamicTable[order] < minValue)
			minValue = dynamicTable[order];
	}

	return minValue;
}

int main()
{
	const int demand[5]={20,30,30,30,10};
	const int month = 5;
	const int initialRange = 5; //0 10 20...40
	const int orderAmount = 7; // 0 10 20....60
	const int initialHighest = 40; // 0 10 20 30 40

	int dynamicTable[month][initialRange][orderAmount]={0};

	int costOfOrder=10;
	
	for(int i=4; i>=0; i--) //per stage/month
	{
		for(int j=0; j<=4; j+=1) //per state/initialValue
		{
			for(int k=0; k<=6; k+=1) //per orderValue
			{
				if( j*10+k*10 < demand[i] ) { dynamicTable[i][j][k] = MAX; continue; }
				if(i==4 && j*10+k*10 > demand[i]) { dynamicTable[i][j][k] = MAX; continue; }
				
				if(k>0) dynamicTable[i][j][k] += costOfOrder;
				dynamicTable[i][j][k] += 0.20*(j*10+k*10-demand[i]);				
				
				if(i!=4) {
					int currentState = (j*10+k*10-demand[i])/10;
					if(currentState <= 4){
						int temp = getMinimum( dynamicTable[i+1][currentState] );
						dynamicTable[i][j][k] += temp; //getmin from previous stage with holding stoves
					}
					else
						dynamicTable[i][j][k] += MAX;
				}
				 
			}			
		}
	}

	cout << dynamicTable[0][0][demand[0]/10];
	getchar();
}