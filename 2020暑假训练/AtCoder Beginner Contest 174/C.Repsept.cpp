#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
bool vis[N];
int main(){
	int k,x=0;scanf("%d",&k);
	for(int i=1;;i++){
		x=(x*10+7)%k;
		if(vis[x])break;
		if(!x)return printf("%d\n",i),0;
		vis[x]=1;
	}
	puts("-1");
	return 0;
}
