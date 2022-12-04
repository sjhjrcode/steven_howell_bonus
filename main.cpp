
//Steven Howell
#include <iostream>


#include <iostream>
#include <stack>
#include <queue>
#include <array>
#include <bits/stdc++.h>
#include <list>
#include <map>
using namespace std;



template<class T>
void insertionsort(T data[], const int n) {
    for (int i = 1, j; i < n; i++) {
        T tmp = data[i];
        for (j = i; j > 0 && tmp < data[j-1]; j--)
            data[j] = data[j-1];
        data[j] = tmp;
    }
    for (int i = 0, j; i < n; i++) {
        cout<<data[i]<<" ";
    }
    cout<<endl;
}

template<class T>
void selectionsort(T data[], const int n) {
    for (int i = 0, least, j; i < n-1; i++) {
        for (j = i+1, least = i; j < n; j++)
            if (data[j] < data[least])
                least = j;
        swap(data[least],data[i]);
    }
    for (int i = 0, j; i < n; i++) {
        cout<<data[i]<<" ";
    }
    cout<<endl;
}

template<class T>
void bubblesort(T data[], const int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = n-1; j > i; --j)
            if (data[j] < data[j-1])
                swap(data[j],data[j-1]);

    for (int i = 0, j; i < n; i++) {
        cout<<data[i]<<" ";
    }
    cout<<endl;
}

template<class T>
void Shellsort(T data[], const int n) {
    int i, j, hCnt, h;
    int increments[20], k;
//  create an appropriate number of increments h
    for (h = 1, i = 0; h < n; i++) {
        increments[i] = h;
        h = 3*h + 1;
    }
    // loop on the number of different increments h
    for (i--; i >= 0; i--) {
        h = increments[i];
        // loop on the number of subarrays h-sorted in ith pass
        for (hCnt = h; hCnt < 2*h; hCnt++) {
            // insertion sort for subarray containing every hth element of array data
            for (j = hCnt; j < n; ) {
                T tmp = data[j];
                k = j;
                while (k-h >= 0 && tmp < data[k-h]) {
                    data[k] = data[k-h];
                    k -= h;
                }
                data[k] = tmp;
                j += h;
            }
        }
    }
    for (int i = 0, j; i < n; i++) {
        cout<<data[i]<<" ";
    }
    cout<<endl;
}

template<class T>
void moveDown (T data[], int first, int last) {
    int largest = 2*first + 1;
    while (largest <= last) {
        if (largest < last && // first has two children (at 2*first+1 and
            data[largest] < data[largest+1]) // 2*first+2) and the second
            largest++;                      // is larger than the first;

        if (data[first] < data[largest]) {   // if necessary,
            swap(data[first],data[largest]);// swap child and parent,
            first = largest;                // and move down;
            largest = 2*first+1;
        }
        else largest = last+1;  // to exit the loop: the heap property
    }                           // isn't violated by data[first];
}

template<class T>
void heapsort(T data[], const int n) {
    int i;
    for (i = n/2 - 1; i >= 0; --i) // create the heap;
        moveDown (data,i,n-1);
    for (i = n-1; i >= 1; --i) {
        swap(data[0],data[i]);     // move the largest item to data[i];
        moveDown(data,0,i-1);      // restore the heap property;
    }
}

template<class T>
void merge(T array1[], T temp[], int first, int last) {
    int mid = (first + last) / 2;
    int i1 = 0, i2 = first, i3 = mid + 1;
    while (i2 <= mid && i3 <= last)
        if (array1[i2] < array1[i3])
            temp[i1++] = array1[i2++];
        else temp[i1++] = array1[i3++];
    while (i2 <= mid)
        temp[i1++] = array1[i2++];
    while (i3 <= last)
        temp[i1++] = array1[i3++];
    for (i1 = 0, i2 = first; i2 <= last; array1[i2++] = temp[i1++]);
}

