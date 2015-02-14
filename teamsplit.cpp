#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    int nt,n,a,b,c,d,x,y,z,m,i,xx,yy;
    long long t,ans=0;
    scanf("%d",&nt);
    while(nt--){
        scanf("%d %d %d %d %d",&n,&a,&b,&c,&d);
        int *s=new int[n];
        int *ss=new int[1000000];
        for(i=0;i<1000000;i++){ss[i]=0;}
        s[0]=d;ss[d]++;xx=s[0];
        for(i=1;i<n;i++){
            t=(long long) s[i-1]*s[i-1]; //cout<<t<<" ";
            x=((t%1000000)*a)%1000000;//cout<<x<<" ";
            y=(s[i-1]*b)%1000000;//cout<<y<<" ";
            s[i]=(x+y+c)%1000000;//cout<<xx<<" ";
            ss[s[i]]=(ss[s[i]]+1)%2;
            if(s[i]>xx){xx=s[i];}
            if(s[i]==s[i-1]){
                if((n-1-i)%2==1){ss[s[i]]=1;break;}
                else{ss[s[i]]=0;break;}
            }
            //cout<<s[i]<<endl;
        }
        //sort(s,s+n);
        m=1;ans=0;
        for(i=xx;i>=0;i--){
            if(ss[i]!=0){
                if(m==1){ans=ans + i;m=0;}
                else if(m==0){ans=ans - i;m=1;}
            }
        }
        if(ans<0){ans=ans*-1;}
        printf("%lld\n",ans);
    }
}
