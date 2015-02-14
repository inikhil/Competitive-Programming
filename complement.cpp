#include<iostream>
using namespace std;
int main(){
    long long n,t,i;
    cin>>n;
    for(i=1;i<=n;i=i*2){}
    cout<<(n^(i-1))<<endl;
}
