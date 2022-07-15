#include<iostream>
using namespace std;
int max(int a,int b)
{
	return (a>b)?a:b;
}
int knapsack(int w,int val[],int wt[],int n)
{
	if(n==0 || w==0)
	{
		return 0;
	}
	if(wt[n-1]>w)
	{
		return knapsack(w,val,wt,n-1);
	}
	else
	{
		return max(val[n-1]+knapsack(w-wt[n-1],val,wt,n-1),knapsack(w,val,wt,n-1));
	}
}
int main()
{
	int val[20],wt[20];
	int w,n;
	cout<<"Enter array size of value and weight: ";
	cin>>n;
	cout<<"\nEnter elements of value array: ";
	for(int i=0;i<n;i++)
	{
		cin>>val[i];
	}
	cout<<"\nEnter elements of weight array: ";
	for(int i=0;i<n;i++)
	{
		cin>>wt[i];
	}
	cout<<"\nEnter knapsack capacity: ";
	cin>>w;
	cout<<"\nElements of value array are: \n";
	for(int i=0;i<n;i++)
	{
		cout<<"val["<<i<<"]= "<<val[i]<<"\n";
	}
	cout<<"\nElements of weight array are: \n";
	for(int i=0;i<n;i++)
	{
		cout<<"wt["<<i<<"]= "<<wt[i]<<"\n";
	}
	cout<<"\nMaximum total value in knapsack: ";
	cout<<knapsack(w,val,wt,n);
}
