#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

bool is_palindrome(int n){
    int m1=n;
    int m=0;
    //m=(int)(log(n)/log(2));
     while(m1 >>= 1){m++;}
    //cout<<m<<" ";
    int l=m,r=0;
    int t=l,p=r;
    while(l>r){
        if((n&(1<<l)) != ((n&(1<<r))<<(l-r))){
        //if((t>>l)&1) != (p>>r) )
            return false;
        }
        else{l--;r++;}
    }
    l=t;r=p;
   /* while(l>r){
        cout<<(n&(1<<l))<<" ";
        cout<<(n&(1<<r))<<" ";
        l--;r++;
    }*/
    return true;
}

int noofbits(int n){
    int cnt=0;
    while(n!=0){
        if(n%2==1){cnt++;}
        n=n/2;
    }
    return cnt;
}
int main(){
    int nt,n,l;
    cin>>nt;
    //printf("%d",printf("%d",printf("%d",1)));
    for(n=1;n<10;n++){
        //cout<<n<<"->"<<" ";
        if(is_palindrome(n)==true){
            cout<<n<<" "<<noofbits(n)<<endl;
        }
    }
}
