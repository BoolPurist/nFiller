//
// Created by nicegraphic on 3/6/22.
//

#include "bufferController.h"
#include "UserInput.h"

void flushBuffer(std::ostream& toFlush, bool flushWithNewLine);

void printNthTimes(std::ostream &output,
	const std::string &toRepeat,
	unsigned int timesToRepeat,
	bool withNLine,
	unsigned int maxBufferSize
  )
{
  const auto sizeOfOneRepeat = toRepeat.size();
  size_t bufferCount = 0;

  for (size_t i_printTimes{0}; i_printTimes < timesToRepeat; i_printTimes++)
  {
	size_t newBufferSize = bufferCount + sizeOfOneRepeat;
	if (newBufferSize < maxBufferSize)
	{
	  // Write to buffer
	  output << toRepeat;
	  bufferCount = newBufferSize;
	}
	else
	{
	  flushBuffer(output, withNLine);
	  // Write to buffer
	  output << toRepeat;
	  bufferCount = sizeOfOneRepeat;
	}
  }

  output.flush();
}

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

void flushBuffer(std::ostream& toFlush, bool flushWithNewLine)
{
  // Flush buffer to not go over the max buffer size.
  if (flushWithNewLine)
  {
	toFlush << std::endl;
  }
  else
  {
	toFlush.flush();
  }
}
