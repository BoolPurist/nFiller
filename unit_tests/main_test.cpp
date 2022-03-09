//
// Created by nicegraphic on 3/6/22.
//

#define BOOST_TEST_MODULE "Unit Test for N-Fill"

#include <boost/test/included/unit_test.hpp>

#include <iostream>
#include <bufferController.h>
#include <UserInput.h>

void testForCreateFromInput(const UserInput &expectedUserInput);

BOOST_AUTO_TEST_SUITE( test_printNTimes )

BOOST_AUTO_TEST_CASE( test_with_new_line )
{
  // Set up
  const std::string expectedOutput = "abab\nab\n";
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
  const std::string expectedOutput = "********************\n";
  const std::string actualPattern = "*";
  const int actualRepetition = 20;

  std::ostringstream os{};
  printNthTimes(os, actualPattern, actualRepetition, false);

  BOOST_CHECK_EQUAL(os.str(), expectedOutput);
}


BOOST_AUTO_TEST_CASE( test_noNewLine_several_flushes )
{
  // Set up
  const std::string expectedOutput = "********************\n";
  const std::string actualPattern = "*";
  const int actualRepetition = 20;
  const int actualMaxBufferSize = 10;

  std::ostringstream os{};
  printNthTimes(
      os,
      actualPattern,
      actualRepetition,
      false,
      actualMaxBufferSize
    );

  BOOST_CHECK_EQUAL(os.str(), expectedOutput);
}

BOOST_AUTO_TEST_CASE( test_with_empty_pattern)
{
  // Set up
  const std::string expectedOutput{"\n"};
  const std::string actualPattern{};
  const int actualRepetition = 20;

  // Act
  std::ostringstream os{};
  printNthTimes(os, actualPattern, actualRepetition, false);

  // Assert
  BOOST_CHECK(os.str() == expectedOutput);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( test_askUserForRepetition )

BOOST_AUTO_TEST_CASE( test_with_valid_input)
{
  // Set up
  const int actualRepetition = 5;
  const std::string actualPattern = "/";

  const UserInput expectedUserInput{actualPattern, actualRepetition};

  // Act & Assert
  testForCreateFromInput(expectedUserInput);
}

BOOST_AUTO_TEST_CASE( test_with_no_repetition)
{
  // Set up
  const int actualRepetition = 0;
  const std::string actualPattern = "/";

  const UserInput expectedUserInput{actualPattern, actualRepetition};

  // Assert
  testForCreateFromInput(expectedUserInput);
}

BOOST_AUTO_TEST_CASE( test_if_invalid_argument_thrown )
{
  // Set up
  const std::string pattern{"a\n"};
  const std::string invalidNumber{"ab4a"};

  std::ostringstream os{};
  std::istringstream is{pattern + invalidNumber};
  // Act & Assert
  BOOST_CHECK_THROW(askUserForRepetition(is, os), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE( test_if_out_of_range_thrown )
{
  // Set up
  const std::string pattern{"a\n"};
  const std::string invalidNumber{
    "222222222222222222222222222222222222222222222222222222222222222222222222"
  };

  std::ostringstream os{};
  std::istringstream is{pattern + invalidNumber};

  // Act & Assert
  BOOST_CHECK_THROW(askUserForRepetition(is, os), std::out_of_range);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( test_UserInput )

BOOST_AUTO_TEST_CASE(test_ouputstream_operater)
{
  const UserInput actualUserInput{"yu", 2};
  const std::string expectedOutput{"toRepeat: yu numberOfRepeat: 2"};

  std::ostringstream actualOutput{};
  actualOutput << actualUserInput;

  BOOST_CHECK_EQUAL(expectedOutput, actualOutput.str());
}

BOOST_AUTO_TEST_SUITE_END()


void testForCreateFromInput(const UserInput &expectedUserInput)
{
  // Act
  std::ostringstream os{};
  std::istringstream is{expectedUserInput.ReconstructSingleInput()};

  auto actualUserInput = askUserForRepetition(is, os);
  // Assert
  BOOST_CHECK_EQUAL(expectedUserInput.toRepeat, actualUserInput.toRepeat);
  BOOST_CHECK_EQUAL(expectedUserInput.numberOfRepeat,actualUserInput.numberOfRepeat);
}

