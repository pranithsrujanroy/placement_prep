//InterviewBit Min steps in an infinite grid
int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int n = A.size();
    long long min_steps = 0;

    for(int i=0;i<n-1;i++){
        int x_dist = abs(A[i+1]-A[i]), y_dist = abs(B[i+1]-B[i]);
        min_steps += x_dist>y_dist?x_dist:y_dist;
    }
    return min_steps;
}
