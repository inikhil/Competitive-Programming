#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,i,cnt=0,t=0;
    long long int x,sum=0;
    scanf("%d",&n);
    scanf("%lld",&x);
    int *a=new int[n];
    for(i=0;i<n;i++){scanf("%d",&a[i]);sum+=a[i];}
   // if(sum<=x){printf("0 0\n");return 0;}
    sort(a,a+n);
    for(i=0;i<n;i++){
        if(a[i]%2==0){
            if(x-a[i]/2>=0){x=x-a[i]/2;cnt++;a[i]=a[i]/2;}
            else{break;}
        }
        else{
            if(x-a[i]/2>=0){x=x-a[i]/2-1;cnt++;a[i]=a[i]/2;}
            else{break;}
        }
    }
    for(i=0;i<n;i++){
        if(x-a[i]>=0){x=x-a[i];t++;}
        else{break;}
    }
    cnt=n-cnt;
    printf("%d %d\n",cnt,t);
}
