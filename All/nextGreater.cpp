vector<int> nextGreater(vector<int> &arr)
{
    int n=sz(arr);
    stack<int> s;
    s.push(0);
    vector<int> ans(n,-1);
    
    for (int i = 1; i < n; i++) {
 
        while (!s.empty() && arr[s.top()] < arr[i]) {
            ans[s.top()] = i;
            s.pop();
        }
 
        s.push(i);
    }
 
    return ans;
}