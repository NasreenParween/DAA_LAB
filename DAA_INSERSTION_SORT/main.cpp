#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

template <class t>
class isort
{
public:
    t a[500];
    t n;
    void input();
    void display();
    int Sort();
};
template <class t>
void isort<t>:: input()
{
    int i;
    cout<<"\nENTER THE NUMBER OF ELEMENTS :";
    cin>>n;
    for(i=1; i<=n; i++)
        a[i]=rand()%100;
}
template<class t>
void isort<t> :: display()
{
    for(int i=1; i<=n; i++)
        cout<<a[i]<<" ";
}
template<class t>
int isort<t>:: Sort()
{
    int i,j,key,count=0;
    for(j=2; j<=n; j++)
    {
        key=a[j];
        i=j-1;
        while(i>0&&a[i]>key)
        {
            a[i+1]=a[i];
            i--;
        count++;
        }
        count++;
        a[i+1]=key;

    }
    cout<<"\nTHE ARRAY AFTER SORTING:";
    display();
    cout<<"\nTHE NUMBER OF COMARISIONS ARE :"<<count;
    return count;
}
int main()
{
   ofstream f("insertionSort.csv");
   int c;
   char ch='y';
  while(ch=='y'||ch=='Y')
   {
       isort<int>i;
       i.input();
       cout<<"THE ELEMENTS OF AN ARRAY ARE :"<<endl;
       i.display();
       c=i.Sort();
       if(f)
       {
           f<<i.n<<","<<c;
           f<<endl;
       }
        cout<<"\n...Do you want to continue ?(y/n)..."<<endl;
       cin>>ch;
   }
   f.close();
    return 0;
}
