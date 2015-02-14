#include<iostream>
using namespace std;
int small(int n,int m){
    if(n<m){
        return n;
    }
    return m;
}
int maxsize(int area,int t,int u,int v){
    int i,m=0;
    i=t;
    double n,n1,n2;
    while(m!=1){
        n=(double)area/(i*i);
        n1=(double)u/i;
        n2=(double)v/i;
        if(((n-int(n))==0)&&((n1-int(n1))==0)&&((n2-int(n2))==0)){
            m=1;
            return n;
        }
        i--;
    }
}
int main(){
    int t,i,j,area,m;
    cin>>t;
    int **a =new int*[t];
    for(i=0;i<t;i++){
        a[i]=new int[2];
    }
    for(i=0;i<t;i++){
        cin>>a[i][0];
        cin>>a[i][1];
    }
    for(i=0;i<t;i++){
        m=small(a[i][0],a[i][1]);
        area=a[i][0]*a[i][1];
        m=maxsize(area,m,a[i][0],a[i][1]);
        cout<<m;
        if(i!=t-1){
            cout<<"\n";
        }
    }
    return 0;
}
