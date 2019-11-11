#include<bits/stdc++.h>
using namespace std;
#define maxn 10000
char s[maxn+5],t[maxn+5];
pair<int,int>ans[maxn*2+5];
int work(){
	int n,si=0;scanf("%d%s%s",&n,s,t);
	for(int i=0;s[i];i++){
		if(s[i]!=t[i]){
			bool fl=0;
			for(int j=i+1;s[j];j++)if(s[j]==s[i]){ans[si++]={j,i},fl=1,swap(s[j],t[i]);break;}
			if(!fl)for(int j=i+1;t[j];j++)if(t[j]==s[i]){ans[si++]={j,j},swap(s[j],t[j]),ans[si++]={j,i},swap(s[j],t[i]),fl=1;break;}
			if(!fl)return puts("NO"),0;
		}
	}
	printf("YES\n%d\n",si);
	for(int i=0;i<si;i++)printf("%d %d\n",ans[i].first+1,ans[i].second+1);
	return 0;
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
