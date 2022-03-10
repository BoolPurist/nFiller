//
// Created by nicegraphic on 3/6/22.
//

#ifndef NFILLER_SHARED_CODE_USER_INPUT_H_
#define NFILLER_SHARED_CODE_USER_INPUT_H_

#include <string>
#include <iostream>

/// Represents a request for printing the repetition of a pattern
struct UserInput
{
  std::string toRepeat{};
  int numberOfRepeat{};
  UserInput(const std::string &to_repeat, int number_of_repeat);
  UserInput();
  /// Returns the original given information in interactive session with the user.
  /// Used for unit testing
  std::string ReconstructSingleInput() const;
  friend std::ostream &operator<<(std::ostream &os, const UserInput &input);
};

#endif //NFILLER_SHARED_CODE_USER_INPUT_H_
