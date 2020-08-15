#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s[N];
struct Node{
	int x,mi;
	bool operator < (const Node &b)const{
		if((x>=0)!=(b.x>=0))return x>=0;
		if(x>=0)return mi>b.mi;
		return x+b.mi>b.x+mi;
	}
}a[N];
int main(){
	int n,sum=0,w,mi;scanf("%d",&n);
	for(int i=0;i<n;i++){
		mi=w=0;scanf("%s",s);
		for(int j=0;s[j];j++){
			if(s[j]=='(')w++;
			else w--,mi=min(mi,w);
		}
		sum+=w;
		a[i]={w,mi};
	}
	if(sum)return puts("No"),0;
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(sum+a[i].mi<0)return puts("No"),0;
		sum+=a[i].x;
	}
	puts("Yes");
	return 0;
}
