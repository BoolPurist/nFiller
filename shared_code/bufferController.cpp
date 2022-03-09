//
// Created by nicegraphic on 3/6/22.
//

#include "bufferController.h"
#include "UserInput.h"

void printNthTimes(
  std::ostream &output,
	const std::string &toRepeat,
	unsigned int timesToRepeat,
	bool withNLine,
	unsigned int maxBufferSize
  )
{
  const auto sizeOfOneRepeat = toRepeat.size();
  maxBufferSize = static_cast<size_t>(maxBufferSize);
  size_t bufferCount = 0;

  auto writeToBuffer = [&output, &toRepeat, &bufferCount]
    (size_t newBufferSize) -> void
    {
      output << toRepeat;
      bufferCount = newBufferSize;
    };

  for (size_t i_printTimes{0}; i_printTimes < timesToRepeat; i_printTimes++)
  {
    size_t newBufferSize = bufferCount + sizeOfOneRepeat;

    if (newBufferSize < maxBufferSize)
    {
      writeToBuffer(newBufferSize);
    }
    else
    {
      // Flushing stream buffer to prevent going over max buffer size.
      if (withNLine)
      {
        output << std::endl;
      }
      else
      {
        output.flush();
      }

      writeToBuffer(sizeOfOneRepeat);
    }
  }

  output << std::endl;
}

UserInput askUserForRepetition(std::istream& input, std::ostream& userPrompt)
{
  UserInput providedInput{};

  userPrompt << "Enter pattern to be repeated" << std::endl;
  std::getline(input, providedInput.toRepeat);

  userPrompt << "Enter number of repetition" << std::endl;
  std::string enteredForNumber{};
  input >> enteredForNumber;

  int converted{};
  try
  {
    converted = std::stoi(enteredForNumber);
  }
  catch (const std::invalid_argument &error)
  {
    // no valid number was entered like "aaa44"
    throw;
  }
  catch (const std::out_of_range &error)
  {
    // entered number has too big amount for an integer
    throw;
  }

  providedInput.numberOfRepeat = converted;
  return providedInput;
}
