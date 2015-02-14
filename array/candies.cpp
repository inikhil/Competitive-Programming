int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,i;
    cin>>n;
    long long sum=0,ans=0;
    long long *a=new long long[n];
    for(i=0;i<n;i++){
        cin>>a[i];sum=sum+a[i];
    }
    sum=(long long)sum/n;
    for(i=0;i<n;i++){
        ans+=abs(sum-a[i]);
    }
    cout<<ans<<endl;
    return 0;
}
