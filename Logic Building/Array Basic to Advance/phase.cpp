Phase 1 – Array Operations

1) Basic Operations

● Access an element at index

int n;
cin>>n;
int arr[n];

for(int i=0;i<n;i++)
{
cin>>arr[i];
}

int ind;
cin>>ind;

if(ind>=0 && ind<n)
{
cout<<arr[ind];
}
else{
cout<<"invalid";
}


● Update an element at index

#include <iostream>
using namespace std;

int main() {
int n;
cin >> n;

```
int arr[n];

for(int i = 0; i < n; i++) {
    cin >> arr[i];
}

int up;
cin >> up;   // fixed

int ind;
cin >> ind;

if(ind >= 0 && ind < n) {
    arr[ind] = up;
} else {
    cout << "Invalid index";
}

for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";   // improved output
}

return 0;
```

}




● Traverse the array
int main() {
int n;
cin >> n;

int arr[n];

// Step 1: Take input
for(int i = 0; i < n; i++) {
    cin >> arr[i];
}

// Step 2: Traverse (print)
for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
}
● Find length of array

int n= arr.size();
int n= arr.length();

int n=sizeof(arr)/sizeof(arr[0]);


2) Insert Operations
● Insert at end

#include <iostream>
using namespace std;

int main() {
int n;
cin >> n;

```
int arr[n];

// Input original array
for(int i = 0; i < n; i++) {
    cin >> arr[i];
}

int ins;
cin >> ins;

// New array of size n+1
int newArr[n + 1];

// Copy old elements
for(int i = 0; i < n; i++) {
    newArr[i] = arr[i];
}

// Insert at end
newArr[n] = ins;

// Print new array
for(int i = 0; i < n + 1; i++) {
    cout << newArr[i] << " ";
}

return 0;
```

}

● Insert at beginning

i#include <iostream>
using namespace std;

int main() {
int n;
cin >> n;

```
int arr[n];

for(int i = 0; i < n; i++) {
    cin >> arr[i];
}

int ins;
cin >> ins;

int newarr[n + 1];

// Shift elements to right
for(int i = n; i > 0; i--) {
    newarr[i] = arr[i - 1];
}

// Insert at beginning
newarr[0] = ins;

// Print array
for(int i = 0; i < n + 1; i++) {
    cout << newarr[i] << " ";
}

return 0;
```

}




● Insert at a given index

#include <iostream>
using namespace std;

int main() {
int n;
cin >> n;

```
int arr[n];

for(int i = 0; i < n; i++) {
    cin >> arr[i];
}

int ind;
cin >> ind;

int ins;
cin >> ins;

int newarr[n + 1];

// Copy elements before index
for(int i = 0; i < ind; i++) {
    newarr[i] = arr[i];
}

// Insert element
newarr[ind] = ins;

// Shift remaining elements
for(int i = ind; i < n; i++) {
    newarr[i + 1] = arr[i];
}

// Print result
for(int i = 0; i < n + 1; i++) {
    cout << newarr[i] << " ";
}

return 0;
```

}



3) Delete Operations
● Delete at end

int n;
cin>>n;
int arr[n];

for(int i=0;i<n;i++)
{
cin>>arr[i];
}

int newarr[n-1];

for(int i=0;i<n-1;i++)
{
newarr[i]=arr[i];
}

for(int i=0;i<n-1;i++)
{
cout<<newarr[i];
}



● Delete at beginning


int n;
cin>>n;
int arr[n];

for(int i=0;i<n;i++)
{
cin>>arr[i];
}

if(n<=1)
{
cout<<"Array become empty";
}

int newarr[n-1];

for(int i=0;i<n-1;i++)
{
newarr[i]=arr[i+1];
}

for(int i=0;i<n-1;i++)
{
cout<<newarr[i];
}

● Delete at a given index

int n;
cin>>n;

int arr[n];

for(int i=0;i<n;i++)
{
cin>>arr[i];
}

