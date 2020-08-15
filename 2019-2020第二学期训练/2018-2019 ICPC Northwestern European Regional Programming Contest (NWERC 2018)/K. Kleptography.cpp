#include<bits/stdc++.h>
using namespace std;
char b[105],a[105];
int main(){
	int n,m;scanf("%d%d",&n,&m);
	scanf("%s%s",a+m-n,b);
	for(int i=m-1;i>=n;i--)
		a[i-n]=(b[i]+26-a[i])%26+'a';
	puts(a);
	return 0;
}
