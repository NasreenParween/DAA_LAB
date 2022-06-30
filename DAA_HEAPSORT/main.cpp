#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
template<class t>
class HeapSort
{
t A[1000];
public:
int size, heap_size, count;
t temp;
void input();
void display();
void MAX_HEAPIFY(t A[], int i);
void BUILD_MAX_HEAP(t A[]);
void heapsort(t A[]);
int left(int i);
int right(int i);
};
template<class t>
void HeapSort<t>::input()
{
count=0;
cout<<"Enter the size of Array : ";
cin>>size;
cout<<"\nEnter the elements of the Array : ";
for(int i=1;i<=size;i++)
{
A[i]=(rand()%1000 + 1);
cout<<A[i]<<"\t";
}
heap_size=size;
heapsort(A);
}
template<class t>
void HeapSort<t>::display()
{
cout<<"\nSorted Array : ";
for(int i=1;i<=size;i++)
{
cout<<A[i]<<"\t";
}
cout<<"\nNo of Comparisons : "<<count;
}
template<class t>
void HeapSort<t>::MAX_HEAPIFY(t A[], int i)
{
int l,r,largest;
l=left(i);
r=right(i);
if(l<=heap_size && A[l]>A[i])
largest=l;
else
largest=i;
count++;
if(r<=heap_size && A[r]>A[largest])
largest=r;
count++;
if(largest!=i)
{
temp=A[i];
A[i]=A[largest];
A[largest]=temp;
MAX_HEAPIFY(A,largest);
}
}
template<class t>
void HeapSort<t>::BUILD_MAX_HEAP(t A[])
{
for(int i=size/2;i>=1;i--)
{
MAX_HEAPIFY(A,i);
}
}
template<class t>
void HeapSort<t>::heapsort(t A[])
{
BUILD_MAX_HEAP(A);
for(int i=size;i>=2;i--)
{
temp=A[1];
A[1]=A[i];
A[i]=temp;
heap_size=heap_size-1;
MAX_HEAPIFY(A,1);
}
}
template<class t>
int HeapSort<t>::left(int i)
{
return(i*2);
}
template<class t>
int HeapSort<t>::right(int i)
{
return(i*2+1);
}
int main()
{
HeapSort<int> h;
ofstream fout;
fout.open("HeapSort.csv");
char ch='y';
while(ch=='y'||ch=='Y')
{
h.input();
h.display();
fout<<h.size<<","<<h.count;
fout<<endl;
cout<<"\n\nDo you wish to continue(y/n) : ";
cin>>ch;
}
fout.close();
return 0;
}

