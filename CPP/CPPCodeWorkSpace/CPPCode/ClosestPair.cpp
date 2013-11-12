#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

struct point {
	int x;
	int y;
};

double distanc( point a, point b )
{
	double dist;

	dist = sqrt( (double)( a.x - b.x )*( a.x - b.x ) + ( a.y - b.y )*( a.y - b.y ) );

	return dist;
}
double closest_pair_simple( vector<point> P )
{
	double dist;
	double d;
	int i;
	int j;

	dist = INT_MAX;

	for( i = 0; i < P.size(); i++ ) {
		for( j = 0; j < P.size(); j++ ) {
			if( j != i ) {
				d = distanc( P[i], P[j] );
				if( d < dist ) {
					dist = d;
				}
			}
		}
	}

	return dist;
}

bool sort_x( struct point& a, struct point& b ) {
	return a.x < b.x;
}
bool sort_y( struct point& a, struct point& b ) {
	return a.y < b.y;
}
void sort_xy( vector<point> &X, vector<point> &Y ) {
	sort( X.begin(), X.end(), sort_x );
	sort( Y.begin(), Y.end(), sort_y );
}

vector< vector<point> > partition( vector<point> X, int l )
{
	vector< vector<point> > V;
	vector<point> T1;
	vector<point> T2;
	int i;

	for( i = 0; i < X.size(); i++ ) {
		if( X[i].x < l ) {
			T1.push_back(X[i]);
		} else {
			T2.push_back(X[i]);
		}
	}

	V.push_back(T1);
	V.push_back(T2);

	return V;
}

void disp( vector<point> P )
{
	int i;
	for( i = 0; i < P.size(); i++ ) {
		cout << "( " << P[i].x << ", " << P[i].y << ")\n";
	}
	cout << endl;
}

double closest_pair( vector<point> P, vector<point> X, vector<point> Y )
{
	double dist;
	int l;
	int i;
	int j;
	int k;
	double d1;
	double d2;
	double t;
	vector< vector<point> > V;
	vector<point> PL, PR, XL, XR, YL, YR, Y1;

	if( P.size() <= 3 ) {
		dist = closest_pair_simple( P );
		return dist;
	} else {
		l = X[X.size()/2].x;
		
		V = partition( P, l );
		PL = V[0];
		PR = V[1];

		V = partition( X, l );
		XL = V[0];
		XR = V[1];

		V = partition( Y, l );
		YL = V[0];
		YR = V[1];

		d1 = closest_pair( PL, XL, YL );
		d2 = closest_pair( PR, XR, YR );

		if( d1 < d2 ) {
			dist = d1;
		} else {
			dist = d2;
		}

		for( i = 0; i < Y.size(); i++ ) {
			if( Y[i].x >= l-dist && Y[i].x <= l+dist ) {
				Y1.push_back( Y[i] );
			}
		}

		for( i = 0; i < Y1.size(); i++ ) {
			for( j = 0; j < Y1.size(); j++ ) { 
			//My update: within 12 position
			//int start; if(i < 6) start = i; else start = i-6;
			//int end;   if(i+6 > Y1.size()) end = Y1.size(); else end = i+6;
			//for( j = start; j < end; j++ ) {
				if( j != i ) {
					d1 = distanc( Y1[i], Y1[j] );
					if( d1 < dist ) {
						dist = d1;
					}
				}
			}
		}

		return dist;

	}
}

int main()
{
	int n;
	int i;
	int a;
	int b;
	point p;
	double dist;
	double d;
	vector< point > P;
	vector< point > X;
	vector< point > Y;

	cout << "Enter the numbers of points: ";
	cin >> n;
	cout << "Enter the points(x,y): ";

	for( i = 0; i < n; i++ ) {

		cin >> a >> b;

		p.x = a;
		p.y = b;

		P.push_back(p);
		X.push_back(p);
		Y.push_back(p);
	}

	p.x = 0;
	p.y = 0;

	sort_xy( X, Y );

	dist = closest_pair( P, X, Y );

	cout << "The sortest distance is: " << dist << endl;

	return 0;
}

//ClosestPair takes O(logn*nlogn) = O(nlog2n) time.

/*
sample input:
6
1 3
3 5
8 7
5 6
2 0
7 5
*/