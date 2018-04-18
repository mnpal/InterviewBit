//  https://www.interviewbit.com/problems/subsets-ii/

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    int n = A.size();
    vector<vector<int> > subs;
    int LIM = pow(2, n);
    for(int i=0;i<LIM;i++) {
        vector<int> temp;
        for(int j=0;j<n;j++) {
            if(i&(1<<j))
                continue;
            temp.push_back(A[j]);
        }
        sort(temp.begin(),temp.end());
        subs.push_back(temp);
    }
    sort(subs.begin(), subs.end());
    
    vector<vector<int> > res;
    res.push_back(subs[0]);
    for(int i=1;i<subs.size();i++) {
        if(subs[i]==subs[i-1])
            continue;
        res.push_back(subs[i]);
    }
    return res;
}

