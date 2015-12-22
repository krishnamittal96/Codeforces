#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
  int n,m;
  cin>>n;
  cin>>m;
  vector<int> v(m,0);
  for(int i=0;i<v.size();i++)
    cin>>v[i];
  sort(v.begin(),v.end());
  int mindist=INT_MAX;
  for(int i=0;i<=m-n;i++)
    mindist = fmin(mindist,v[i+n-1]-v[i]);
  cout<<mindist;
}

