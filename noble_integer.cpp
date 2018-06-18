//InterviewBit: Noble integer
int Solution::solve(vector<int> &A) {
    int n=A.size();
    sort(A.begin(),A.end());
    for(int i=0;i<n;i++){
       // if(A[i]>n-i-1 || A[i]<n-i-1)
         //   continue;
        int k=i+1;
        while(A[i]==A[k]){
            k++;
            continue;
        }
        if(A[i]==n-k)
            return 1;
    }
    if(A[n-1]==0)
        return 1;
    return -1;
}
