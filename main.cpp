#include <iostream>
#include <string>
#include <sstream>
#include <bufferController.h>

const size_t k_maxAllowedBufferSize = 1000;



UserInput CreateFromInput(std::istream& input, std::ostream& userPrompt)
{
  UserInput providedInput{};
  size_t size = -2;
  std::cout << size << std::endl;
  userPrompt << "Enter pattern to be repeated" << std::endl;
  std::getline(input, providedInput.toRepeat);
  userPrompt << "Enter number of repetition" << std::endl;
  input >> providedInput.numberOfRepeat;
  if (input.fail())
  {
	userPrompt << "No valid number provided" << std::endl;
  }
  return providedInput;
}

int main() {

  return 0;
}





