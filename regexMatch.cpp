#include <iostream>
#include <string>
#include <string.h>

using namespace std;

bool check(string s, string p) {

    char tmpChar, stopChar;
    int tmpS = s.length()-1;

    for(int i=p.length()-1;i>=0;i--) {

        if(p[i] != '*' && p[i] != '.') {

            if(p[i] != s[tmpS--])
                return false;
        }
        else if(p[i] == '.') {

            tmpS--;
        }
        else if(p[i] == '*') {

            char patternChar = p[i-1];
            int j = i-2;
            while(j > 0 && p[j] == '*') {
                j-=2;
            }

            if(j < 0) {
                stopChar = p[i-3];
                if(patternChar != '.')
                {
                    while(tmpS >= 0 && s[tmpS] == patternChar) {
                        tmpS--;
                    }

                    if(tmpS == -1)
                        return true;
                    else if(s[tmpS] != stopChar) {
                        cout << stopChar << " " << s[tmpS] << endl;
                        return false;
                    }
                    else {
                        i--;
                        continue;
                    }

                } 
                else {
                    return true;
                }

                
            }

            stopChar = p[j];

            if(patternChar == '.') {

                while(s[tmpS] != stopChar) {
                    tmpS--;
                }

                if(s[tmpS] != stopChar)
                    return false;
            }
            else {
                while(patternChar == s[tmpS]) {
                    tmpS--;
                }
                if(s[tmpS] != stopChar)
                    return false;
            }

            i--;
        }
    }

    return true;

}

int main() {

    string s, p;
    cin >> s >> p;


    cout << check(s, p) << endl;

    return 0;
}