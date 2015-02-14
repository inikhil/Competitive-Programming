 #include<iostream>
 #include<cstdio>
 #include<cstdlib>
 #include<algorithm>
 using namespace std;

# define m 1000000007;

int main(){
    int nt,n,i,j;
    cin>>nt;
    while(nt--){
        cin>>n;
            long long *a=new long long[n+1];
            a[0]=0;
            a[1]=2;
            a[2]=5;
            for(i=3;i<=n;i++){a[i]=2*a[i-1]+a[i-2]+a[i-3];a[i]=a[i]%m;}
            cout<<a[n]<<endl;
    }
}
