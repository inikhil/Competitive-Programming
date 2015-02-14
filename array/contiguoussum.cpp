#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main(){
    int nt,n,i,j;
    int maxsofar,sum,index,sum1=0;
    cin>>nt;
    while(nt--){
        cin>>n;
        maxsofar=0;sum=0;index=0;sum1=0;
        int *a=new int[n];
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        for(i=0;i<n;i++){
            if(sum<0){sum=0;}
            sum=sum+a[i];
            sum1=0;
            for(j=index;j<i;j++){
                if(a[j]==a[i]){
                    index=j+1;
                    sum=sum-sum1-a[j];
                    break;
                }
                else{
                    sum1+=a[j];
                }
            }
            if(j==i){
                maxsofar=max(maxsofar,sum);
            }
            cout<<maxsofar<<" ";
        }
        cout<<endl;
    }

}
