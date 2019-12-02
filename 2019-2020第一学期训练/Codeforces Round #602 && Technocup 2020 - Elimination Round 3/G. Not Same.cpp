#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
struct Node{
	int x,id;
	bool operator <(const Node &b)const{
		return x>b.x;
	}
}a[maxn];
char s[maxn];
int main(){
	int n,fl=0;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i),a[i].id=i;
	sort(a,a+n);for(int i=0;i<n;i++)if(a[i].x+i>n){fl=1;break;}
	printf("%d\n",n+fl);
	for(int i=1-fl;i<=n;i++){
		for(int j=0;j<i;j++)s[a[j].id]=j+a[j].x>=i?'1':'0';
		if(i!=n)s[a[i].id]='0';
		for(int j=i+1;j<n;j++)s[a[j].id]=(j+a[j].x-n-fl>=i?'1':'0');
		puts(s);
	}
	return 0;
}
