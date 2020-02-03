#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
vector<int>v[maxn];
void work(){
	for(int i=2;i<maxn;i++)v[i].clear();
	int n,m,x,l,r,d,w,w1,fl;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		for(int j=2;j*j<=x;j++)while(x%j==0)x/=j,v[j].push_back(i);
		if(x)v[x].push_back(i);
	}
	for(int i=2;i<maxn;i++)v[i].push_back(n+1);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&l,&r,&d),fl=1;
		for(int j=2;j*j<=d;j++){
			if(d%j==0){
				w=0;while(d%j==0)d/=j,w++;
				w1=(upper_bound(v[j].begin(),v[j].end(),r)-v[j].begin())-(lower_bound(v[j].begin(),v[j].end(),l)-v[j].begin());
				if(w1<w){fl=0;break;}
			}
		}
		if(d>1&&fl){
			w1=(upper_bound(v[d].begin(),v[d].end(),r)-v[d].begin())-(lower_bound(v[d].begin(),v[d].end(),l)-v[d].begin());
			if(!w1)fl=0;
		}
		if(fl)puts("Yes");
		else puts("No");
	}
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
