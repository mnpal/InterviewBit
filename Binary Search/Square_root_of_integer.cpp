//  https://www.interviewbit.com/problems/square-root-of-integer/

int Solution::sqrt(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    double n = A;
    double error = 0.00000001;
    double s = n;
    while((s - n/s) > error)
        s = (s + n/s)/2;
    return int(s);
}

