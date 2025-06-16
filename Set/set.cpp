#include "set.h"

int main() {
    Set<int> A({1, 2, 3, 4});
    Set<int> B({3, 4, 5, 6});

    std::cout << "Set A: ";
    A.Print();
    std::cout << "Set B: ";
    B.Print();

    Set<int> unionSet = A.Union(B);
    std::cout << "Union: ";
    unionSet.Print();

    Set<int> intersectionSet = A.Intersection(B);
    std::cout << "Intersection: ";
    intersectionSet.Print();

    Set<int> diffSet = A.Difference(B);
    std::cout << "Difference A - B: ";
    diffSet.Print();

    Set<int> symDiffSet = A.SymmetricDifference(B);
    std::cout << "Symmetric Difference: ";
    symDiffSet.Print();

    return 0;
}

