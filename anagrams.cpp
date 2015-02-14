#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

void sw(char *x,char *y){
    char temp;
    temp = *x;
    *x = *y;
    *y= temp;
}

bool Match(char Str[],int i,int j)
{
    if(i == j)
        return false;
    else
        for(;i<j;i++)
            if(Str[i]==Str[j])
                return true;
    return false;

}

void permute(char *s,int i,int n){
    int j;
    //cout<<"a";
    if(i==n){
        printf("%s\n",s);
    }
    else{
        for(j=i;j<=n;j++){
            //if(s[i]==s[j] && i!=j)
             //   continue;
            if(!Match(s,i,j)){
                sw(s+i,s+j);
                permute(s,i+1,n);
                sw(s+i,s+j);
            }
        }
    }
}

int main(){
    char s[100];
    int n;cin>>n;
    int i;
    scanf("%s",s);
    //permute(s,0,n-1);
    sort(s,s+n);
    do{
        for(i=0;i<n;i++){cout<<s[i];}
        cout<<"\n";
    }while(next_permutation(s,s+n));
}
