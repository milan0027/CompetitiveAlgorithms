int sizee=1000000;
int fact[sizee+1];
//call this function form int main
void pre_calculate()
{
	fact[0]=1;
	for(int i=1;i<=sizee;i++)
	{
		fact[i] = fact[i-1]*i; 
		fact[i]%=mod;
	}
}

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

int ncr(int n,int r)
{
	int temp1 = fact[n];
	int temp2 = (fact[n-r]*fact[r])%mod;
	temp1*=bepower(temp2,mod-2);
	return temp1%mod;
}

int npr(int n,int r)
{
	int temp1 = fact[n];
	temp1*=bepower(fact[n-r],mod-2);
	return temp1%mod;
}