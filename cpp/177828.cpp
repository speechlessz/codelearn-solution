int sofaShipping(std::vector<int> a) {
    int n = a.size();
    stack<int> st;
    for (int i=n-1;i>=0;i--) st.push(a[i]);
    int res = 0;
    sort(a.begin(), a.end());
    for (int x : a) {
        stack<int> tmp;
        while (!st.empty() && st.top() != x) {
            res++;
            tmp.push(st.top());
            st.pop();
        }
        st.pop();
        res++;
        for (; !tmp.empty(); st.push(tmp.top()), tmp.pop()) {
        }
    }
    return res;
}
