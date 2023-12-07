#include <iostream>

template <typename T>
class vector {
private:
    T* array;  // Dynamic array to store elements
    size_t size;  // Number of elements in the vector
    size_t capacity;  // Capacity of the array

public:

    // Constructor
    vector(size_t initialSize = 0) : size(initialSize), capacity(initialSize * 2) {

        if (capacity == 0) ++capacity;
        array = new T[capacity];
    }

    // Destructor
    ~vector() {
        delete[] array;
    }

    // Getter for size
    size_t getSize() const {
        return size;
    }

    // Access element at index
    T& operator[](size_t index) {
        return array[index];
    }

    // Push element to the back
    void push_back(const T& value) {
        if (size == capacity) {
            // Double the capacity
            capacity *= 2;

            // Create a new array with double capacity
            T* newArray = new T[capacity];

            // Copy elements to the new array
            for (size_t i = 0; i < size; ++i) {
                newArray[i] = array[i];
            }

            // Delete the old array
            delete[] array;

            // Point to the new array
            array = newArray;
        }

        // Add the new element to the end
        array[size] = value;
        ++size;
    }

    // pop element from front
    void pop_front() {

        // create a new array to store old array without first index
        T* newArray = new T[capacity];

        // add every element from old array to new array, but skip first element
        for (size_t i = 0; i < size-1; ++i) {
            newArray[i] = array[i + 1];
        }

        // delete the old array
        delete[] array;

        // point to the new array
        array = newArray;
        --size;
    }

    // pop element from back
    void pop_back() {

        // create a new array to store old array without first index
        T* newArray = new T[capacity];

        // add every element from old array to new array, but skip last element
        for (size_t i = 0; i < size-2; ++i) {
            newArray[i] = array[i]
        }

        // delete the old array
        delete[] array;

        // point to the new array
        array = newArray;
        --size;

    }


    // get element at front
    T front() {return array[0];}
    


    // get element at back
    T back() {return array[size-1];}


    // insert element at index
    void insert(int index, const T& value) {

        // create a new array to store old array with new element at index
        T* newArray = new T[++capacity];

        // add every element before index from old array to new array
        for (int i = 0; i < index; ++i) {
            newArray[i] = array[i];
        }

        // add element at index
        newArray[index] = value;

        // add every element after index from old array to new array
        for (size_t i = index; i < size; ++i) {
            newArray[i + 1] = array[i];
        }

        delete[] array;

        array = newArray;
        ++size;

    }


    // get size of vector
    // just use .size, there is already a size attribute

};

int main() {
    // Create a vector of integers
    vector<int> intVector;

    // Push some elements to the vector
    for (int i = 0; i < 10; ++i) {
        intVector.push_back(i * 10);
    }

    // Access and print elements
    for (size_t i = 0; i < intVector.getSize(); ++i) {
        std::cout << "Element at index " << i << ": " << intVector[i] << std::endl;
    }
    
    intVector.pop_front();

    std::cout << "pop front: " << std::endl;

    // Access and print elements
    for (size_t i = 0; i < intVector.getSize(); ++i) {
        std::cout << "Element at index " << i << ": " << intVector[i] << std::endl;
    }
    std::cout << std::endl;

    intVector.insert(3, 31);

    std::cout << "insert at index 3: " << std::endl;

    // Access and print elements
    for (size_t i = 0; i < intVector.getSize(); ++i) {
        std::cout << "Element at index " << i << ": " << intVector[i] << std::endl;
    }
    std::cout << std::endl;






    return 0;
}