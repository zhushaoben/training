#include<bits/stdc++.h>
using namespace std;
int f[10005];
int main(){
	int h,n,a,b;scanf("%d%d",&h,&n);
	memset(f,0x1f,sizeof(f)),f[h]=0;
	for(int i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		for(int j=h;j;j--){
			f[max(0,j-a)]=min(f[max(0,j-a)],f[j]+b);
		}
	}
	printf("%d",f[0]);
	return 0;
} 
