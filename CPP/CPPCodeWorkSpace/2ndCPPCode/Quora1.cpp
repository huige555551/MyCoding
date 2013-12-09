#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

class Topic{

public:
	int id;
	double x;
	double y;

	static double root_x;
	static double root_y;
};

double Topic::root_x;
double Topic::root_y;

int T; // num of topic
int Q; // num of questions
int N; // num of queries

int getMin(int a, int b) { return a < b? a : b;}
bool compareInt (int i, int j) { return (i>j); }

void swap(vector<Topic>& topicArray, int i, int j)
{
    Topic temp = topicArray[i];
    topicArray[i] = topicArray[j];
    topicArray[j] = temp;
}

double getDist(Topic p)
{
	double dx = p.x - Topic::root_x;
	double dy = p.y - Topic::root_y;
    return dx * dx + dy * dy;    
}

bool compareTopic(const Topic& a, const Topic& b)
{
	double da = getDist(a);
	double db = getDist(b);

	if(fabs(da-db) < 1e-8){
		return a.id > b.id;
	}
		
	return (da < db);
}

int partition(vector<Topic>& topicArray, int k, int start, int end)
{
    double pivot = getDist(topicArray[end]);
    
    int j = -1;
    for(int i = 0; i <= end-1; i++)
    {
        if(getDist(topicArray[i]) <= pivot)
        {
            j = j + 1;
            swap(topicArray, i, j);
        }
    }
    swap(topicArray, j+1, end);
    
    return j+1;
}

void find_k_nearest(vector<Topic>& topicArray, int k, char ch, map<int, vector<int> >& topic2question)
{
    int start = 0;
    int end = topicArray.size()-1;
    

    while(1)
    {
		int q = partition(topicArray, k, start, end);
        
        if (q == k-1) {
            if(ch == 't') break;
			//else ch == 'q'

			vector<bool> allQues(1001, false);
			int count = 0;
			for(int i = 0; i < k; i++)
			{
				vector<int> qList = topic2question[topicArray[i].id];
				for(int j = 0; j < (int)qList.size(); j++){
					if(!allQues[qList[j]])
					{
						allQues[qList[j]] = true;
						count++;
						if(count >= k || count >= Q) break;
					}
				}
			}

			if(q >= T-1 || count >= k || count >= Q) break;
			else if ( q < T-1 && count < k) {
				k++;
			}

		}
        else if (q < k - 1)
            start = q + 1;
        else 
            end = q - 1;
    }
}

vector<int> find_result(char ch, int n, vector<Topic>& topicArray, map<int, vector<int> >& topic2question)
{
	int k = getMin( n, topicArray.size());

	// find the k nearest topics of the location
	//find_k_nearest(topicArray, k, ch, topic2question);

	// sort the topics
	sort(topicArray.begin(), topicArray.end(), compareTopic);

	if(ch == 't') 
	{
		// get the sorted topic ids
		vector<int> tList(k);

		for(int i = 0; i < k; i++){
			tList[i] = topicArray[i].id;
		}

		return tList;
	} 
	else 
	{
		vector<bool> allQues(1001, false);
		vector<int> questList;
		int serial = 0;

		// iterate through k topic ids
		for(int i = 0; i < k; i++)
		{
			// get the question list for each topic
			vector<int> qList = topic2question[topicArray[i].id];
			for(int j = 0; j < (int)qList.size(); j++)
			{
				if(!allQues[qList[j]])
				{
					allQues[qList[j]] = true;
					questList.push_back(qList[j]); 
					serial++;
					if(serial >= n) break;
				}
			}
		}

		return questList;
	}
}

int main() 
{

	cin >> T >> Q >> N;

	vector<Topic> topicArray(T);	// topics are stored here
	//read all topic id and their location
	for(int i=0; i<T; i++) {
		Topic topic;
		cin >> topic.id >> topic.x >> topic.y;
		topicArray[i] = topic;
	}

	vector<int> question(Q);				// id for questions
	vector<list<int> > relatedTopic(Q);		// related toptic of questoin
	map<int, vector<int> > topic2question;	// map for topic to question list

	for(int i = 0; i < Q; i++)
	{
		int n;
		cin >> question[i];			//read question id
		cin >> n;					//read num of topic associated with question id
		for(int j = 0; j < n; j++)	// read all topics associated with question id 
		{
			int t; 
			cin >> t;				//topic id
			relatedTopic[i].push_back(t);
			topic2question[t].push_back(question[i]);
		}
	}

	//sort the question list for each topic - 
	//helps to get higher order question id in case of tie at the end
	//sorted in descending order
	for(int i = 0; i < topic2question.size(); i++)
		sort(topic2question[i].begin(), topic2question[i].end(), compareInt);

	//read N queries
	for(int i = 0; i < N; i++)
	{
		char ch;	// type of query - topic or question
		cin >> ch;

		int n;		// number of results wanted
		cin >> n; 

		double x, y; // location
		cin >> x >> y;

		Topic::root_x = x;
		Topic::root_y = y;

		vector<int> result = find_result(ch, n, topicArray, topic2question);

		for(int j = 0; j < result.size(); j++)
			cout << result[j] << " ";
		cout << "\n";
	}

    return 0;
}

/*
3 6 2
0 0.0 0.0
1 1.0 1.0
2 2.0 2.0
0 1 0
1 2 0 1
2 3 0 1 2
3 0
4 0
5 2 1 2
t 2 0.0 0.0
q 5 100.0 100.0
*/
