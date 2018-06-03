// https://www.interviewbit.com/problems/rain-water-trapped/

int Solution::trap(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
class Solution {
    public:
        int trap(int A[], int n) {
            int left = 0; int right = n - 1;
            int res = 0;
            int maxleft = 0, maxright = 0;
            while(left <= right){
                if(A[left] <= A[right]){
                    if(A[left] >= maxleft) maxleft = A[left];
                    else res += maxleft-A[left];
                    left++;
                }
                else{
                    if(A[right] >= maxright) maxright = A[right];
                    else res += maxright - A[right];
                    right--;
                }
            }
            return res;
        }
};
}