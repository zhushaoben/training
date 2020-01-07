#include<bits/stdc++.h>
using namespace std;
int a[30][30],b[30][30];
void work(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%s",a[i]);
	for(int i=0;i<m;i++)scanf("%s",b[i]);
	int q,x;scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d",&x),x--;
		printf("%s%s\n",a[x%n],b[x%m]);
	}
}
int main(){
	int t=1;
//	scanf("%d",&t);
	while(t--)work();
	return 0;
}
