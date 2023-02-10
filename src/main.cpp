#include "old_phonepad.cpp"
#include <iostream>

int main() {

  OldPhonePad oldPhonePad;
  std::string line;

  while (std::getline(std::cin, line)) {
    std::cout << line << " --> " << oldPhonePad.decode(line) << std::endl;
  }
}
