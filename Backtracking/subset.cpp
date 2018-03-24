//  https://www.interviewbit.com/problems/subset/

vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int> > res;
    int n = A.size();
    int LIM = pow(2, n);
    
    for(int i=0;i<LIM;i++) {
        vector<int> temp;
        for(int j=0;j<n;j++) {
            if(i&(1<<j))
                continue;
            temp.push_back(A[j]);
        }
        sort(temp.begin(), temp.end());
        res.push_back(temp);
    }
    sort(res.begin(), res.end());
    return res;
}

