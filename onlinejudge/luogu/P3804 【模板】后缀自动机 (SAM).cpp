#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
struct SAM{
	int ch[26],len,fa;
	SAM(){memset(this,0,sizeof(SAM));}
}a[N];
int last=1,tot=1,si[N];
vector<int>V[N];
long long ans=0;
char s[N];
void add(int c){
	int p=last,np=last=++tot;si[np]=1;
	a[np].len=a[p].len+1;
	while(p&&!a[p].ch[c])a[p].ch[c]=np,p=a[p].fa;
	if(!p){a[np].fa=1;return;}
	int q=a[p].ch[c];
	if(a[q].len==a[p].len+1)a[np].fa=q;
	else{
		int nq=++tot;a[nq]=a[q];
		a[nq].len=a[p].len+1,a[q].fa=a[np].fa=nq;
		while(p&&a[p].ch[c]==q)a[p].ch[c]=nq,p=a[p].fa;
	}
}
void dfs(int x){
	for(auto v:V[x]){
		dfs(v);
		si[x]+=si[v];
	}
	if(si[x]!=1)ans=max(ans,1ll*si[x]*a[x].len);
}
int main(){
	scanf("%s",s);
	for(int i=0;s[i];i++)add(s[i]-'a');
	for(int i=2;i<=tot;i++)V[a[i].fa].push_back(i);
	dfs(1);
	printf("%lld",ans);
	return 0;
}
