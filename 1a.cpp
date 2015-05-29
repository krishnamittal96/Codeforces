#include<iostream>
using namespace std;
int main(){
	double n,m,a;
	cin>>n;
	cin>>m;
	cin>>a;
	long double x=n/a;
	long double y=m/a;
	if(x!=unsigned long long(x))
	x++;
	if(y!=unsigned long long(y))
	y++;
	unsigned long long res=unsigned long long(x)*unsigned long long(y);
	cout<<res;
	return 0;
	
}