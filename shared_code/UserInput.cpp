//
// Created by nicegraphic on 3/6/22.
//

#include "UserInput.h"

std::ostream &operator<<(std::ostream &os, const UserInput &input) {
  os << "toRepeat: " << input.toRepeat << " numberOfRepeat: " << input.numberOfRepeat;
  return os;
}

UserInput::UserInput(const std::string &to_repeat, int number_of_repeat)
	: toRepeat(to_repeat), numberOfRepeat(number_of_repeat) {}
UserInput::UserInput() {}

std::string UserInput::ReconstructSingleInput() const {
  std::string reconstructed{toRepeat};
  reconstructed += "\n";
  reconstructed += std::to_string(numberOfRepeat);
  return reconstructed;
}
