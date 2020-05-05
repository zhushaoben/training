const int maxn=100000;
int f[maxn][2];
//f[i][0]记录i子树中不选i的最大值
//f[i][1]记录i子树中选i的最大值
void search(int x){
	f[x][1]=p[x];
	for(v是x的子节点){
		search(v);
		f[x][1]+=f[v][0],
		f[x][0]+=max(f[v][0],f[v][1]);
	}
}
int main(){
	return 0;
}
