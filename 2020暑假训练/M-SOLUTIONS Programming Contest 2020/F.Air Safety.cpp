#include<bits/stdc++.h>
using namespace std;
const int N=2e5,inf=1e9;
int x[N],y[N],n;char dr[N],d[]="URDL";
void rotate(){
	int t;
	for(int i=0;i<n;i++){
		t=y[i],y[i]=N-x[i],x[i]=t;
		for(int j=3;~j;j--)if(dr[i]==d[j]){dr[i]=d[(j+1)%4];break;}
	}
}
vector<pair<int,char> >v[N*2+5];pair<int,char>pre;
int calc(){
	int ret=inf;
	for(int i=N<<1;~i;i--)v[i].clear();
	for(int i=0;i<n;i++)
		if(dr[i]=='R'||dr[i]=='U')v[x[i]+y[i]].push_back(make_pair(x[i],dr[i]));
	for(int i=N<<1;~i;i--){
		sort(v[i].begin(),v[i].end());pre.second='D';
		for(auto x:v[i]){
			if(pre.second=='R'&&x.second=='U')ret=min(ret,(x.first-pre.first)*10);
			pre=x;
		}
	}
	return ret;
}
int calc1(){
	int ret=inf;
	for(int i=N;~i;i--)v[i].clear();
	for(int i=0;i<n;i++)
		if(dr[i]=='R'||dr[i]=='L')v[y[i]].push_back(make_pair(x[i],dr[i]));
	for(int i=N;~i;i--){
		sort(v[i].begin(),v[i].end());pre.second='D';
		for(auto x:v[i]){
			if(pre.second=='R'&&x.second=='L')ret=min(ret,(x.first-pre.first)*5);
			pre=x;
		}
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%d%s",x+i,y+i,dr+i);
	int ans=inf;
	for(int i=0;i<4;i++){
		ans=min(ans,min(calc(),calc1()));
		rotate();
	}
	if(ans==inf)puts("SAFE");
	else printf("%d",ans);
	return 0;
} 
