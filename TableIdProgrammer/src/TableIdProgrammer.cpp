//============================================================================
// Name        : TableIdProgrammer.cpp
// Author      : Harald
//============================================================================

#include <iostream>
#include <boost/program_options.hpp>
#include <iostream>

#include "ReadFile.h"
#include "IdTableParser.h"
#include <Framework/ProgramOptions.h>

using namespace boost::program_options;
using namespace std;

/**
 * For compiling, you need to define: -DBOOST_TEST_ALTERNATIVE_INIT_API
 */

ProgramOptions progOptions;

int main(int argc, char *argv[]) {
	if (FAIL == progOptions.init(argc, argv)) {
		return FAIL;
	}
	po::variables_map varMap = progOptions.getVarMap();

	if (varMap.count("progid")) {
		std::cout << "Programming Id-file to device.\n";
		ReadFile readFile(varMap["idTableFile"].as<string>());
		IdTableParser idTableParser(readFile.getContent());
		// sendData
	} else if (varMap.count("readid")) {
		std::cout << "readid\n";
	}

	return 0;
}
