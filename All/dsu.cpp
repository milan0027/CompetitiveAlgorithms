class dsu{
    
    public:
    vector<int> par;
    vector<int> rank;
    
    dsu(int n){
        par.resize(n);
        rank.resize(n);
       
        for(int i=0;i<n;i++){
            par[i]=i;
            rank[i]=1;
        }
    }
    
    int findset(int i){
        if(par[i]==i) 
            return i;
        
        return par[i]=findset(par[i]);
    }
    
    void merge(int x,int y){
        int a=findset(x);
        int b=findset(y);
        if(a==b)
            return;
        
        if(rank[a]<rank[b]) swap(a,b);
        
        par[b]=a;
        rank[a]+=rank[b];   
    }
};