#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int a[maxn];
int main(){
	int n,x,y;scanf("%d%d%d",&n,&x,&y);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<n;i++){
		bool fl=1;
		for(int j=i-1;j>=0&&j>=i-x;j--)if(a[j]<=a[i]){fl=0;break;}
		for(int j=i+1;j<n&&j<=i+y;j++)if(a[j]<=a[i]){fl=0;break;}
		if(fl){printf("%d",i+1);return 0;}
	}
	return 0;
} 
