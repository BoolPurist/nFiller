#include <iostream>
#include <string>
#include <sstream>
#include <bufferController.h>
#include <vector>

#include "ArgumentHandler.h"


int main(int argc, char** argv) {

  bool isUsedInteractive{argc < 2};

  if (isUsedInteractive)
  {
    handleInteractiveUsage();
  }
  else
  {
    handleCommandLineInput(argc, argv);
  }

  return 0;
}







