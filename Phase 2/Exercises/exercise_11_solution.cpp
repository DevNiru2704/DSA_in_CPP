#include <iostream>
#include <vector>
#include <array>
#include <memory>
#include <chrono>
#include <stdexcept>
using namespace std;
using namespace std::chrono;

// Exercise 11: STL vs Raw Pointers
// Solution: Comprehensive comparison of memory management approaches

// Raw pointer approach (error-prone)
class RawMatrix
{
private:
    int *data;
    int rows, cols;

public:
    RawMatrix(int r, int c) : rows(r), cols(c), data(nullptr)
    {
        if (r <= 0 || c <= 0)
        {
            throw invalid_argument("Invalid dimensions");
        }
        data = new int[r * c];
        // Initialize to zero
        for (int i = 0; i < r * c; i++)
        {
            data[i] = 0;
        }
    }

    // Copy constructor - easy to forget!
    RawMatrix(const RawMatrix &other) : rows(other.rows), cols(other.cols)
    {
        data = new int[rows * cols];
        for (int i = 0; i < rows * cols; i++)
        {
            data[i] = other.data[i];
        }
    }

    // Assignment operator - easy to forget!
    RawMatrix &operator=(const RawMatrix &other)
    {
        if (this != &other)
        {
            delete[] data; // Don't forget cleanup!
            rows = other.rows;
            cols = other.cols;
            data = new int[rows * cols];
            for (int i = 0; i < rows * cols; i++)
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    ~RawMatrix()
    {
        delete[] data;
    }

    int &at(int r, int c)
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
        {
            throw out_of_range("Matrix indices out of range");
        }
        return data[r * cols + c];
    }

    int at(int r, int c) const
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
        {
            throw out_of_range("Matrix indices out of range");
        }
        return data[r * cols + c];
    }

    void fill(int value)
    {
        for (int i = 0; i < rows * cols; i++)
        {
            data[i] = value;
        }
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }
};

// STL approach (safe and convenient)
class STLMatrix
{
private:
    vector<int> data;
    int rows, cols;

public:
    STLMatrix(int r, int c) : rows(r), cols(c), data(r * c, 0)
    {
        if (r <= 0 || c <= 0)
        {
            throw invalid_argument("Invalid dimensions");
        }
    }

    // Copy constructor - automatically handled by vector
    STLMatrix(const STLMatrix &other) = default;

    // Assignment operator - automatically handled by vector
    STLMatrix &operator=(const STLMatrix &other) = default;

    // Destructor - automatically handled by vector
    ~STLMatrix() = default;

    int &at(int r, int c)
    {
        return data.at(r * cols + c); // Bounds checking included
    }

    int at(int r, int c) const
    {
        return data.at(r * cols + c); // Bounds checking included
    }

    void fill(int value)
    {
        std::fill(data.begin(), data.end(), value);
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    // Additional STL benefits
    size_t size() const { return data.size(); }
    bool empty() const { return data.empty(); }
    auto begin() { return data.begin(); }
    auto end() { return data.end(); }
    auto begin() const { return data.begin(); }
    auto end() const { return data.end(); }
};

// Smart pointer approach (RAII)
class SmartMatrix
{
private:
    unique_ptr<int[]> data;
    int rows, cols;

public:
    SmartMatrix(int r, int c) : rows(r), cols(c)
    {
        if (r <= 0 || c <= 0)
        {
            throw invalid_argument("Invalid dimensions");
        }
        data = make_unique<int[]>(r * c);
        // Initialize to zero
        for (int i = 0; i < r * c; i++)
        {
            data[i] = 0;
        }
    }

    // No copy constructor/assignment - unique ownership
    SmartMatrix(const SmartMatrix &) = delete;
    SmartMatrix &operator=(const SmartMatrix &) = delete;

    // Move operations are allowed
    SmartMatrix(SmartMatrix &&) = default;
    SmartMatrix &operator=(SmartMatrix &&) = default;

    ~SmartMatrix() = default; // Automatic cleanup

    int &at(int r, int c)
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
        {
            throw out_of_range("Matrix indices out of range");
        }
        return data[r * cols + c];
    }

    int at(int r, int c) const
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
        {
            throw out_of_range("Matrix indices out of range");
        }
        return data[r * cols + c];
    }

    void fill(int value)
    {
        for (int i = 0; i < rows * cols; i++)
        {
            data[i] = value;
        }
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }
};

void demonstrateExceptionSafety()
{
    cout << "\n=== Exception Safety Comparison ===\n"
         << endl;

    cout << "Raw pointers - exception unsafe:" << endl;
    try
    {
        RawMatrix *raw = new RawMatrix(10, 10);
        raw->fill(42);
        // If an exception occurs here, raw is leaked!
        throw runtime_error("Simulated exception");
        delete raw; // Never reached
    }
    catch (const exception &e)
    {
        cout << "Exception caught: " << e.what() << endl;
        cout << "RawMatrix was leaked!" << endl;
    }

    cout << "\nSTL containers - exception safe:" << endl;
    try
    {
        STLMatrix stl(10, 10);
        stl.fill(42);
        // If an exception occurs here, stl is automatically cleaned up
        throw runtime_error("Simulated exception");
    }
    catch (const exception &e)
    {
        cout << "Exception caught: " << e.what() << endl;
        cout << "STLMatrix was automatically cleaned up" << endl;
    }

    cout << "\nSmart pointers - exception safe:" << endl;
    try
    {
        auto smart = make_unique<SmartMatrix>(10, 10);
        smart->fill(42);
        // If an exception occurs here, smart is automatically cleaned up
        throw runtime_error("Simulated exception");
    }
    catch (const exception &e)
    {
        cout << "Exception caught: " << e.what() << endl;
        cout << "SmartMatrix was automatically cleaned up" << endl;
    }
}

