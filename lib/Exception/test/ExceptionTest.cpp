#include "../Exception.hpp"
#include <string>

const string exceptionToTest = "FileNotFoundException";

int main() {
  try {
    if (exceptionToTest == "InvalidCommandException") {
      throw new InvalidCommandException("EXCEPTION_TEST");
    }
    if (exceptionToTest == "FileNotFoundException") {
      throw new FileNotFoundException("EXCEPTION_TEST");
    }
    cout << "Test ran without finding any exceptions!" << endl;
  } catch (BaseException* e) {
    e->what();
  }
  return 0;
}