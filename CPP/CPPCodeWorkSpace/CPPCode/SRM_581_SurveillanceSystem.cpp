#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class SurveillanceSystem {
public:
	
	string getContainerInfo(string containers, vector <int> reports, int L) 
	{
		string output = "";
		for(int i=0; i<containers.size(); i++) output += '-';

		vector<string> subSet;
		vector<int> containerInSubset;

		for(int i=0; i<containers.size()-L+1; i++)
		{
			subSet.push_back("");
			int count = 0;
			for(int j=0; j<L; j++)
			{
				subSet[i] += containers[i+j];
				if(subSet[i][j] == 'X') count++;				
			}
			containerInSubset.push_back(count);
		}

		vector<int> numOfCamera(L+1);
		vector<int> numOfSubset(L+1);

		for(int i=0; i<reports.size(); i++) numOfCamera[reports[i]]++;
		for(int j=0; j<subSet.size(); j++) numOfSubset[containerInSubset[j]]++;

		for(int i=L; i>=0; i--)
		{
			if(numOfCamera[i]==0) continue;			

			if(numOfCamera[i] == numOfSubset[i])
			{
				for(int j=0; j<subSet.size(); j++)
				{
					if(containerInSubset[j]==i)
					{
						for(int k=0; k<L; k++)
							output[j+k] = '+';
					}
				}
			}
			else
			{
				vector<int>	slotCoverage(containers.size(), 0);

				for(int j=0; j<subSet.size(); j++)
				{
					if(containerInSubset[j]==i)	{
						for(int k=0; k<L; k++) slotCoverage[j+k]++; 						
					}
				}
				
				for(int j=0; j<containers.size(); j++){
					if(output[j]=='+') continue;
					if(slotCoverage[j] > numOfSubset[i] - numOfCamera[i])
						output[j] = '+';
					else if(slotCoverage[j] != 0) output[j] = '?';
				}
			}
		}

		return output;
	}

};

















//<%:testing-code%>

//<%:start-tests%>
double test0() {
	string p0 = "-X--XX";
	int t1[] = {1, 2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 3;
	SurveillanceSystem * obj = new SurveillanceSystem();
	clock_t start = clock();
	string my_answer = obj->getContainerInfo(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "??++++";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string p0 = "-XXXXX-";
	int t1[] = {2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 3;
	SurveillanceSystem * obj = new SurveillanceSystem();
	clock_t start = clock();
	string my_answer = obj->getContainerInfo(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "???-???";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string p0 = "------X-XX-";
	int t1[] = {3, 0, 2, 0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 5;
	SurveillanceSystem * obj = new SurveillanceSystem();
	clock_t start = clock();
	string my_answer = obj->getContainerInfo(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "++++++++++?";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string p0 = "-XXXXX---X--";
	int t1[] = {2, 1, 0, 1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 3;
	SurveillanceSystem * obj = new SurveillanceSystem();
	clock_t start = clock();
	string my_answer = obj->getContainerInfo(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "???-??++++??";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string p0 = "-XX--X-XX-X-X--X---XX-X---XXXX-----X";
	int t1[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 7;
	SurveillanceSystem * obj = new SurveillanceSystem();
	clock_t start = clock();
	string my_answer = obj->getContainerInfo(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "???++++?++++++++++++++++++++??????--";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
//<%:end-tests%>
int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
