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
            newArray[i] = array[i];
        }

        // delete the old array
        delete[] array;

        // point to the new array
        array = newArray;
        --size;

    }

    // function to pop element by index and return popped element
    T pop(int index=-10) {

        if (index == -10) index = size-1;

        // create a new array to store old array without element at index
        T* newArray = new T[capacity];

        // add every element before index from old array to new array
        for (int i = 0; i < index; ++i) {
            newArray[i] = array[i];
        }

        // add every element after index from old array to new array
        for (size_t i = index; i < size-1; ++i) {
            newArray[i] = array[i + 1];
        }

        T item = array[index];

        // delete the old array
        delete[] array;

        // point to the new array
        array = newArray;
        --size;

        // return popped item
        return item;
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

    // function to return index of string if string is in array
    int find(std::string value) {

        // loop through every index of the array

        for (size_t i = 0; i < size; ++i) {
            if (array[i] == value) return i;
        }

        return -1;


    }

    // function to return index of last occurence of string if string is in array
    int rfind(std::string value) {

        // loop through every index of the array backwards
        for (size_t i = size; i > 0; --i) {
            if (array[i] == value) return i;
        }
    
    return -1;

    }



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

    std::cout << "pop index 3: " << intVector.pop(3) << std::endl;

    // Access and print elements
    for (size_t i = 0; i < intVector.getSize(); ++i) {
        std::cout << "Element at index " << i << ": " << intVector[i] << std::endl;
    }

    std::cout << std::endl;

    std::cout << "pop last item: " << intVector.pop() << std::endl;

    // Access and print elements
    for (size_t i = 0; i < intVector.getSize(); ++i) {
        std::cout << "Element at index " << i << ": " << intVector[i] << std::endl;
    }

    std::cout << std::endl;

    std::cout << "pop first item: " << intVector.pop(0) << std::endl;

    // Access and print elements
    for (size_t i = 0; i < intVector.getSize(); ++i) {
        std::cout << "Element at index " << i << ": " << intVector[i] << std::endl;
    }

    std::cout << std::endl;

    vector<std::string> stringVector;

    std::string characters = "characters";

    for (char i : characters) {
        stringVector.push_back(std::string(1, i));
    }

    // Access and print elements
    for (size_t i = 0; i < stringVector.getSize(); ++i) {
        std::cout << "Element at index " << i << ": " << stringVector[i] << std::endl;
    }

    std::cout << std::endl;

    std::string character = "r";

    int index = characters.find(character);

    if (index == -1) std::cout << "could not find character";
    else std::cout << "the character \'" << character << "\' is at index " << index << std::endl;

    std::cout << std::endl;

    index = characters.rfind(character);

    if (index == -1) std::cout << "could not find character";
    else std::cout << "the last occurence of the character \'" << character << "\' is at index " << index << std::endl;






    return 0;
}