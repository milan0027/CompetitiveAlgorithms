class segment{
    
    public:
    int n;
    vector<int> a;
    vector<int> seg;
    
    segment(vector<int> &aa){
        n=sz(aa);
        a=aa;
        seg.resize(4*n);
    }
    
    int func(int aa,int bb){
        return max(aa,bb);
    }
    
    void build(int ind,int lo,int hi){
        if(lo==hi){
            seg[ind]=a[lo];
            return;
        }
        
        int mid=(lo+hi)>>1;
        build(2*ind+1,lo,mid);
        build(2*ind+2,mid+1,hi);
        seg[ind]=func(seg[2*ind+1],seg[2*ind+2]);
    }
    
    int query(int ind,int lo,int hi,int l,int r){
        if(lo>=l and hi<=r)
        return seg[ind];
        
        if(r<lo or hi<l)
        return -inf;
        
        int mid = (lo+hi)>>1;
        int q1 = query(2*ind+1,lo,mid,l,r);
        int q2 = query(2*ind+2,mid+1,hi,l,r);
        return func(q1,q2);
    }
    
    void add(int ind,int lo,int hi,int node,int val){
        if(lo==hi){
            seg[ind]+=val;
        }
        else{
            int mid = (lo+hi)>>1;
            if(node <= mid)
                add(2*ind+1,lo,mid,node,val);
            else
                add(2*ind+2,mid+1,hi,node,val);
            
            seg[ind]=func(seg[2*ind+1],seg[2*ind+2]);
        }
        
    }
    
    void update(int ind,int lo,int hi,int node,int val){
        if(lo==hi){
            seg[ind]=val;
        }
        else{
            int mid = (lo+hi)>>1;
            if(node <= mid)
                update(2*ind+1,lo,mid,node,val);
            else
                update(2*ind+2,mid+1,hi,node,val);
            
            seg[ind]=func(seg[2*ind+1],seg[2*ind+2]);
        }
    }
      
};