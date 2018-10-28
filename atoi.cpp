#include <iostream>
#include <string>
#include <string.h>
#include <limits.h>

using namespace std;

int myatoi(string s) {

    string intmax = to_string(INT_MAX);

    bool foundRegChar = false;
    bool negative = false;
    int brCifara = 0;
        
    int solution = 0;

    for(int i=0;i<s.length();i++) {

        char tmp = s[i];

        if(tmp == ' ' && !foundRegChar) {
            continue;
        }
        if(tmp == ' ' && foundRegChar) {
            break;
        }
        if(tmp == '-' && solution == 0) {
            negative = true;
        }
        else if(!isdigit(tmp))
            return solution;
        else if(isdigit(tmp)) {

            solution = solution*10 + tmp-'0';
            brCifara++;

            if(brCifara >= 10) {
                string pom = to_string(solution);
                if(pom.compare(intmax) > 0) {
                    if(negative)
                        return INT_MIN;
                    else
                        return INT_MAX;
                }
            }

        }
    }

    solution = negative ? solution*-1 : solution;
    return solution;
}

int main() {

    string s;
    cin >> s;

    cout << "Kraj : " << myatoi(s) << endl;

    return 0;
}