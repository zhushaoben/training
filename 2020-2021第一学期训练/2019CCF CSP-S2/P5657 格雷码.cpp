#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long uLL;
char s[100];int si;
void calc(int n,uLL k){
	if(!n)return;
	if(k<(1llu<<(n-1)))s[si++]='0',calc(n-1,k);
	else s[si++]='1',calc(n-1,(1llu<<(n-1))-(k-(1llu<<(n-1)))-1);
}
int main(){
	int n;uLL k;scanf("%d%llu",&n,&k);
	si=0;calc(n,k),s[n]=0;puts(s);
	return 0;
}
