#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int in[N],la[N];
int main(){
	int n,u,v,a=0,b=0,c=0;scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),in[u]++,in[v]++,la[u]=la[v]=i;
	for(int i=1;i<=n;i++){
		if(in[i]==1){
			if(!a)a=la[i];
			else if(!b)b=la[i];
			else if(!c)c=la[i];
		}
	}
	int now=3;
	if(!c)for(int i=1;i<n;i++)printf("%d\n",i-1);
	else for(int i=1;i<n;i++){
		if(a==i)puts("0");
		else if(b==i)puts("1");
		else if(c==i)puts("2");
		else printf("%d\n",now++);
	}
	return 0;
}
