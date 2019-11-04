/*
For each bit i, 
let L = set of indices x with bit i=0, 
R = set of indices y with bit i=1 and y+1 also has bit i=1.

Similarly, for each bit i, 
let L = set of indices x with bit i=1, 
R = set of indices y with bit i=0 and y+1 also has bit i=0.

now we used 247 sets

then we find only pairs(x,y) with y=...0111..1 are uncovered
*/
#include<bits/stdc++.h>
using namespace std;
void work(int n){
	int ans=36;
	for(int i=0;i<13;i++)if(n<(1<<i))ans-=2;
	for(int i=0;i<12;i++)if(n<(1<<(i+1))-1)ans--;
	if(n>=2&&n<4)ans--;
	printf("%d\n",ans);int w;
	for(int i=1;i<13;i++){//L:bit i=0
		if(n<(1<<i))break;
		int j,w;
		for(j=1,w=0;j<=n;j++)if((j&(1<<i))==0)w++;
		for(printf("%d ",w),j=1;j<=n;j++)if((j&(1<<i))==0)printf("%d ",j);puts("");
		for(j=1,w=0;j<=n;j++)if((j&(1<<i))&&((j+1)&(1<<i)))w++;
		for(printf("%d ",w),j=1;j<=n;j++)if((j&(1<<i))&&((j+1)&(1<<i)))printf("%d ",j);puts("");
	}
	for(int i=1;i<13;i++){//L:bit i=1 
		if(n<(1<<i))break;
		if(i==1&&n<4)continue;
		int j,w;
		for(j=1,w=0;j<=n;j++)if((j&(1<<i)) )w++;
		for(j=1,printf("%d ",w);j<=n;j++)if((j&(1<<i)) )printf("%d ",j);puts("");
		for(j=1,w=0;j<=n;j++)if((j&(1<<i))==0&&((j+1)&(1<<i))==0)w++;
		for(j=1,printf("%d ",w);j<=n;j++)if((j&(1<<i))==0&&((j+1)&(1<<i))==0)printf("%d ",j);puts("");
	}
	for(int i=0;i<12;i++){//R:y=...01111..1
		if(n<(1<<(i+1))-1)break;
		int j,w;
		for(j=1,w=0;j<=n;j++)if(!(((j+1)&(1<<(i+1)))&&(j&(1<<(i+1)))==0||((j)&(1<<(i+1)))&&((j-1)&(1<<(i+1)))==0))w++;
		for(j=1,printf("%d ",w);j<=n;j++)if(!(((j+1)&(1<<(i+1)))&&(j&(1<<(i+1)))==0||((j)&(1<<(i+1)))&&((j-1)&(1<<(i+1)))==0))printf("%d ",j);puts("");
		for(j=1,w=0;j<=n;j++)if(((j+1)&(1<<(i+1)))&&(j&(1<<(i+1)))==0)w++;
		for(j=1,printf("%d ",w);j<=n;j++)if(((j+1)&(1<<(i+1)))&&(j&(1<<(i+1)))==0)printf("%d ",j);puts("");
	}
}
int main(){
	int n;scanf("%d",&n);
	if(n>2){work(n);return 0;}
	if(n==2){printf("1\n1 1\n1 2\n");return 0;}
//	printf("%d\n",n);
//	for(int i=1;i<=n;i++){
//		printf("%d",n-2+(i==n));
//		for(int j=1;j<=n;j++){
//			if(j==i||j==i+1)continue;
//			printf(" %d",j);
//		}
//		printf("\n1 %d\n",i);
//	}
	return 0;
} 
