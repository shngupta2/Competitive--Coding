#include <iostream>
using namespace std;

int value(char c) {
    if(c == 'I') 
        return 1;
    if(c == 'V')
        return 5;
    if(c == 'X')
        return 10;
    if(c == 'L') 
        return 50;
    if(c == 'C')
        return 100;
    if(c == 'D') 
        return 500;
    if(c == 'M')
        return 1000;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        string k;
        cin>>k;
        int n = k.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            int s1 = value(k[i]);
            if(i + 1 < n) {
                int s2 = value(k[i + 1]);
                if(s1 >= s2) {
                    res += s1;
                } else {
                    res += s2 - s1;
                    i++;
                }
            } else {
                res += s1;
            }
        }
        cout<<res<<endl;
    }


	//code
	return 0;
}
