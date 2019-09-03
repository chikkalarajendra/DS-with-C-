#include<iostream>
using namespace std;

template<typename T>
class Quick{
     private:
        int size;
        T *arr;
     public:
        Quick(int);
        void read();
        void quickcall();
        int quicksort(T[],int,int);
        void swap(int &,int &);
        void disp();
};
template<typename T>
Quick<T>::Quick(int n){
size=n;
arr=new T[size];
}
template<typename T>
void Quick<T>::read(){
cout<<"\n enter elements...\n";
for(int i=0;i<size;i++) 
{
cout<<"enter arr["<<i<<"]:";
cin>>arr[i];
}
}
template<typename T>
void Quick<T>::quickcall(){
quicksort(arr,0,size-1);
}
template<typename T>
int Quick<T>::quicksort(T arr[],int lb,int ub)
{
int l=lb,u=ub,p=l;
if(lb>ub)
return 0;
while(l<u)
{
while(arr[u]>=arr[p] && p!=u)
u--;
if(p==u)
break;
if(arr[u]<arr[p])
swap(u,p);
p=u;
while(arr[l]>=arr[p] && p!=l)
l++;
if(p==l)
break;
if(arr[l]<arr[p])
swap(l,p);
p=l;
}
quicksort(arr,lb,p-1);
quicksort(arr,p+1,ub);
}
template<typename T>
void Quick<T>::swap(int &i,int &j){
T t;
t=arr[i];
arr[i]=arr[j];
arr[j]=t;
}
template<typename T>
void Quick<T>::disp(){
cout<<"\n elements are:";
for(int i=0;i<size;i++)
cout<<arr[i]<<"\t";
}
int main()
{
int n;
cout<<"Enter size:";
cin>>n;
Quick<int> s(n);
s.read();
cout<<"\n elements before sort are...";
s.disp();
s.quickcall();
cout<<"\n elements after sort are...";
s.disp();
cout<<"Enter size:";
cin>>n;
Quick<float> f(n);
f.read();
cout<<"\n elements before sort are...";
f.disp();
f.quickcall();
cout<<"\n elements after sort are...";
f.disp();
}
