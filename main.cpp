#include <iostream>
#include <fstream>
#include "Data.h"
#include <vector>
#include <cassert>
#include <cstdio>
#include <ctime>


template<typename T>
void bubbleSort(vector <T>& arr, int size){
    int i, j;
    bool swapped;
    for (i = 0; i < size-1; i++){
        swapped=false;// Last i elements are already in place
        for (j = 0; j < size-i-1; j++)
            if (arr[j+1] < arr[j]) {
                swap(arr[j], arr[j + 1]);
                swapped=true;
            }    //if there wasn't any swap in the inner loop, stop
        if(!swapped)
            break;
    }
}


//Selection Sort from Class 22 ppt
template <typename T>
void selectionSort(vector <T>& arr, int size) {
    int min;
    for (int i = 0; i < size - 1; ++i){
        // Find index of smallest remaining element
        min = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[i],arr[min]);
    }
}

//MergeSort from Project 2
template <typename T>
void mergeSortedLists(vector<T>& a, vector<T>& tmp, int left, int middle, int right) {
    int i=left;
    int j=middle+1;
    int k=left;

    while(i<=middle&&j<=right){

        if(a.at(i)<=a.at(j)){
            tmp.at(k)=a.at(i);
            i++;
            k++;
        }else{
            tmp.at(k)=a.at(j);
            j++;
            k++;
        }

    }
    //adds end of vector if remaining values are in right half

    while(j<=right){
        tmp.at(k)=a.at(j);
        j++;
        k++;
    }


    //adds end of vector if remaining values are in left half

    while(i<=middle){
        tmp.at(k)=a.at(i);
        i++;
        k++;
    }
    for(int l=left;l<=right;l++){
        a.at(l)=tmp.at(l);
    }



}
template <typename T>
void mergeSort(vector<T>& a, vector<T>& tmp, int left, int right) {

    //base case
    int n = (right +left)/2;
    if (left==right) {
        return;
    } else if (left < right) {
        // recursive step
        mergeSort(a, tmp, left, n );
        mergeSort(a, tmp, n  + 1, right);

        //sorts list
        mergeSortedLists(a, tmp, left, n, right);

    }



}



//QuickSort from Zybooks

template <typename T>
int Partition(vector<T>& numbers, int i, int k) {
    int l;
    int h;
    int midpoint;
    T pivot;
    T temp;
    bool done;

    /* Pick middle element as pivot */
    midpoint = i + (k - i) / 2;
    pivot = numbers[midpoint];

    done = false;
    l = i;
    h = k;

    while (!done) {

        /* Increment l while numbers[l] < pivot */
        while (numbers[l] < pivot) {
            ++l;
        }

        /* Decrement h while pivot < numbers[h] */
        while (pivot < numbers[h]) {
            --h;
        }

        /* If there are zero or one elements remaining,
         all numbers are partitioned. Return h */
        if (l >= h) {
            done = true;
        }
        else {
            /* Swap numbers[l] and numbers[h],
             update l and h */
            temp = numbers[l];
            numbers[l] = numbers[h];
            numbers[h] = temp;

            ++l;
            --h;
        }
    }

    return h;
}

template <typename T>
void Quicksort(vector<T>& numbers, int i, int k) {
    int j;

    /* Base case: If there are 1 or zero elements to sort,
     partition is already sorted */
    if (i >= k) {
        return;
    }

    /* Partition the data within the array. Value j returned
     from partitioning is location of last element in low partition. */
    j = Partition(numbers, i, k);

    /* Recursively sort low partition (i to j) and
     high partition (j + 1 to k) */
    Quicksort(numbers, i, j);
    Quicksort(numbers, j + 1, k);
}

