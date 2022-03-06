//
// Created by nicegraphic on 3/6/22.
//

#define BOOST_TEST_MODULE "Unit Test for N-Fill"

#include <boost/test/included/unit_test.hpp>

#include <bufferController.h>
#include <UserInput.h>

BOOST_AUTO_TEST_SUITE( test_printNTimes )

BOOST_AUTO_TEST_CASE( test_with_new_line )
{
  // Set up
  const std::string expectedOutput = "abab\nab";
  const std::string actualPattern = "ab";
  const int actualMaxBufferSize = 5;
  const int actualRepetition = 3;

  std::ostringstream os{};
  printNthTimes(os, actualPattern, actualRepetition, true, actualMaxBufferSize);

  BOOST_CHECK_EQUAL(os.str(), expectedOutput);
}

BOOST_AUTO_TEST_CASE( test_noNewLine )
{
  // Set up
  const std::string expectedOutput = "********************";
  const std::string actualPattern = "*";
  const int actualRepetition = 20;

  std::ostringstream os{};
  printNthTimes(os, actualPattern, 20, false);

  BOOST_CHECK_EQUAL(os.str(), expectedOutput);
}

BOOST_AUTO_TEST_CASE( test_with_empty_pattern)
{
  // Set up
  const std::string expectedOutput;
  const std::string actualPattern;
  const int actualRepetition = 20;

  // Act
  std::ostringstream os{};
  printNthTimes(os, actualPattern, actualRepetition, false);

  // Assert
  BOOST_CHECK(os.str().empty());
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( test_createFromInput )

BOOST_AUTO_TEST_CASE( test_with_valid_input)
{
  // Set up
  const int actualRepetition = 5;
  const std::string actualPattern = "/";

  const UserInput expectedUserInput{actualPattern, actualRepetition};

  // Act
  std::ostringstream os{};
  std::istringstream is{"/\n5"};

  auto actualUserInput = CreateFromInput(is, os);

  // Assert
  BOOST_CHECK_EQUAL(expectedUserInput.toRepeat, actualUserInput.toRepeat);
  BOOST_CHECK_EQUAL(expectedUserInput.numberOfRepeat,actualUserInput.numberOfRepeat);
}

BOOST_AUTO_TEST_SUITE_END()
