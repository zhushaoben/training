#include<bits/stdc++.h>
bool vis[10];
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++){
		char x=getchar();
		while(x!='L'&&x!='R'&&(x>'9'||x<'0'))x=getchar();
		if(x=='L'){
			for(int i=0;i<10;i++){
				if(!vis[i]){vis[i]=1;break;}
			}
		}
		else if(x=='R'){
			for(int i=9;i>=0;i--){
				if(!vis[i]){vis[i]=1;break;}
			}
		}
		else{
			vis[x-'0']=0;
		}
	}
	for(int i=0;i<10;i++)printf("%d",vis[i]);
	return 0;
}
