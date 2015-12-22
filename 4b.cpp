#include<iostream>
#define loop(i,n) for(int i=0;i<n;i++);
int main(){
	int d,sumtime;
	cin>>d;
	cin>>sumtime;
	vector<int> min;
	vector<int> max;
	vector<int> result;
	loop(i,d){
		int l,u;
		cin>>l;
		cin>>u;
		min.push_back(l);
		max.push_back(u);
	}
	int i=0,j=0,k=0;
	int sum=sumtime;
	while(1){
		if(sum-max[i]<0){
			break;
			int cur=sum;
			
		}
		sum-=max[i];
		result.push_back(max[i]);
		i++;
	}
	
	if(i>d){
		cout<<"NO"<<endl;
		return 0;
	}


	else{

	}


}