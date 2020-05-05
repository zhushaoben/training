#include<bits/stdc++.h>
using namespace std;
#define maxn 2005
char s[maxn],ans[maxn];bool fl;
int vis[26][26],num[26],vis1[26];
void dfs(int x,int d){
	ans[d]=x+'a';vis1[x]=1;
	for(int i=0;i<26;i++){
		if(vis[x][i]){
			if(!vis1[i])dfs(i,d+1);
			else if(ans[d-1]!=i+'a')fl=0;
		}
	}
}
void work(){
	scanf("%s",s);memset(vis1,0,sizeof(vis1)),memset(vis,0,sizeof(vis)),memset(num,0,sizeof(num));
	if(!s[1]){puts("YES");for(int i=0;i<26;i++)putchar(i+'a');puts("");return;}
	for(int i=0;s[i];i++){if(i)vis[s[i]-'a'][s[i-1]-'a']=vis[s[i-1]-'a'][s[i]-'a']=1;num[s[i]-'a']++;}
	fl=1;int s=-1,w1=0,w2=0;
	for(int i=0;i<26;i++){
		if(num[i])w1++;else continue;
		int w=0;
		if(vis[i][i])fl=0;
		for(int j=0;j<26;j++)w+=vis[i][j];
		if(w>2)fl=0;if(w==1)s=i,w2++;
	}
	if(!fl||s==-1||w2<2){puts("NO");return;}
	ans[w1-1]=ans[w1]=0;dfs(s,0);
	if(!ans[w1-1]||!fl){puts("NO");return;}
	for(int i=0;i<26;i++)if(!num[i])ans[w1++]='a'+i;
	puts("YES");puts(ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
