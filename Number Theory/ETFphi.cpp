const int sizee=1000000;
int phi[sizee+1];
//call this function form int main
void precalculate()
{
	for(int i=0;i<=sizee;i++)
		phi[i]=i;

	for(int i=2;i<=sizee;i++)
	{
		if(phi[i]==i)
		{
			for(int j=i;j<=sizee;j+=i)
				phi[j] = phi[j]-phi[j]/i;
		}
	}
}