#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;
template <class t>
class msort
{

public:
    t a[1000];
    int count;
    int n;
    void input();
    void display();
    t mergesort(t a[], int p, int r);
    void Merge(t a[],int p, int q,int r);
};
template <class t>
void msort<t>:: input()
{
    int i;
    cout<<"\n ENTER THE NUMBER OF ELEMENTS :"<<endl;
    cin>>n;
    for(i=1;i<=n;i++)
        a[i]=rand()%100;
}
template <class t>
void msort<t>::display()
{
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
}
template <class t>
t msort<t>:: mergesort(t a[],int p, int r)
{
    if(p<r)
    {
        int q=(p+r-1)/2;
        mergesort(a,p,q);
        mergesort(a,q+1,r);
        Merge(a,p,q,r);

    }
    return count;
}
template <class t>
void msort<t>:: Merge(t a[], int p, int q, int r)
{
  int i,j;
  int n1=q-p+1;
  int n2=r-q;
  t L[500] , R[500];
  for(i=1;i<=n;i++)
    L[i]=a[p+i-1];
  for(j=1; j<=n;j++)
    R[j]=a[q+j];
    L[n1+1]=INT_MAX;
    R[n2+1]=INT_MAX;
    i=j=1;
    for(int k=p; k<=r; k++)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        count++;
    }
}
int main()
{
    ofstream f("mergesort.csv");
    int c;
    char ch='y';
    while(ch=='y'||ch=='y')
    {
        msort<int>m;

        m.input();
        cout<<"\n THE ELEMENT OF AN ARRAY ARE :";
        m.display();
        m.count=0;
        c=m.mergesort(m.a,1,m.n);
        cout<<"\n AFTER SORTHING THE ELEMENTS ARE:"<<endl;
        m.display();
        if(f)
        {
            f<<m.n<<","<<c;
            f<<endl;
        }
         cout << "\n THE NUMBER OF COMPARISIONS ARE :" << c;
         cout<<"\n DO YOU WANT TO CONTINUE ? (y/n) ";
         cin>>ch;
    }
    cout<<"\n NUMBER OF COMPARISIONS :"<<c;
    f.close();

    return 0;
}
