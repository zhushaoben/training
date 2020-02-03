#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL x[60],y[60],ax,ay,bx,by,sx,sy,t;
int main(){
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",x,y,&ax,&ay,&bx,&by,&sx,&sy,&t);
	int ans=0,w,s;LL tot;
	for(int i=1;;i++){
		x[i]=ax*x[i-1]+bx,y[i]=ay*y[i-1]+by;
		if(x[i]>2e16||y[i]>2e16){s=i;break;}
	}
	for(int i=0;i<s;i++){
		if(abs(x[i]-sx)+abs(y[i]-sy)>t)continue;
		tot=abs(x[i]-sx)+abs(y[i]-sy);w=1;
		for(int j=i-1;~j;j--,w++){
			tot+=x[j+1]-x[j]+y[j+1]-y[j];
			if(tot>t)break;
		}
		ans=max(ans,w);
		tot=abs(x[i]-sx)+abs(y[i]-sy);w=1;
		for(int j=i+1;j<s;j++,w++){
			tot+=x[j]-x[j-1]+y[j]-y[j-1];
			if(tot>t)break;
		}
		ans=max(ans,w);
	}
	printf("%d",ans);
	return 0;
}
