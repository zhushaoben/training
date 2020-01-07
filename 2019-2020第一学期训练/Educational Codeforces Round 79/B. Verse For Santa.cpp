#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int a[maxn];
void work() {
	int n,s,ans=0,ans1=0,w,w1;long long sum=0,sum1=0;
	scanf("%d%d",&n,&s);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<n;i++){
		sum1+=a[i];sum+=a[i];
		if(sum1>sum-a[i])sum1=sum-a[i],w=i;
		if(sum<=s)ans=i+1;
		if(sum1<=s){ans1=i;w1=w;}
		else break;
	}
	printf("%d\n",(ans1>ans?w1+1:0));
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--)work();

	return 0;
}
