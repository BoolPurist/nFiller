//
// Created by nicegraphic on 3/6/22.
//

#ifndef NFILLER_BUFFER_CONTROLLER_HEADER_
#define NFILLER_BUFFER_CONTROLLER_HEADER_

#include <iostream>
#include <UserInput.h>

void writeToBufferNTimes(
  std::ostream &output,
  const std::string &toRepeat,
  unsigned int timesToRepeat,
  bool withNLine = true,
  unsigned int maxBufferSize = 1000
);

UserInput askUserForRepetition(std::istream &input, std::ostream &userPrompt);

#endif //NFILLER_BUFFER_CONTROLLER_HEADER_
