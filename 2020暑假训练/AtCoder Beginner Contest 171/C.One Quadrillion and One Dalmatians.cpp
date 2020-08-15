#include<bits/stdc++.h>
using namespace std;
char s[100];
int main(){
	long long n,si;scanf("%lld",&n);
	while(n){
		s[si++]='a'+(n-1)%26;
		n=(n-1)/26;
	}
	for(int i=0;i<si-i-1;i++)swap(s[i],s[si-i-1]);
	puts(s);
	return 0;
} 
