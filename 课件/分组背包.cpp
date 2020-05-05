

for(所有组k)
	for(所有属于组k的物品i)
		for(int j=V;j>=v[i];j--)
			f[k][j]=max(f[k][j],max(f[k-1][j],f[k-1][j-v[i]]+val[i]));