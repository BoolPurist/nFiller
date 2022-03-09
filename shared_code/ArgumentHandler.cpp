//
// Created by nicegraphic on 3/9/22.
//

#include <ArgumentHandler.h>

void printRequestedRepetition(const UserInput &givenInput, bool printWithBar);
UserInput validateAndConvertCommandLineArgs(int argc, char** argv);
void endForInvalidNumber();
void endForOutOfRangeNumber();

void handleInteractiveUsage()
{
  UserInput userInput{};

  try
  {
    userInput = askUserForRepetition(std::cin, std::cout);
  }
  catch (const std::invalid_argument &error)
  {
    endForInvalidNumber();
  }
  catch (const std::out_of_range &error)
  {
    endForOutOfRangeNumber();
  }

  printRequestedRepetition(userInput, true);
}

void printRequestedRepetition(const UserInput &givenInput, bool printWithBar)
{
  const auto absoluteAmount = static_cast<unsigned int>(
    std::abs(givenInput.numberOfRepeat)
  );

  if (printWithBar)
  {
    const auto bar = std::string(30, '=');
    std::cout << bar << std::endl;
  }


  printNthTimes(
    std::cout,
    givenInput.toRepeat,
    absoluteAmount,
    false,
    10
  );
}

void handleCommandLineInput(int argc, char** argv)
{
  auto converted = validateAndConvertCommandLineArgs(argc, argv);
  printRequestedRepetition(converted, false);
}

UserInput validateAndConvertCommandLineArgs(int argc, char** argv)
{

  if (argc != 3)
  {
    endProgramForUserMistake("2 arguments are required");
  }

  std::vector<std::string> commandLineArgs{};
  commandLineArgs.assign(argv + 1, argv + argc);

  UserInput processedInput{};
  processedInput.toRepeat = commandLineArgs.front();

  const std::string &unconvertedNumber = commandLineArgs.back();
  int convertedNumber{};

  try
  {
    convertedNumber = std::stoi(unconvertedNumber);
  }
  catch (const std::invalid_argument &error)
  {
    endForInvalidNumber();
  }
  catch (const std::out_of_range &error)
  {
    endForOutOfRangeNumber();
  }

  processedInput.numberOfRepeat = convertedNumber;

  return processedInput;
}

void endProgramForUserMistake(const std::string &message)
{
  std::cerr << message << std::endl;
  exit(-1);
}

void endForInvalidNumber()
{
  endProgramForUserMistake("No number was given.");
}

void endForOutOfRangeNumber()
{
  endProgramForUserMistake("Amount of number is to big.");
}

