#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
vector<int> result;
bool myfunction(pair<int,int> v1,pair<int,int> v2){
	double d1=((double)v1.second)/v1.first;
	double d2=((double)v2.second)/v2.first;
	if(d1>d2) return true;
	else if(d1==d2) return v1.first<v2.first;
	else return false; 
}

void output(vector<pair<int,int> > &vehicles,int index,unsigned long long &cap,unsigned long long volume,unsigned long long volume_lorry,map<pair<int,int>,vector<pair<int,bool> > > &m){
	
	if(volume>volume_lorry){
		cap-=((vehicles[index-1]).second);
	}
	if(index==vehicles.size())
		return;
	else{
		cap+=(vehicles[index]).second;
		volume+=(vehicles[index]).first;
		output(vehicles,index+1,cap,volume,volume_lorry,m);
		if(volume<=volume_lorry){
		pair<int,int> p=make_pair(vehicles[index].first,vehicles[index].second);
		int j=0;
		while(!((m[p])[j]).second)
			j++;
		result.push_back(((m[p])[j]).first);
		//if(index!=0) cout<<" ";
		((m[p])[j]).second=false;
	}

	}

}
int main(){
	unsigned long long volume_lorry;
	unsigned long count_vehicles;
	cin>>count_vehicles;
	cin>>volume_lorry;
	vector<pair<int,int> > vehicles;
	map<pair<int,int>,vector<pair<int,bool> > > m;
	for(int i=0;i<count_vehicles;i++){
		int type,cap;
		cin>>type;
		cin>>cap;
		vehicles.push_back(make_pair(type,cap));
		m[make_pair(type,cap)].push_back(make_pair(i+1,true));
	}
	sort(vehicles.begin(),vehicles.end(),myfunction);
	if(volume_lorry==1){
		for(int i=0;i<vehicles.size();i++){
			if(vehicles[i].first==1){
				cout<<vehicles[i].second<<endl;
				pair<int,int> p=make_pair(vehicles[i].first,vehicles[i].second);
				cout<<(m[p])[0].first<<endl;
				return 0;

			}
		}
		cout<<0<<endl;
		return 0;
	}
	unsigned long long cap=0;
	unsigned long long volume=0;
	output(vehicles,0,cap,volume,volume_lorry,m);
	volume=0;
	int pos=-1;
	int i;
	reverse(result.begin(),result.end());
	for(i=0;i<vehicles.size() ;i++){
		if(volume>volume_lorry){
			volume-=vehicles[i-1].first;
			break;
		}
		volume+=vehicles[i].first;
		if(vehicles[i].first==1)
			pos=i;

	}
	i--;
	if(volume==volume_lorry-1){
		//if(volume_lorry==1319) cout<<"in";
		for(;i<vehicles.size();i++){
			if(vehicles[i].first==2 && vehicles[i].second>vehicles[pos].second){
				pair<int,int> p=make_pair(vehicles[i].first,vehicles[i].second);
				int j=0;
				while(!((m[p])[j]).second)
					j++;
				result[pos]=(m[p])[j].first;
				cap=cap-vehicles[pos].second+vehicles[i].second;
				break;

			}

		}

	}
	cout<<cap<<endl;
	i=0;
	for(;i<result.size()-1;i++)
		cout<<result[i]<<" ";
	cout<<result[i]<<endl;
}