#include < iostream >
#include < queue >

using namespace std;

void push(queue<int> &q, int num)
{
	q.push(num);

	for(int i=0; i<q.size()-1; i++)
	{
		int temp = q.front(); q.pop();
		q.push(temp);
	}
}

void pop(queue<int> &q)
{
	if(!q.empty())
	{
		int temp = q.front(); q.pop();
		printf("%d\n",temp);

		return;
	}
}

queue<int> q1;
queue<int> q2;

void push2(int num)
{
	if(q1.empty())
		q1.push(num);
	else
	{
		while(!q1.empty())
		{
			int temp = q1.front(); q1.pop();
			q2.push(temp);
		}

		q1.push(num);

		while(!q2.empty())
		{
			int temp = q2.front(); q2.pop();
			q1.push(temp);
		}

	}
	
}

void main()
{
	queue<int> q;
	push(q,1);
	push(q,2);
	push(q,3);
	push(q,4);

	push2(1);
	push2(2);
	push2(3);
	push2(4);

	pop(q);
	pop(q);
	pop(q);
	pop(q);

	pop(q1);
	pop(q1);
	pop(q1);
	pop(q1);


	getchar();
}