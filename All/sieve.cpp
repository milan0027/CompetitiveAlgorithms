const int sizee=1000000;
bool isPrime[sizee+1];
//call this function form int main
void precompute()
{
	for(int i=0;i<=sizee;i++)
		isPrime[i]=1;

	isPrime[1]=0;
	isPrime[0]=0;

	for(int i=2;i*i<=sizee;i++)
	{
		if(isPrime[i])
		{
			for(int j=i*i;j<=sizee;j+=i)
				isPrime[j]=0;
		}
	}
}