const int sizee=1000000;
int fact[sizee+1];
int inv[sizee+1];
int bepower(int x,int n)
{
	int res=1;

	while(n)
	{
		if(n%2==1){
			res*=x;
			res%=mod;
		}
		n/=2;
		x*=x;
		x%=mod;
	}
	return res;
}
//call this function form int main
void precompute()
{
	fact[0]=1;
	inv[0]=1;
	for(int i=1;i<=sizee;i++)
	{
		fact[i] = fact[i-1]*i; 
		fact[i]%=mod;
		inv[i]=bepower(fact[i],mod-2);
	}
}

int ncr(int n,int r)
{
	return (((fact[n]*inv[n-r])%mod)*inv[r])%mod;
}

int npr(int n,int r)
{
	return (fact[n]*inv[n-r])%mod;
}