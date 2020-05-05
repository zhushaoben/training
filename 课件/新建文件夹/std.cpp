const int inf=1000000000;
int search(int n,int W){//前n个物品，占W重量的最大价值
	if(n==0||W==0)return 0;
	if(W<0)return -inf;
	return max( v[n] + search(n-1,W-w[n]) , search(n-1,W) );
}