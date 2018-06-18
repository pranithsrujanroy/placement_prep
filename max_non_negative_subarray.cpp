//Maximum non negative sub array
//Find out the maximum sub-array of non negative numbers from an array.
//The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.
//Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).
vector<int> Solution::maxset(vector<int> &A) {
    int n=A.size(), s=-1, e=-1,s_i=-1,e_i=-1;
    long sum=0,s_prev=-1;
    vector<int> m;
    for(int i=0;i<n;i++){
        while(A[i]>=0&&i<n){
            if(s==-1){
                s=i;
                e=i;
            }
            else
                e=e+1;
            sum+=A[i];
            i++;
        }
        if(s_prev==-1 || sum>s_prev){
            s_prev=sum;
            s_i = s;
            e_i = e;
        }
        sum = 0;
        s = -1;
        e = -1;
    }
    if(s_i>-1){
        for(int i=s_i;i<=e_i;i++)
            m.push_back(A[i]);
    }
    return m;
}
