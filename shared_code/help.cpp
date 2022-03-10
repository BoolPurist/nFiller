//
// Created by nicegraphic on 3/10/22.
//

#include "help.h"

void provideUserWithHelpIfWanted(std::string &possibleHelpFlag)
{
  if (
      possibleHelpFlag == "-h" ||
      possibleHelpFlag == "--help" ||
      possibleHelpFlag == "help"
    )
  {
    printHelpToUser();
    exit(0);
  }
}

void printHelpToUser()
{
  const std::string helpMessage = R"(
  NAME: nFiller

  SUMMARY:
  Program to print a given pattern with a number for repetition

  SYNOPSIS:
  (1) nfiller <pattern to repeat> <number of repetition>
  (2) nfiller (-h|--help|help)

  Note: if no argument is given then the interactive mode is entered.
  In this mode the user is asked to enter the 2 arguments.

  (1) Prints out the repetition of the pattern according to the given
  in line arguments
  (2) Prints out help

  Example for (1)
  nfiller '*' 5
  output is *****
)";

  std::cout << helpMessage << std::endl;
}
