📌 Selection Sort – Concept
💡 Idea:
Har pass mein, chhota (minimum) element dhoondo unsorted part se

Usko swap karo uss position ke element ke saath

Socho jaise cricket team se best player dhoond ke sabse aage la rahe ho 😄


class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        // code here
       int n = arr.size();
       
       for (int i = 0; i < n - 1; i++) {
       int minIndex = i;
        for (int j = i + 1; j < n; j++) {
        if (arr[j] < arr[minIndex]) {
            minIndex = j;
            }
        }
    swap(arr[i], arr[minIndex]);
    }
};
