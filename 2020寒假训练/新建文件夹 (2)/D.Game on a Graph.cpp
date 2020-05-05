#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
char s[maxn];
void work(){
	int k,n,m;scanf("%d%s%d%d",&k,s,&n,&m);
	for(int i=0;i<m;i++)scanf("%*d%*d");
	printf("%c\n",s[(m-n+1)%k]^3);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
