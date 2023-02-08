#include <string>
#include <vector>

class PhonePad {
  virtual std::vector<std::string> tokenise(const std::string &inputString) = 0;
  virtual std::string
  mapTokensToLetters(const std::vector<std::string> tokens) = 0;

  virtual std::string decode(const std::string &encodedString) = 0;
};
