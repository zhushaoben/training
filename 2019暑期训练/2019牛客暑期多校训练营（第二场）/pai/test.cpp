#include<bits/stdc++.h>
using namespace std;
#define maxn 1020
#define LL __int128
int a[maxn],m;long long n;
bool check(LL x){
	LL num=0;
	for(int i=0;i<m;i++){
		num+=(x-1)/a[i]+1;
	}
	return num<=n;
}
int work(){
	for(int i=0;i<m;i++)scanf("%d",a+i);
	LL l=0,r=n,mid;r=r*10;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	LL num=0;
	for(int i=0;i<m;i++){
		if(r%a[i])num=1e20;
		num+=r/a[i];
	}
	if(num!=n)return puts("No"),0;
	puts("Yes");
	for(int i=0;i<m-1;i++)printf("%d ",(long long)r/a[i]);
	printf("%lld\n",(long long)r/a[m-1]);
	return 0;
}
int main(){
	while(~scanf("%d%lld",&m,&n))work();
	return 0;
}
