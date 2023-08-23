class sparseTable{
    
    public:
    int n;
    vector<vector<int>> table;
    
    sparseTable(vi &arr){
        n=(int)arr.size();
        int to=logtwo(n);
        table=vector<vector<int>> (n+1, vector<int> (to+1,0));
        for (int i = 0; i < n; i++)
        table[i][0] = arr[i];
 
        // Build sparse table
        for (int j = 1; j <= to; j++)
            for (int i = 0; i <= n - (1 << j); i++)
                table[i][j] = func(table[i][j - 1],
                        table[i + (1 << (j - 1))][j - 1]);
    }
    
    int logtwo(int x){
        int cnt=0;
        while(x!=0){
            x>>=1;
            cnt++;
        }
        return cnt-1; 
    }
    
    int func(int x,int y){
        return max(x,y);
    }
    
    int query(int L, int R){  
        int j = logtwo(R - L + 1);
        return func(table[L][j], table[R - (1 << j) + 1][j]);
    }
};