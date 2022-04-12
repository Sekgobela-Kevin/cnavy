#include "enable_crawler_test.hpp"
#include "enable_rsm_test.hpp"
#include "enable_tools_test.hpp"
#include "enable_xtess_test.hpp"


/**
 * This file contains declaraction for Enable_Doctest().
 * This function calls other functions in other source files.
 * The function bodies are left empty.
 * But this enables doctest to register tests.
 * 
 * Enable_Doctest() is called by main test file(one with main() implementation)
 * This results in other functions in test files located libraries to be called.
 * Which registers tests in linked libraries to be registered to main test file.
 * 
 * Using doctest_force_link_static_lib_in_target.cmake script can help but has errors when executed.
 * Author of Doctest is aware of it and recommends that script which to me failed to execute.
 * The solution was result experimenting and surfing the web especially link at below.
 * 
 * see here: https://github.com/pthom/DocTest_LibTest/
 *   commit/e6373522cecdb170388e7d4c5c93b16e645089cc
 * also here: https://github.com/doctest/doctest/blob/master/doc/markdown/faq.md
 */

/**
 * @brief Calls other functions in different test files.
 * Called by main test file(one implementing main).
 * This causes functions in test files to be called which registers test.
 * If tests files are in libraries and are linked to main test file.
 * Only tests in main test file get executed but other in libraries are ignored.
 * This is just trick for registering the tests which Doctest is failing to do.
 * 
 */
void Enable_Doctest();
