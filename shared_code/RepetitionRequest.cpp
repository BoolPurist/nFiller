//
// Created by nicegraphic on 3/6/22.
//

#include "RepetitionRequest.h"

std::ostream &operator<<(std::ostream &os, const RepetitionRequest &input) {
  os << "toRepeat: " << input.toRepeat << " numberOfRepeat: " << input.numberOfRepeat;
  return os;
}

RepetitionRequest::RepetitionRequest(const std::string &to_repeat, int number_of_repeat)
	: toRepeat(to_repeat), numberOfRepeat(number_of_repeat) {}
RepetitionRequest::RepetitionRequest()=default;

std::string RepetitionRequest::ReconstructSingleInput() const {
  std::string reconstructed{toRepeat};
  reconstructed += "\n";
  reconstructed += std::to_string(numberOfRepeat);
  return reconstructed;
}