template<class T>
void mergesort(T data[], T temp[], int first, int last) {
    if (first < last) {
        int mid = (first + last) / 2;
        mergesort(data, temp, first, mid);
        mergesort(data, temp, mid+1, last);
        merge(data, temp, first, last);
    }
}

template<class T>
void mergesort(T data[], const int n) {
    T *temp = new T[n];
    mergesort(data,temp,0,n-1);
}


void menu(){
    std::cout.width(20);
    std::cout<<"MENU"<<std::endl<<std::endl<<"Input Data (0), Insertion Sort (1), Selection Sort (2), \n"
                                             "Bubble Sort (3), Shell Sort (4), Exit Program (5) "<<std::endl;
    std::cout<<"Choose?";

}

vector<int> store;
int size_array;

std::string decision(const std::string& user_input){
    std::string key = "null";

    std::string del = " ";//parameter to use
    std::stringstream ss(user_input);
    std::string word;
    std::vector<std::string> wordlist{};//command vector
/*
while (!ss.eof()) {
    getline(ss, word, del);
    std::cout << word << std::endl;
}
*/

    while (ss >> word) {//splits string by space
        //std::cout << word << std::endl;

        wordlist.push_back(word);//puts the individual strings into a vector
        if(wordlist.size()>50){//if there is are 3 detected inputs then return error
            std::cout<<"Input has too many parameters. Please try again."<<std::endl;
            //wordlist.empty();
            return key;
            //break;
        }
    }
    //checks if the first input matches the command number and is a valid input
    if((wordlist.at(0) == ("1")||
        wordlist.at(0) == ("2")||
        wordlist.at(0) == ("3")||
        wordlist.at(0) == ("4")||
        wordlist.at(0) == ("5"))&&
       wordlist.size()!=1){
        std::cout<<"too many inputs"<<std::endl;
        return key;
    }
/*
    else if ((wordlist.at(0) == ("0"))
             &&wordlist.size()!=2){
        std::cout<<"too many inputs"<<std::endl;
        return key;
    }
*/
    //check valid input or if the input value is 0
    if(wordlist.size() > 1){
        for(int k = 1; k<wordlist.size();k++) {
            for (char i: wordlist.at(k)) {
                if (!std::isdigit(i)) {
                    std::cout << "input is not a int" << std::endl;
                    return key;
                }
            }
        }

    }




    if(wordlist.at(0) == "0"){
        size_array = wordlist.size()-1;
        //store = new int[size_array];

        for(int k=1; k<wordlist.size();k++) {
            store.push_back(stoi(wordlist.at(k)));
            cout<<store.at(k-1)<<" ";
        }
        cout<<endl;


    }

    else if(wordlist.at(0) == "1"){
        int store_tmp[size_array];
        int count = 0;
        for(auto x: store) {
            store_tmp[count] = x;
            count++;
        }
        insertionsort(store_tmp,size_array);


    }
    else if(wordlist.at(0) == "2"){
        int store_tmp[size_array];
        int count = 0;
        for(auto x: store) {
            store_tmp[count] = x;
            count++;
        }
        selectionsort(store_tmp,size_array);

    }
    else if(wordlist.at(0) == "3"){
        int store_tmp[size_array];
        int count = 0;
        for(auto x: store) {
            store_tmp[count] = x;
            count++;
        }
        bubblesort(store_tmp,size_array);

    }
    else if(wordlist.at(0) == "4"){
        int store_tmp[size_array];
        int count = 0;
        for(auto x: store) {
            store_tmp[count] = x;
            count++;
        }
        Shellsort(store_tmp,size_array);

    }

    else if(wordlist.at(0) == "5"){
        key = "exit"; //pass exit code
    }

    return key;
}




int main() {

    std::string exit = "go";
    //vector<vector<int>> map;
    while(exit != "exit") {

        menu();
        std::string u_input;
        getline(std::cin,u_input);




        exit = decision(u_input);//decide on output checks if it should exit

    }
    std::cout<<"Program finished have a nice day!"<<std::endl;//a friendly message
    return 0;
}