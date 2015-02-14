#include<iostream>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main(){
    int i,j,k,t=0;
    int *a=new int[100];
    for(i=0;i<100;i++){a[i]=5;}
    sort(a,a+100);
    for(i=0;i<150;i++){
        //cout<<"\n";
        for(j=99;j>0;j--){
            if(a[j]>a[j-1]){t=t+a[j];a[j]--;break;}
        }
        if(j==0){t=t+a[j];a[j]--;}
        //for(j=0;j<100;j++){cout<<a[j]<<" ";}
    }
    cout<<t<<endl;

}
