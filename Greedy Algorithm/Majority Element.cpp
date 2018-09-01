//  https://www.interviewbit.com/problems/majority-element/

int Solution::majorityElement(const vector<int> &A) {
    
    // checking for candidate
    int count = 0;
    int candidate, n = A.size();
    
    for(int i=0;i<n;i++) {
        if(count==0) {
            candidate = A[i];
            count++;
        } else {
            if(candidate==A[i])
                count++;
            else
                count--;
        }
    }
    
    if(count==0)
        return -1;
    // validating candidate
    count = 0;
    for(int i=0;i<n;i++)
        if(candidate==A[i])
            count++;
    
    return (count>n/2)?candidate:-1;
}

