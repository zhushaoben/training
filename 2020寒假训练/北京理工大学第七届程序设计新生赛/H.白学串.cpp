#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int a[maxn],b[maxn];
void work(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	int L,R;
	for(int i=0;i<m;i++){
		scanf("%d%d",&L,&R),L--,R--;
		if(R-L>38){puts("yes");continue;}
		for(int j=L;j<=R;j++)b[j]=a[j];
		sort(b+L,b+R+1);bool fl=0;
		for(int j=L;j<R-1;j++)if(b[j]+b[j+1]>b[j+2]){fl=1;break;}
		if(fl)puts("yes");
		else puts("no");
	}
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
