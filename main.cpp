#include <iostream>
#include <string>

#include <fstream>
#include <sstream>
#include <bufferController.h>

const size_t k_maxAllowedBufferSize = 1000;

struct UserInput
{
  std::string toRepeat;
  int numberOfRepeat;

  friend std::ostream &operator<<(std::ostream &os, const UserInput &input)
  {
	os << "toRepeat: " << input.toRepeat << " numberOfRepeat: " << input.numberOfRepeat;
	return os;
  }
};

UserInput CreateFromInput(std::istream& input, std::ostream& userPrompt)
{
  UserInput providedInput{};
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
//  auto result = CreateFromInput(std::cin, std::cout);
//  std::cout << result << std::endl;
  printNthTimes(std::cout, "a", 10);
  return 0;
}





