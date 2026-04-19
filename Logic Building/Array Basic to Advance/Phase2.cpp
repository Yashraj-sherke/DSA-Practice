

Phase 2 – Array Foundation Questions


Level 1: Fundamentals

1. Input n and store n integers in an array, then print them.
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
cin>>arr[i];
}

for(int i=0;i<n;i++)
{
cout<<arr[i];
}

2. Find the sum of all elements in an array.

int sum=0;

for(int i=0;i<n;i++)
{
sum+=arr[i];
}
cout<<sum;

3. Find the average of array elements.

int n;
int arr[n];

for(int i=0;i<n;i++)
{
cin>>arr[i];
}

int sum=0;

for(int i=0;i<n;i++)
{
sum+=arr[i];
}


cout<<sum/n;

4. Find the maximum element in an array.
int ma=INT_MIN;
for(int i=0;i<n;i++)
{
ma=max(ma,arr[i]);
}
cout<<ma;
5. Find the minimum element in an array.

int mi=INT_MIN;
for(int i=0;i<n;i++)
{
mi= min(mi,arr[i]);
}
cout<<mi;

6. Count how many elements are positive, negative, or zero.
int  pos=0;
int  neg=0;
int ze=0;

for(int i=0;i<n;i++)
{
if(arr[i]>0)
{
pos++;
}
else if(arr[i]<0)
{
neg++;
}
else{
ze++;
}

}
cout<<pos<<" "<<neg<< " "<<ze;

7. Count how many elements are even and odd.
int ev=0;
int od=0;

for(int i=0;i<n;i++)
{
if(arr[i]%2==0)
{
ev++;
}
else{
od++;
}
}
cout<<ev<<" "<<od;

8. Find the index of the maximum element.

int ma=INT_MIN;
for(int i=0;i<n;i++)
{
ma=max(ma,arr[i]);
}
cout<<i;

9. Find the index of the minimum element.

int ma=INT_MAX;
for(int i=0;i<n;i++)
{
ma=m(ma,arr[i]);
}
cout<<i;

10. Print only those elements that are greater than a given value k.

int k;
cin>>k;

for(int i=0;i<n;i++)
{
if(arr[i]>k)
{
cout<<arr[i]<<" ";
}
}

Level 2: Searching and Counting Logic
11. Check whether a given element exists in the array.

int x;
cin>>x;
bool exist = false;
for(int i=0;i<n;i++)
{
if(arr[i]==x)
{
cout<<i;
exist = true;
break;
}
}
if(!exist)
{
cout<<"element not find";
}

12. Count how many times a given element appears.

int count=0;
int x;
cin>>x;

for(int i=0;i<n;i++)
{
if(arr[i]==x)
{
count++;
}
}
cout<<count;

13. Find the first occurrence of a given number.


int x;
cin>>x;

for(int i=0;i<n;i++)
{
if(arr[i]==x)
{
cout<<i;
break
}
}

14. Find the last occurrence of a given number.

15. Check if all elements in an array are unique.

//Wrong 
unordered_map<int ,int>mp;

for(int i=0;i<n;i++)
{
mp[arr[i]]++;
}

if(arr.second >1)
{
cout<<"Not Unique";

//Correct
bool unique = true;

for(auto it : mp)
{
    if(it.second > 1)
    {
        unique = false;
        break;
    }
}

if(unique) cout << "Unique";
else cout << "Not Unique";

16. Find the sum of even elements only.
int sum=0;
for(int i=0;i<n;i++)
{
if(arr[i]%2==0){
sum+=arr[i];
}
}cout<<sum;
17. Find the sum of odd elements only.

int sum=0;
for(int i=0;i<n;i++)
{
if(arr[i]%2!=0){
sum+=arr[i];
}
}
cout<<sum;

18. Count the prime numbers in the array.


19. Count how many numbers are divisible by both 3 and 5.

int count=0;
for(int i=0;i<n;i++)
{
if(arr[i]%3==0 && arr[i]%5==0){
count++;
}
}
cout<<count;
20. Count how many elements are perfect squares.

 int count = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] >= 0)   // avoid negative numbers
        {
            int root = sqrt(arr[i]);

            if(root * root == arr[i])
            {
                count++;
            }
        }
    }

    return count;


