//  https://www.interviewbit.com/problems/simplify-directory-path/

string Solution::simplifyPath(string A) {
    stack<string> st;
    
    int n = A.size();
    for(int i=1;i<n;i++) {
        if(A[i]=='.'&&A[i+1]=='.') {
            if(!st.empty())
                st.pop();
        }
        else if(A[i]=='.')
            continue;
        else {
            string a;
            while(A[i]!='/') {
                a += A[i];
                i++;
                if(i==n)
                    break;
            }
            if(a.size()!=0)
                st.push(a);
        }
    }
    string path;
    if(!st.empty()) {
        path = st.top();
        st.pop();
    }
        
    while(!st.empty()) {
        path = st.top() + "/" + path;
        st.pop();
    }
    return "/"+path;
}

