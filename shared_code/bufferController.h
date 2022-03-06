//
// Created by nicegraphic on 3/6/22.
//

#ifndef NFILER__BUFFERCONTROLLER_H_
#define NFILER__BUFFERCONTROLLER_H_

#include <iostream>

#define MAX_ALLOWED_BUFFER_SIZE 1000

void printNthTimes(std::ostream &output,
  const std::string &toRepeat,
  size_t timesToRepeat,
  bool withNLine = true,
  size_t maxBufferSize = MAX_ALLOWED_BUFFER_SIZE
);

#endif //NFILER__BUFFERCONTROLLER_H_
