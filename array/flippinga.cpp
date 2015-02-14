#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

struct index{
    char c;
    int in;
};

bool sortbyin(index a, index b){
    return a.in<b.in;
}

void solve(){
    int n,i,j,k,t,m,x,y,cnt,d=0;
    cin>>n;
    index *a=new index[2*n];
    for(i=0;i<2*n;i=(i+2)){
        cin>>a[i].in;a[i].c='a';
        cin>>a[i+1].in;a[i+1].c='b';
        a[i].in--;a[i+1].in--;
    }
    sort(a,a+2*n,sortbyin);
    int *b=new int[4];
    int *p=new int[16];
    for(i=0;i<16;i++){p[i]=0;}
    for(i=0;i<4;i++){b[i]=0;}
    t=a[0].in%4;
    m=a[0].in/4;
    if(m>0){p[0]+=m;}
    b[t]=1;cnt=1;
    char prev='a';
    for(i=1;i<2*n;i++){
        t=a[i-1].in%4;m=a[i-1].in/4;
        x=a[i].in%4;  y=a[i].in/4;
        if(m==y){
            for(j=t+1;j<x;j++){b[j]=cnt;}
            if(prev=='a' && a[i].c=='a'){cnt=(cnt+1)%2;b[x]=cnt;}
            else if(prev=='b' && a[i].c=='b'){b[x]=cnt;cnt=(cnt+1)%2;}
            else if(prev=='a' && a[i].c=='b'){b[x]=cnt;prev='b';cnt=(cnt+1)%2;}
            else if(prev=='b' && a[i].c=='a'){cnt=(cnt+1)%2;b[x]=cnt;prev='a';}
            if(i==2*n-1){d=1;}
        }
        else{
            for(j=t+1;j<4;j++){b[j]=cnt;}
            p[b[0]*8+b[1]*4+b[2]*2+b[3]]++;
            if(y-m>1){
                if(cnt==1){p[15]=p[15]+y-m-1;}
                else if(cnt==0){p[0]=p[0]+y-m-1;}
            }
            for(j=0;j<x;j++){b[j]=cnt;}
            if(prev=='a' && a[i].c=='a'){cnt=(cnt+1)%2;b[x]=cnt;}
            else if(prev=='b' && a[i].c=='b'){b[x]=cnt;cnt=(cnt+1)%2;}
            else if(prev=='a' && a[i].c=='b'){b[x]=cnt;prev='b';cnt=(cnt+1)%2;}
            else if(prev=='b' && a[i].c=='a'){cnt=(cnt+1)%2;b[x]=cnt;prev='a';}
        }
    }
    for(j=x+1;j<4;j++){b[j]=0;d=1;}
    if(d==1){p[b[0]*8+b[1]*4+b[2]*2+b[3]]++;m=10000000-4*(y+1);}
    else{m=10000000-4*(y);}
    p[0]=p[0]+m/4;
    for(i=0;i<16;i++){cout<<p[i]<<" ";}
    cout<<"\n";
}
int main(){
    int nt;
    cin>>nt;
    while(nt--){
        solve();
    }
}

