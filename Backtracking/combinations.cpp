//  https://www.interviewbit.com/problems/combinations/

vector<vector<int> > Solution::combine(int n, int B) {
    
    vector<vector<int> > result;
    vector<int> A(n);
    for(int i=0;i<n;i++)
        A[i] = i+1;
        
    int lim = pow(2, n);
    vector<int> temp;
    for(int i=0;i<lim;i++) {
        
        for(int j=0;j<n;j++) {
            if(i&(1<<j))
                temp.push_back(A[j]);
        }
        if(temp.size()==B) {
            sort(temp.begin(), temp.end());
            result.push_back(temp);
        }
        temp.clear();
    }
    sort(result.begin(), result.end());
    return result;
}

######## ANOTHER SOLUTION ###########

vector<vector<int> > Solution::combine(int A, int B) {
    vector<vector<int> > result;
    
    auto lim = pow(2, A);
    
    for(auto i=0;i<lim;i++) {
        vector<int> temp;
        for(auto j=0;j<A;j++) {
            if(i&(1<<j))
                continue;
            temp.push_back(j+1);
        }
        if(temp.size()==B) {
            sort(temp.begin(), temp.end());
            result.push_back(temp);
        }
    }
    sort(result.begin(), result.end());
    return result;
}
