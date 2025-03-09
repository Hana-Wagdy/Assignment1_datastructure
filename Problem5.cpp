#include <iostream>
using namespace std;


int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
template<typename T>
class Stat{

private:
    T* data;     //Dynamically allocated array for storing data
    int size;    //Number of elements in the array
public:
    Stat(int size);
    ~Stat();

    void sort();        //Implement Sort Algorithm

    //Statistical Calculation Functions
    T findMedian();
    T findMax();
    T findMin();
    double findMean();
    T findSummation();

    //Utility Functions
    void displayArray();    //Display Sorted array
    void inputData();       //Take input dynamically
    void satisicsMenu();    //Menu for statistical operations
};

//Constructor
template<typename T>
Stat<T>::Stat(int n ):size(n){
    data = new T[size];
}

//Destructor
template<typename T>
Stat<T>::~Stat() {
    delete[] data;
}

//Sort
template<typename T>
void Stat<T>::sort(){
    for (T i = 0; i < size-1; ++i) {
        for (T j = 0; j < i+1; ++j) {
            if(j<i){
             T tmp=i;
             i=j;
             j=tmp;
            }
        }
    }
}

//Min
template<typename T>
T Stat<T>::findMin(){
    return data[0];
}

//Max
template<typename T>
T Stat<T>::findMax(){
    return data[size-1];
}

//Summation
template <typename T>
T Stat<T>::findSummation() {
    T Sum=0;
    for (T i = 0; i <size-1 ; ++i) {
        Sum=Sum+data[i];
    }
    return Sum;
}

//Mean
template <typename T>
double Stat<T>::findMean() {
    T total=findSummation();
    double mean = total/size;
    return mean;
}

//Median
template<typename T>
T Stat<T>::findMedian() {
    if(size%2==0){  //size is even number
        T first_pos=size/2;
        T second_pos=(size+1)/2;
        T pos =(first_pos+second_pos)/2;
        T index= pos-1;
        return data[index];

    }else{          //size is odd
        T pos=(size+1)/2;
        T index=pos-1;
        return data[index];
    }
}

//display
template<typename T>
void Stat<T>::displayArray() {
    cout<<"Sorted Array: ";
    for (T element:data) {
        cout<<element<<" ,";
    }
    cout<<endl;
}

//Taking input
template<typename T>
void Stat<T>::inputData(){
    for (T i = 0; i <size-1 ; ++i) {
        cin>>data[i];
    }
}

//MENU
template<typename T>
void Stat<T>::satisicsMenu(){
//lesa ma 5lastesh
}