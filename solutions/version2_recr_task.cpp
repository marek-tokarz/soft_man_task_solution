#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <algorithm>

/*
Function checking whether a specific number is a prime number,
function is a classical prime number alghoritm checking
it checks if it can find a divider that gives a 0 as a reminder
*/
bool isPrime(int n)
{                   
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false; // checking whether a number is a even number, 
                                  //so in the next step it only will be checking odd numbers
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

/*
This is a function that solves a main task - creating an output 
sequence with given constraints
*/
std::vector<int> createResultVector(const std::vector<int>& A, const std::vector<int>& B)
{ 
    std::unordered_map<int, int> sequence; // unordered_map used for its time efficiency

    for (const int& num : B) { // iterating a sequence B
    auto it = sequence.find(num);
    if (it != sequence.end()) {
        it->second += 1; // a value is increased if a key already exists
    } else {
        sequence[num] = 1; // adding a new key with value 1 - it means an occcurence of this key is 1 - new key
    }
}
    
std::vector<int> C;

for (const int& key : A) { // iterating a sequence A
    auto it = sequence.find(key);
    if (it != sequence.end()) { // if a specific key already exists in a map 'sequence'
        int value = it->second;
        if (!isPrime(value)) {
            C.push_back(key); // then we add that key to the output vector if an occurence number is not a prime number
        }
    } else {
        C.push_back(key); // if a key was not found in sequence, then we safely can add this to output vector
    }
}

    return C; // function returns a vector C after all given constraints were checked
}

void validateResult(const std::vector<int>& A, const std::vector<int>& B, const std::vector<int>& actual, const std::vector<int>& expected)
{
    if (expected.size() != actual.size()) {
        std::cout << "Actual and expected differs in size." << std::endl;
        return;
    }
    for (auto& value : expected)
        if (std::find(actual.begin(), actual.end(), value) == actual.end()) {
            std::cout << "Expected value <" << value << "> is missing in sequence <";
            for (int num : actual) std::cout << num << " ";
            std::cout << ">" << std::endl;
            return;
        }
    std::cout << "Test successful." << std::endl;
}

int main() 
{
    std::cout << "\nTest cases below:" << std::endl;

    std::cout << "\n### Static test case ###" << std::endl;

    // Input data for A and B - Static test - example from a task description
    std::vector<int> A = {2, 3, 9, 2, 5, 1, 3, 7, 10}; // Sequence A
    std::vector<int> B = {2, 1, 3, 4, 3, 10, 6, 6, 1, 7, 10, 10, 10}; // Sequence B
    std::vector<int> expected = {2, 9, 2, 5, 7, 10}; // Sequence C

    std::vector<int> actual = createResultVector(A, B); // Call the function to create result sequence
    validateResult(A, B, actual, expected);

    // Test case 1
    std::cout << "\n### Test case 1 ###\nExpected result: difference in size\n";
    std::vector<int> A_1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> B_1 = {1, 1, 2, 3, 5, 5, 7, 7, 11, 13, 4, 6, 9, 8, 8, 2, 2, 3, 3, 3, 10, 10, 10, 10, 10, 14, 15, 16, 17, 18};
    std::vector<int> expected_1 = {1, 4, 6, 8, 9, 10};
    std::vector<int> actual_1 = createResultVector(A_1, B_1);
    validateResult(A_1, B_1, actual_1, expected_1);

    // Test case 2
    std::cout << "\n### Test case 2 ###\nExpected result: difference in size\n";
    std::vector<int> A_2 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    std::vector<int> B_2 = {10, 10, 20, 30, 50, 50, 70, 70, 110, 130, 40, 60, 90, 80, 80, 20, 20, 30, 30, 30, 100, 100, 100, 100, 100, 140, 150, 160, 170, 180};
    std::vector<int> expected_2 = {10, 40, 60, 80, 90, 100};
    std::vector<int> actual_2 = createResultVector(A_2, B_2);
    validateResult(A_2, B_2, actual_2, expected_2);

    // Test case 3
    std::cout << "\n### Test case 3 ###\nExpected result: difference in size\n";
    std::vector<int> A_3 = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    std::vector<int> B_3 = {5, 10, 15, 25, 35, 110, 130, 20, 30, 45, 40, 50, 140, 150, 160, 170, 180};
    std::vector<int> expected_3 = {5, 20, 30, 40, 45, 50};
    std::vector<int> actual_3 = createResultVector(A_3, B_3);
    validateResult(A_3, B_3, actual_3, expected_3);

    // Test case 4
    std::cout << "\n### Test case 4 ###\nExpected result: success\n";
    std::vector<int> A_4 = {3, 6, 9, 12, 15, 18, 21, 24, 27, 30};
    std::vector<int> B_4 = {3, 6, 9, 12, 15, 18, 21, 24, 27, 30};
    std::vector<int> expected_4 = {3, 6, 9, 12, 15, 18, 21, 24, 27, 30};
    std::vector<int> actual_4 = createResultVector(A_4, B_4);
    validateResult(A_4, B_4, actual_4, expected_4);

    // Test case 5
    std::cout << "\n### Test case 5 ###\nExpected result: difference in size\n";
    std::vector<int> A_5 = {7, 14, 21, 28, 35, 42, 49, 56, 63, 70};
    std::vector<int> B_5 = {14, 21, 28, 35, 49, 56, 63, 70};
    std::vector<int> expected_5 = {14, 21, 28, 35, 49, 56, 63, 70};
    std::vector<int> actual_5 = createResultVector(A_5, B_5);
    validateResult(A_5, B_5, actual_5, expected_5);

    // Test case 6
    std::cout << "\n### Test case 6 ###\nExpected result: difference in size\n";
    std::vector<int> A_6 = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    std::vector<int> B_6 = {4, 8, 12, 16, 20, 24, 28, 32, 36, 40};
    std::vector<int> expected_6 = {4, 8, 12, 16, 20};
    std::vector<int> actual_6 = createResultVector(A_6, B_6);
    validateResult(A_6, B_6, actual_6, expected_6);

    // Test case 7
    std::cout << "\n### Test case 7 ###\nExpected result: difference in size\n";
    std::vector<int> A_7 = {11, 22, 33, 44, 55, 66, 77, 88, 99, 110};
    std::vector<int> B_7 = {22, 33, 44, 55, 77, 88, 99};
    std::vector<int> expected_7 = {22, 33, 44, 55, 77, 88, 99};
    std::vector<int> actual_7 = createResultVector(A_7, B_7);
    validateResult(A_7, B_7, actual_7, expected_7);

    // Test case 8
    std::cout << "\n### Test case 8 ###\nExpected result: difference in size\n";
    std::vector<int> A_8 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    std::vector<int> B_8 = {20, 30, 40, 50, 60, 70, 80, 90};
    std::vector<int> expected_8 = {20, 30, 40, 50, 60, 70, 80, 90};
    std::vector<int> actual_8 = createResultVector(A_8, B_8);
    validateResult(A_8, B_8, actual_8, expected_8);

    // Test case 9
    std::cout << "\n### Test case 9 ###\nExpected result: success\n";
    std::vector<int> A_9 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    std::vector<int> B_9 = {10, 20, 30};
    std::vector<int> expected_9 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}; // Incorrect
    std::vector<int> actual_9 = createResultVector(A_9, B_9);
    validateResult(A_9, B_9, actual_9, expected_9);

    // Test case 10
    std::cout << "\n### Test case 10 ###\nExpected result: success\n";
    std::vector<int> A_10 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    std::vector<int> B_10 = {11, 21, 31, 41, 51, 61, 71, 81, 91, 101};
    std::vector<int> expected_10 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}; // Incorrect
    std::vector<int> actual_10 = createResultVector(A_10, B_10);
    validateResult(A_10, B_10, actual_10, expected_10);

    return 0;
}