#include<iostream>
#include<cstdio>
using namespace std;

void solve(int n){
    int *c=new int[8];
    int *a=new int[16];
    int *b=new int[16];
    int x,y,i,j,k,nz=0;
    for(i=0;i<8;i++){c[i]=0;}
    scanf("%d",&x);
    for(i=0;i<16;i++){scanf("%d",&a[i]);}
    scanf("%d",&y);
    for(i=0;i<16;i++){scanf("%d",&b[i]);}
    x=(x-1)*4;y=(y-1)*4;k=0;
    for(i=x;i<x+4;i++){
        for(j=y;j<y+4;j++){
            if(a[i]==b[j]){c[k]=a[i];k++;}
        }
    }
    for(i=0;i<8;i++){
        if(c[i]==0){nz++;}
    }
    if(nz==8){printf("Case #%d: Volunteer cheated!\n",n);}
    else if(nz==7){printf("Case #%d: %d\n",n,c[0]);}
    else{printf("Case #%d: Bad magician!\n",n);}

}

int main(){
    int nt,i;
    scanf("%d",&nt);
    for(i=1;i<=nt;i++){
        solve(i);

    }
}
