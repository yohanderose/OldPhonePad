#include "phonepad.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#define DEBUG 0
using namespace std;

class OldPhonePad : public PhonePad {

private:
  map<string, vector<char>> m_tokenToLetterMap = {
      {"2", {'A', 'B', 'C'}}, {"3", {'D', 'E', 'F'}},
      {"4", {'G', 'H', 'I'}}, {"5", {'J', 'K', 'L'}},
      {"6", {'M', 'N', 'O'}}, {"7", {'P', 'Q', 'R', 'S'}},
      {"8", {'T', 'U', 'V'}}, {"9", {'W', 'X', 'Y', 'Z'}},
  };

  vector<string> tokenise(const string &inputString) override {
    /*
     * Accepts a string of digits and returns a vector of token strings.
     */

    vector<string> res;
    string curr;

    for (auto c : inputString) {
      if (c == ' ') {
        res.push_back(curr);
        curr = "";
        continue;
      }

      if (curr.empty()) {
        curr += c;
      } else if (curr.back() == c) {
        curr += c;
      } else {
        res.push_back(curr);
        curr = c;
      }
    }

    return res;
  }

  string mapTokensToLetters(const vector<string> tokens) override {
    /*
     * Accepts a vector of token strings and converts each token to a letter,
     * returning the resulting string.
     */

    string result;
    stringstream letterStream;
    string token;
    string keyButton;
    int letterIndex;

    for (int i = tokens.size() - 1; i >= 0; i--) {
      token = tokens[i];
      if (token == "*") {
        // If the token is a backspace, remove the subsequent letter
        i -= 1;
        continue;
      }

      // The first character of the token is the key button
      keyButton = token.substr(0, 1);
      // The letter index is the number of times the key button was pressed,
      // modulo the number of letters on that key
      letterIndex = (token.size() - 1) % m_tokenToLetterMap[keyButton].size();

      letterStream << m_tokenToLetterMap[keyButton][letterIndex];
    }

    result = letterStream.str();
    reverse(result.begin(), result.end());

    return result;
  }

public:
  string decode(const string &encodedString) override {
    /*
     * Accepts a string of digits and returns the corresponding string of
     * letters defined in this OldPhone.
     */

#if DEBUG
    cout << "OldPhonePad::decode: " << encodedString << " -> ";
#endif

    vector<string> tokens = tokenise(encodedString);
    string letters = mapTokensToLetters(tokens);

#if DEBUG
    for (int i = 0; i < tokens.size(); i++) {
      cout << tokens[i] << (i < tokens.size() - 1 ? "," : "");
    }

    cout << " -> " << letters;
    cout << endl;
#endif

    return letters;
  }
};
