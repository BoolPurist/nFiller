//
// Created by nicegraphic on 3/9/22.
//

#include <ArgumentHandler.h>

/// Carries out task of writing the requested repetition.
/// Precondition: This function expects validated information.
void printRequestedRepetition(const RepetitionRequest &givenInput, bool printWithBar);
/// Validates and tries to convert the given in line commands.
/// If validation is successful then the structured information for an repetition
/// request is returned.
RepetitionRequest processCommandLineArgs(int argc, char** argv);
/// Prints message for not given number like "ab"
void endForInvalidNumber();
/// Prints message for too big number like
/// "2222222222222222222222222222222222222222222222222222222222222222222222222"
void endForOutOfRangeNumber();


void handleInteractiveUsage()
{
  RepetitionRequest userInput{};

  // Checking if the user is providing a valid number for the repetition.
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

void printRequestedRepetition(const RepetitionRequest &givenInput, bool printWithBar)
{
  const auto absoluteAmount = static_cast<unsigned int>(
    std::abs(givenInput.numberOfRepeat)
  );

  if (printWithBar)
  {
    const auto bar = std::string(30, '=');
    std::cout << bar << std::endl;
  }

  writeToBufferNTimes(
    std::cout,
    givenInput.toRepeat,
    absoluteAmount,
    false,
    10
  );
}

void handleCommandLineInput(int argc, char** argv)
{
  auto converted = processCommandLineArgs(argc, argv);
  printRequestedRepetition(converted, false);
}

RepetitionRequest processCommandLineArgs(int argc, char** argv)
{

  if (argc != 3)
  {
    endProgramForUserMistake("2 arguments are required");
  }

  std::vector<std::string> commandLineArgs{};
  commandLineArgs.assign(argv + 1, argv + argc);

  RepetitionRequest processedInput{};
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

