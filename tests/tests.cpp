#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
// enables testing for linked lib
// just run Enable_Doctest() in doctes main()
#include "enable_doctest.hpp"

int main(int argc, char** argv) {
    doctest::Context context(argc, argv);

    int res = context.run();
    if(context.shouldExit()) return res;

    Enable_Doctest();
    return res;
}