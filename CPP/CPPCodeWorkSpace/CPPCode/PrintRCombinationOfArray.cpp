#include <iostream>
#include <vector>
using namespace std;

vector<int> emptyV;

void printVector(vector<int> v)
{
	for(int i=0; i<v.size(); i++)        
        cout << v[i] << " ";
    cout << endl;
}

//include or exclude
void printCombination(int arr[], int n, int r, int index=0, vector<int>& v = emptyV)
{
	//if r element in vector, then print
    if(v.size()==r){
        printVector(v);
        return;
    }     

	//if index goes out of bound then return
	if(index >= n) return;
    
	//include current index element
    v.push_back(arr[index]);  
	while(arr[index]==arr[index+1]) index++; //extra line for removing duplicates
    printCombination(arr, n, r, index+1, v);    
    
	//exclude current index element
    v.pop_back();
    printCombination(arr, n, r, index+1, v);    
}

//similar to 8 queen
void printCombination2(int arr[], int n, int r, int index=0, vector<int>& v = emptyV)
{
	//if r element in vector, then print
    if(v.size()==r){
        printVector(v);
        return;
    }     

	//it's like 8 queen without any checking
	for(int i=index; i<n; i++){
		v.push_back(arr[i]);
		while(arr[i]==arr[i+1]) i++; //extra line for removing duplicates
		printCombination2(arr, n, r, i+1, v);
		v.pop_back();
	}
}

int main() {

	int arr[] = {1, 1, 2, 3, 4, 5};
    int r = 3;
    int n = sizeof(arr)/sizeof(arr[0]);

	cout << "First method" << endl;
    printCombination(arr, n, r);
    
	cout << "2nd method" << endl;
	printCombination2(arr, n, r);

	printVector(emptyV);
	return 0;
}