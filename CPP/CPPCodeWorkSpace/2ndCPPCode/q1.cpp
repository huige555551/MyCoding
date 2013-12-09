#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

struct Topic {
    int id;
    double x, y;
    Topic(int id, double x, double y): id(id), x(x), y(y) {}
};

bool more(int a, int b) { return a > b; }

struct Distance 
{
    double x, y;

    Distance(double x, double y): x(x), y(y) {}

    bool operator() (Topic *a, Topic *b) 
	{
        double da = (x - a->x) * (x - a->x) + (y - a->y) * (y - a->y);
        double db = (x - b->x) * (x - b->x) + (y - b->y) * (y - b->y);
        
		if (fabs(da - db) < 1e-8) {
            return a->id > b->id;
        }
        return da < db;
    }
};

int main()
{
    int T, Q, N;
    cin >> T >> Q >> N;
    vector<Topic*> topics;
    for (int t = 0; t < T; t++) {
        int id;
        double x, y;
        cin >> id >> x >> y;
        topics.push_back(new Topic(id, x, y));
    }

    typedef map<int, vector<int> > Questions; // topic_id to vector of question_ids
    Questions questions;
    for (int q = 0; q < Q; q++) {
        int id, Qn;
        cin >> id >> Qn;
        for (int qn = 0; qn < Qn; qn++) {
            int tid;
            cin >> tid;
            questions[tid].push_back(id);
        }
    }

    for (Questions::iterator it = questions.begin(); it != questions.end(); it++) {
        sort(it->second.begin(), it->second.end(), more);
    }

    // Try brute forcing, with n=1000 O(n^2 log n) might as well work.
    for (int n = 0; n < N; n++) {
        char c;
        int m, z;
        double x, y;
        cin >> c >> m >> x >> y;
        z = m;

        Distance d(x, y);
        sort(topics.begin(), topics.end(), d);
        if (c == 't') {
            for (int i = 0; i < topics.size() && m; i++, m--) {
                if (i > 0) {
                    cout << " ";
                }
                cout << topics[i]->id;
            }
        }
        if (c == 'q') 
		{
            set<int> s, t;
            bool first = true;
            for (int i = 0; i < topics.size() && (m > 0 || !t.empty()); i++) 
			{
                if (!t.empty()) 
				{
                    Topic *t1 = topics[i];
                    Topic *t2 = topics[i - 1];
                    double da = (x - t1->x) * (x - t1->x) + (y - t1->y) * (y - t1->y);
                    double db = (x - t2->x) * (x - t2->x) + (y - t2->y) * (y - t2->y);
                    if (fabs(da - db) >= 1e-8) 
					{
                        vector<int> v(t.begin(), t.end());
                        sort(v.begin(), v.end(), more);
                        for (int j = 0; j < v.size() && z; j++) 
						{
                            if (first) {
                                first = false;
                            } else {
                                cout << " ";
                            }
                            cout << v[j];
                            z--;
                        }
                        t.clear();
                        if (m <= 0) break;
                    }
                }
                vector<int>& v = questions[topics[i]->id];
                for (int j = 0; j < v.size() && (m > 0|| !t.empty()); j++) {
                    if (s.find(v[j]) == s.end()) {
                        s.insert(v[j]);
                        t.insert(v[j]);
                        m--;
                    }
                }
            }
            if (!t.empty()) {
                vector<int> v(t.begin(), t.end());
                sort(v.begin(), v.end(), more);
                for (int j = 0; j < v.size() && z; j++) {
                    if (first) {
                        first = false;
                    } else {
                        cout << " ";
                    }
                    cout << v[j];
                    z--;
                }
            }
        }
        cout << endl;
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
