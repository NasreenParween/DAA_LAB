#include <iostream>
#include<limits.h>
#include<stdlib.h>
#include<fstream>
using namespace std;
template <class t>
class QuickSort
{
    t A[1000];
public:
    t count ,n;
    int input();
    void Randomized_quick(t A[],int p, int r);
    int Randomized_partition(t A[], int p,int r, int n);
    int partition(t A[], int p, int r);
    void display();
};
template <class t>
int QuickSort<t>::input()
{
    count=0;
    cout<<"ENTER THE NUMBER OF ELEMENTS IN AN ARRAY:"<<endl;
    cin>>n;
    for(int i=1; i<=n;i++)
    {
        A[i]=(rand()%1000)+1;
    }
    Randomized_quick(A,1,n);
}
template <class t>
int QuickSort<t>::partition(t A[],int p,int r)
{
    int x,i,j,temp,temp2;
    x=A[r];
    i=p-1;
    for(j=p; j<r; j++)
    {
        if(A[j]<=x)
        {
         i++;
         temp=A[i];
         A[i]=A[j];
         A[j]=temp;
         count++;
        }
        else{
            count++;
        }
    }
    temp2=A[i+1];
    A[i+1]=A[r];
    A[r]=temp2;
    return (i+1);
}
template <class t>
void QuickSort<t> :: Randomized_quick(t A[], int p,int r)
{
    int q;
    if(p<r)
    {
       q=Randomized_partition(A,p,r,n);
       Randomized_quick(A,p,q-1);
       Randomized_quick(A,q+1,r);
    }
}
template <class t>
int QuickSort<t> :: Randomized_partition(t A[], int p,int r, int n)
{
    int i, temp;
    i=p+rand()%(r-p+1);
    temp=A[r];
    A[r]=A[i];
    A[i]=temp;
    return partition(A,p,r);
}
template <class t>
void QuickSort<t>::display()
{
   for(int i=1; i<=n; i++){
    cout<<A[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    cout<<"....Quick SORT...."<<endl;
    ofstream f("QuickSort.csv");
    int c;
    char ch='y';
    while(ch=='y'||ch=='y')
    {
        QuickSort<int> q;
        q.input();
        cout<<"THE ELEMENT OF AN ARRAY BEFORE SORTING : "<<endl;
        q.display();
        cout<<"THE ELEMENT OF AN ARRAY AFTER SORTING :"<<endl;
        q.display();
        if(f)
        {
            f<<q.n<<","<<q.count;
            f<<endl;
        }
        cout<<"THE NUMBER OF COMPARISIONS ARE:"<<q.count<<endl;
        cout<<"\nDO YOU WANT TO CONTINUE?(y/n) :";
        cin>>ch;
        cout<<endl;
    }
    f.close();
    return 0;
}
