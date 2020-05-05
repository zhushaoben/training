#include<bits/stdc++.h>
using namespace std;
#define maxn 105
int a[maxn];
void work(){
	int n,sum=0,ans=0,w,num;scanf("%d",&n);
	double ans1=0;
	for(int i=1;i<n;i++)scanf("%d",a+i),sum+=a[i];
	for(int i=100;i>=0;i--){
		if(i>(w=(sum+i)*2/3/n))continue;
		num=1;bool fl=1;
		for(int j=1;j<n;j++){
			if(a[j]>i&&a[j]<=w){fl=0;break;}
			if(a[j]==w)num++;
		}
		if(!fl)continue;
		if(1.0/num>ans1)ans1=1.0/num,ans=i;
	}
	printf("%d %.2lf\n",ans,ans1);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
/*
x=(sum+x)*2/3/n;
(1-2/3n)x=sum*2/3n
3n-2 x=2*sum
*/
