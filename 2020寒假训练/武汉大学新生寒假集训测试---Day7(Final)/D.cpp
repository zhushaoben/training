#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
#define LL long long
struct Node{
	int num2,num3;LL x;
	bool operator < (const Node &b)const{
		if(num3!=b.num3)return num3>b.num3;
		return num2<b.num2;
	}
}a[maxn];
int main(){
	int n;LL x;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&x),a[i].x=x;
		while(x%2==0)x/=2,a[i].num2++;
		while(x%3==0)x/=3,a[i].num3++;
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)printf("%lld ",a[i].x);
	return 0;
}
