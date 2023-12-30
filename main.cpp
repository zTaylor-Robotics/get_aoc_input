#include <iostream>
#include <string>
#include <version.h>

void print_version(){
	printf("get_input version: %d.%d.%d\n", PROJECT_VERSION_MAJOR, PROJECT_VERSION_MINOR, PROJECT_VERSION_PATCH);
	printf("Author: SH3P-Productions\n");
	printf("Details: $get_input <day> <year> will store the Advent of Code\nprompt for the given day of the given year in a data.in file\n");
	return;
}

int main(int argc, const char **argv){
	if(!strcmp(argv[1], "--version") || !strcmp(argv[1], "-v")){
		print_version();
		return 1;
	}
	if(argc <= 2){
		std::cerr << "Error: <Day> and <Year> needed" << std::endl;
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