#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

void magic_trick(int counter)
{
	int r1, r2;
	int v[17] = {0};
	int count = 0;
	int result = 0;

	cin >> r1;
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++){
			int temp;
			cin >> temp;
			if(i==r1-1) v[temp] += 1;
		}
	}
		
	cin >> r2;
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++){
			int temp;
			cin >> temp;
			if(i==r2-1) {
				v[temp] += 1;
				if(v[temp] > 1) {
					count++;
					result = temp;
				}
			}
		}
	}
		
	cout << "Case #" << counter << ": ";
	if(count == 0) cout << "Volunteer cheated!"; 
	else if (count > 1) cout << "Bad magician!";
	else if (count == 1) cout << result;
	cout << "\n";
}

int main()
{
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("output.out", "w", stdout);

	int input_count;
	cin >> input_count;

	int counter = 1;
	while(input_count)
	{
		magic_trick(counter++);

		//finish work
		input_count--;
	}

	return 0;
}