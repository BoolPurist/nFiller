//
// Created by nicegraphic on 3/6/22.
//

#ifndef NFILLER_BUFFER_CONTROLLER_HEADER_
#define NFILLER_BUFFER_CONTROLLER_HEADER_

#include <iostream>
#include <RepetitionRequest.h>

/// Writes the result of the requested repetition of a pattern to the given buffer
/// It flushes the buffer whenever the max buffer size would be exceeded
/// with the next repetition.
/// Reason: User could request a big number of repetition. Without flushing
/// to console for example, the program could go out of memory
/// or disk could be bloated with data.
void writeToBufferNTimes(
  std::ostream &output,
  const std::string &toRepeat,
  unsigned int timesToRepeat,
  bool newLineOnFlush = true,
  unsigned int maxBufferSize = 1000
);

/// Creates a console dialog with the user to get needed information.
/// it validates entered information and returns it as an object.
/// Note: It throws invalid_argument if the given string is not a number like "ab"
/// Note: It throws out_of_range if the given string as number is too big for
/// integer value like "2222222222222222222222222222222222222222222"
RepetitionRequest askUserForRepetition(std::istream &input, std::ostream &userPrompt);

#endif //NFILLER_BUFFER_CONTROLLER_HEADER_
