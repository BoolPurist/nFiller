
#include "ArgumentHandler.h"

/// Console app to repeat a given pattern in a given number of repetition.
/// Example: The user wants the pattern *&2 4 times.
/// This app the puts out  *&2*&2*&2*&2
/// This app either takes this request in command as in line arguments
/// Or it gets the needed arguments in interactive dialog with the user.
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







