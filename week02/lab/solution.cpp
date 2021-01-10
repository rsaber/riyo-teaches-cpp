#include <iostream>
#include <vector>

enum class Grade_t
{
	HD,
	D,
	CR,
	P,
	F
};

struct CountWams
{
	int m_upperRange;
	int m_lowerRange;
	CountWams(Grade_t grade)
	{
		switch(grade)
		{
			case HD:
			{
				m_upperRange = 100;
				m_lowerRange = 85;
				break;
			}
			case D:
			{
				m_upperRange = 84;
				m_lowerRange = 75;
				break;
			}
			case CR:
			{
				m_upperRange = 74;
				m_lowerRange = 65;
				break;
			}
			case P:
			{
				m_upperRange = 64;
				m_lowerRange = 50;
				break;
			}
			case F:
			{
				m_upperRange = 49;
				m_lowerRange = 0;
				break;
			}
		}
	}

	bool operator()(int wam)
	{
		return m_lowerRange <= wam && wam <= m_upperRange;
	}
};

double calculateGpa(const std::vector<int>& wams, bool is7Point)
{
	std::unordered_map gradeCounts;

	gradeCounts["HD"] = std::count_if(wams.begin(), wams.end(), CountWams(Grade_t::HD));
	gradeCounts["D"] = std::count_if(wams.begin(), wams.end(), CountWams(Grade_t::D));
	gradeCounts["CR"] = std::count_if(wams.begin(), wams.end(), CountWams(Grade_t::CR));
	gradeCounts["P"] = std::count_if(wams.begin(), wams.end(), CountWams(Grade_t::P));
	gradeCounts["F"] = std::count_if(wams.begin(), wams.end(), CountWams(Grade_t::F));

	double weightedSum = is7Point ? 
		(7*gradeCounts["HD"] + 6*gradeCounts["D"] + 5*gradeCounts["C"] + 4*gradeCounts["P"]) :
		(4*(gradeCounts["HD"] + gradeCounts["D"]) + 3*gradeCounts["C"] + 2*gradeCounts["P"]);

	return weightedSum / wams.size();
}

// ------------------

double calculateGpa(const std::vector<int>& wams, bool is7Point)
{
	int hdCount = 0;
	int dCount = 0;
	int cCount = 0;
	int pCount = 0;
	int fCount = 0;

	for(auto it : wams)
	{
		int wam = it;
		if (85 <= wam && wam <= 100)
		       hdCount++;
		else if(75 <= wam && wam < 85)
			dCount++;
		else if(65 <= wam && wam < 75)
			cCount++;
		else if(50 <= wam && wam < 65)
			pCount++;
		else if (wam < 50) 
			fCount++;
	}

	std::cout << "HD: " << hdCount << std::endl;
	std::cout << "D : " << dCount << std::endl;
	std::cout << "CR: " << cCount << std::endl;
	std::cout << "P : " << pCount << std::endl;
	std::cout << "F : " << fCount << std::endl;

	if(is7Point)
	{
		double weighted = 7*hdCount + 6*dCount + 5*cCount + 4*pCount;
		return (double) weighted / wams.size();
	}
	else {
		double weighted = 4*(hdCount + dCount) + 3*cCount + 2*pCount;
		return (double) weighted / wams.size();
	}
}

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

	std::cout << (is7Point ? "7-Point" : "4-Point") << " Estimated GPA: " <<  gpa << std::endl;

	return 0;
}
