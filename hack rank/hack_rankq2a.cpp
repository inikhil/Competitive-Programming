#include<iostream>
using namespace std;
int main(){
    int n,l,i,j,cunt=0,t,k,p,q;
    cin>>n>>l;
    int *a=new int[n];
    for(i=0;i<n;i++){
        a[i]=0;
    }
    int **b=new int*[l];
    for(j=0;j<l;j++){
        b[j]=new int[2];
    }
    for(i=0;i<l;i++){
        cin>>b[i][0];
        cin>>b[i][1];
    }
   // return 0;
    k=1;
    for(i=0;i<l;i++){
       p=b[i][0];
       q=b[i][1];
       if((a[p]==0)&&(a[q]==0)){
            a[p]=k;
            a[q]=k;
            for(j=i+1;j<l;j++){
                if(b[j][0]==p||b[j][0]==q){
                    a[b[j][1]]=k;
                }
                if(b[j][1]==p||b[j][1]==q){
                    a[b[j][0]]=k;
                }
            }
            k++;
       }
       else if(a[p]>0){
            a[q]=a[p];
       }
       else{
            a[p]=a[q];
       }
       /*for(j=0;j<n;j++){
            cout<<a[j]<<" ";
       }
       cout<<"\n";*/

    }
    for(i=0;i<n;i++){
        if(a[i]==0){
            a[i]=k;
            k++;
        }
    }
    int *c=new int[k];
    for(i=0;i<k;i++){
        c[i]=0;
    }
    for(i=0;i<n;i++){
        //cout<<a[i]<<" ";
        t=a[i];
        c[t]=c[t]+1;
    }
   // cout<<"\n";
  /* for(i=1;i<k;i++){
        cout<<c[i]<<" ";
    }
    cout<<"\n";*/
    if(k==2){
        cout<<0;
        return 0;
    }
    for(i=1;i<k;i++){
        for(j=i+1;j<k;j++){
            cunt=cunt+c[i]*c[j];
        }
    }
    cout<<cunt<<endl;
}
