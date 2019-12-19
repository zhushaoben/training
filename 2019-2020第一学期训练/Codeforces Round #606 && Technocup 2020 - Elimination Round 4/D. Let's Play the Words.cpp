#include<bits/stdc++.h>
using namespace std;
#define maxn 4000005
char s[maxn];
vector<int> v[4];
map<int,int>mp;
bool vis[maxn];
int work(){
	for(int i=0;i<4;i++)v[i].clear();mp.clear();
	int n,a[4]={0},b=0,c=0,l,w,w1,S=0;scanf("%d",&n);
	for(int i=0;i<n;i++)vis[i]=0;
	for(int i=0;i<n;i++){
		scanf("%s",s);
		S=l=0;while(s[l])S=S*3+s[l]-'0'+1,l++;
		mp[S]=i+1;S=0;
		for(int i=l-1;~i;i--)S=S*3+s[i]-'0'+1;
		w=s[0]=='1',w1=s[l-1]=='1';
		if(mp[S]){
			vis[i+1]=1,vis[mp[S]]=1;
			if((w<<1|w1)==1)b++;
			if((w<<1|w1)==2)c++;
		}
		a[w<<1|w1]++,v[w<<1|w1].push_back(i+1);
	}
	if(a[0]&&a[3]&&!(a[1]||a[2]))return puts("-1"),0;
	b=a[1]-b,c=a[2]-c;
	if((a[1]-a[2]>1&&a[1]-2*b-a[2]>1)||(a[2]-a[1]>1&&a[2]-2*c-a[1]>1))return puts("-1"),0;
	int ans=abs(a[1]-a[2])/2,d=(a[1]<a[2])+1;w=0;
	printf("%d\n",ans);
	for(auto j:v[d]){
		if((w)==ans)break;
		if(!vis[j])printf("%d ",j),w++;
	}
	puts("");
	return 0;
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
