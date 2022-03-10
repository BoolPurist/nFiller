//
// Created by nicegraphic on 3/9/22.
//

#ifndef NFILLER_SHARED_CODE_ARGUMENT_HANDLER_H_
#define NFILLER_SHARED_CODE_ARGUMENT_HANDLER_H_

#include "UserInput.h"
#include "bufferController.h"
#include <string>
#include <vector>

void endProgramForUserMistake(const std::string &message);
void handleInteractiveUsage();
void handleCommandLineInput(int argc, char** argv);


#endif //NFILLER_SHARED_CODE_ARGUMENT_HANDLER_H_
