#include <iostream>

template <typename T>
class ArrayList
{
private:
    unsigned int sizeOf;
    T *array;

public:
    ArrayList()
    {
        sizeOf = 0;
        array = new T[1];
    }

    /*
        Add value to end of ArrayList
    */
    void add(T value)
    {
        sizeOf++;
        T *newArray = new T[sizeOf];
        for (int i = 0; i < sizeOf - 1; i++)
        {
            newArray[i] = array[i];
        }
        newArray[sizeOf - 1] = value;
        delete[] array;
        array = newArray;
    }

    /*
        Remove value from ArrayList at index
    */
    void remove(unsigned index)
    {
        if (index < sizeOf)
        {
            sizeOf--;
            T *newArray = new T[sizeOf];
            int originalArrayPos = 0;
            for (int i = 0; i < sizeOf; i++)
            {
                // if we are at the index that is to be removed, skip
                if (originalArrayPos == index)
                {
                    originalArrayPos++;
                }
                newArray[i] = array[originalArrayPos];
                originalArrayPos++;
            }
            delete[] array;
            array = newArray;
        }
        else
        {
            throw std::runtime_error("Index out of bounds index " + std::to_string(index) + " not in range: " + std::to_string(sizeOf - 1));
        }
    }

    /*
        Get value at array list index
    */
    T get(unsigned index)
    {
        if (index < sizeOf)
        {
            return array[index];
        }
        else
        {
            throw std::runtime_error("Index out of bounds index " + std::to_string(index) + " not in range: " + std::to_string(sizeOf - 1));
        }
    }

    /*
        Get the amount of elements stored in the ArrayList
    */
    int count()
    {
        return sizeOf;
    }

    ~ArrayList()
    {
        delete[] array;
        array = nullptr;
    }

    
};
