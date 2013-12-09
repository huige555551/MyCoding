#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Point {

  double x;
  double y;
};
    
void swap(Point* myList, int i, int j)
{
    Point temp = myList[i];
    myList[i] = myList[j];
    myList[j] = temp;
}

double getDist(Point p)
{
    return p.x * p.x + p.y * p.y;    
}

int partition(Point* myList, int n, int k, int start, int end)
{
    double pivot = getDist(myList[end]);
    
    int j = -1;
    for(int i = 0; i <= end; i++)
    {
        if(getDist(myList[i]) <= pivot)
        {
            j = j + 1;
            swap(myList, i, j);
        }
    }
    swap(myList, j+1, end);
    
    return j+1;
}

void find_k_nearest(Point* myList, int n, int k)
{
    int start = 0;
    int end = n-1;
    
    while(1)
    {
        int q = partition(myList, n, k, start, end);
        
        if (q == k-1) 
            break;
        else if (q < k - 1)
            start = q + 1;
        else 
            end = q - 1;
    }
}

static Point * closestk( Point * myList, int n, int k ) {
    
    find_k_nearest(myList, n, k);
    
    vector<Point> KPoint(n);
    
    for(int i = 0; i < k; i++){
        KPoint[i] = myList[i];
    }
    
    return &KPoint[0];
}


int main()
{
	int n = 5;
	vector<Point> myList(n);

	myList[0].x = 0; myList[0].y = 0;
	myList[1].x = 1; myList[1].y = 5;
	myList[2].x = 1; myList[2].y = -3;
	myList[3].x = 2; myList[3].y = 2;
	myList[4].x = 1; myList[4].y = 1;

	closestk(&myList[0], 5, 2);

	return 0;
}