#include "O_log_n.h"

using namespace std;

logN::logN()
{


}

logN::~logN()
{


}

int logN::binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
        {
            cout << "We found " << x << " , it was in position" << mid << endl;
            return mid;
        }
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            cout << "The current mid, '" << arr[mid] << "' , is less than element " << x << "." << endl;
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
            cout << "The current mid, '" << arr[mid] << "' , is more than element " << x << "." << endl;
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    
    return -1;
}

void logN::inputReader()
{
    int read;
    logN searcher;
    int n = sizeof(ar) / sizeof(ar[0]);
    cout << "Please enter a number from 1 to 10 into the console. We'll check an ordered array \n";
    cout << "that goes from 1 to 10 for it and print out if we find it, and in what position in the array" << endl;
    cin >> read;
    cout << "Checking for element : " << read << endl;
    int result = searcher.binarySearch(ar, 0, n,read);
    if (result == -1)
    {
        cout << "We could not locate the element '" << read << "' in the array." << endl;
    }
    else
    {
        cout << "Element" << read << "was successfully located." << endl;
    }
}