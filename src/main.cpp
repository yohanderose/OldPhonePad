#include "old_phonepad.cpp"
#include <iostream>

int main() {

  OldPhonePad oldPhonePad;

  // Given examples
  /* oldPhonePad.decode("227#"); */
  /* oldPhonePad.decode("227*#"); */
  /* oldPhonePad.decode("227* 33 333#"); */
  oldPhonePad.decode("4433555 555666#");
  oldPhonePad.decode("8 88777444666*664#");
  // Looping through the same number
  /* oldPhonePad.decode("6#"); */
  /* oldPhonePad.decode("66#"); */
  /* oldPhonePad.decode("666#"); */
  /* oldPhonePad.decode("6666#"); */
  /* oldPhonePad.decode("66666#"); */
  /* oldPhonePad.decode("666666#"); */
  // Leading backspace
  oldPhonePad.decode("*666*6666#");
  // Empty message
  oldPhonePad.decode("");
  oldPhonePad.decode("666*666 6#");
}
