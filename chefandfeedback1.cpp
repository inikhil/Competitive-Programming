#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int nt,i,m,k;scanf("%d",&nt);
    char s[100000];
    while(nt--){
        scanf("%s",s);
        m=strlen(s);k=0;
        if(m==1||m==2){printf("Bad\n");}
        else{
            for(i=0;i<m-2;i++){
                if(s[i]=='0' && s[i+1]=='1' && s[i+2]=='0'){printf("Good\n");k=1;break;}
                if(s[i]=='1' && s[i+1]=='0' && s[i+2]=='1'){printf("Good\n");k=1;break;}
            }
            if(k!=1){printf("Bad\n");}
        }
    }
}