void performanceComparison()
{
    cout << "\n=== Performance Comparison ===\n"
         << endl;

    const int SIZE = 1000;
    const int ITERATIONS = 100;

    // Raw Matrix
    auto start = high_resolution_clock::now();
    for (int iter = 0; iter < ITERATIONS; iter++)
    {
        RawMatrix raw(SIZE, SIZE);
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                raw.at(i, j) = i + j;
            }
        }
    }
    auto rawTime = duration_cast<milliseconds>(high_resolution_clock::now() - start);

    // STL Matrix
    start = high_resolution_clock::now();
    for (int iter = 0; iter < ITERATIONS; iter++)
    {
        STLMatrix stl(SIZE, SIZE);
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                stl.at(i, j) = i + j;
            }
        }
    }
    auto stlTime = duration_cast<milliseconds>(high_resolution_clock::now() - start);

    // Smart Matrix
    start = high_resolution_clock::now();
    for (int iter = 0; iter < ITERATIONS; iter++)
    {
        SmartMatrix smart(SIZE, SIZE);
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                smart.at(i, j) = i + j;
            }
        }
    }
    auto smartTime = duration_cast<milliseconds>(high_resolution_clock::now() - start);

    cout << "Raw Matrix: " << rawTime.count() << " ms" << endl;
    cout << "STL Matrix: " << stlTime.count() << " ms" << endl;
    cout << "Smart Matrix: " << smartTime.count() << " ms" << endl;
    cout << "STL overhead: " << (double)stlTime.count() / rawTime.count() << "x" << endl;
    cout << "Smart pointer overhead: " << (double)smartTime.count() / rawTime.count() << "x" << endl;
}

int main()
{
    cout << "=== Exercise 11: STL vs Raw Pointers ===\n"
         << endl;

    // Demonstrate basic usage
    cout << "Creating matrices of size 3x4:" << endl;

    RawMatrix raw(3, 4);
    STLMatrix stl(3, 4);
    SmartMatrix smart(3, 4);

    // Fill with values
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int val = i * 4 + j;
            raw.at(i, j) = val;
            stl.at(i, j) = val;
            smart.at(i, j) = val;
        }
    }

    cout << "All matrices filled with values 0-11" << endl;

    // Demonstrate bounds checking
    cout << "\nBounds checking:" << endl;
    try
    {
        raw.at(10, 10) = 999; // Should throw
    }
    catch (const exception &e)
    {
        cout << "RawMatrix bounds check: " << e.what() << endl;
    }

    try
    {
        stl.at(10, 10) = 999; // Should throw
    }
    catch (const exception &e)
    {
        cout << "STLMatrix bounds check: " << e.what() << endl;
    }

    // Demonstrate STL features
    cout << "\nSTL-specific features:" << endl;
    cout << "STLMatrix size: " << stl.size() << endl;
    cout << "STLMatrix empty: " << (stl.empty() ? "yes" : "no") << endl;

    // Range-based for loop (STL only)
    cout << "STLMatrix contents using range-based for: ";
    for (int val : stl)
    {
        cout << val << " ";
    }
    cout << endl;

    // Exception safety
    demonstrateExceptionSafety();

    // Performance comparison
    performanceComparison();

    cout << "\n=== Final Verdict ===" << endl;
    cout << "Raw Pointers:" << endl;
    cout << "  ✓ Maximum performance" << endl;
    cout << "  ✓ Full control" << endl;
    cout << "  ✗ Error-prone (leaks, dangling pointers)" << endl;
    cout << "  ✗ No bounds checking" << endl;
    cout << "  ✗ Manual memory management" << endl;
    cout << endl;

    cout << "STL Containers:" << endl;
    cout << "  ✓ Memory safe (RAII)" << endl;
    cout << "  ✓ Bounds checking (in debug mode)" << endl;
    cout << "  ✓ Rich feature set" << endl;
    cout << "  ✓ Exception safe" << endl;
    cout << "  ✗ Slight performance overhead" << endl;
    cout << endl;

    cout << "Smart Pointers:" << endl;
    cout << "  ✓ Automatic memory management" << endl;
    cout << "  ✓ Exception safe" << endl;
    cout << "  ✓ Clear ownership semantics" << endl;
    cout << "  ✓ Good performance" << endl;
    cout << "  ✗ Cannot be copied (unique_ptr)" << endl;
    cout << endl;

    cout << "Recommendation: Use STL for most cases, raw pointers only when necessary!" << endl;

    return 0;
}