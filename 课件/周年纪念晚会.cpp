const int maxn=100000;
int f[maxn][2];
//f[i][0]��¼i�����в�ѡi�����ֵ
//f[i][1]��¼i������ѡi�����ֵ
void search(int x){
	f[x][1]=p[x];
	for(v��x���ӽڵ�){
		search(v);
		f[x][1]+=f[v][0],
		f[x][0]+=max(f[v][0],f[v][1]);
	}
}
int main(){
	return 0;
}
