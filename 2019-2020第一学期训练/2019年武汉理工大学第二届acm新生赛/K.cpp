#include<bits/stdc++.h>
using namespace std;
#define maxn 100
int a[maxn+5];
void work(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)a[i]=i;
	for(int i=1;i<=n;i++){
		int a1,b1,x,x1,x2,x3,x4;
		scanf("%d%d",&a1,&b1);
		for(int j=1;j<=n;j++){
			if(a[j]==i)x=j;
			if(a[j]==a1)x3=j;
			if(a[j]==b1)x4=j;
		}
		x1=x%n+1,x2=x1%n+1;
		if(a[x1]==a1)swap(a[x2],a[x4]);
		else if(a[x2]==a1)swap(a[x1],a[x4]);
		else if(a[x1]==b1)swap(a[x2],a[x3]);
		else if(a[x2]==b1)swap(a[x1],a[x3]);
		else{
			swap(a[x1],a[x3]),swap(a[x2],a[x4]);
		} 
		for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
	}
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
