// OwnVector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

template<typename T>
class vectorclass
{
private:
    T* arr;
    int capacity;
    int current;

public:
    vectorclass()
    {
        arr = new T[1];
        capacity = 1;
        current = 0;
    }

    void push(T data)
    {
        if (current == capacity)
        {
            //capacity = *2;
            T* temp = new T[2*capacity];
            for (int i = 0; i < current; i++)
                temp[i] = arr[i];
            delete[] arr;
            capacity *= 2;
            arr = temp;
                 
        }
        arr[current] = data;
        current++;
    }
    void push(T data, int indx)
    {
        if (indx == capacity)
            push(data);
        else
        arr[indx] = data;
    }
    void pop()
    {
        current--;
    }
    T get(int indx)
    {
        if (indx > current)
            return -1;
        return arr[indx];
    }
    int size()
    {
        return current;
    }
    int getcapacity()
    {
        return capacity;
            
    }
    ~vectorclass()
    {
        delete[] arr;
    }

    void print()
    {
        for (int i = 0;i<current;i++)
            std::cout << arr[i] << " ";
        std::cout << endl;
    }

    void erase(int a)
    {
        bool findflag = false;
        for (int i = 0; i < current; i++)
        {
            if (arr[i] == a)
            {
                current = current - 1;
                for (int j = i; j < current; j++)
                    arr[j] = arr[j + 1];
                findflag = true;
            }

        }
        if (findflag)
        {
            //     size = size-1;
        }
        else
        {
            std::cout << a << ":" << "element not find in array :" << std::endl;
        }
    }

};

int main()
{
    vectorclass<int> v;
    vectorclass<char> v1;
    v.push(10);
    v.push(20);
    v.push(30);
    v.push(40);
    v.push(50);
    v1.push(71);
    v1.push(72);
    v1.push(73);
    v1.push(74);

    cout << "Vector size : " << v.size() << endl;
    cout << "Vector capacity : " << v.getcapacity() << endl;

    cout << "Vector elements : ";
    v.print();

    v.push(100, 1);

    cout << "\nAfter updating 1st index" << endl;

    cout << "Vector elements of type int : " << endl;
    v.print();
    
    v.erase(50);

    cout << "\nAfter removing  element" << endl;

    cout << "Vector elements of type int : " << endl;
    v.print();
    std::cout << "Hello World!\n";
}
