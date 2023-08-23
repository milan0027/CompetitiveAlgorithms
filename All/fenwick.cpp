class Fenwick{
public:
    vector<int> fenwick;
    vector<int> a;
    int n;
    
    Fenwick(vector<int>& nums) {
        n=nums.size();
        a.resize(n+1,0);
        for(int i=1;i<=n;i++)
            a[i]=nums[i-1];
        
        vector<int> pref(n+1,0);
        for(int i=1;i<=n;i++)
            pref[i]=pref[i-1]+nums[i-1];
        
        fenwick.resize(n+1);
        fenwick[0]=0;
        for(int i=1;i<=n;i++)
            fenwick[i]=pref[i]-pref[i-LSB(i)];
        
        
    }
    int LSB(int i)
    {
        return i&(-i);
    }
    
    void add(int i, int val)
    {
        while(i<=n)
        {
            fenwick[i]+=val;
            i+=LSB(i);
        }
    }
    
    void update(int index, int val) {
        index++;
        int neg=-a[index];
        add(index,neg);
        add(index,val);
        a[index]=val;
        
    }
    int query(int i){
        int ans=0;
        while(i>0)
        {
            ans+=fenwick[i];
            i-=LSB(i);
        }
        return ans;
    }
    
    int sumRange(int left, int right) {
        
        return query(right+1)-query(left);
        
    }
};