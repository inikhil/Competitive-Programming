#include<iostream>
using namespace std;
int main(){
    int n,l,i,b,c,j,cunt=1,t;
    cin>>n>>l;
    int *a=new int[n];
    for(i=0;i<n;i++){
        a[i]=0;
    }
    cin>>b>>c;
    a[b]=1;
    a[c]=1;
    i=2;
    for(j=1;j<l;j++){
        cin>>b>>c;
        if((a[b]>0)&&(a[c]==0)){
            a[c]=a[b];
        }
        else if((a[c]>0)&&(a[b]==0)){
            a[b]=a[c];
        }
        //else if((a[b]>0)&&(a[c]>0)){
          //  if(a[b]<a[c]){

            //}
        //}
        else{
            a[b]=i;
            a[c]=i;
            i++;
        }
    }
    int *m=new int[i];
    for(j=0;j<i;j++){
        m[j]=0;
    }
    for(j=0;j<n;j++){
        b=a[j];
        m[b]++;
    }
    for(j=1;j<i;j++){
        cunt=cunt*m[j];
    }
    cout<<cunt<<endl;
}
