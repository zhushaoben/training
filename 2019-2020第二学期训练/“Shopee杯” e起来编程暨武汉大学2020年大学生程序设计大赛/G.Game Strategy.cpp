#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N],b[N],c[N];
void work(){
	int n,ma=-1e9,mi=1e9,x,ans=-1e9,w;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<n;i++)scanf("%d",b+i);
	for(int i=0;i<n;i++)scanf("%d",c+i);
	int ans2=-1e9;
	for(int i=0;i<n;i++){
		int ans1=1e9;
		for(int j=0;j<n;j++){
			int ans=1e9,w;
			for(int k=0;k<n;k++){
				if(abs(w=a[i]+b[j]+c[k])<abs(ans)||(abs(w)==abs(ans)&&w>ans))ans=w;
			}
			if(ans<ans1)ans1=ans;
		}
		if(ans1>ans2)ans2=ans1;
	}
	printf("%d",ans2);
}
int main(){
	int T=1;
//	scanf("%d",&T);
	while(T--)work();
	return 0;
} 
