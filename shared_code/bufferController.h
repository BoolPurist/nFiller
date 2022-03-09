//
// Created by nicegraphic on 3/6/22.
//

#ifndef NFILER__BUFFERCONTROLLER_H_
#define NFILER__BUFFERCONTROLLER_H_

#include <iostream>
#include <UserInput.h>

void printNthTimes(std::ostream &output,
   const std::string &toRepeat,
   unsigned int timesToRepeat,
   bool withNLine = true,
   unsigned int maxBufferSize = 1000
);

UserInput askUserForRepetition(std::istream &input, std::ostream &userPrompt);

#endif //NFILER__BUFFERCONTROLLER_H_
