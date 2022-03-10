
#include "ArgumentHandler.h"


int main(int argc, char** argv) {

  // if true only the program name is given
  // and none are given as in lime arguments.
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







