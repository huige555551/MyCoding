#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> maxheap;
vector<int> minheap;

bool maxheapcomparator(int i, int j){ return i<j;}
bool minheapcomparator(int i, int j){ return i>j;}

//[0,N)
int random_num_gen(int N)
{
	//return rand()%N;
	//return rand()/(RAND_MAX/N+1);
	return (rand()/(RAND_MAX+1.0))*N;
}

//maxhead always be greater or equal to minheap
void add_new_number(int n)
{
	if(maxheap.size()==minheap.size())
	{
		if(minheap.size()!=0 && n>minheap.front())
		{
			maxheap.push_back(minheap.front());
			push_heap(maxheap.begin(), maxheap.end(), maxheapcomparator);

			pop_heap(minheap.begin(), minheap.end(), minheapcomparator);
			minheap.pop_back();

			minheap.push_back(n);
			push_heap(minheap.begin(), minheap.end(), minheapcomparator);

		}
		else
		{
			maxheap.push_back(n);
			push_heap(maxheap.begin(), maxheap.end(), maxheapcomparator);
		}
	}
	else
	{
		if(n < maxheap.front()){
			minheap.push_back(maxheap.front());
			push_heap(minheap.begin(), minheap.end(), minheapcomparator);

			pop_heap(maxheap.begin(), maxheap.end(), maxheapcomparator);
			maxheap.pop_back();

			maxheap.push_back(n);
			push_heap(maxheap.begin(), maxheap.end(), maxheapcomparator);
		}
		else{
			minheap.push_back(n);
			push_heap(minheap.begin(), minheap.end(), minheapcomparator);
		}
	}
}

double getMedian()
{
	if(maxheap.size()==0) 
		return 0;
	else if(maxheap.size()==minheap.size())
	{
		return (maxheap.front()+minheap.front())/2.0;
	}
	else if(maxheap.size() > minheap.size())
	{
		return maxheap.front();
	}
	else{
		return minheap.front();
	}
}

int main()
{
	for(int i=0; i<10; i++)
	{
		int n = random_num_gen(100);		
		add_new_number(n);
		double m = getMedian();

		cout << "Insert: " << n << endl;

		cout << "Maxheap: ";
		for(int i=0; i<maxheap.size(); i++) cout << maxheap[i] << " ";
		cout << endl << "Minheap: ";		
		for(int i=0; i<minheap.size(); i++) cout << minheap[i] << " ";
		cout << endl;

		cout << "Median: " << m << endl;
	}
	

	/*int myints[] = {10,20,30,5,15};
	std::vector<int> v(myints,myints+5);

	std::make_heap (v.begin(),v.end());
	std::cout << "initial max heap   : " << v.front() << '\n';

	std::pop_heap (v.begin(),v.end()); v.pop_back();
	std::cout << "max heap after pop : " << v.front() << '\n';

	v.push_back(99); std::push_heap (v.begin(),v.end());
	std::cout << "max heap after push: " << v.front() << '\n';

	std::sort_heap (v.begin(),v.end());

	std::cout << "final sorted range :";
    for (unsigned i=0; i<v.size(); i++)
		std::cout << ' ' << v[i];*/

	return 0;
}
