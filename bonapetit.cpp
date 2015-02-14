#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct person{int s;int f;int p;};
bool sortbycomp(const person &lhs, const person &rhs) { return lhs.p < rhs.p; }
bool sortbyfin(const person &lhs, const person &rhs) { return lhs.f < rhs.f; }
int main(){
    int nt,n,k,i,j,c,sum=0,fini,m;scanf("%d",&nt);
    while(nt--){
        scanf("%d %d",&n,&k);
        person *a=new person[n];
        for(i=0;i<n;i++){scanf("%d %d %d",&a[i].s,&a[i].f,&a[i].p);}
        sort(a,a+n,sortbycomp);
        j=0;m=0;sum=0;
        for(i=0;i<n;i=j){
            m=0;
            for(j=i;m!=1;j++){
                if(j==n){m=1;}
                else if(a[j].p!=a[i].p){m=1;}
            }
            j=j-1;
            sort(a+i,a+j,sortbyfin);
            sum=sum++;fini=a[i].f;
            for(c=i+1;c<j;c++){
                if(a[c].s>=fini){sum++;fini=a[c].f;}
            }
        }
        //for(i=0;i<n;i++){printf("%d %d %d",a[i].s,a[i].f,a[i].p);cout<<"\n";}
        //cout<<"\n";
        printf("%d\n",sum);
    }
}
