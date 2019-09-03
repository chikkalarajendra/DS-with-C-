#include<iostream>
using namespace std;
class Sparse{
	int a[10][10],r,c,ct,sm[3][30],t[30][3];
	public:
		int f;
		Sparse(int r,int c){
			this->r=r;
			this->c=c;
			ct=0;
			f=0;
		}
		void read();
		void convert();
		void transpose();
		void display();
		void display1();
		void display2();
};
void Sparse::read(){
	int i,j;
	cout<<"\nEnter Sparse Matrix:";
	for(i=0;i<r;i++)
		for(j=0;j<c;j++){
			cout<<"\nEnter element a["<<i<<"]["<<j<<"] :";
			cin>>a[i][j];
		}
	ct=0;
	cout<<"\ncount ="<<ct;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(a[i][j]!=0){
				ct++;
			}
		}
	}
	cout<<"\ncount ="<<ct;
	cout<<"\nMatrix is=\n";
	if(ct<(r*c)/2){
		f=1;
		display();
		cout<<"\nIts is a Sparse Matrix";
	}else{
		display();
		cout<<"\nIts is not a Sparse Matrix";
	}
}
void Sparse::display(){
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}
}
void Sparse::display1(){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<ct;j++){
			cout<<sm[i][j]<<"\t";
		}
		cout<<"\n";
	}
}
void Sparse::display2(){
	int i,j;
	for(i=0;i<ct;i++){
		for(j=0;j<3;j++){
			cout<<t[i][j]<<"\t";
		}
		cout<<"\n";
	}
}


void Sparse::convert(){
	int k,i,j;
	k=0;
	sm[3][ct]=(0);
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(a[i][j]!=0){
				sm[0][k]=i;
				sm[1][k]=j;
				sm[2][k]=a[i][j];
				k++;	
			}
			
		}
	}
}
void Sparse::transpose(){
	int i,j;
	t[ct][3]=(0);
	for(i=0;i<ct;i++)
		for(j=0;j<3;j++)
			t[i][j]=sm[j][i];
}
int main(){
	int f;
	Sparse s(3,3);
	s.read();
	f=s.f;
	if(f==1){
		s.convert();
		cout<<"\n Converted Matrix is:\n";
		s.display1();
		s.transpose();
		cout<<"\nAfter Transpose Matrix is:\n";
		s.display2();
		return 0;	
	}
	else
		return 0;
	
	
	
}
