Counting Sort : make sorted element - frequency pair 

allot the element in final array 
e.g. 3 5 4 1 1
allot like : 1 1 3 4 5 

algorithm:

int k=maxi(arr); // max. of arr
int count[k+1]; // array to count freq. of element 

for(int i=0;i<n;i++) // freq. count 
count[arr[i]]++;

// logic

for(int i=1;i<k;i++) // to determine index correctly in sorted array 
count[i]=count[i-1]+count[i];

// now count just not have freq. also have no. of element less than or equal to this : this concept help in determining index in O(1) time and overall O(n) allotment time 

int ans[n];
for(int i=n-1;i>=0;i--){
ans[count[arr[i]]-1]=arr[i];
count[arr[i]]--; // for next arr[i] to be in one less postion 
}

return ans;

