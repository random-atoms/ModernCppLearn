// ModernCppLearn.cpp : Defines the entry point for the application.
//

#include "ModernCppLearn.h"
#include "Vector.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace NVector;

int main()
{
    const int size = 10;
    std::cout << "create v1,v2" << std::endl;
    Vector<int> v1(size);
    Vector<int> v2(size);
    for (auto ii = 0; ii < size; ++ii) {
        v1[ii] = ii;
        v2[ii] = 2 * ii;
    }
    std::cout << "create v3" << std::endl;
    Vector<int> v3;
    std::cout << "v3 = v1" << std::endl;
    v3 = v1;
    std::cout << "v4(v2)" << std::endl;
    Vector<int> v4{v2};

    std::cout << "v5 add" << std::endl;
    const Vector<int> v5 = v1 + v3 + v4;

    for (auto ii = 0; ii < size; ++ii) {
        std::cout << v1[ii] << "," << v3[ii] << "," << v4[ii] << "," << v5[ii] << std::endl;
    }
    for (auto &x : v1) {
        std::cout << ++x << std::endl;
    }
    std::cout << "test moves" << std::endl;
    // Create a vector object and add a few elements to it.
    std::vector<Vector<int> > v;
    v.push_back(Vector<int>(25000));
    v.push_back(Vector<int>(75000));

    // Insert a new element into the second position of the vector.
    v.insert(v.begin() + 1, Vector<int>(50));
	return 0;
}
