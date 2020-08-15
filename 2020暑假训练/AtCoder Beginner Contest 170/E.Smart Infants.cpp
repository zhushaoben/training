#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
multiset<int> s[N],ans;
int a[N],b[N];
int main(){
	int n,q,c,d;scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d%d",a+i,b+i),s[b[i]].insert(a[i]);
	for(int i=0;i<N;i++)if(s[i].size())ans.insert(*--s[i].end());
	for(int i=0;i<q;i++){
		scanf("%d%d",&c,&d);
		if(b[c]==d){
			printf("%d\n",*ans.begin());
			continue;
		}
		ans.erase(ans.find(*--s[b[c]].end()));
		if(s[d].size())ans.erase(ans.find(*--s[d].end()));
		s[b[c]].erase(s[b[c]].find(a[c]));
		s[d].insert(a[c]);
		if(s[b[c]].size())ans.insert(*--s[b[c]].end());
		ans.insert(*--s[d].end());
		b[c]=d;
		printf("%d\n",*ans.begin());
	}
	return 0;
}
