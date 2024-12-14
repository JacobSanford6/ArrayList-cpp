#include <iostream>
#include <string>

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
        Remove from array by index
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
            // throw an error for out of bounds
        }
    }

    T get(unsigned index)
    {
        if (index < sizeOf)
        {
            return array[index];
        }
        else
        {
            throw std::runtime_error("Index out of bounds index " + std::to_string(index) + " not in range: " + std::to_string(sizeOf - 1));
            // throw error for out of bounds
        }
    }

    int size()
    {
        return sizeOf;
    }

    ~ArrayList()
    {
        delete[] array;
        array = nullptr;
    }

    
};