int main() {
    ifstream inFile;
    inFile.open("Sales records.csv");
    if(!inFile.is_open()) {
        cout << "file does not exist";
        return 1;//indicates error
    }

    int n=50000;
    //creates Vector
    vector<Data> dataV(n);


    //while loop to read csv file while adding to linked lists
    int count = 0;
    while (count < n) {
        string region;
        string type;
        string order;
        string sold;
        string profit;

        //takes in separate data members
        getline(inFile, region, ',');
        getline(inFile, type, ',');
        getline(inFile, order, ',');
        getline(inFile, sold, ',');
        getline(inFile, profit);
        int order1 = stoi(order);
        int sold1 = stoi(sold);
        int profit1 = stoi(profit);

        Data temp = Data(region, type, stoi(sold), stoi(sold), stoi(profit));
        dataV.at(count) = temp;
        count++;
    }




    vector<Data> dataV_B = dataV;
    vector<Data> dataV_S = dataV;
    vector<Data> dataV_Q = dataV;
    vector<Data> dataV_M = dataV;

    //makes random integer vector
    vector<int> intV(n);
    for(int j=0;j<n;j++){
        intV.at(j)=rand()%100;
    }

    cout << "1"<<endl;
    //copy data sets
    vector<int> intV_B = intV;
    vector<int> intV_S = intV;
    vector<int> intV_Q = intV;
    vector<int> intV_M = intV;

    //sort vectors
    cout << "3"<<endl;
    //BubbleSort
    clock_t start_bubbleSortData = clock();
    bubbleSort<Data>(dataV_B, dataV_B.size());
    clock_t end_bubbleSortData = clock();

    clock_t start_bubbleSortInt = clock();
    bubbleSort<int>(intV_B, intV_B.size());
    clock_t end_bubbleSortInt = clock();

    cout << "4"<<endl;
    //SelectionSort
    clock_t start_SelectionSortData = clock();
    selectionSort(dataV_S, dataV_S.size());
    clock_t end_SelectionSortData = clock();

    clock_t start_SelectionSortInt = clock();
    selectionSort(intV_S, intV_S.size());
    clock_t end_SelectionSortInt = clock();
    cout << "5"<<endl;
    //QuickSort

    clock_t start_quickSortData = clock();
    cout << "5.1"<<endl;
    Quicksort(dataV_Q, 0, dataV_Q.size());
    cout << "5.2"<<endl;
    clock_t end_quickSortData = clock();
    cout << "5.5"<<endl;
    clock_t start_quickSortInt = clock();
    Quicksort(intV_Q, 0, intV_Q.size());
    clock_t end_quickSortInt = clock();
    cout << "6"<<endl;
    //MergeSort
    vector<Data> DataTemp(dataV_M.size());
    vector<int> IntTemp(intV_M.size());
    cout << "7"<<endl;
    clock_t start_mergeSortData = clock();
    mergeSort(dataV_M,DataTemp,  0, dataV_M.size()-1);
    clock_t end_mergeSortData = clock();

    clock_t start_mergeSortInt = clock();
    mergeSort(intV_M, IntTemp ,0, intV_M.size()-1);
    clock_t end_mergeSortInt = clock();

    cout << "2"<<endl;
    double elapsed_bubbleSortData = double(end_bubbleSortData - start_bubbleSortData) / CLOCKS_PER_SEC;
    double elapsed_bubbleSortInt = double(end_bubbleSortInt - start_bubbleSortInt) / CLOCKS_PER_SEC;
    double elapsed_SelectionSortData = double(end_SelectionSortData - start_SelectionSortData) / CLOCKS_PER_SEC;
    double elapsed_SelectionSortInt = double(end_SelectionSortInt - start_SelectionSortInt) / CLOCKS_PER_SEC;
    double elapsed_mergeSortData = double(end_mergeSortData - start_mergeSortData) / CLOCKS_PER_SEC;
    double elapsed_mergeSortInt = double(end_mergeSortInt - start_mergeSortInt) / CLOCKS_PER_SEC;
    double elapsed_quickSortData = double(end_quickSortData - start_quickSortData) / CLOCKS_PER_SEC;
    double elapsed_quickSortInt = double(end_quickSortInt - start_quickSortInt) / CLOCKS_PER_SEC;


    cout << n;
    cout<< " " << elapsed_bubbleSortData << " " << elapsed_bubbleSortInt << " " << elapsed_SelectionSortData
         << " " << elapsed_SelectionSortInt << " " <<
         elapsed_quickSortData << " " << elapsed_quickSortInt << " " << elapsed_mergeSortData << " "
         << elapsed_mergeSortInt;



    //run over sorted vectors

    //BubbleSort
    clock_t start_bubbleSortData2 = clock();
    bubbleSort<Data>(dataV_B, dataV_B.size());
    clock_t end_bubbleSortData2 = clock();

    clock_t start_bubbleSortInt2 = clock();
    bubbleSort<int>(intV_B, intV_B.size());
    clock_t end_bubbleSortInt2 = clock();


    //SelectionSort
    clock_t start_SelectionSortData2 = clock();
    selectionSort(dataV_S, dataV_S.size());
    clock_t end_SelectionSortData2 = clock();

    clock_t start_SelectionSortInt2 = clock();
    selectionSort(intV_S, intV_S.size());
    clock_t end_SelectionSortInt2 = clock();



    //QuickSort

    clock_t start_quickSortData2 = clock();
    Quicksort(dataV_Q, 0, dataV_Q.size());
    clock_t end_quickSortData2 = clock();

    clock_t start_quickSortInt2 = clock();
    Quicksort(intV_Q, 0, intV_Q.size());
    clock_t end_quickSortInt2 = clock();

    //MergeSort
    vector<Data> DataTemp2(dataV_M.size());
    vector<int> IntTemp2(intV_M.size());

    clock_t start_mergeSortData2 = clock();
    mergeSort(dataV_M,DataTemp,  0, dataV_M.size()-1);
    clock_t end_mergeSortData2 = clock();

    clock_t start_mergeSortInt2 = clock();
    mergeSort(intV_M, IntTemp, 0, intV_M.size()-1);
    clock_t end_mergeSortInt2 = clock();


    double elapsed_bubbleSortData2 = double(end_bubbleSortData2 - start_bubbleSortData2) / CLOCKS_PER_SEC;
    double elapsed_bubbleSortInt2 = double(end_bubbleSortInt2 - start_bubbleSortInt2) / CLOCKS_PER_SEC;
    double elapsed_SelectionSortData2 = double(end_SelectionSortData2 - start_SelectionSortData2) / CLOCKS_PER_SEC;
    double elapsed_SelectionSortInt2 = double(end_SelectionSortInt2 - start_SelectionSortInt2) / CLOCKS_PER_SEC;
    double elapsed_mergeSortData2 = double(end_mergeSortData2 - start_mergeSortData2) / CLOCKS_PER_SEC;
    double elapsed_mergeSortInt2 = double(end_mergeSortInt2 - start_mergeSortInt2) / CLOCKS_PER_SEC;
    double elapsed_quickSortData2 = double(end_quickSortData2 - start_quickSortData2) / CLOCKS_PER_SEC;
    double elapsed_quickSortInt2 = double(end_quickSortInt2 - start_quickSortInt2) / CLOCKS_PER_SEC;

    cout << " " << elapsed_bubbleSortData2 << " " << elapsed_bubbleSortInt2 << " " << elapsed_SelectionSortData2
         << " " << elapsed_SelectionSortInt2 << " " <<
         elapsed_quickSortData2 << " " << elapsed_quickSortInt2 << " " << elapsed_mergeSortData2 << " "
         << elapsed_mergeSortInt2 << endl;




    inFile.close();





    return 0;
}
