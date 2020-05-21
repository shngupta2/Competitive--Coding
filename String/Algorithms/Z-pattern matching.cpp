//Question https://www.interviewbit.com/problems/implement-strstr/
//Source https://www.youtube.com/watch?v=z2pcwg82rOE
//implementation https://www.youtube.com/watch?v=uFPSFsOlklE
//T.C = O(patt.size() + text.size())

int Solution::strStr(const string A, const string B) {
    if(A.size() == 0 || B.size() == 0 || B.size() > A.size())
        return -1;
    string concat = B + "$" + A;
    int n = concat.size();
    vector <int> z (n);
    
    int l = 0;
    int r = 0;
    for(int i = 1; i < n; i++) {
        if(i > r) {
            l = r = i;
            while(r < n && concat[r - l] == concat[r])
                r++;
            z[i] = r - l;
            r--;
        }
        else {
           int k = i - l;
            if(z[k] < r - i + 1) {
                z[i] = z[k];
            }
            else {
                l = i;
                while(r < n && concat[r - l] == concat[r])
                r++;
            z[i] = r - l;
            r--;                
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(z[i] == B.size())
            return i - B.size() - 1;
    }
    return -1;
}