int ind;
cin>>ind;

int newarr[n-1];

for(int i=0;i<ind;i++)
{
newarr[i]=arr[i];
}


● Delete by value

int n;
cin>>n;
int N;
cin>>N;
for(int i=0;i<N;i++)
{
if(arr[i]==n)
{
continue;
}
cout<<arr[i]<<" ";
}
}



4) Search Operations
● Linear search
int x;
cin >> x;

bool found = false;

for(int i = 0; i < n; i++)
{
    if(arr[i] == x)
    {
        cout << "Element found at index: " << i;
        found = true;
        break;
    }
}

if(!found)
{
    cout << "Element not found";
}

● Binary search

int start=0;
int last=n-1;
int n;
cin>>n;

while(last>start)
{
int mid= start+(end-start)/2;

if(arr[i]==arr[mid])
{
cout<<arr[mid];
}
else if(arr[i]>arr[mid])
{
start++;
}
else{
end--}
}



5) Sort Operations
● Sort in ascending order

//for Vector

sort(arr.begin(),arr.end());

sort(arr,arr+n);


● Sort in descending order

sort(arr.begin(),arr.end(),greater<int>());
sort(arr, arr + n, greater<int>());
● Sort using custom comparator
✅ Example 1: Sort in Descending (manually)
bool cmp(int a, int b)
{
    return a > b;
}

sort(arr.begin(), arr.end(), cmp);
✅ Example 2: Sort Pairs (by second value)
#include <vector>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b)
{
    return a.second < b.second;
}

sort(v.begin(), v.end(), cmp);

👉 Sorts based on second element of pair

✅ Example 3: If equal, then sort by first
bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}



6) Reverse Operations
● Reverse full array

reverse(arr,arr+n);
reverse(arr.begin(),arr.end());
//Wrong
int start=arr[0];
int end= arr[n-1];

while(start<=end)
{
swap(arr[start],arr[end]);
start++;
end--;
}

//correct
int start = 0;
int end = n - 1;

while(start <= end)
{
    swap(arr[start], arr[end]);
    start++;
    end--;
}

● Reverse a subarray from i to j

while(i < j)
{
    swap(arr[i], arr[j]);
    i++;
    j--;
}

✅ Using STL (Best way)
reverse(arr + i, arr + j + 1);

👉 STL uses:

[start, end)

So always think:

“End is one past the last element”

👉 For vector:

reverse(arr.begin() + i, arr.begin() + j + 1);

● Reverse using the reverse trick
// Step 1
reverse(arr, arr + n);

// Step 2
reverse(arr, arr + k);

// Step 3
reverse(arr + k, arr + n);


7) Rotation Operations


● Rotate right by 1
int temp=arr[0];
int newarr[n];

for(int i=0;i<n-1;i++)
{
newarr[i]=arr[i+1];
}

newarr[n-1]=temp;

for(int i=0;i<n;i++)
{
cout<<arr[i];
}

● Rotate left by 1

int temp=arr[n-1];
int newarr[n];

for(int i=n;i>0;i++)
{
newarr[i]=arr[n-2];
}

newarr[0]=temp;

for(int i=0;i<n;i++)
{
cout<<arr[i];
}

⚡ 3) In-place Rotation (Better – No extra array)
✅ Left Rotate by 1
int temp = arr[0];

for(int i = 0; i < n - 1; i++)
{
    arr[i] = arr[i + 1];
}

arr[n - 1] = temp;
✅ Right Rotate by 1
int temp = arr[n - 1];

for(int i = n - 1; i > 0; i--)
{
    arr[i] = arr[i - 1];
}

arr[0] = temp;

👉 Right rotate by k:

reverse(arr, arr + n);
reverse(arr, arr + k);
reverse(arr + k, arr + n);

👉 Left rotate by k:

reverse(arr, arr + k);
reverse(arr + k, arr + n);
reverse(arr, arr + n);

● Cyclic rotation by 1

