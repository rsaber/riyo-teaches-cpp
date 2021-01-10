#include <iostream>
#include <vector>

// Do not change anything below this line
int main(int argc, char** argv)
{
	if(argc < 2){
		std::cout << "Not enough arguments provided" << std::endl;
		return 1;
	}

	if(argv[1][0] != '-')
	{
		std::cout << "Please specify if 7 point or 4 point" << std::endl;
		return 1;
	}

	bool is7Point = std::string(argv[1]) == "-7";

	auto wams = std::vector<int>{};

	for(int i=2; i< argc; ++i)
	{
		wams.push_back(atoi(argv[i]));
	}

	double gpa = calculateGpa(wams, is7Point);

	std::cout << gpa << std::endl;

	return 0;
}
