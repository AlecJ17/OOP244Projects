/*
     *****************************************************************************
                   <Workshop - 10>
     Full Name         : Alec Josef Serrano
     Student ID#       : 133592238
     Email             : ajserrano2@myseneca.ca
     Section           : NEE
     Date Accomplished : April 02,2024
     Authenticity Declaration:
     I declare this submission is the result of my own work and has not been
     shared with any other student or 3rd party content provider. This submitted
     piece of work is entirely of my own creation.
     *****************************************************************************
*/
#ifndef SENECA_MATCHPAIR_H
#define SENECA_MATCHPAIR_H
namespace seneca{

    template<class T, class U>
    struct Pair{
        T first;
        U second;
    };

    template<typename T, typename U>
    void addDynamicPairElement(Pair<T, U>*& pArray,const T& first, const U& second, int& size) {
        Pair<T, U>* temp = new Pair<T, U>[size + 1];
        for (int k = 0; pArray && k < size; k++) {
            temp[k] = pArray[k];
        }
        temp[size].first = first;
        temp[size].second = second;
        delete[] pArray;
        pArray = temp;
        size++;
    }

    template<typename T, typename U>
    Pair<T,U>* matches(T* arr1, U* arr2, int size1, int size2, int& size3){
        Pair<T, U>* temp = nullptr;
        size3 = 0;
        for (int i = 0; i < size1; i++) {
            for (int j = 0; j < size2; j++) {
                if (arr1[i] == arr2[j]) {
                    addDynamicPairElement(temp, arr1[i], arr2[j], size3);
                }
            }
        }
        return temp;
    }
    template<typename T>
    void releaseMem(T* arr) {
        delete[] arr;
    }
}
#endif // !SENECA_MATCHPAIR_H