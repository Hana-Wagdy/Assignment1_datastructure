#include <iostream>
using namespace std;


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

//Sort "BUBBLE"
template<typename T>
void Stat<T>::sort(){
    for (T i = 0; i < size-1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (data[j] > data[j + 1]) {
                T tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
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
    for (T i = 0; i <size ; ++i) {
        Sum=Sum+data[i];
    }
    return Sum;
}

//Mean
template <typename T>
double Stat<T>::findMean() {
    T total=findSummation();
    return static_cast<double>(total) / size;
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
    for (int i = 0; i < size; ++i) {
        cout<<data[i]<<" ,";
    }
    cout<<endl;
}

//Taking input
template<typename T>
void Stat<T>::inputData(){
    for (T i = 0; i <size ; ++i) {
        cout<<"Enter element "<<i+1<<": ";
        cin>>data[i];
    }
}

//MENU
template<typename T>
void Stat<T>::satisicsMenu(){
    int choice;
inputData();
sort();
displayArray();

cout <<"Select a statistical calculation:\n ";
    do {
        cout << "1. Find Median\n";
        cout << "2. Find Minimum\n";
        cout << "3. Find Maximum\n";
        cout << "4. Find Mean\n";
        cout << "5. Find Summation\n";
        cout << "6. Display Sorted Array\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Median: " << findMedian() << endl;
                break;
            case 2:
                cout << "Minimum: " << findMin() << endl;
                break;
            case 3:
                cout << "Maximum: " << findMax() << endl;
                break;
            case 4:
                cout << "Mean: " << findMean() << endl;
                break;
            case 5:
                cout << "Summation: " << findSummation() << endl;
                break;
            case 6:
                displayArray();
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 7);

}



int main() {
    int s;
    cout << "Enter the number of elements: ";
    cin >> s;
    Stat<int>Array(s);

    Array.satisicsMenu();

    return 0;
}
