#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
void merge(int &a,int &b,int c,int d){a=max(a,c),b=min(b,d);}
int l[N],r[N],ans[N];
void work(){
	int n,k;scanf("%d%d",&n,&k);
	l[0]=0,r[0]=1e9;bool fl=1;
	for(int i=1;i<=n;i++){
		scanf("%d%d",l+i,r+i);
		merge(l[i],r[i],l[i-1]-k,r[i-1]+k);
		if(l[i]>r[i])fl=0;
	}
	if(!fl){puts("NO");return;}
	puts("YES");
	for(int i=n;i>=1;i--){
		ans[i]=l[i];
		merge(l[i-1],r[i-1],l[i]-k,l[i]+k);
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
