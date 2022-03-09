#include <iostream>
#include <string>
#include <sstream>
#include <bufferController.h>

void EndProgramForUserMistake(const std::string &message);

int main() {

  UserInput userInput{};

  try
  {
    userInput = askUserForRepetition(std::cin, std::cout);
  }
  catch (const std::invalid_argument &error)
  {
    EndProgramForUserMistake("No number was given.");
  }
  catch (const std::out_of_range &error)
  {
    EndProgramForUserMistake("Amount of number is to big.");
  }

  const auto absoluteAmount = static_cast<unsigned int>(
      std::abs(userInput.numberOfRepeat)
    );
  const auto bar = std::string(30, '=');

  std::cout << bar << std::endl;
  printNthTimes(
      std::cout,
      userInput.toRepeat,
      absoluteAmount
    );

  return 0;
}

void EndProgramForUserMistake(const std::string &message)
{
  std::cerr << message << std::endl;
  exit(0);
}




