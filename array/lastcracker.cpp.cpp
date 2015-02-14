#include<iostream>
using namespace std;

int main(){
    int nt,n,m,a;
    cin>>nt;
    while(nt--){
        cin>>n>>a>>m;
        a=(a+m)%n;
        if(a==0){cout<<n<<endl;}
        else{cout<<a<<endl;}
    }
}
