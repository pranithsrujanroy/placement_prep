//InterviewBit: Maxspprod
int Solution::maxSpecialProduct(vector<int> &A) {
    int n = A.size();
    int lsv[n],rsv[n];
    stack<pair<long long int,int>> s;
    pair<int,int>p;
    p=make_pair(10000000000,0);
    s.push(p);
    for(int i=0;i<n;i++){
        while(A[i]>=s.top().first)
            s.pop();
        lsv[i]=s.top().second;
        s.push(make_pair(A[i],i));
    }
    while(!s.empty())
        s.pop();
    s.push(p);
    for(int i=n-1;i>=0;i--){
        while(A[i]>=s.top().first)
            s.pop();
        rsv[i]=s.top().second;
        s.push(make_pair(A[i],i));
    }
    long long x=lsv[0],y=rsv[0];
    long long m=x*y;
    for(int i=1;i<n;i++){
        x=lsv[i];
        y=rsv[i];
        m=max(m,x*y);
    }
    return m%1000000007;
}