Level 3: Transformation and Manipulation
21. Create a new array containing squares of all numbers.
int n;
cin>>n;

for(int i=0;i<n;i++)
{
cin>>arr[i];
}

int newarr[n];

for(int i=0;i<n;i++)
{
newarr[i]=arr[i]*arr[i];
}

for(int i=0;i<n;i++)
{
cout<<newarr[i];
}

22. Create a new array containing only even elements.

int n;
cin>>n;

for(int i=0;i<n;i++)
{
cin>>arr[i];
}

int newarr[n];

for(int i=0;i<n;i++)
{
if(arr[i]%2==0)
{
newarr[i]=arr[i];
}
}

//correct 
✅ Correct Approach:
int k = 0;
for(int i=0;i<n;i++)
{
    if(arr[i]%2==0)
    {
        newarr[k++] = arr[i];
    }
}
🧠 Intuition:

Filtering = use separate index (k)

for(int i=0;i<n;i++)
{
cout<<newarr[i];
}


23. Replace every negative number with 0.

int n;
cin>>n;

for(int i=0;i<n;i++)
{
cin>>arr[i];
}

for(int i=0;i<n;i++)
{
if(arr[i]<0)
{
arr[i]=0;
}
}

for(int i=0;i<n;i++)
{
cout<<arr[i];
}





24. Replace all even numbers with 1 and all odd numbers with 0.

int n;
cin>>n;

for(int i=0;i<n;i++)
{
cin>>arr[i];
}

for(int i=0;i<n;i++){
if(arr[i]%2==0)
{
arr[i]=1;
}
else{
arr[i]=0;
}
}
for(int i=0;i<n;i++)
{
cout<<arr[i];
}

25. Swap the first and last elements of the array.

int n;
cin>>n;

for(int i=0;i<n;i++)
{
cin>>arr[i];
}

int first = arr[0];
int last = arr[n-1];


swap(first,last);

for(int i=0;i<n;i++)
{
cout<<arr[i];
}

26. Reverse an array without using built-in reverse.

int n;
cin>>n;

for(int i=0;i<n;i++)
{
cin>>arr[i];
}

int first= arr[0];
int last= arr[n-1];

while(start<= last)
{
swap(first,last);
start++;
last++;
}

for(int i=0;i<n;i++)
{
cout<<arr[i];
}

27. Rotate an array by one position to the left.

int n;
cin>>n;

for(int i=0;i<n;i++)
{
cin>>arr[i];
}
28. Rotate an array by one position to the right.

int n;
cin>>n;

for(int i=0;i<n;i++)
{
cin>>arr[i];
}
29. Swap alternate elements.

int n;
cin>>n;

for(int i=0;i<n;i++)
{
cin>>arr[i];
}

for(int i=0;i<n-1;i=i+2)
{
swap(arr[i],arr[i+1]);
}

for(int i=0;i<n;i++)
{
cout<<arr[i];
}
30. Copy one array into another manually.

int n;
cin>>n;

for(int i=0;i<n;i++)
{
cin>>arr[i];
}

int newarr[n];

for(int i=0;i<n;i++)
{
newarr[i]=arr[i];
}

for(int i=0;i<n;i++)
{
cout<<newarr[i];
}



Level 4: Aggregate and Comparative Thinking
31. Compare two arrays and check if they are equal in both order and elements.
int n;
cin>>n;
for(int i=0;i<n;i++)
{
cin>>arr[i];
}

int m;
cin>>m;
for(int i=0i<m;i++)
{
cin>>arr[i];
}

if(n != m) → not equal

bool equal = true;

for(int i=0;i<n;i++)
{
    if(arr1[i] != arr2[i])
    {
        equal = false;
        break;
    }
}


32. Compare two arrays and check if they contain the same elements ignoring order.

33. Merge two arrays into a third array.
34. Find the common elements between two arrays.
35. Find elements that are present in one array but not in the other.
36. Count how many elements are common between two arrays.
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        if(arr1[i] == arr2[j])
        {
            count++;
            break;
        }
    }
}

37. Find element-wise sum of two arrays.
for(int i=0;i<n;i++)
{
cout << arr1[i] + arr2[i] << " ";

}

