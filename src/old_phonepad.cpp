#include "phonepad.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#define DEBUG 1

class OldPhonePad : public PhonePad {

private:
  std::map<std::string, std::vector<char>> m_tokenToLetterMap = {
      {"2", {'A', 'B', 'C'}}, {"3", {'D', 'E', 'F'}},
      {"4", {'G', 'H', 'I'}}, {"5", {'J', 'K', 'L'}},
      {"6", {'M', 'N', 'O'}}, {"7", {'P', 'Q', 'R', 'S'}},
      {"8", {'T', 'U', 'V'}}, {"9", {'W', 'X', 'Y', 'Z'}},
  };

  std::vector<std::string> tokenise(const std::string &inputString) override {
    std::vector<std::string> res;
    std::string curr;

    for (auto c : inputString) {
      /* if (c == '0' || c == '1') { */
      /*   continue; */
      /* } */

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

  std::string
  mapTokensToLetters(const std::vector<std::string> tokens) override {
    std::string result;
    std::stringstream letterStream;
    std::string token;
    std::string keyButton;
    int letterIndex;

    for (int i = tokens.size() - 1; i >= 0; i--) {
      token = tokens[i];
      if (token == "*") {
        i -= 1;
        continue;
      }

      keyButton = token.substr(0, 1);
      letterIndex = (token.size() - 1) % m_tokenToLetterMap[keyButton].size();

      letterStream << m_tokenToLetterMap[keyButton][letterIndex];
    }

    result = letterStream.str();
    reverse(result.begin(), result.end());

    return result;
  }

public:
  std::string decode(const std::string &encodedString) override {

#if DEBUG
    std::cout << "OldPhonePad::decode: " << encodedString << " -> ";
#endif

    std::vector<std::string> tokens = tokenise(encodedString);
    std::string letters = mapTokensToLetters(tokens);

#if DEBUG
    for (int i = 0; i < tokens.size(); i++) {
      std::cout << tokens[i] << (i < tokens.size() - 1 ? "," : "");
    }

    std::cout << " -> " << letters;
    std::cout << std::endl;
#endif

    return letters;
  }
};
