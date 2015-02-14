#include<iostream>
#include<cstdio>
#include<sstream>
#include<fstream>
using namespace std;
ifstream myfile;
ofstream myfile1;

int main(){
	int nt,i,n,p,q,k,j,t;
	static int m=1;
	myfile.open("input.txt");
	myfile1.open("output1.txt");
	myfile>>nt;
	while(nt--){
		myfile>>n;
		//cout<<n;
		int *b=new int[5001];
		for(i=0;i<5001;i++){
			b[i]=0;
		}
		for(i=0;i<2*n;i=(i+2)){
			myfile>>p;
			myfile>>q;
			for(j=p;j<=q;j++){
				b[j]++;
			}
		}
		myfile>>k;
		//cout<<k;
		myfile1<<"Case #";
		myfile1<<m;
		myfile1<<": ";
		for(i=0;i<k;i++){
			myfile>>t;
			//cout<<t;
			myfile1<<b[t]<<" ";
			//cout<<b[t];
		}
		myfile1<<"\n";
		m++;
	}
}
