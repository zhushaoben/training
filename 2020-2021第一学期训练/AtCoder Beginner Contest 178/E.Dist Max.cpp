#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x,y,w,w1,ma=-2e9,ma1=-2e9,mi=2e9,mi1=2e9;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		w=x+y,w1=x-y;
		ma=max(ma,w),mi=min(mi,w),ma1=max(ma1,w1),mi1=min(mi1,w1);
	}
	printf("%d",max(ma-mi,ma1-mi1));
	return 0;
}
