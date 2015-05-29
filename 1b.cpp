#include<iostream>
#include<string>
#include<math.h>
using namespace std;
void convert1(string cell){
	string row="";
	int column=0;
	int i=cell.size()-1;
	int p=0;
	while(cell[i]!='C'){
		column+=(cell[i]%48)*(pow(10.0,p));
		p++;
		i--;
	}
	i--;
	while(cell[i]!='R'){
		row+=cell[i];
		i--;
	}

	string c="";
	while(column!=0){
		if(column%26!=0){
			c+=64+(column%26);
			column=column/26;
		}
		else{
			column=column/26;
			column--;
			c+='Z';
		}

		
	}
	int j=c.size()-1;
	while(j>=0){
		cout<<c[j];
		j--;
	}
	j=row.size()-1;
	while(j>=0){
		cout<<row[j];
		j--;
	}
}

void convert2(string cell){
	string row="";
	string column="";
	int i=0;
	for(;cell[i]>=65;i++){
		column+=cell[i];
	}
	while(i<cell.size()){
		row+=cell[i];
		i++;
	}
	i=column.size()-1;
	int c=0;
	int p=0;
	while(i>=0){
		int num=column[i]%64;
		c+=num*(pow(26.0,p));
		p++;
		i--;

	}
	cout<<"R"<<row<<"C"<<c;

}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string cell;
		cin>>cell;
		/*if(cell[0]=='R' && cell.find_first_of('C')!=cell.npos &&cell[1]!='C')
			convert1(cell);*/
		if(cell[0]=='R' && cell[1]<=57 && cell.find_first_of('C')!=cell.npos && cell[cell.find_first_of('C')+1]<=57)
			convert1(cell);
		else
			convert2(cell);
		cout<<endl;
	}
	return 0;

}