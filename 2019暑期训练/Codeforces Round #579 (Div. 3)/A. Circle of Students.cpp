#include<bits/stdc++.h>
using namespace std;
int a[500];
void work(){
	int n;scanf("%d",&n);
	bool fl=0;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i),a[n+i]=a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==n){
			bool w=1;
			for(int j=0;j<n;j++){
				if(a[i+j]!=n-j){w=0;break;}
			}
			fl=w;
		}
		if(a[i]==1){
			bool w=1;
			for(int j=0;j<n;j++){
				if(a[i+j]!=j+1){w=0;break;}
			}
			fl=w;
		}
		if(fl)break;
	}
	if(fl)puts("YES");
	else puts("NO");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
