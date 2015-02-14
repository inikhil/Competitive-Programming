#include<iostream>
using namespace std;
int main(){
    int nt,i,t;
    long long n,k,m;
    cin>>nt;
    for(i=0;i<nt;i++){
        cin>>n>>k;
        if(k==0){
            cout<<0<<" "<<n<<endl;
        }
        else if(n==0){
            cout<<0<<" "<<0<<endl;
        }
        else{
            if(n%k==0){
                cout<<n/k<<" "<<0<<endl;
            }
            else{
                cout<<n/k<<" "<<n%k<<endl;
            }
        }
    }
    return 0;
}
