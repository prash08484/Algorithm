
/*
              Min Heap
                 │
      ┌──────────┼──────────┐
      ↓          ↓          ↓
  buildHeap   insert     extractMin
      │          │          │
   sift down  sift up    sift down
                            │
                       decreaseKey
                            │
                         sift up

| Operation     |Complexity|
| ------------- |--------- |
| getMin()      |     O(1) |
| insert()      | O(log n) |
| extractMin()  | O(log n) |
| increaseKey() | O(log n) |
| remove()      | O(log n) |
| buildHeap()   |     O(n) |


*/


class MinHeap {
private:
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; } 
    int cap, n;
    int *arr;

public:
    MinHeap(int n) {
        this->n = 0;
        cap = n;
        arr = new int[cap];
    }
    MinHeap(vector<int>& a) {
        n = a.size();
        cap = n;
        arr = new int[cap];
        for(int i = 0; i < n; i++)
            arr[i] = a[i];
        
        buildHeap();
    }
    void buildHeap() { // O(n)
        for(int i = n/2 - 1; i >= 0; i--) {
            Heapify(i);
        }
    }

    void insert(int v) {  // log(n)
        if (n >= cap) {
            cout << "Heap Overflow\n";
            return;
        }
        arr[n] = v;
        int idx = n;
        n++;
        
         // pull up
        while (idx > 0 && arr[parent(idx)] > arr[idx]) {
            swap(arr[parent(idx)],arr[idx]);
            idx = parent(idx);
        }
    }

    void Heapify(int idx) { // O(h) :h height
        // push down - child violation
        while (true) {
            int l = left(idx), r = right(idx);
            int smallest = idx;
    
            if (l < n && arr[l] < arr[smallest]) smallest = l;
            if (r < n && arr[r] < arr[smallest]) smallest = r;
    
            if (smallest == idx) break;
    
            swap(arr[idx], arr[smallest]);
            idx = smallest;
       }
    }

    void remove(int idx){ // log(n)
        if(idx < 0 || idx >= n) return;
        decreaseKey(idx, -INF);
        extractMin();
    }

    int extractMin() { // log(n)
        if (n <= 0) return INF;
        if (n == 1){
            n--;
            return arr[0];
        }
        int mini = arr[0];

        // Copy last Node value to root Node
        arr[0] = arr[n - 1];
        n--;

        // Call heapify on root node
        Heapify(0);

        return mini;
    }
    void decreaseKey(int idx, int v) {  // log(n)
        if(idx < 0 || idx >= n) return;
        arr[idx] = v;
        // pull up

        // move till violate the heap property
        while (idx > 0 and arr[parent(idx)] > arr[idx]) {
            swap(arr[parent(idx)],arr[idx]);
            idx = parent(idx);
        }
    }
    ll getMin() {  // O(1)
        if(n==0) return INF;
        return arr[0];
    }
    void print() {  // O(n)
        for (int i = 0; i < n; i++) {
            cout << arr[i]<<" ";

            cout<< "["; 

            if (left(i) < n) cout << arr[left(i)];
            else cout << "null";

            cout << ",";

            if (right(i) < n) cout << arr[right(i)];
            else cout << "null";

            cout << "]\n";

        }
    }
};

/*
              Max Heap
                 │
      ┌──────────┼──────────┐
      ↓          ↓          ↓
  buildHeap   insert     extractMax
      │          │          │
   shift down  sift up    shift down
                            │
                       increaseKey
                            │
                         sift up

| Operation     |Complexity|
| ------------- |--------- |
| getMax()      |     O(1) |
| insert()      | O(log n) |
| extractMax()  | O(log n) |
| increaseKey() | O(log n) |
| remove()      | O(log n) |
| buildHeap()   |     O(n) |


*/

class MaxHeap {
private:

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    const int INF = 1e9;

    int cap;
    int n;
    vector<int> arr;

public:

    // Empty heap with given capacity
    MaxHeap(int cap) : cap(cap), n(0), arr(cap) {}

    // Build heap from existing array
    MaxHeap(vector<int>& arr) : arr(arr) {
        n = arr.size();
        cap = arr.size();

        buildHeap();
    }

    void buildHeap() {

        // Leaves are already heaps
        for(int i = n / 2 - 1; i >= 0; i--) {
            heapify(i);
        }
    }

    void heapify(int i) {

        // Sift down
        while(true) {

            int l = left(i);
            int r = right(i);

            int largest = i;

            if(l < n && arr[l] > arr[largest])
                largest = l;

            if(r < n && arr[r] > arr[largest])
                largest = r;

            if(largest == i)
                break;

            swap(arr[i], arr[largest]);

            i = largest;
        }
    }

    int extractMax() {

        if(n == 0)
            return -1;

        int maxi = arr[0];

        arr[0] = arr[n - 1];
        n--;

        if(n > 0)
            heapify(0);

        return maxi;
    }

    void increaseKey(int idx, int val) {

        if(idx < 0 || idx >= n)
            return;

        arr[idx] = val;

        // Sift up
        while(idx > 0 && arr[idx] > arr[parent(idx)]) {

            swap(arr[idx], arr[parent(idx)]);

            idx = parent(idx);
        }
    }

    void remove(int idx) {

        if(idx < 0 || idx >= n)
            return;

        increaseKey(idx, INF);
        extractMax();
    }

    void insert(int val) {

        if(n == cap)
            return;

        int idx = n;

        arr[idx] = val;
        n++;                         

        // Sift up
        while(idx > 0 && arr[idx] > arr[parent(idx)]) {

            swap(arr[idx], arr[parent(idx)]);

            idx = parent(idx);
        }
    }

    int getMax() {

        if(n == 0)
            return -1;

        return arr[0];
    }
};

 
