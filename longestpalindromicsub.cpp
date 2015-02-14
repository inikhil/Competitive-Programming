#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct table{
    int tot,left,right;
};
void lps(char* str,int n){
    table a[n][n];
    int i,p,j;
    memset(a,0,sizeof(a));
    for(i=0;i<n;i++){
        a[i][i].tot=1;a[i][i].left=i;a[i][i].right=i;
    }
    for(p=1;p<n;p++){
        for(i=0,j=p;j<n;i++,j++){
            if(str[i]==str[j]){
                if(i!=j){a[i][j].tot=2+a[i+1][j-1].tot;}
                else{a[i][j].tot=1+a[i+1][j-1].tot;}
                a[i][j].left=i;
                a[i][j].right=j;
            }
            else if(a[i+1][j].tot>a[i][j-1].tot){
                a[i][j].tot=a[i+1][j].tot;
                a[i][j].left=i+1;
                a[i][j].right=j;
            }
            else{
                a[i][j].tot=a[i][j-1].tot;
                a[i][j].left=i;
                a[i][j].right=j-1;
            }
        }
    }
    for(i=a[0][n-1].left;i<=a[0][n-1].right;i++){
        cout<<str[i];
    }
    cout<<"\n";
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<a[i][j].tot<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    char str[1000];
    int n;
    scanf("%s",str);
    n=strlen(str);
    lps(str,n);
}
