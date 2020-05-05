/*
when N = M
1. When N = 1. grid with 1 satisfy the conditon.
2. When N > 1, we fill the four corner with the matrix for (N-1)
fill the center cell with 1 and other cell with 0
like A0A
     010
	 A0A
when N!=M w=max(N,M)
we construct a matrix for w and printf the first (1<<N-1,1<<M-1)cell
*/
#include<bits/stdc++.h>
using namespace std;
const int S=1<<10;
char s[S][S];
void work(int x1,int y1,int x2,int y2){
	if(x1==x2){s[x1][y1]=1;return;}
	int mix=(x1+x2)/2,miy=(y1+y2)/2;
	s[mix][miy]=1;
	work(x1,y1,mix-1,miy-1),work(x1,miy+1,mix-1,y2),
	work(mix+1,y1,x2,miy-1),work(mix+1,miy+1,x2,y2);
}
int main(){
	int n,m,w;scanf("%d%d",&n,&m);
	w=max(n,m);work(1,1,(1<<w)-1,(1<<w)-1);
	for(int i=1;i<(1<<n);i++){
		for(int j=1;j<(1<<m);j++)putchar(s[i][j]+'0');
		puts("");
	}
	
	return 0;
} 