38. Find element-wise product of two arrays.
for(int i=0;i<n;i++)
{
cout<<arr1[i]*arr2[i]<<" ";
}
39. Create a frequency array of numbers.
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
cout<<arr[i];
}

int freq[100] = {0};

for(int i=0;i<n;i++)
{
    freq[arr[i]]++;
}

for(int i=0;i<n;i++)
{
cout<<freq[i];
}

40. Print all elements that appear more than once.


Level 5: Logical and Applied Array Problems
41. Check if the array is sorted in ascending order.
int n;
cin>>n;
for(int i=0;i<n-1;i++)
{
cin>>arr[i];
}

bool sorted = true;

for(int i=0;i<n-1;i++)
{
    if(arr[i] > arr[i+1])
    {
        sorted = false;
        break;
    }
}



42. Check if the array is sorted in descending order.
int n;
cin>>n;
for(int i=0;i<n-1;i++)
{
cin>>arr[i];
}

bool check = false;
for(int i=0;i<n;i++)
{
if(arr[i]>arr[i+1])
{
check= true;
}
}

if(!check)
{
cout<<"Array is not sorted";
}

43. Find the second largest element in an array.
int n;
cin>>>n;
for(int i=0;i<n;i++)
{
cin>>arr[i];
}

int largest = INT_MIN, second = INT_MIN;

for(int i=0;i<n;i++)
{
    if(arr[i] > largest)
    {
        second = largest;
        largest = arr[i];
    }
    else if(arr[i] > second && arr[i] != largest)
    {
        second = arr[i];
    }
};

44. Find the second smallest element in an array.

45. Find the difference between the largest and smallest element.

int n;
cin>>>n;
for(int i=0;i<n;i++)
{
cin>>arr[i];
}
//Wrong 
int la=INT_MIN;
int sn=INT_MAX;

for(int i=0;i<n;i++)
{
if(arr[i]>la)
{
la=arr[i];
}
}

for(int i=0;i<n;i++)
{
if(arr[i]<sm)
{
sm= arr[i];
}
}

cout<<la-sm;
//correct
int min = INT_MAX, max = INT_MIN;

for(int i=0;i<n;i++)
{
    if(arr[i] < min) min = arr[i];
    if(arr[i] > max) max = arr[i];
}

cout << max - min;

46. Find the sum of all elements except the largest and smallest.

int n;
cin>>>n;
for(int i=0;i<n;i++)
{
cin>>arr[i];
}

int la=INT_MIN;
int sn=INT_MAX;

for(int i=0;i<n;i++)
{
if(arr[i]>la)
{
la=arr[i];
}
}

for(int i=0;i<n;i++)
{
if(arr[i]<sm)
{
sm= arr[i];
}
int sum=0;
for(int i=0;i<n;i++)
{
if(arr[i]!=la && arr[i]!=sm)
{
sum+=arr[i];
}
}
cout<<sum;

47. Count how many pairs of elements have a sum equal to a given number k.

int n,k;
cin>>>n>>k;
for(int i=0;i<n;i++)
{
cin>>arr[i];
}
int count=0;
for(int i=0;i<n-1;i++)
{
for(int j=i+1;j<n;j++)
{
if(arr[i]+arr[j]==k)
{
count++;
}
}
}
cout<<count;

48. Count how many elements are greater than the average of the array.

int n,k;
cin>>>n>>k;
for(int i=0;i<n;i++)
{
cin>>arr[i];
}
int sum=0;
for(int i=0;i<n;i++)
{
sum+=arr[i];
}

int avg= (double)sum/n;

int count=0;

for(int i=0;i<n;i++)
{
if(arr[i]>avg)
{
count++;
}
}
cout<<count;

49. Print the frequency of each distinct element.
unordered_map<int,int>mp;

for(int i=0;i<n;i++)
{
mp[arr[i]]++;
}

for(auto it:mp)
{
cout<<mp.second<<" ";
}

50. Print all unique elements that occur exactly once.

unordered_map<int,int>mp;

for(int i=0;i<n;i++)
{
mp[arr[i]]++;
}

for(auto it:mp)
{
if(mp.second==1)
cout<<mp.first<<" ";
}

