#include <iostream>
#include <string.h>
using namespace std;
int main(){
	while(1){
		string str;
		cin>>str;
		if(!strcmp(str.c_str(),"0"))
			break;
		int l=str.length();
		int p[l+1]={0};
		p[0]=p[1]=1;
		for(int i=2;i<=l;i++){
			int ch1 = str[i-2]-'0';
			int ch2 = str[i-1]-'0';
			if(ch2!=0)
				p[i]=p[i-1];
			if(ch1==1 || (ch1==2 && ch2<=6))
				p[i]+=p[i-2];
		}
		cout<<p[l]<<endl;
	}
	return 0;
}