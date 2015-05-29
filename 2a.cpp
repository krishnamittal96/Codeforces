#include<iostream>
#include<string>
#include<sstream>
#include<map>
#include<math.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	map<int,map<string,int> > m;
	for(int i=1;i<=n;i++){
		string name;
		cin>>name;
		string s;
		cin>>s;
		int num=stoi(s);
		if(i==1){
			(m[i])[name]=num;
		}
		else{
			m[i]=m[i-1];
			if(m[i].find(name)==m[i].end())
				(m[i])[name]=num;
			else
				(m[i])[name]+=num;
		}
	}
	int max=-1;
	string winner;
	for(auto it=m[n].begin();it!=m[n].end();it++){
		if(it->second>max){
			winner=it->first;
			max=it->second;
		}
		else if(it->second==max){
			for(auto jt=m.begin();jt!=m.end();jt++){
				if((jt->second).find(winner)!=(jt->second).end() && (jt->second)[winner] >=max)
					break;
				if((jt->second).find(it->first)!=(jt->second).end() && (jt->second)[it->first] >=max){
					winner=it->first;
					break;
				}
			}


		}
	}

	cout<<winner;
}