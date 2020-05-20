// Question https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/
// Approach as we all know if a string isnt palindromic and you have to make it palindrome by adding characters
// at start then according to this approach ive tried to make a new string by adding from last charcter and compare 
// whether it is palindrome or not

int Solution::solve(string A) {
    string b = A;
    int n = A.size();
    reverse(b.begin(), b.end());
    if(A == b) return 0;
    int count = 0;
    string tmp = "";
    for(int i = n - 1; i >= 0; i--) {
        tmp += A[i];
        string first = tmp + A;
        string second = first;
        count++;
        reverse(first.begin(), first.end()); 
        if(first == second) {
            return count;
            break;
        }
    }
    
}