//similar to right rotaion by 1 
int temp = arr[n - 1];

for(int i = n - 1; i > 0; i--)
{
    arr[i] = arr[i - 1];
}

arr[0] = temp;

// print
for(int i = 0; i < n; i++)
{
    cout << arr[i] << " ";
}


8) Merge / Split Operations
● Merge two sorted arrays

int i = 0, j = 0;
vector<int> result;

while(i < n && j < m)
{
    if(arr1[i] < arr2[j])
    {
        result.push_back(arr1[i]);
        i++;
    }
    else
    {
        result.push_back(arr2[j]);
        j++;
    }
}

// remaining elements
while(i < n)
{
    result.push_back(arr1[i]);
    i++;
}

while(j < m)
{
    result.push_back(arr2[j]);
    j++;
}

● Merge two unsorted arrays

vector<int> result;

for(int i = 0; i < n; i++)
{
    result.push_back(arr1[i]);
}

for(int i = 0; i < m; i++)
{
    result.push_back(arr2[i]);
}
● Split an array at a given index
vector<int> left, right;

for(int i = 0; i < k; i++)
{
    left.push_back(arr[i]);
}

for(int i = k; i < n; i++)
{
    right.push_back(arr[i]);
}


9) Aggregation Operations
● Find minimum

int ma=INT_MAX;
for(int i=0;i<n;i++)
{
ma= min(ma,arr[i]);
}
cout<<ma;

● Find maximum
int ma=INT_MIN;
for(int i=0;i<n;i++)
{
ma= max(ma,arr[i]);
}
cout<<ma;
● Find sum
int sum=0;
for(int i=0;i<n;i++)
{
sum+=arr[i];
}
cout<<sum;

● Find product

int pro=1;
for(int i=0;i<n;i++)
{
pro*=arr[i];
}
cout<<pro;
● Count occurrences
int x;
cin>>x;

int count =0;

for(int i=0; i<n;i++)
{
if(arr[i]==x)
{
count++;
}
}
cout<<count;

● Build frequency map

unordered_map<int,int>mp;

for(int i=0;i<n;i++)
{
mp[arr[i]]++;
}

//Direct Iteration on the map for find max/min
auto mi = *min_element(arr, arr + n);
auto ma = *max_element(arr, arr + n);
int sum = accumulate(arr, arr + n, 0);




10) Copy Operations
● Shallow copy
● Deep copy
● Copy a subarray
● Copy one array into another manually

📋 1) Shallow Copy
💡 Idea:

👉 Copies reference / address, not actual data

So both variables point to the same memory

⚠️ Example (Pointers)
int arr1[] = {1, 2, 3};
int* arr2 = arr1;   // shallow copy

👉 Now:

Changing arr2[0] will also change arr1[0]
🔴 Problem:
arr2[0] = 100;

Result:

arr1 = [100, 2, 3]
📋 2) Deep Copy
💡 Idea:

👉 Copies actual data into new memory

✅ Example:
int arr1[] = {1, 2, 3};
int arr2[3];

for(int i = 0; i < 3; i++)
{
    arr2[i] = arr1[i];
}

👉 Now both arrays are independent

📋 3) Copy a Subarray

👉 Copy elements from index i to j

✅ Manual Method:
int k = 0;
int sub[100];

for(int x = i; x <= j; x++)
{
    sub[k++] = arr[x];
}
✅ STL Method (Best)
vector<int> sub(arr.begin() + i, arr.begin() + j + 1);

👉 Again j + 1 because of:

[start, end)
📋 4) Copy One Array into Another (Manually)
✅ Code:
for(int i = 0; i < n; i++)
{
    arr2[i] = arr1[i];
}
⚡ STL Shortcuts (Very Important)
✅ Using copy()
#include <algorithm>

copy(arr1, arr1 + n, arr2);
✅ Using vector assignment
vector<int> v2 = v1;

👉 This is deep copy for vectors ✅
