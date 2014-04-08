#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
using namespace std;

class Node
{
public:  
    int value; //each end points of all intervals
    Node* left;
    Node* right;

	//intervals that intersect with the node value
	set<int> leftEnds;  //left ends of intervals - sorted
	set<int> rightEnds; //right ends of intervals - sorted

	//constructor
	Node(int val): value(val), left(NULL), right(NULL){}
};

//count the number of intervals intersect with the num
int num_of_intervals(Node* root, int num)
{
    if(root == NULL)        
        return 0;

    int count = 0;

    if(num < root->value)
    {
		//check the leftends of the intervals which intersect the current root node
		//in ascending order while leftend starts before the num
        auto it = root->leftEnds.begin();
		while(it != root->leftEnds.end() &&  *it < num)
		{
			count++;
			it++;
		}

        return count + num_of_intervals(root->left, num);
    }
    else //if (num >= root->value)
    {
		//check the rightends of the intervals that intersect with the current node
		//in descending order WHILE rightend of the inreval ends after the num
        auto it = root->rightEnds.rbegin();
		while(it != root->rightEnds.rend())
        {
			count++;
			it++;
        }

        return count + num_of_intervals(root->right,num);
    }
}

//add one interval to the tree
void add_interval(Node* root, pair<int, int> interval)
{
    if(root==NULL)
        return;

	//if interval ends before the current endpoint then go to left side
    if(interval.second < root->value)
        add_interval(root->left, interval);

	//if interval starts after the current endpoint then go to right side
    else if(interval.first > root->value)
        add_interval(root->right, interval);

    else
    {
		//add the interval in the current node and return
        root->leftEnds.insert(interval.first);
        root->rightEnds.insert(interval.second);
    }
}

//add the intervals to the tree with endpoints
void add_all_intervals(Node* root, map<int, int> intervals)
{
    for(auto it = intervals.begin(); it!= intervals.end(); it++)
    {
        add_interval(root, make_pair(it->first, it->second));
    }
}

//build a balanced tree with all the end points
Node* build_tree(int left_index, int right_index, vector<int> numbers)
{
    if(left_index > right_index)
        return NULL;

    int index = (left_index + right_index)/2;
	Node* root = new Node(numbers[index]);

    root->left = build_tree(left_index, index-1, numbers);
    root->right = build_tree(index+1, right_index, numbers);

	return root;
}

int main()
{
    // Read input from a file and store it in suitable data structure
	ifstream file("interval_input.txt", ios_base::in);
	if(!file) cout << "file error";

    string line;
    vector<int> numbers;
    map<int, int> intervals;
    while(!file.eof())
    {
        getline(file, line);
        istringstream stream(line);
		if(line.empty()) continue;
        int num1,num2;
        stream >> num1;
        stream >> num2;

        numbers.push_back(num1);
        numbers.push_back(num2);
        intervals[num1] = num2;
    }

    sort(numbers.begin(),numbers.end());

    // Display the intervals that have been read from the file
    for(auto it = intervals.begin(); it != intervals.end(); it++)
        cout << "(" << it->first << "-" << it->second << ") ";
    cout << endl;

    // Build tree and add the intervals
    Node* root = build_tree(0, numbers.size()-1, numbers);  
    add_all_intervals(root, intervals);

    // Enter the number for which intervals are to be searched
    cout <<  "Enter a number" << endl;
    int num;
    cin >> num;

    cout << "The number of intervals for " << num << " are " << num_of_intervals(root, num) << endl;

    system("pause");
	return 0;
}

/*
5 20
15 30
28 40 
50 70
0 9 
60 90

// This function builds the tree out of the interval values
Node* build_tree(int left_index, int right_index, vector<int> numbers);

// This function adds the appropriate intervals in the tree nodes
void add_all_intervals(Node* root, map < int,int >);

// Helper function for add_intervals
void add_interval(Node *root, pair < int,int >);

// Returns the number of valid intervals for a given number
int num_of_intervals(Node* root,int num);
*/