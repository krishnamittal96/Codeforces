#include<iostream>
#include<vector>
#include<unordered_map>
#include<math.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  if(n==0){
    cout<<0;
    return 0;
  }
  vector<int> v;
  for(int i=0;i<n;i++){
    int val;
    cin>>val;
    v.push_back(val);
  }
  unordered_map<int,int> latest;
  int start = 0, end = 0, len = 1, curmin=v[0], curmax=v[0];
  while(start<n){
    if(end == n){
      if(v[start] ==  curmin && latest[curmin] == start)
        curmin++;
      if(v[start] == curmax && latest[curmax] == start)
        curmax--;
      start++;
      end--;
    }
    latest[v[end]] = end;
    if(v[end] >= curmax)
      curmax = v[end];
    if(v[end] <= curmin)
      curmin = v[end];
    if(abs(curmax-curmin) <= 1){
      len = max(len,end-start+1);
      end++;
    }
    else{
      if(v[start] ==  curmin && latest[curmin] == start)
        curmin++;
      if(v[start] == curmax && latest[curmax] == start)
        curmax--;
      start++;
    }
  }
  cout<<len;
  return 0;
}
