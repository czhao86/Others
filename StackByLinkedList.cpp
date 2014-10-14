#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

struct node
{
	int key;
	node *next;
};

node* init(int a[],int n)
{
	node *head=new node;
	node *p=head;
	for (int i=0;i<n;++i)
	{
		if (i==0) {head->key=a[i];head->next=NULL;continue;}
		node *q=new node;
		p->next=q;
		q->key=a[i];
		p=q;
	}
	return head;
}

class Stack
{
	node* head;
public:
	Stack();
	~Stack();
	void stackpush(int n);
	int stackpop();
};

Stack::Stack()
{
	head=NULL;
}

Stack::~Stack()
{
	while (head)
	{
		node *tmp=head->next;
		delete head;
		head=tmp;
	}
}

void Stack::stackpush(int n)
{
	node *p=new node;
	p->next=head;
	p->key=n;
	head=p;
}

int Stack::stackpop()
{
	if (head==NULL) throw 12;
	node *p=head;
	int k=head->key;
	head=p->next;
	delete p;
	return k;
}

int main()
{
	// int a[]={1,2,3,4,5};
	// node* head=init(a,5);
	Stack st;
	st.stackpush(1);
	cout<<st.stackpop();
	cout<<st.stackpop();
	return 0;
}
