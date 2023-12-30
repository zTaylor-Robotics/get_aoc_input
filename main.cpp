#include <iostream>
#include <string>

#include "version.h"

void printVersion(){
	printf("get_input v%d.%d.%d\n", MAJOR_VERSION, MINOR_VERSION, PATCH_VERSION);
}

int main(int argc, const char **argv){
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
	if((argc > 1) && strcmp(argv[1], "--version")){
		printVersion();
		return 1;
	}else if(argc <= 2){
		std::cerr << "Error: Day and Year needed" << std::endl;
		return 0;
	}else if(argc > 3){
		std::cerr << "Error: Too Many Arguments! Only <Day> and <Year> is needed!!!" << std::endl;
		return 0;
	}

	std::string day_num = argv[1];
	std::string year_num = argv[2];
	std::string geturl = "https://adventofcode.com/"+ year_num + "/day/" + day_num + "/input";
	std::string cookies = "session=53616c7465645f5ff784101bd41356d91d49ec9622b01e9b562a7614dcd35d3e8d211536f5bd7e693af62f414e591a98a65f75c597e4e1e78b2e96d728242e2a;";
	std::string curl_command = "curl " + geturl + " --cookie \"" + cookies + "\"" + " -o data.in";

	int result = system(curl_command.c_str());

	return result;
}