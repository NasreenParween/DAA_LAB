#include <iostream>
#include<stdlib.h>
using namespace std;
#define max 30
template<class t>
class node
{
	public:
	node *next;
	int vertex;
};
template<class t>
class graphq
{
	public:
	int data[max];
	int rear,front;
	void enqueue(graphq *, int);
	int dequeue(graphq *);
	int empty(graphq *);
	int full(graphq *);
	void BFS(int);
	void readgraph();
	void insert(int vi, int vj);
	int discovered[max];
	int layer[max],parent[max];
	node<t> *heads[max];
	int n;
};


template<class t>
void graphq<t>::BFS(int v)
{
	int w,i;
	graphq Q;
	node<t> *p;
	Q.rear=Q.front=-1;
	for(i=1;i<=n;i++)
	discovered[i]=0;
	enqueue(&Q,v);
	int ly=0;
	layer[v]=ly;
	parent[v]=-1;
	cout<<"\nVisit "<<v;
	cout<<"\tand its parent is none and layer is : "<<layer[v];
	discovered[v]=1;
	ly=1;
	while(!empty(&Q))
	{
		v=dequeue(&Q);
		for(p=heads[v];p!=NULL;p=p->next)
		{
			w=p->vertex;
			if(discovered[w]==0)
			{
				parent[w]=v;
				layer[w]=layer[parent[w]]+1;
				enqueue(&Q,w);
				discovered[w]=1;
				cout<<"\nVisit "<<w;
				cout<<"\nParent of "<<w<<" is "<<parent[w]<<" and its layer is "<<layer[w];
				}
		}
	}
}
template<class t>
int graphq<t>::empty(graphq *p)
{
	if(p->rear==-1)
	return(1);
	return(0);
}
template<class t>
int graphq<t>::full(graphq *p)
{
	if(p->rear==max-1)
	return(1);
	return(0);
}
template<class t>
void graphq<t>::enqueue(graphq *p, int x)
{
	if(p->rear==-1)
	{
		p->rear=p->front=0;
		p->data[p->rear]=x;
	}
	else
	{
		p->rear=p->rear+1;
		p->data[p->rear]=x;
	}
}
template<class t>
int graphq<t>::dequeue(graphq *p)
{
	int x;
	x=p->data[p->front];
	if(p->rear==p->front)
	{
		p->rear=-1;
		p->front=-1;
	}
	else
	p->front=p->front+1;
	return(x);
}
template<class t>
void graphq<t>::readgraph()
{
	int i,vi,vj, nofedges;
	cout<<"\nEnter the number of vertices : ";
	cin>>n;
	for(i=0;i<n;i++)
	heads[i]=NULL;
	cout<<"\nEnter the number of edges : ";
	cin>>nofedges;
	for(i=0;i<nofedges;i++)
	{
		cout<<"\nEnter an edge (u,v) : ";
		cin>>vi>>vj;
		insert(vi,vj);
		insert(vj,vi);
	}
}
template<class t>
void graphq<t>::insert(int vi, int vj)
{
	node<t>*P;
	node<t>*Q;
	Q=new node<t>;
	Q->vertex=vj;
	Q->next=NULL;
	if(heads[vi]==NULL)
	heads[vi]=Q;
	else
	{
		P=heads[vi];
		while(P->next!=NULL)
		P=P->next;
		P->next=Q;
	}
}
int main()
{
	int i;
	graphq<int>gq;
	cout<<"\nCreate a node";
	gq.readgraph();
	cout<<"\nBFS";
	cout<<"\nStarting node number : ";
	cin>>i;
	gq.BFS(i);
	return 0;
}
