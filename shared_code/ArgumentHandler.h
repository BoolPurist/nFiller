//
// Created by nicegraphic on 3/9/22.
//

#ifndef NFILLER_SHARED_CODE_ARGUMENT_HANDLER_H_
#define NFILLER_SHARED_CODE_ARGUMENT_HANDLER_H_

#include <string>
#include <vector>
#include "help.h"
#include "RepetitionRequest.h"
#include "bufferController.h"

/// User made a mistake which makes fulfilling the given task
/// for this run impossible. User gets a message shown on the console.
/// This message indicates the mistake. The program terminates.
/// Note: One could instead let the user reenter the information.
/// This complicates things and is not a option for the command line approach neither.
void endProgramForUserMistake(const std::string &message);
/// Asks the user for the needed information in interactive dialog and
/// then prints out the result to the console.
void handleInteractiveUsage();
/// Logic run to if the argument were provided via command line instead of
/// the usage of the interactive mode.
void handleCommandLineInput(int argc, char** argv);


#endif //NFILLER_SHARED_CODE_ARGUMENT_HANDLER_H_
