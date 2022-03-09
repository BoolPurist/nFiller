//
// Created by nicegraphic on 3/6/22.
//

#ifndef NFILER_SHARED_CODE_USERINPUT_H_
#define NFILER_SHARED_CODE_USERINPUT_H_

#include <string>
#include <iostream>

struct UserInput
{
  std::string toRepeat;
  int numberOfRepeat;
  UserInput(const std::string &to_repeat, int number_of_repeat);
  UserInput();
  std::string ReconstructSingleInput() const;
  friend std::ostream &operator<<(std::ostream &os, const UserInput &input);
};

#endif //NFILER_SHARED_CODE_USERINPUT_H_
