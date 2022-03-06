#include <iostream>
#include <string>

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
//  auto result = CreateFromInput(std::cin, std::cout);
//  std::cout << result << std::endl;
  const std::string expectedOutput = "abab\nab";
  const std::string actualPattern = "ab";
  const int actualMaxBufferSize = 5;
  const int actualRepetition = 3;
  printNthTimes(std::cout, actualPattern, actualRepetition, true, actualMaxBufferSize);
  return 0;
}





