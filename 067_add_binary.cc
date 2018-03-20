// Given two binary strings, return their sum (also a binary string).
//
// For example,
//     a = "11"
//     b = "1"
//     Return "100".
//

#include <string>
#include <sstream> 
#include <iostream>

#include "gtest/gtest.h"

using namespace std;

class Solution {
    typedef string::reverse_iterator iter;
  public:
    string addBinary(string a, string b) {
        ostringstream oss;
        if (a.size() < b.size()) {
            add(oss, b.rbegin(), b.rend(), a.rbegin(), a.rend(), false);
        } else {
            add(oss, a.rbegin(), a.rend(), b.rbegin(), b.rend(), false);
        }
        auto s = oss.str();
        reverse(s.begin(), s.end());
        return s;
    }

    void add(ostringstream& oss, iter ai, iter ae, iter bi, iter be, bool carry) {
        if (ai == ae) {
            if (carry)
                oss << '1';
            return;
        }

        if (bi == be) {
            if(!carry) {
                for (; ai != ae; ++ai)
                    oss << *ai;
                return;
            }

            oss << (*ai == '1' ? '0' : '1');
            add(oss, ai+1, ae, bi, be, *ai == '1');
            return;
        }

        if (*ai == '1' && *bi == '1') {
            oss << (carry ? '1' : '0');
            add(oss, ai+1, ae, bi+1, be, true);
            return;
        }

        if (*ai == '0' && *bi == '0') {
            oss << (carry ? '1' : '0');
            add(oss, ai+1, ae, bi+1, be, false);
            return;
        }

        oss << (carry ? '0' : '1');
        add(oss, ai+1, ae, bi+1, be, carry);
        return;
    }
};

TEST(AddBinary, 1) {
    cout << Solution().addBinary("1", "1111111") << endl;
    cout << Solution().addBinary("1", "0") << endl;
    cout << Solution().addBinary("0", "0") << endl;
}
