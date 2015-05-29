#include<iostream>
#include<map>
#include<math.h>
#include<vector>
#include<string>
using namespace std;

long prime2(long num){
	if(num==0) return 1;
	int count=0;
	while(num%2==0){
		count++;
		num=num/2;
	}
	return count;

}

long prime5(long num){
	if(num==0) return 1;
	int count=0;
	while(num%5==0){
		count++;
		num=num/5;
	}
	return count;
}

string path(vector<vector<long> > &zeroes,int i,int j,int n){
	string res="";
	if(i==0 && j==0) return "";
	else if(i==0 && j>0)
		res=path(zeroes,i,j-1,n)+"R";
	else if(i>0 && j==0)
		res=path(zeroes,i-1,j,n)+"D";
	else{
		if(zeroes[i-1][j]<zeroes[i][j-1])
			res=path(zeroes,i-1,j,n)+"D";
		else
			res=path(zeroes,i,j-1,n)+"R";
	}
	return res;


}

int main(){
	int n;
	cin>>n;
	vector<vector<long> > matrix;
	vector<vector<long> > zeroes;
	vector<vector<long> > twos;
	vector<vector<long> > fives;
	int i0=-1,j0=-1;
	for(int i=0;i<n;i++){
		matrix.push_back(vector<long>());
		for(int j=0;j<n;j++){
			long val;
			cin>>val;
			if(val==0){
				i0=i;
				j0=j;
			}
			matrix[i].push_back(val);
		}
	}


	for(int i=0;i<n;i++){
		zeroes.push_back(vector<long>());
		twos.push_back(vector<long>());
		fives.push_back(vector<long>());

		for(int j=0;j<n;j++){
			long count_two=prime2(matrix[i][j]);
			long count_five=prime5(matrix[i][j]);
			twos[i].push_back(count_two);
			fives[i].push_back(count_five);
			if(i==0 && j!=0){
				twos[i][j]+=twos[i][j-1];
				fives[i][j]+=fives[i][j-1];
			}
			else if(j==0 && i!=0){
				twos[i][j]+=twos[i-1][j];
				fives[i][j]+=fives[i-1][j];
				
			}
			else if(i>0 && j>0){
				twos[i][j]+=min(twos[i][j-1],twos[i-1][j]);
				fives[i][j]+=min(fives[i][j-1],fives[i-1][j]);

			}
			zeroes[i].push_back(min(twos[i][j],fives[i][j]));

		}
	}
	if(zeroes[n-1][n-1]!=0 && i0>=0){
		
		cout<<1<<endl;
		int i=0,j=0;
		for(;i<i0;i++)
			cout<<"D";
		for(;j<j0;j++)
			cout<<"R";
		for(;i<n-1;i++)
			cout<<"D";
		for(;j<n-1;j++)
			cout<<"R";
		return 0;
	
	}
	cout<<zeroes[n-1][n-1]<<endl;
	string result;
	if(twos[n-1][n-1]<=fives[n-1][n-1])
		result=path(twos,n-1,n-1,n);
	else
		result=path(fives,n-1,n-1,n);
	cout<<result;
}