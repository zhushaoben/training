#include<bits/stdc++.h>
using namespace std;
#define LL long long
int f[1000];
int main(){
	int m;scanf("%d",&m);
	for(int i=1;i<=100;i++){
		f[i]=0;
		for(int k=1;k<=m+1;k++){
			if(k>=i||f[i-k]>k){f[i]=1;break;}
		}
		if(!f[i])for(int j=2;;j++){
			int k=j+m;
			if(k>=i||f[i-k]>k){f[i]=j;break;}
		}
		printf("%d %d\n",i,f[i]);
	}
	return 0;
} 
