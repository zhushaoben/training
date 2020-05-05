/******************************************************************
贪心
下午最大的搭配晚上最小的
******************************************************************/
#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 105
int n,d,r,a[maxn],b[maxn];
void work(){
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<n;i++)scanf("%d",b+i);
	sort(a,a+n);sort(b,b+n);
	int ans=0;
	for(int i=0;i<n;i++){
		if(a[i]+b[n-i-1]>d)ans+=a[i]+b[n-i-1]-d;
	}
	printf("%d\n",ans*r);
}
int main(){
	while(~scanf("%d%d%d",&n,&d,&r)&&n|d|r)work();
	return 0;
} 
