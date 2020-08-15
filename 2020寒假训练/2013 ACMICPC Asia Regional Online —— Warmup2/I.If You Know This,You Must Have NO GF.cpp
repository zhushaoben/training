#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
map<string,int>mp;
vector<int>V[N];
int si,n;
char s1[N],s2[N];
bool vis[N];
void add_edge(int u,int v){V[u].push_back(v);}
int calc(int x){
	if(vis[x]||!V[x].size())return 0;
	int ans=1;
	for(auto v:V[x]){
		int w=calc(v);
		if(!w&&!vis[v])return 0;
		ans+=w;
	}
	vis[x]=1;
	return ans;
}
void work(){
	mp.clear();
	for(int i=1;i<=si;i++)V[i].clear();
	si=0;memset(vis,0,sizeof(vis));
	while(gets(s1)&&(s1[0]=='\0'||s1[0]=='\n'||s1[0]=='\r'));
	while(s1[0]!='='){
		int l=strlen(s1);
		while(s1[l-1]=='\\'){
			l--,gets(s1+l);
			while(s1[++l]);
		}
		if(strstr(s1,":")==NULL){gets(s1);continue;}
		string x=s1,x1;int w=x.find('#'),u,w1;
		if(w!=string::npos)x.erase(w,x.size()-w);
		w=x.find(':');
		x1=x.substr(0,w);x.erase(0,w+2);
		if(!mp[x1])mp[x1]=++si;u=mp[x1];
		const char *s=x.c_str();w=0;
		while(sscanf(s+w,"%s%n",s2,&w1)!=EOF){
			w+=w1;
			if(!mp[s2])mp[s2]=++si;
			add_edge(u,mp[s2]);
		}
		gets(s1);
	}
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",s1);
		if(mp[s1])vis[mp[s1]]=1;
	}
	scanf("%d",&n);vis[0]=1;
	for(int i=0;i<n;i++){
		scanf("%*s%s",s1);
		printf("%d\n",calc(mp[s1]));
	}
}
int main(){
	int t,x;scanf("%d",&t);
	for(int i=1;i<=t;i++){
		printf("Case #%d:\n",i);
		work();
		if(i!=t)puts("");
	}
	return 0;
} 
