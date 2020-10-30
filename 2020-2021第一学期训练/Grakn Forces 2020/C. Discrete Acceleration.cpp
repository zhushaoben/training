#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
void work(){
	double ans=0,v1=1,v2=1,t,L=0,R;
	int n,l,r;scanf("%d%lf",&n,&R);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	l=0,r=n+1;
	while(l<r-1){
		if((a[l+1]-L)/v1<=(R-a[r-1])/v2){
			t=(a[l+1]-L)/v1,v1+=1,L=a[++l];
			R-=v2*t;
		}
		else{
			t=(R-a[r-1])/v2,v2+=1,R=a[--r];
			L+=v1*t;
		}
		ans+=t;
	}
	ans+=(R-L)/(v1+v2);
	printf("%.12lf\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
