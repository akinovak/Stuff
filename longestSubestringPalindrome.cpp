#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s, int start, int end) {

    for(int i=start,j=end;i < j;i++, j--) {

        if(s[i] != s[j])
            return false;
    }
    
    return true;

}

string longestPalindrome(string s) {

    if(s.length() == 1)
        return s;
    
    int maximum = -1;
    string najveci;
    for(int i=0;i<s.length();i++) {

        for(int j=i+1;j<s.length();j++) {

            if(s[j] == s[i]) {

                //cout << i << " " << j << endl;

                if(isPalindrome(s, i, j)) {

                    int tmpMax = j-i+1;
                    if(tmpMax > maximum) {
                        maximum = tmpMax;
                        najveci.clear();
                        // if(i == 0)
                        //     najveci = s.substr(i, j+1);
                        // else
                        //     najveci = s.substr(i, j);
                        najveci = s.substr(i, j-i+1);
                    }
                        
                }
            }

        }

    }

    //cout << najveci.length() << endl;

    if(najveci.length() > 0)
        return najveci;
    else
        {
            char c = s[0];
            string kraj(1, c);
           // cout << kraj << endl;
            return kraj;
        }

}

int main() {

    string s;
    cin >> s;

    cout << longestPalindrome(s) << endl;
   // cout << isPalindrome("avnva", 0, 4) << endl;
    return 0;
}