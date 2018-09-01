//  https://www.interviewbit.com/problems/gas-station/

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    
    int gavail = 0;
    int i = 0, k;
    int n = A.size();
    
    while(i<n) {
        if(A[i]-B[i]>=0) {
            int start = i;
            
            gavail = A[i]-B[i];
            int j = (i+1)%n;
            k = i+1;
            
            while(gavail+(A[j]-B[j]) >= 0) {
                gavail += (A[j]-B[j]);
                //cout << gavail << endl;
                if(j==start)
                    return start;
                    
                j++;
                k++;
                if(j>=n)
                    j = j%n;
            }
            i = j+1;
        } else 
            i++;
        if(k>=n)
            break;
    }
    return -1;
}

