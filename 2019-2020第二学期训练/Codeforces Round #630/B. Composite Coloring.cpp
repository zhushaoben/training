#include<bits/stdc++.h>
using namespace std;
int a[11]={2,3,5,7,11,13,17,19,23,29,31},num[11],ans[1005],ans2[11];
void work(){
	memset(num,0,sizeof(num));
	int n,x;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		for(int j=0;j<11;j++)if(x%a[j]==0){ans[i]=j,num[j]++;break;}
	}
	int ans1=0;
	for(int i=0;i<11;i++)if(num[i])ans2[i]=++ans1;
	printf("%d\n",ans1);
	for(int i=0;i<n;i++)printf("%d ",ans2[ans[i]]);
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
