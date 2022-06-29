#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
template <class t>
class bsort
{
public:
t a[500];
t n;
void input();
void display();
int sort();
};
template <class t>
void bsort<t>::input()
{
int i;
cout<<"\nEnter the number of elements:";
cin>>n;
for(i=1;i<=n;i++)
a[i]=rand()%100;
}
template <class t>
void bsort<t>::display()
{
for(int i=1;i<=n;i++)
cout<<a[i]<<" ";
}
template <class t>
int bsort<t>::sort()
{
int temp,i,j,swap,count=0;
for(i=1;i<=n;i++)
{
swap=0;
for(j=1;j<=(n-i);j++)
{
if(a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
swap=1;
}
count++;
}
if(swap==0)
    {
break;
}
}
cout<<"\nArray after Sorting : ";
display();
cout<<"\nThe number of Comparisons are : "<<count;
return count;
}
int main()
{
ofstream f("bubbleSort.csv");
int c;
char ch='y';
while(ch=='y'||ch=='Y')
{
bsort<int> i;
i.input();
cout<<"\nElements of Array are : ";
i.display();
c=i.sort();
if(f)
{
f<<i.n<<","<<c;
f<<endl;
}
cout<<"\nDo you wish to continue(y/n) : ";
cin>>ch;
}
f.close();
return 0;
}

