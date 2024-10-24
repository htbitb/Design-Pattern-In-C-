#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <variant>

using namespace std;

using ReturnType = variant<int, bool>;

struct IOperation {
    virtual ReturnType ResultOf(int *begin, int *end) = 0;
    virtual ~IOperation() = default;
};

class Operation : public IOperation {
public:
    ReturnType ResultOf(int *begin, int *end) override {
        // Example implementation: Sum all values in the range
        int sum = 0;
        while (begin != end) {
            sum += *begin;
            ++begin;
        }
        return sum;  // Returning sum as an int
    }
};

class BoolOperation : public IOperation {
public:
    ReturnType ResultOf(int *begin, int *end) override {
        // Example implementation: Check if all values are positive
        while (begin != end) {
            if (*begin <= 0) return false;  // Return false if any value is non-positive
            ++begin;
        }
        return true;  // All values are positive, return true
    }
};

void Operate(IOperation *func) {
    int arr[5] = {1, 2, 3, 4, 5};  // Initialized array
    auto result = func->ResultOf(arr, arr + 5);

    // Print the result based on the type held in variant
    if (holds_alternative<int>(result)) {
        cout << "Result is an int: " << get<int>(result) << endl;
    } else if (holds_alternative<bool>(result)) {
        cout << "Result is a bool: " << (get<bool>(result) ? "true" : "false") << endl;
    }
}

int main() {
    Operation op;
    BoolOperation boolOp;

    Operate(&op);       // Output: Result is an int: 15
    Operate(&boolOp);   // Output: Result is a bool: true

    return 0;
}