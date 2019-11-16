#include<bits/stdc++.h>
using namespace std;
int a[200],id[200];
void work(){
	int n,m,x;scanf("%d%d",&n,&m);
	for(int i=0;i<=m;i++)a[i]=0;
	for(int i=0;i<n;i++){
		scanf("%d",&x);bool fl=0;
		for(int j=1;j<=m;j++)if(a[j]==x){id[j]=i,fl=1;break;}
		if(!fl)for(int j=1;j<=m;j++){
			if(a[j]==0){a[j]=x,id[j]=i,fl=1;break;}
		}
		if(!fl){
			int mi=123123,w=0;
			for(int j=1;j<=m;j++)if(id[j]<mi)mi=id[j],w=j;
			id[w]=i,a[w]=x;
		}
	}
	for(int i=1;i<=m;i++)printf("%d %d\n",i,a[i]);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
