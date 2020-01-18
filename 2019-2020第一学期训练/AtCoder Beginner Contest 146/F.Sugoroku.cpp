#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int pre[maxn],ans[maxn],si;char s[maxn];
int main(){
	int n,m;scanf("%d%d%s",&n,&m,s);
	pre[0]=s[0]=='1'?-1:0;
	for(int i=1;s[i];i++){
		pre[i]=-1;
		if(s[i]=='1')continue;
		for(int j=min(m,i);j;j--){
			if(pre[i-j]!=-1){pre[i]=i-j;break;}
		}
	}
	if(pre[n]==-1)return puts("-1"),0;
	int x=n;
	while(x)ans[++si]=x-pre[x],x=pre[x];
	for(int i=si;i;i--)printf("%d ",ans[i]);
	return 0;
}
