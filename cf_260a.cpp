#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<math.h>
using namespace std;
int solver(vector<int> &v,vector<vector<int> > &dp,/*vector<vector<bool> > &visited*/unordered_map<int,pair<int,int> > &m,int start, int end){
  if(start<0 || end>=v.size() || end<start) return 0;
  if(dp[start][end]!=INT_MIN) return dp[start][end];

  // case when you select the current value
  int sum1 = (m[v[end]].second - m[v[end]].first + 1) * v[end];
  int start1 = start, start2=-1, end1=-1,end2=end;

  if(m.find(v[end]-1)!=m.end())
    end1=m[v[end]-1].first-1;
  else
    end1=m[v[end]].first-1;

  if(m.find(v[end]+1)!=m.end())
    start2=m[v[end]+1].second+1;
  else
    start2=m[v[end]].second+1;

  sum1+=solver(v,dp,/*visited,*/m,start1,end1);
  sum1+=solver(v,dp,/*visited,*/m,start2,end2);

  // case when you don't select the current value
  int sum2 = solver(v,dp,/*visited,*/m,start,end-1);

  //visited[start][end] = true;
  return dp[start][end] = max(sum1,sum2);
}
int main(){
  vector<int> v;
  unordered_map<int,pair<int,int> > m;
  int n; cin>>n;
  for(int i=0;i<n;i++){
    int val; cin>>val;
    v.push_back(val);
  }
  sort(v.begin(),v.end());
  for(int i=0;i<v.size();i++){
    if(m.find(v[i]) == m.end())
      m[v[i]] = make_pair(i,i);
    else
      m[v[i]].second = i;
  }
  vector<vector<int> > dp(n,vector<int>(n,INT_MIN));
//  vector<vector<bool> > visited(n,vector<bool>(n,false));
  cout<<solver(v,dp,/*visited,*/m,0,n-1)<<endl;
  return 0;
}

