#include <iostream>
#include <queue>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }

        // Step1: put last element into first index
        arr[1] = arr[size];

        // step2: Remove last element
        size--;

        // take root node to its correct position
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
                return;
        }
    }
};

void heapify(int arr[], int size, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= size && arr[largest] < arr[left])
    {
        largest = left;
    }

    if (right <= size && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, size, largest);
    }
}


void heapSort(int arr[], int n){
    int t = n;

    while(t>1){
        //Step1: Swap
        swap(arr[1], arr[t]);
        
        //Step2: size--
        t--;

        //Step3: root ko correct pos
        heapify(arr,t,1);
    }
}

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deleteFromHeap();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    cout << "Printing the array now" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr,n);

    cout << "Printing the array now" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout<<"Using priority queue here"<<endl;
    priority_queue<int>pq;  //Max Heap
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);
    pq.pop();
    cout<<"Element at top "<<pq.top()<<endl;

    cout<<"Size is "<<pq.size()<<endl;

    if(pq.empty()) cout<<"Pq is empty"<<endl;
    else cout<<"PQ is not empty"<<endl;

    priority_queue<int, vector<int>, greater<int> >pq2;

    pq2.push(4);
    pq2.push(2);
    pq2.push(5);
    pq2.push(3);
    // pq2.pop();
    cout<<"Element at top "<<pq2.top()<<endl;

    cout<<"Size is "<<pq2.size()<<endl;

    if(pq2.empty()) cout<<"Pq is empty"<<endl;
    else cout<<"PQ is not empty"<<endl;

}   