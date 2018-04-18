//  https://www.interviewbit.com/problems/evaluate-expression/

int Solution::evalRPN(vector<string> &A) {
    stack<string> st;
    
    int n1, n2;
    
    int n = A.size();
    for(int i=0;i<n;i++) {
        if(A[i]!="+" && A[i]!="-" && A[i]!="/" && A[i]!="*") {
            //cout << A[i] << endl;
            st.push(A[i]);
        }
        else {
            stringstream sa(st.top());
            sa >> n2;
            st.pop();
            stringstream sb(st.top());
            sb >> n1;
            st.pop();
            //cout << n1 << " " << n2 << endl;
            if(A[i]=="+")
                st.push(to_string(n1+n2));
            else if(A[i]=="-") 
                st.push(to_string(n1-n2));
            else if(A[i]=="*")
                st.push(to_string(n1*n2));
            else if(A[i]=="/")
                st.push(to_string(n1/n2));
        }
       // cout << st.top() << endl;
    }
    int res; 
    stringstream ss(st.top());
    ss >> res;
    return res;
}

