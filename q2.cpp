#include<iostream>
#include<cstdio>
#include<algorithm>
#include<sstream>
#include<fstream>
using namespace std;

ifstream myfile;
ofstream myfile1;



class value{
public:
	int ind;
	int val;
};

bool sortbyval(value c, value d){
	return c.val<d.val;
}


void solve(int n){
		int i,t,k,l;
		value *a=new value[2*n];
		for(i=0;i<2*n;i=(i+2)){
			myfile>>a[i].val;
			myfile>>a[i+1].val;
			a[i].ind=1;
			a[i+1].ind=-1;
		}
		sort(a,a+2*n,sortbyval);
		int *b=new int[a[2*n-1].val+1];
		int cnt=0;
		int j=0;
		for(j=0;j<a[0].val;j++){
			b[j]=0;
		}
		b[a[0].val]=1;
		cnt=1;
		for(i=1;i<2*n;i++){
			for(j=a[i-1].val+1;j<=a[i].val;j++){
				b[j]=cnt;
			}
			if(a[i].ind==1){cnt++;b[a[i].val]=cnt;}
			else if(a[i].ind==-1){cnt--;}
		}
		myfile>>t;
		while(t--){
			myfile>>k;
			if(k>a[2*n-1].val+1){myfile1<<0<<" ";}
			else{myfile1<<b[k]<<" ";}
		}
		myfile1<<"\n";
}


int main(){
	int nt,n,i,t,k,l;
	static int m=1;
	myfile.open("input.txt");
    myfile1.open("output.txt");
	myfile>>nt;
	while(nt--){
		myfile >> n;
		//myfile1<<n;
		myfile1<<"Case #"<<m<<": ";
		solve(n);
		m++;
		//myfile1<<nt;
	}
}

