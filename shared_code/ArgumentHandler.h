//
// Created by nicegraphic on 3/9/22.
//

#ifndef NFILER_SHARED_CODE_ARGUMENTHANDLER_H_
#define NFILER_SHARED_CODE_ARGUMENTHANDLER_H_

#include "UserInput.h"
#include "bufferController.h"
#include <string>
#include <vector>

void endProgramForUserMistake(const std::string &message);
void handleInteractiveUsage();
void handleCommandLineInput(int argc, char** argv);


#endif //NFILER_SHARED_CODE_ARGUMENTHANDLER_H_
