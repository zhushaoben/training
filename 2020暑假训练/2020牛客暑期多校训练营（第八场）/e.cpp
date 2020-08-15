#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long f[N+1];
int main(){
	freopen("a4.out","r",stdin);
	freopen("a5.out","w",stdout);
	for(int i=1;i<=N;i++)scanf("%lld,",f+i);
	for(int i=1;i<=N;i++){
		f[i]+=128;
		if(f[i]=='\n')printf("\\n");
		else if(f[i]=='\\')printf("\\\\");
		else if(f[i]=='\r')printf("\\r");
		else if(f[i]=='\"')printf("\\\"");
		else printf("%c",f[i]);
	}
	return 0;
}
