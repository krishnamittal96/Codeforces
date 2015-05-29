#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<map>
using namespace std;

void output(map<pair<int,int>,pair<int,int> > &m,int x1,int y1,int x2,int y2,int count){
	if(x2==x1 && y2==y1){
		cout<<count<<endl;
		return;
	}
	count++;
	pair<int,int> parent=m[make_pair(x2,y2)];
	output(m,x1,y1,parent.first,parent.second,count);
	if(parent.first==x2+1 && parent.second==y2){
		cout<<'L'<<endl;
	}
	else if(parent.first==x2-1 && parent.second==y2){
		cout<<'R'<<endl;
	}
	else if(parent.first==x2 && parent.second==y2-1){
		cout<<'U'<<endl;
	}
	else if(parent.first==x2 && parent.second==y2+1){
		cout<<'D'<<endl;
	}
	else if(parent.first==x2-1 && parent.second==y2-1)
		cout<<"RU"<<endl;
	else if(parent.first==x2-1 && parent.second==y2+1)
		cout<<"RD"<<endl;
	else if(parent.first==x2+1 && parent.second==y2-1)
		cout<<"LU"<<endl;
	else
		cout<<"LD"<<endl;

}
int main(){
	string s1,s2;
	cin>>s1;
	cin>>s2;
	bool visited[8][8];
	memset(visited,false,sizeof(visited[0][0])*64);
	map<pair<int,int>,pair<int,int> > m;
	int x1=s1[0]%97;
	int y1=s1[1]%49;
	int x2=s2[0]%97;
	int y2=s2[1]%49;
	if(x1==x2 && y1==y2){
		cout<<0<<endl;
		return 0;
	}
	queue<pair<int,int> > q;
	q.push(make_pair(x1,y1));
	while(!q.empty()){
		pair<int,int> cur=q.front();
		q.pop();
		int x=cur.first;
		int y=cur.second;
		if(x==x2 && y==y2){
		 break;
		}
		bool up=false,down=false,left=false,right=false;
		
		if(x-1>=0 && !visited[x-1][y]){
			q.push(make_pair(x-1,y));
			visited[x-1][y]=true;
			m[make_pair(x-1,y)]=make_pair(x,y);
			left=true;
		}

		if(x+1<8 && !visited[x+1][y]){
			q.push(make_pair(x+1,y));
			visited[x+1][y]=true;
			m[make_pair(x+1,y)]=make_pair(x,y);
			right=true;
		}

		if(y-1>=0 && !visited[x][y-1]){
			q.push(make_pair(x,y-1));
			visited[x][y-1]=true;
			m[make_pair(x,y-1)]=make_pair(x,y);
			down=true;

		}

		if(y+1<8 && !visited[x][y+1]){
			q.push(make_pair(x,y+1));
			visited[x][y+1]=true;
			m[make_pair(x,y+1)]=make_pair(x,y);
			up=true;

		}

		if(left && up &&!visited[x-1][y+1]){
			q.push(make_pair(x-1,y+1));
			visited[x-1][y+1]=true;
			m[make_pair(x-1,y+1)]=make_pair(x,y);

		}

		if(left && down &&!visited[x-1][y-1]){
			q.push(make_pair(x-1,y-1));
			visited[x-1][y-1]=true;
			m[make_pair(x-1,y-1)]=make_pair(x,y);

		}

		if(right && up &&!visited[x+1][y+1]){
			q.push(make_pair(x+1,y+1));
			visited[x+1][y+1]=true;
			m[make_pair(x+1,y+1)]=make_pair(x,y);

		}

		if(right && down &&!visited[x+1][y-1]){
			q.push(make_pair(x+1,y-1));
			visited[x+1][y-1]=true;
			m[make_pair(x+1,y-1)]=make_pair(x,y);

		}
	}
	output(m,x1,y1,x2,y2,0);
	return 0;
}