//
// Created by nicegraphic on 3/6/22.
//

#include "bufferController.h"

void writeToBufferNTimes(
  std::ostream &output,
	const std::string &toRepeat,
	unsigned int timesToRepeat,
	bool newLineOnFlush,
	unsigned int maxBufferSize
  )
{
  const auto sizeOfOneRepeat = toRepeat.size();
  maxBufferSize = static_cast<size_t>(maxBufferSize);
  size_t charsWrittenLastFlush = 0;

  // Also updates count of chars written to buffer since the last flush.
  auto writeToBuffer = [&output, &toRepeat, &charsWrittenLastFlush]
    (size_t newBufferSize) -> void
    {
      output << toRepeat;
      charsWrittenLastFlush = newBufferSize;
    };

  for (size_t i_repetition{0}; i_repetition < timesToRepeat; i_repetition++)
  {
    size_t newBufferSize = charsWrittenLastFlush + sizeOfOneRepeat;

    if (newBufferSize < maxBufferSize)
    {
      writeToBuffer(newBufferSize);
    }
    else
    {
      // Flushing stream buffer to prevent going over max buffer size.
      if (newLineOnFlush)
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

RepetitionRequest askUserForRepetition(std::istream& input, std::ostream& userPrompt)
{
  RepetitionRequest providedInput{};

  userPrompt << "Enter pattern to be repeated" << std::endl;
  std::getline(input, providedInput.toRepeat);

  userPrompt << "Enter number of repetition" << std::endl;
  std::string enteredForNumber{};
  input >> enteredForNumber;

  // Validate the 2. string if it is actual a number and if it not too big.
  int converted;
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
