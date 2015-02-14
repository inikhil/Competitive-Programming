#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int nt,i,m,k;scanf("%d",&nt);
    string t;
    char s[100000];
    while(nt--){
        scanf("%s",s);
        t=s[0];m=strlen(s);k=0;
        for(i=1;i<m;i++){
            if( t=="0" && s[i]=='1'){t="01";}
            else if( t=="1" && s[i]=='0'){t="10";}
            else if( (t=="0"|| t=="10") && s[i]=='0'){t="0";}
            else if( (t=="1"||t=="01") && s[i]=='1'){t="1";}
            else if( t=="01" && s[i]=='0'){printf("Good\n");k=1;break;}
            else if( t=="10" && s[i]=='1'){printf("Good\n");k=1;break;}
        }
        if(k!=1){printf("Bad\n");}
    }
}
