#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;

bool check(vector<string> s,string t)
{
	int i;
    for (i = 0;i<s.size();i++){
        if (s[i]==t){return true;}
    }
    return false;
}

void solve(int nt){
	int n,i;
	cin>>n;
    if(n==1){
       string s,d;
       cin>>s;cin>>d;
       cout<<"Case #"<<nt<<": "<<s<<"-"<<d<<endl;
       return;
    }
    string s1,s2,src,dst,temp;
   	map<string,string> mapp;
    map<string,int>cnt;
    map<string,int>::iterator it;
    vector<string> s;
    vector<string> d;
    int mi = 0;
    for(i=0;i<n;i++){
         cin>>s1;cin>>s2;
         s.push_back(s1);
         d.push_back(s2);
         mapp[s1] = s2;
         if(cnt.find(s1)!= cnt.end()){cnt[s1]++;}
         else{cnt[s1] = 1;}
         if(cnt.find (s2)!=cnt.end()){cnt[s2]++;}
         else{cnt[s2]=1;}
    }
    for(it=cnt.begin();it!=cnt.end();it++){
    	 if(it->second==1){
             s1 = it->first;
             if(check(s, s1)){src = s1;}
             else if(check(d, s1)){dst = s1;}
         }
    }
    cout<<"Case #"<<nt<<": ";
    while (src != dst)
    {
        temp=mapp[src];
        cout<<src<<"-"<<dst<<" ";
        src=temp;
    }
   	cout<<"\n";    
}
    

int main(){
	int nt,i;
	cin>>nt;
	for(i=1;i<=nt;i++){
		solve(i);
	}
}
