#include<bits/stdc++.h>
using namespace std;
int a[]={0,60,62,65,67,70,75,80,85,90,95};
double b[]={0,1,1.7,2.0,2.3,2.7,3.0,3.3,3.7,4.0,4.3};
void work(){
	double ans=0;
	int n;scanf("%d",&n);
	for(int i=0;i<11;i++){
		for(int j=0;j<11;j++){
			for(int k=0;k<11;k++){
				for(int l=0;l<11;l++){
					if(a[i]+a[j]+a[k]+a[l]<=n)ans=max(ans,b[i]+b[j]+b[k]+b[l]);
				}
			}
		}
	}
	printf("%.1lf\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
