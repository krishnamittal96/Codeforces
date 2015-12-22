#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n; cin>>n;
  if(n==0) {
    cout<<n;
    return 0;
  }
  vector<int> v(n,0);
  for(int i=0;i<n;i++)
    cin>>v[i];
  vector<int> dp(n,1);
  int maxlen = 1;
  for(int i=1;i<n;i++){
    if(v[i]>=v[i-1])
      dp[i] = dp[i-1]+1;
    maxlen = max(dp[i],maxlen);
  }
  cout<<maxlen;
  return 0;
}

