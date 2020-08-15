#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL w[200];char s[100],s1[100];
int n,m,i1;
LL check(LL x){
	for(;i1<n;i1++){
		if(w[i1]==x)return 2e18;
		if(w[i1]>x)return x-i1;
	}
	return x-i1;
}
void Print(LL x){
	for(int i=m-1;i>=0;i--)s1[m-i-1]=(x&(1ll<<i))?'1':'0';
	s1[m]=0;
	puts(s1);
}
void work(){
	scanf("%d%d",&n,&m),i1=0;
	for(int i=0;i<n;i++){
		scanf("%s",s);w[i]=0;
		for(int j=0;s[j];j++)w[i]=w[i]*2+s[j]-'0';
	}
	sort(w,w+n);
	LL k=((1ll<<m)-n-1)/2;
	for(LL i=k;;i++)
		if(check(i)==k){Print(i);return;}
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
