#include <iostream>
#include <vector>

double calculateGPA(std::vector<int> wams)
{
    int hds = 0;
    int ds = 0;
    int crs = 0;
    int ps = 0;
    int fails = 0;

    for(auto it : wams)
    {
        if(85 <= it && it <= 100)
        {
            hds++;
        }
        else if(75 <= it && it <= 84)
        {
            ds++;
        }
        else if(65 <= it && it <= 74)
        {
            crs++;
        }
        else if(50 <= it && it <= 64)
        {
            ps++;
        }
        else
        {
            fails++;
        }
    }

    double gpa = (double) (4 * (hds + ds) + 3*(crs) + 2*(ps)) / wams.size();

    return gpa;
}

int main()
{
    std::vector<int> wams = {};

    for(int i=0; i<10; ++i)
    {
        int b;
        std::cin >> b;
        wams.push_back(b);
    }

    for(
        std::vector<int>::iterator it = wams.begin();
        it != wams.end();
        ++it
    )
    {
        std::cout << "Value at index: " << it - wams.begin() << " is: " << *it << std::endl;
    }

    double gpa = calculateGPA(wams);

    std::cout << "The gpa is: " << gpa << std::endl;

    return 0; 
}