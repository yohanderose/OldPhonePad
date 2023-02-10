#include "old_phonepad.cpp"
#include <cassert>
#include <ostream>

#define assert(condition, message)                                             \
  (!(condition))                                                               \
      ? (std::cerr << "Assertion failed: (" << #condition << "), "             \
                   << "function " << __FUNCTION__ << ", file " << __FILE__     \
                   << ", line " << __LINE__ << "." << std::endl                \
                   << message << std::endl,                                    \
         abort(), 0)                                                           \
      : 1

int main() {

  OldPhonePad oldPhonePad;
  std::string input;
  std::string result;
  std::string expected;
  std::vector<std::pair<std::string, std::string>> cases = {
      // Given examples
      {"227#", "BP"},
      {"227*#", "B"},
      {"4433555 555666#", "HELLO"},
      {"8 88777444666*664#", "TURING"},
      // Looping the same number
      {"6#", "M"},
      {"66#", "N"},
      {"666#", "O"},
      {"6666#", "M"},
      {"66666#", "N"},
      {"666666#", "O"},
      {"6666666#", "M"},
      // Empty input
      {"", ""},
      {"#", ""},
      {"*", ""},
      {"*#", ""},
      // Backspaces
      {"666*666#", "O"},
      // Pause agnostic
      {"3322 22#", "EBB"},
      {"3322 3#", "EBD"},
      {"33223#", "EBD"},
  };

  for (auto &c : cases) {
    input = c.first;
    expected = c.second;
    result = oldPhonePad.decode(input);
    assert(result == expected, "(FAIL) | Input: " + input + ", expected: " +
                                   expected + ", result: " + result);
    std::cout << "(PASS) | Input: " << input << ", expected: " << expected
              << std::endl;
  }
}
