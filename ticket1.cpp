#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,m,i,t,p,q,k;
    cin>>n>>m;
    int *a=new int[n];
    for(i=0;i<n;i++){cin>>a[i];}
    sort(a,a+n);
    vector<int> index;
    vector<int> freq;
    int cnt=1;
    for(i=n-1;i>=0;i--){
        if(i==0){
            index.push_back(a[i]);
            freq.push_back(cnt);
        }
        else if(a[i]==a[i-1]){cnt++;}
        else{
            index.push_back(a[i]);
            freq.push_back(cnt);
            cnt=1;
        }
    }
    i=0;
    long long ans=0;
    while(i<index.size()){
        if(freq[i]>=m){ans+=(long long)index[i]*m;break;}
        else{
            ans+=(long long) index[i]*freq[i];
            if(index[i+1]+1==index[i]){
                freq[i+1]+=freq[i];
                m=m-freq[i];
                i++;
            }
            else{
                k=index[i]-index[i+1]-1;
                t=freq[i]*k;
                m=m-freq[i];
                if(m>=t){
                    freq[i+1]+=freq[i];
                    m=m-t;//cout<<m<<" ";
                    ans+=(long long) t*index[i+1] + (long long)freq[i]*((long long)k*(k+1))/2;
                    i++;
                }
                else{
                    p=m/freq[i];q=m%freq[i];
                    ans+=(long long) p*freq[i]*index[i] - freq[i]*(p*(p+1))/2;
                    ans+=(long long) q*(index[i]-p-1);
                    break;
                }
            }
        }
    }
    if(i==index.size()){cout<<-1<<endl;}
    else{cout<<ans<<endl;}
}
