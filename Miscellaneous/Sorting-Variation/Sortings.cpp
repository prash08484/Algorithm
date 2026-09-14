
vector<int> bubbleSort(vector<int> &arr){
    vector<int> a(arr); 
    int n = arr.size(); 

    // best T.C. : O(n) no swap exit
    // worst T.C. : (n*n) reversed array

    for(int i=0; i<n-1; i++){
        bool sorted=1;
        for(int j=0; j<n-i-1; j++){
            if(a[j]>a[j+1]){
                sorted=0;
                swap(a[j],a[j+1]);
            }
        }
        if(sorted) break;
    }
    return a;
}

vector<int> selectionSort(vector<int> &arr){
    
    vector<int> a(arr); 
    int n = arr.size(); 

    // select the max put at last

    // best T.C. : O(n*n) 
    // worst T.C. : (n*n) 

    for(int i=0; i<n-1; i++){
        int mxIdx=0;
        for(int j=0; j<n-i; j++){
            if(a[j]>a[mxIdx]){  
                mxIdx=j;
            }
        }   
        swap(a[n-i-1], a[mxIdx]);
    }
    return a;
}

vector<int> insertionSort(vector<int> &arr){

    vector<int> a(arr); 
    int n = arr.size(); 

    // select the next element and put it in previous sorted array at correct place

    // best T.C. : O(n) no swap exit
    // worst T.C. : (n*n) reversed array 

    for(int i=1; i<n; i++){ 
        for(int j=i-1; j>=0; j--){
            if(a[j]>a[j+1]){  
                swap(a[j],a[j+1]);
            }
            else break; 
        }  
    }
    return a;
    

}

vector<int> quickSort(vector<int> &arr){
    
    vector<int> a(arr); 
    int n = arr.size(); 

    // best T.C. : O(nlogn) 
    // worst T.C. : (n*n) sorted array

    // take a last as PIVOT value, move element to left if less than PIVOT else skip 

    auto pivot = [&](int l,int r){

        int j=l;
        int pivotVal = a[r];
        for(int i=l; i<=r; i++){
            if(a[i]<=pivotVal){
                swap(a[i], a[j++]); 
            }
        }

        return j-1; // index of pivot element after sorting 

    };

    function<void(int,int)> quick = [&](int l, int r)->void{
        if(l<r){
            int pvt = pivot(l,r); 
            quick(l,pvt-1);
            quick(pvt+1,r);
        }
    };

    quick(0,n-1);
    
    return a;

}

vector<int> mergeSort(vector<int> &arr){

    vector<int> a(arr); 
    int n = arr.size(); 

    // best T.C. : O(nlogn) 
    // worst T.C. : (nlogn) 

    // take break from mid, sort them then merge them 

    auto merge = [&](int l,int m, int r){

        vector<int>temp(r-l+1); 
        int idx=0; 
        
        int il=l, jl=m+1;

        while(il<=m && jl<=r){
            if(a[il]<=a[jl]){
                temp[idx++]=a[il++];
            }
            else{
                temp[idx++]=a[jl++];
            }
        }

        while(il<=m){
            temp[idx++]=a[il++];
        }
        while(jl<=r){
            temp[idx++]=a[jl++];
        }

        for(int i=l; i<=r; i++){
            a[i]=temp[i-l];
        }
       
    };

    function<void(int,int)> helper = [&](int l, int r)->void{
        if(l<r){
            int mid = (l+r)/2;
            helper(l,mid);
            helper(mid+1,r);
            merge(l,mid,r);
        }
    };

    helper(0,n-1);
    
    return a;

}

vector<int> countingSort(vector<int>& arr) {
    
    vector<int>a(arr);

    // T.C. : O(n+k) , n : number of elements, k: range of elements max-min

    int mn = *min_element(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end());

    int range = mx - mn + 1;

    vector<int> count(range, 0);

    // Count frequencies
    for(int x : a)
        count[x - mn]++;

    // Reconstruct sorted array
    vector<int> ans;

    for(int i = 0; i < range; i++) {
        while(count[i]--) {
            ans.push_back(i + mn);
        }
    }

    return ans;
}

vector<int> heapSort(vector<int>&arr){

   // ascending order 
    
    vector<int>a(arr);
    
    int n = a.size();

    function<void(int,int)> heapify = [&](int n, int i)->void{

        int largest = i;
    
        int left = 2 * i + 1;
        int right = 2 * i + 2;
    
        if(left < n && a[left] > a[largest])
            largest = left;
    
        if(right < n && a[right] > a[largest])
            largest = right;
    
        if(largest != i) {
            swap(a[i], a[largest]);
            heapify(n, largest);
        }
    };

    // Build max heap
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    // Extract maximum one by one
    for(int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);

        // Heap size becomes i
        heapify(i, 0);
    }

    return a; 

}

void printArr(vector<int>&arr){
    for(auto &it: arr){ 
        cout<<it<<" "; 
    }
    cout<<endl;
}
 
int main(){

    vector<int> arr = {2,533,3,2,6,43,5,4,35,33,4,3,54,34,3}; 
    int n = arr.size(); 
     
    // Naive
    vector<int> bubbleSorted = bubbleSort(arr);             printArr(bubbleSorted);
    vector<int> insertionSorted = insertionSort(arr);       printArr(insertionSorted);
    vector<int> selectionSorted = selectionSort(arr);       printArr(selectionSorted); 
    
    // Important
    vector<int> quickSorted = quickSort(arr);               printArr(quickSorted);
    vector<int> mergeSorted = mergeSort(arr);               printArr(mergeSorted);
    vector<int> heapSorted = heapSort(arr);                 printArr(heapSorted);
    
    // Complementry (not a comparision based sorting algorithm)
    vector<int> countingSorted = countingSort(arr);         printArr(countingSorted);
    



    return 0;
}
