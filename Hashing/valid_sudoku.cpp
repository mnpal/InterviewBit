//  https://www.interviewbit.com/problems/valid-sudoku/

bool validRow(const vector<string> &A) {
    
    for(int i=0;i<A.size();i++) {
        
        vector<int> row(10, 0);
        
        for(int j=0;j<A[i].size();j++) {
            
            int d = A[i][j]-'0';
            if(d>0 && d<=9) {
                row[d]++;
                if(row[d]>1)
                    return false;
            }
            else if(A[i][j]!='.')
                return false;
        }
        
    }
    return true;
}

bool validColumn(const vector<string> &A) {
    
    for(int i=0;i<A.size();i++) {
        
        vector<int> row(10, 0);
        
        for(int j=0;j<A[i].size();j++) {
            
            int d = A[j][i]-'0';
            if(d>0 && d<=9) {
                row[d]++;
                if(row[d]>1)
                    return false;
            }
            else if(A[j][i]!='.')
                return false;
        }
       
    }
    return true;
}

bool validGrid(const vector<string> &A) {
    
    int k = 0, a=0, b=0;
    while(k<9) {
        vector<int> row(10, 0);
        int a = 3*(k/3);
        int b;
        if(k%3==0)
            b = 0;
        else 
            b += 3;
        for(int i=a;i<3+a;i++) {
            
            for(int j=b;j<3+b;j++) {
                
                int d = A[i][j]-'0';
                if(d>0 && d<=9) {
                    row[d]++;
                    if(row[d]>1)
                        return false;
                }
                else if(A[i][j]!='.')
                    return false;
            }
        }
        
        k++;
        
    }
    return true;
}

int Solution::isValidSudoku(const vector<string> &A) {
    
    if(validRow(A) && validColumn(A) && validGrid(A))
        return 1;
    return 0;
}

