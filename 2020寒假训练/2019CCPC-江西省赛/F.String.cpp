#include<bits/stdc++.h>
using namespace std;
char s[105];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	int n;
	while(~scanf("%d%s",&n,s)){
		int a=0,v=0,i=0,n1=0;
		for(int j=0;s[j];j++){
			if(s[j]=='a')a++;
			else if(s[j]=='v')v++;
			else if(s[j]=='i')i++;
			else n1++;
		}
		printf("%d/%d\n",a*v*i*n1/gcd(a*v*i*n1,n*n*n*n),n*n*n*n/gcd(a*v*i*n1,n*n*n*n));
	}
	return 0;
}
