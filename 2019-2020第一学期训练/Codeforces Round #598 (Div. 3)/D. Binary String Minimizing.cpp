#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn 1000000
char s[maxn+5];int p[maxn+5],si;
void work(){
	int n;LL k;scanf("%d%lld%s",&n,&k,s);
	si=0;for(int i=0;s[i];i++)if(s[i]=='0')p[si++]=i;
	for(int i=0;i<si;i++){
		if(k>=(p[i]-i))swap(s[p[i]],s[i]),k-=p[i]-i;
		else swap(s[p[i]],s[p[i]-k]),k=0;
		if(!k)break;
	}
	puts(s);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
