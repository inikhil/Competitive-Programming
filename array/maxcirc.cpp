#include<iostream>
#include<climits>
#include<cmath>
using namespace std;

int main(){
    int nt,n,i,maxsofar,track,m,k;
    cin>>nt;
    while(nt--){
        cin>>n;
        int *a=new int[n];
        for(i=0;i<n;i++){cin>>a[i];}
        track=0;maxsofar=INT_MIN;m=0;
        for(i=0;i<n;i++){
            //if(track<0 && m==1){break;}
            if(track<0){track=0;}
            track=track+a[i];
            maxsofar=max(maxsofar,track);
           // cout<<maxsofar<<" ";
            //if(i==n-1 && m==1){break;}
           // if(i==n-1){i=-1;m=1;}
           k=log(31)/log(2);
           cout<<k<<" ";
        }
        cout<<maxsofar<<endl;
    }
}
