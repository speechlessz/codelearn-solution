typedef long long ll;

ll nthSpecialNumber(int n) {
    set<ll> st;
    st.insert(1ll);
    for (int i=1;i<n;i++) {
        ll u = *st.begin();
        st.erase(st.begin());
        st.insert(u*2);
        st.insert(u*3);
        st.insert(u*5);
    }
    return *st.begin();
}
