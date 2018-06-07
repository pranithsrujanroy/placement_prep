/*COINS - Bytelandian gold coins
In Byteland they have a very strange monetary system.
Each Bytelandian gold coin has an integer number written on it. A coin n can be exchanged in a bank into three coins: n/2, n/3 and n/4. But these numbers are all rounded down (the banks have to make a profit).
You can also sell Bytelandian coins for American dollars. The exchange rate is 1:1. But you can not buy Bytelandian coins.
You have one gold coin. What is the maximum amount of American dollars you can get for it?*/
#include <iostream>
#include <string.h>
#include <math.h>
#include<map>
using namespace std;
#define lint long long int

map<int,lint> pr;

long long max_profit(long long n){
	if(n==0)
	    return pr[n]=0;
	if(n==1)
		return pr[n]=1;
	if(pr[n]!=0)
	    return pr[n];
	pr[n]= max(n,max_profit(floor(n/2))+max_profit(floor(n/3))+max_profit(floor(n/4)));
	return pr[n];
}

int main() {
	// your code goes here
	int n;
	while(cin>>n){
		lint l = max_profit(n);
		cout<<l<<endl;
	}
	return 0;
}
