#include<bits/stdc++.h>
using namespace std;
char s[200];
int main(){
	int n;scanf("%d%s",&n,s);
	if(n&1)return puts("No"),0;
	n/=2;
	for(int i=0;i<n;i++)if(s[i]!=s[i+n])return puts("No"),0;
	puts("Yes");
	return 0;
}
