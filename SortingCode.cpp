#include<iostream>
using namespace std;

//special functions from assignment instructions
void oneDimArray(int* test, int* source, int sizeX, int sizeY);
void measure(int* test, int fun, int sizeX, int sizeY);

//sorting functions prototype declaration
void merge(int* arr, int l, int m, int r);
void swap(int* a, int* b);
void selectionSort(int* arr, int n);
void mergeSort(int* arr, int l, int r);
int partition(int* arr, int low, int high);
void quickSort(int* arr, int low, int high);


void main()
{
    //two dimensional array; 5 rows, 6 columns
    int test[100];
    int arr[5][6];
    int max = 100;
    //declaring x and in the case arrays is not a square matrix
    int min = 1;
    int x = 5;//row
    int y = 6; //col
    cout << "Two-dim array: " << endl;
    for (int i = 0; i < x; i++)//for i(row), itterate until i=x(row)--->(5)
    {
        for (int j = 0; j < y; j++)
        {
            //random numbers generated using the min of 1 and max of 100 in place of i and j
            int randNum = rand() % (max - min + 1) + min;
            arr[i][j] = randNum;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;

    oneDimArray(test, *arr, x, y);

    measure(test, 1, x, y);

    system("pause>0");

}

void oneDimArray(int* test, int* source, int sizeX, int sizeY)
{
    int ind = 0;//starting index in test

    cout << "Array from oneDimArray function: " << endl;
    for (int i = 0; i < sizeX; i++)
    {
        for (int j = 0; j < sizeY; j++)
        {
            //incrimenting; will equal # of elements in array
            //to create one dim array stored in test
            test[ind] = source[ind++];//source[(i*sizeX)+j];

            cout << test[ind - 1] << " ";

        }

    }
    cout << endl << endl;
}


void measure(int* test, int fun, int sizeX, int sizeY)
{

    int userInput;
    cout << "Please select which sort function you would like to time: " << endl
        << "1. Selection sort" << endl << "2. Merge Sort" << endl << "3. Quick sort" << endl;
    cin >> userInput;

    clock_t start, end;
    start = clock();
    switch (userInput) //switch allows user to choose type of sorrting array that they want timed
    {
    case 1:
        cout << "Selection sorted array:" << endl;
        selectionSort(test, sizeX * sizeY);
        break;
    case 2:
        cout << "Merge sorted array:" << endl;
        mergeSort(test, 0, sizeX * sizeY - 1);
        break;
    case 3:
        cout << "Quick sorted array:" << endl;
        quickSort(test, 0, sizeX * sizeY - 1);
        break;
    }
    //selectionSort(test, sizeX*sizeY);   // <----- commented out hard coded sorts
    // mergeSort(test,0,sizeX*sizeY-1);
    // quickSort(test, 0, sizeX * sizeY - 1);
    // cout << "From sort function: "<<endl;
    for (int i = 0; i < sizeX * sizeY; i++)

    {
        cout << test[i] << " ";

    }
    end = clock();
    double total = (double)(end - start) / CLOCKS_PER_SEC;
    cout << endl << endl;
    cout << "It took " << total << " miliseconds to execute. " << endl;
}


//sorting function definitions

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// selection sort

void selectionSort(int* arr, int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(arr[min_idx], arr[i]);
    }
}

// quick sort algorithm

int partition(int* arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
//acrual function being called
void quickSort(int* arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// merge sort algorithm

void merge(int* arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[100], R[100];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
//function being called
void mergeSort(int* arr, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

