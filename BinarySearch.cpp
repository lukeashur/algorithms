#include <iostream>

using namespace std;

class Vector
{
private:
    int dimension;
    int *data;

public:
    Vector(int dim)
    {
        dimension = dim;
        data = new int[dimension];
    }

    virtual ~Vector() // Destructor
    {
        delete[] data;
    }

    void set(int i, int val)
    {
        if (i >= 0 && i < dimension)
            data[i] = val;
    }

    int get(int i)
    {
        if (i >= 0 && i < dimension)
            return data[i];
        return -1; // Error
    }


    int bin_search(int sv) // Requires data to be sorted in ascending order
    {
        int low = 0, high = dimension - 1;

        while (low <= high)
        {
            int middle = (low + high) / 2;
            int value = data[middle];

            if (value == sv)
                return middle; // Element found, return index
            else if (value < sv)
                low = middle + 1; // Move to/search lower bound
            else
                high = middle - 1; // Move to/search upper bound
        }

        return -1; // Element not found
    }
};

int main()
{
    Vector v(20); // Create vector object with dimension 20

    for (int i = 0; i < 20; i++) // Populate vector with sorted data
    {
        v.set(i, i * 2); // Set values: 0, 2, 4, 6, 8, 10...
    }

    cout << "Vector contents: "; // Display vector's contents
    for (int i = 0; i < 20; i++)
    {
        cout << v.get(i) << " ";
    }
    cout << endl;
    
    cout << "\nEnter search value: ";

    int input;
    cin >> input;

    int searchValue = input; // Perform binary search for specific value
    int index = v.bin_search(searchValue);

    if (index != -1) // Output result of binary search
    {
        cout << "Value " << searchValue << " found at index " << index << "." << endl;
    }
    else
    {
        cout << "Value " << searchValue << " not found in the vector." << endl;
    }

    return 0;
}