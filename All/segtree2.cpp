class segment{
    
    public:
    int n;
    vector<int> a;
    vector<int> seg;
    vector<int> lazy;
    vector<int> idle;
    
    segment(vector<int> &aa){
        n=sz(aa);
        a=aa;
        seg=vector<int> (4*n,0);
        lazy=vector<int> (4*n,0);
        idle=vector<int> (4*n,inf);
    }
    
    int func(int aa,int bb){
        return aa+bb;
    }
    
    void build(int ind,int lo,int hi){
        
        if(lo==hi){
            seg[ind]=a[lo];
            return;
        }
        
        int mid = (lo+hi)>>1;
        build(2*ind+1,lo,mid);
        build(2*ind+2,mid+1,hi);
        seg[ind]=func(seg[2*ind+1],seg[2*ind+2]);
    }
    
    int querySum(int ind,int lo,int hi,int l,int r){
        
        if(idle[ind]!=inf){
            seg[ind]=(hi-lo+1)*idle[ind];
            if(lo!=hi){
                idle[2*ind+1]=idle[ind];
                idle[2*ind+2]=idle[ind];
                lazy[2*ind+1]=0;
                lazy[2*ind+2]=0;
            }
            idle[ind]=inf;
        }
        
        if(lazy[ind]){
            seg[ind]+=(hi-lo+1)*lazy[ind];
            if(lo!=hi){
                lazy[2*ind+1]+=lazy[ind];
                lazy[2*ind+2]+=lazy[ind];
            }
            lazy[ind]=0;
        }
        
        if(r<lo or hi<l or lo>hi)
        return 0;
        
        if(l<=lo and hi<=r)
        return seg[ind];
 
        int mid = (lo+hi)>>1;
        int q1=querySum(2*ind+1,lo,mid,l,r);
        int q2=querySum(2*ind+2,mid+1,hi,l,r);
        return func(q1,q2);
    }
    
    void rangeAdd(int ind,int lo,int hi,int l,int r,int val){
        
        if(idle[ind]!=inf){
            seg[ind]=(hi-lo+1)*idle[ind];
            if(lo!=hi){
                idle[2*ind+1]=idle[ind];
                idle[2*ind+2]=idle[ind];
                lazy[2*ind+1]=0;
                lazy[2*ind+2]=0;
            }
            idle[ind]=inf;
        }
        if(lazy[ind]){
            seg[ind]+=(hi-lo+1)*lazy[ind];
            if(lo!=hi){
                lazy[2*ind+1]+=lazy[ind];
                lazy[2*ind+2]+=lazy[ind];
            }
            lazy[ind]=0;
        }
        
        if(lo>r or hi<l or lo>hi)
        return;
        
        if(l<=lo and hi<=r){
            seg[ind]+=(hi-lo+1)*val;
            if(lo!=hi){
                lazy[2*ind+1]+=val;
                lazy[2*ind+2]+=val;
            }
            return; 
        }
        int mid = (lo+hi)>>1;
        rangeAdd(2*ind+1,lo,mid,l,r,val);
        rangeAdd(2*ind+2,mid+1,hi,l,r,val);
        seg[ind]=func(seg[2*ind+1],seg[2*ind+2]);
        
    }
    
    void rangeUpdate(int ind,int lo,int hi,int l,int r,int val){
        if(idle[ind]!=inf){
            seg[ind]=(hi-lo+1)*idle[ind];
            if(lo!=hi){
                idle[2*ind+1]=idle[ind];
                idle[2*ind+2]=idle[ind];
                lazy[2*ind+1]=0;
                lazy[2*ind+2]=0;
            }
            idle[ind]=inf;
        }
        if(lazy[ind]){
            seg[ind]+=(hi-lo+1)*lazy[ind];
            if(lo!=hi){
                lazy[2*ind+1]+=lazy[ind];
                lazy[2*ind+2]+=lazy[ind];
            }
            lazy[ind]=0;
        }
        if(lo>r or hi<l or lo>hi)
        return;
        
        if(l<=lo and hi<=r){
            seg[ind]=(hi-lo+1)*val;
            if(lo!=hi){
                idle[2*ind+1]=val;
                idle[2*ind+2]=val;
                lazy[2*ind+1]=0;
                lazy[2*ind+2]=0;
            }
            return;
        }
        int mid = (lo+hi)>>1;
        rangeUpdate(2*ind+1,lo,mid,l,r,val);
        rangeUpdate(2*ind+2,mid+1,hi,l,r,val);
        seg[ind]=func(seg[2*ind+1],seg[2*ind+2]);
        
    }
    
};