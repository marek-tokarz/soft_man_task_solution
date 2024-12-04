#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>

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
std::vector<int> createResultVector(const std::vector<int>& A, const std::vector<int>& B, std::unordered_map<int, int>* rejected)
{ 
    std::unordered_map<int, int> sequence; // unordered_map used for its time efficiency

    int i = B.size();
    
    for(int j = 0; j < i; j++)      // this loop creates a pairs in a unordered_map, key - a number from vector B and 
                                    // value - how many times this number is in vector
    {
        auto it = sequence.find(B[j]); // iterator to easily search for element and return a result of search

        if (it != sequence.end()) // if element was found (return of find() was not end())
        {
            it->second = it->second + 1; // then add 1 to the value for that key
        }
        else{
            sequence[B[j]]= 1; // if iterator was not found then create a new pair of key and value
        }
    }

    std::vector<int> C;

    int k = A.size();

    for (int l = 0; l<k; l++) // this loop checks whether an element from A is present in B
    {
        int key = A[l];

        auto it = sequence.find(key);

        if (it != sequence.end()) // now instead of B we use unordered map, if an element (key) was found in map
        {
            int value = it->second;

            if(!isPrime(value)) // so then we check whether a value for that key in map is a prime number
            {
                C.push_back(key); // if not, then add an element to the output sequence B
            }
                else
                {
                    // if a condition for rejection was passed
                    if (rejected) {
                        (*rejected)[key] = value;  // then this key and value are added to the map: 'rejected'
                    }
                }
            
        }
        else // if an element was not found (is not a key in a map)
        {
            C.push_back(key); // then we safely can add it to the output sequence C
        }
    }

    return C; // functions returns a sequence C after all given constraints were checked
}

// Prime numbers from natural numbers from 1 to 50 - just for reference for test cases
void printPrimeNumbers() 
{
    std::cout << "Prime numbers from 1 to 50: ";
    for (int i = 1; i <= 50; i++) {
        if (isPrime(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

// Function that generates random tests - two randomly created vectors
void generateRandomTest(std::vector<int>& A, std::vector<int>& B) 
{
    A.clear();
    B.clear();

    // 50 numbers for vector A
    for (int i = 0; i < 10; i++) {
        A.push_back(rand() % 50 + 1);
    }

    // 50 numbers for vector B
    for (int i = 0; i < 50; i++) {
        B.push_back(rand() % 10 + 1);
    }
}

// Printing test results
void displayTestResults(const std::vector<int>& A, const std::vector<int>& B, const std::vector<int>& C, const std::unordered_map<int, int>& rejected) 
{
    std::cout << "\n  Input sequence A: ";
    for (int num : A) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "\n  Input sequence B: ";
    for (int num : B) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Printing Output
    std::cout << "\n  Output sequence C: ";
    for (int num : C) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Printing rejected numbers and their occurence in sequence B
    std::cout << "\n'Rejected numbers': (prime counts)" << std::endl;
    for (const auto& pair : rejected) {
        std::cout << "Rej: '" << pair.first << "': (" << pair.second << ")" << std::endl;
    }
}

int main() 
{
    srand(time(0)); // Random numbers generator initalization

    std::cout << "\nTest cases below:" << std::endl;

    std::cout << "\n### Static test case" << std::endl;

    // Hardcoded input data for A and B - Static test - example froma a task description
    std::vector<int> A = {2, 3, 9, 2, 5, 1, 3, 7, 10}; // Sequence A
    std::vector<int> B = {2, 1, 3, 4, 3, 10, 6, 6, 1, 7, 10, 10, 10}; // Sequence B

    std::unordered_map<int, int> rejected; // Map to store rejected numbers and their counts

    std::vector<int> output_C = createResultVector(A, B, &rejected); // Call the function to create result sequence

    displayTestResults(A, B, output_C, rejected); // Static test case results

    // 5 test cases that are randomly generated
    for (int test = 1; test <= 5; test++) {
        std::cout << "\n### Random test case " << test << ":" << std::endl;
        std::vector<int> A, B;
        generateRandomTest(A, B);

        std::vector<int> output_C = createResultVector(A, B, &rejected);

        displayTestResults(A, B, output_C, rejected);
    }

    return 0;
}