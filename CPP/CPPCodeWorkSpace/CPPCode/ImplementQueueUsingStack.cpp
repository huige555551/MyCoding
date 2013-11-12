#include < iostream >
#include < stack >
using namespace std;

void queueInsert(stack<int> &s, int num)
{
	if(s.empty())
	{
		s.push(num);
	}
	else
	{
		int temp = s.top(); s.pop();
		queueInsert(s,num);
		s.push(temp);
	}
}

int queueRemove(stack<int> &s)
{
	if(!s.empty())
	{
		int temp = s.top();
		s.pop();
		printf("%d\n",temp);

		return temp;
	}

	return 0;
}

void main()
{
	stack<int> s;
	queueInsert(s,1);
	queueInsert(s,2);
	queueInsert(s,3);
	queueInsert(s,4);

	queueRemove(s);
	queueRemove(s);
	queueRemove(s);
	queueRemove(s);
	
}

//using 2 stacks
/*
	stack : inbox, outbox

	insert -> inbox.push()
	remove ()
	{	
		if (outbox is empty)
			transfer inbox to outbox : outbox.push(inbox.pop())
			outbox.pop()
		else
			outbox.pop();
	}
*/