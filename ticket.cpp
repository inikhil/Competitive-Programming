#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n,i,t;
    long long m;
    cin>>n>>m;
    int *a=new int[n];
    for(i=0;i<n;i++){a[i]=rand()%100000;}
    sort(a,a+n);
    t=a[n-1]+1;
    int *b=new int[t];
    for(i=0;i<t;i++){b[i]=0;}
    for(i=0;i<n;i++){b[a[i]]++;}
    i=t-1;
    long long ans=0;
    while(m>0){
        if(b[i]>=m){ans+=m*i;m=m-b[i];cout<<ans;break;}
        else{m=m-b[i];b[i-1]+=b[i];ans+=b[i]*i;i--;}
    }
}
