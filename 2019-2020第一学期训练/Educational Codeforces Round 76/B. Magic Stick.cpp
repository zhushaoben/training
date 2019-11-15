#include<bits/stdc++.h>
using namespace std;
void work(){
	int x,y;scanf("%d%d",&x,&y);
	if(x>3||(x>1&&y<=3)||(x==1&&y==1))puts("YES");
	else puts("NO");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
