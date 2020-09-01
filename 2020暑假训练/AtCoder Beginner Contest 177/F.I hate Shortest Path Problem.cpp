#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
multiset<int>val;
map<int,int>mp;
int main(){
	int h,w,l,r;scanf("%d%d",&h,&w);
	for(int i=1;i<=w;i++)val.insert(0),mp[i]=0;
	for(int i=1;i<=h;i++){
		scanf("%d%d",&l,&r);
		if(r!=w){
			auto x=mp.lower_bound(r+1);
			if(x->first!=r+1&&x!=mp.begin()){
				x--;
				int v=x->second+(r+1-x->first);
				mp[r+1]=v,val.insert(v);
			}
		}
		auto x=mp.lower_bound(l);
		while(x!=mp.end()&&x->first<=r)val.erase(val.find(x->second)),x=mp.erase(x);
		if(!val.empty())printf("%d\n",i+*val.begin());
		else puts("-1");
	}
	return 0;
}
