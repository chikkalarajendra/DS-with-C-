#include<iostream>
using namespace std;
template<class T>
class MergeSort{
	private:
		int size,low,high;
		T *arr;
	public:
		MergeSort(int);
		void read();
		void mergecall();
		void merge(T[],int,int);
		void mergesort(T[],int,int,int);
		void disp();
};
template<class T>
MergeSort<T>::MergeSort(int n){
	size=n;
	arr=new T[size];
}
template<class T>
void MergeSort<T>::read(){
	int i;
	cout<<"\nEnter sorting elements...";
	for(i=0;i<size;i++){
		cout<<"\nEnter arr["<<i<<"] :";
		cin>>arr[i];
	}
}
template<class T>
void MergeSort<T>::mergecall(){
	merge(arr,0,size-1);
}
template<class T>
void MergeSort<T>::merge(T arr[],int l,int h){
	int mid;
	if(l<h){
		mid=(l+h)/2;
		merge(arr,l,mid);
		merge(arr,mid+1,h);
		mergesort(arr,l,mid,h);	
	}
}
template<class T>
void MergeSort<T>::mergesort(T arr[],int l,int m,int h){
	int i,j,k;
	T temp[50];
	i=l;
	j=m+1;
	k=l;
	while(i<=m&&j<=h){
		if(arr[i]<=arr[j])
			temp[k++]=arr[i++];
		else
			temp[k++]=arr[j++];
	}
	while(i<=m)
		temp[k++]=arr[i++];
	while(j<=h)
		temp[k++]=arr[j++];
	for(k=l;k<=h;k++)
		arr[k]=temp[k];
}
template<class T>
void MergeSort<T>::disp(){
	int i;
	cout<<"\nElements are :";
	for(i=0;i<size;i++)
		cout<<"\t"<<arr[i];
}
int main(){
	int n;
	cout<<"Enter n=";
	cin>>n;
	MergeSort<char> m(n);
	m.read();
	cout<<"\nElements before sort are...";
	m.disp();
	m.mergecall();
	cout<<"\nElements after sort are...";
	m.disp();
	return 0;
}
