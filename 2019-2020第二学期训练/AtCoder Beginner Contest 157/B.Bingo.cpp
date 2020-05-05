#include<bits/stdc++.h>
using namespace std;
int a[3][3],n,x;
int main(){
	for(int i=0;i<3;i++)for(int j=0;j<3;j++)scanf("%d",a[i]+j);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		for(int i=0;i<3;i++)for(int j=0;j<3;j++)if(a[i][j]==x)a[i][j]=0;
	}
	for(int i=0;i<3;i++){
		bool fl=1;
		for(int j=0;j<3;j++)if(a[i][j])fl=0;
		if(fl)return puts("Yes"),0;
		fl=1;
		for(int j=0;j<3;j++)if(a[j][i])fl=0;
		if(fl)return puts("Yes"),0;
	}
	bool fl=1;
	for(int i=0;i<3;i++)if(a[i][i])fl=0;
	if(fl)return puts("Yes"),0;
	fl=1;
	for(int i=0;i<3;i++)if(a[i][2-i])fl=0;
	if(fl)return puts("Yes"),0;
	puts("No");
	return 0;
}
