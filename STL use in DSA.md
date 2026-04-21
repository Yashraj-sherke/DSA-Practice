


# C++ COMPLETE REFERENCE FOR TCS NQT CODING
## From Scratch to Submit — Everything You Need to Know

---

<br>

## 📋 TABLE OF CONTENTS

| # | Section | Jump |
|---|---------|------|
| 1 | Headers & Basic Setup | [→ Section 1](#-section-1-headers--basic-setup) |
| 2 | Input/Output Patterns | [→ Section 2](#-section-2-inputoutput-patterns) |
| 3 | String Functions & Operations | [→ Section 3](#-section-3-string-functions--operations) |
| 4 | Character Functions | [→ Section 4](#-section-4-character-functions) |
| 5 | Type Conversions | [→ Section 5](#-section-5-type-conversions) |
| 6 | Vector Operations | [→ Section 6](#-section-6-vector-operations-essential-stl) |
| 7 | Set & Map Operations | [→ Section 7](#-section-7-set--map-operations) |
| 8 | Array Operations | [→ Section 8](#-section-8-array-operations) |
| 9 | Math Functions | [→ Section 9](#-section-9-math-functions) |
| 10 | Common Patterns & Idioms | [→ Section 10](#-section-10-common-patterns--idioms) |
| 11 | Edge Cases to Remember | [→ Section 11](#-section-11-edge-cases-to-remember) |
| 12 | Quick Reference Table | [→ Section 12](#-section-12-quick-reference-table) |

---

<br>

## ✅ SECTION 1: HEADERS & BASIC SETUP

### What to Include at Top of Every Program:

```cpp
// Option 1: Include everything (RECOMMENDED for exams)
#include <bits/stdc++.h>
using namespace std;

// Option 2: Include specific headers (more professional)
#include <iostream>      // cin, cout
#include <string>        // string class
#include <vector>        // vector
#include <algorithm>     // sort, reverse, etc.
#include <set>           // set
#include <map>           // map
#include <unordered_map> // unordered_map
#include <cmath>         // sqrt, pow, abs
#include <cctype>        // isalpha, tolower, etc.
using namespace std;
```

> **For TCS NQT: Use Option 1** — saves time! ✅

### Basic Program Structure:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Your code here
    
    return 0;
}
```

---

<br>

## ✅ SECTION 2: INPUT/OUTPUT PATTERNS

### 2.1 Single Number Input

```cpp
// Method 1: Using cin
int n;
cin >> n;                    // Read one integer

// Method 2: Long long for large numbers
long long n;
cin >> n;

// Example:
int a, b, c;
cin >> a >> b >> c;         // Read 3 integers from same/different lines
```

---

### 2.2 Single String Input

```cpp
// Method 1: Single word (no spaces)
string s;
cin >> s;                    // Reads until space/newline

// Method 2: Full line (with spaces)
string s;
getline(cin, s);            // Reads entire line including spaces

// IMPORTANT: After reading number, use this before getline
int n;
cin >> n;
cin.ignore();               // Clear newline left in buffer
getline(cin, s);           // Now reads full line correctly
```

**Example:**
```cpp
// Input: "hello world"
string s;
cin >> s;                   // s = "hello" only
getline(cin, s);           // s = "hello world" (full line)
```

---

### 2.3 Array Input (Fixed Size)

```cpp
// Method 1: Using array
int n;
cin >> n;                   // Size of array
int arr[n];
for(int i = 0; i < n; i++) {
    cin >> arr[i];
}

// Method 2: Using vector (BETTER!)
int n;
cin >> n;
vector<int> arr(n);
for(int i = 0; i < n; i++) {
    cin >> arr[i];
}   

// Method 3: Direct push_back
int n;
cin >> n;
vector<int> arr;
for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
}
```

**Example Input:**
```
5
10 20 30 40 50
```

**Code:**
```cpp
int n;
cin >> n;                   // n = 5
vector<int> arr(n);
for(int i = 0; i < n; i++) {
    cin >> arr[i];          // arr = [10, 20, 30, 40, 50]
}
```

---

### 2.4 Array Input (Each Element on New Line)

```cpp
// Very common in TCS NQT!
int n;
cin >> n;
vector<int> arr;
for(int i = 0; i < n; i++) {
    int x;
    cin >> x;               // Reads from new line each time
    arr.push_back(x);
}
```

**Example Input:**
```
5
10
20
30
40
50
```

---

### 2.5 2D Array Input

```cpp
// Input: rows and columns, then matrix
int rows, cols;
cin >> rows >> cols;

vector<vector<int>> matrix(rows, vector<int>(cols));

for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
        cin >> matrix[i][j];
    }
}
```

**Example Input:**
```
3 3
1 2 3
4 5 6
7 8 9
```

---

### 2.6 String Array Input

```cpp
// Multiple strings (no spaces in each string)
int n;
cin >> n;
vector<string> arr(n);
for(int i = 0; i < n; i++) {
    cin >> arr[i];
}

// Multiple strings with spaces (full lines)
int n;
cin >> n;
cin.ignore();               // Clear buffer after reading n
vector<string> arr;
for(int i = 0; i < n; i++) {
    string s;
    getline(cin, s);
    arr.push_back(s);
}
```

---

### 2.7 Character Input

```cpp
// Single character
char ch;
cin >> ch;

// Array of characters
int n;
cin >> n;
vector<char> arr(n);
for(int i = 0; i < n; i++) {
    cin >> arr[i];
}
```

---

### 2.8 Mixed Input (Number then String)

```cpp
// TRICKY: Number followed by string with spaces
int n;
string s;
cin >> n;
cin.ignore();               // MUST DO THIS!
getline(cin, s);

// Example:
// Input:
// 5
// hello world
// 
// Without cin.ignore():     Fails! ❌
// With cin.ignore():        Works! ✅
```

---

### 2.9 OUTPUT PATTERNS

```cpp
// Single number
cout << n << endl;         // Print and newline

// Multiple numbers on same line
cout << a << " " << b << " " << c << endl;

// Array on same line with spaces
for(int i = 0; i < arr.size(); i++) {
    cout << arr[i];
    if(i < arr.size() - 1) cout << " ";  // Space between elements
}
cout << endl;

// Array on separate lines
for(int i = 0; i < arr.size(); i++) {
    cout << arr[i] << endl;
}

// String output
cout << s << endl;

// No space at end
for(int x : arr) {
    cout << x << endl;      // Each on new line
}
```

**Common OUTPUT Formats in TCS NQT:**
```cpp
// Format 1: Space-separated
// Output: 10 20 30 40 50
for(int i = 0; i < arr.size(); i++) {
    if(i > 0) cout << " ";
    cout << arr[i];
}
cout << endl;

// Format 2: Newline-separated
// Output:
// 10
// 20
// 30
for(int x : arr) {
    cout << x << endl;
}
```

---

<br>

## ✅ SECTION 3: STRING FUNCTIONS & OPERATIONS

### 3.1 String Basics

```cpp
string s = "hello";

// Length
int len = s.length();       // 5
int len = s.size();         // 5 (same as length)

// Access characters
char first = s[0];          // 'h'
char last = s[s.length()-1]; // 'o'

// Empty check
if(s.empty()) {             // Returns true if empty
    cout << "Empty string";
}

// Clear string
s.clear();                  // Makes string empty
```

---

### 3.2 String Input/Output

```cpp
// Single word
string s;
cin >> s;                   // "hello" (stops at space)

// Full line with spaces
string s;
getline(cin, s);           // "hello world"

// Output
cout << s << endl;
```

---

### 3.3 String Concatenation

```cpp
string s1 = "hello";
string s2 = "world";

// Method 1: Using +
string s3 = s1 + " " + s2;  // "hello world"

// Method 2: Using +=
s1 += " ";
s1 += s2;                   // s1 = "hello world"

// Append character
s1 += 'x';                  // s1 = "hello worldx"
s1.push_back('y');          // s1 = "hello worldxy"
```

---

### 3.4 String Traversal

```cpp
string s = "hello";

// Method 1: Index-based
for(int i = 0; i < s.length(); i++) {
    cout << s[i] << " ";    // h e l l o
}

// Method 2: Range-based (EASIER!)
for(char c : s) {
    cout << c << " ";       // h e l l o
}

// Method 3: Iterator
for(auto it = s.begin(); it != s.end(); it++) {
    cout << *it << " ";
}
```

---

### 3.5 String Comparison

```cpp
string s1 = "abc";
string s2 = "xyz";

if(s1 == s2)                // Equal
if(s1 != s2)                // Not equal
if(s1 < s2)                 // Lexicographically smaller
if(s1 > s2)                 // Lexicographically larger
```

---

### 3.6 Substring

```cpp
string s = "hello world";

// Extract substring
string sub = s.substr(0, 5);     // "hello" (start=0, length=5)
string sub = s.substr(6);        // "world" (from index 6 to end)
string sub = s.substr(6, 3);     // "wor" (start=6, length=3)

// Find character/substring
int pos = s.find('w');           // 6 (index of 'w')
int pos = s.find("world");       // 6 (index where "world" starts)
if(pos == string::npos) {        // Not found
    cout << "Not found";
}
```

---

### 3.7 String Reversal

```cpp
string s = "hello";

// Method 1: Using reverse() ✅ BEST
reverse(s.begin(), s.end());     // s = "olleh"

// Method 2: Manual
string rev = "";
for(int i = s.length()-1; i >= 0; i--) {
    rev += s[i];
}

// Method 3: Two pointers
int left = 0, right = s.length()-1;
while(left < right) {
    swap(s[left], s[right]);
    left++;
    right--;
}
```

---

### 3.8 Character-wise Operations

```cpp
string s = "hello";

// Convert to uppercase
for(int i = 0; i < s.length(); i++) {
    s[i] = toupper(s[i]);        // HELLO
}

// Convert to lowercase
for(int i = 0; i < s.length(); i++) {
    s[i] = tolower(s[i]);        // hello
}

// Using transform (FASTER!)
transform(s.begin(), s.end(), s.begin(), ::toupper);  // HELLO
transform(s.begin(), s.end(), s.begin(), ::tolower);  // hello
```

---

### 3.9 Sorting String

```cpp
string s = "dcba";
sort(s.begin(), s.end());        // s = "abcd"

// Reverse sort
sort(s.begin(), s.end(), greater<char>());  // s = "dcba"
```

---

### 3.10 Removing Characters

```cpp
string s = "hello world";

// Remove specific character
s.erase(remove(s.begin(), s.end(), 'l'), s.end());  // "heo word"

// Remove spaces
s.erase(remove(s.begin(), s.end(), ' '), s.end());  // "helloworld"

// Remove at specific position
s.erase(2, 3);                   // Remove 3 chars starting from index 2
```

---

### 3.11 String to Character Array

```cpp
string s = "hello";

// Method 1: Iterate
for(int i = 0; i < s.length(); i++) {
    char c = s[i];
}

// Method 2: c_str() (for C-style functions)
const char* cstr = s.c_str();
```

---

### 3.12 Character Frequency in String

```cpp
string s = "hello";

// Method 1: Using map
map<char, int> freq;
for(char c : s) {
    freq[c]++;
}
// freq['h'] = 1, freq['e'] = 1, freq['l'] = 2, freq['o'] = 1

// Method 2: Using array (for a-z only)
int count[26] = {0};
for(char c : s) {
    count[c - 'a']++;
}
// count[7] = 1 (h), count[4] = 1 (e), count[11] = 2 (l), count[14] = 1 (o)

// Print frequency
for(auto p : freq) {
    cout << p.first << ": " << p.second << endl;
}
```

---

<br>

## ✅ SECTION 4: CHARACTER FUNCTIONS

### 4.1 Character Type Checking

```cpp
char c = 'A';

// Check if alphabetic (a-z, A-Z)
if(isalpha(c))              // true for 'A', 'a', false for '1', '@'

// Check if digit (0-9)
if(isdigit(c))              // true for '0'-'9', false for 'A'

// Check if alphanumeric (a-z, A-Z, 0-9)
if(isalnum(c))              // true for 'A', '5', false for '@'

// Check if uppercase
if(isupper(c))              // true for 'A', false for 'a'

// Check if lowercase
if(islower(c))              // true for 'a', false for 'A'

// Check if space
if(isspace(c))              // true for ' ', '\t', '\n'

// Check if punctuation
if(ispunct(c))              // true for '.', ',', '!', etc.
```

**Complete Example:**
```cpp
string s = "Hello123!";
for(char c : s) {
    if(isalpha(c)) cout << c << " is alphabet\n";
    if(isdigit(c)) cout << c << " is digit\n";
    if(ispunct(c)) cout << c << " is punctuation\n";
}
// Output:
// H is alphabet
// e is alphabet
// ...
// 1 is digit
// 2 is digit
// 3 is digit
// ! is punctuation
```

---

### 4.2 Character Conversion

```cpp
char c = 'A';

// Convert to lowercase
char lower = tolower(c);     // 'a'

// Convert to uppercase
char upper = toupper(c);     // 'A'

// Examples:
// tolower('A') = 'a'
// tolower('a') = 'a' (no change)
// tolower('1') = '1' (no change)

// toupper('a') = 'A'
// toupper('A') = 'A' (no change)
// toupper('1') = '1' (no change)
```

---

### 4.3 Character to/from ASCII

```cpp
char c = 'A';

// Character to ASCII value
int ascii = (int)c;          // 65
int ascii = c;               // 65 (implicit conversion)

// ASCII to character
int ascii = 65;
char c = (char)ascii;        // 'A'
char c = ascii;              // 'A' (implicit conversion)

// Common ASCII values:
// 'A' = 65, 'Z' = 90
// 'a' = 97, 'z' = 122
// '0' = 48, '9' = 57
// 'A' to 'a' difference = 32
```

**Examples:**
```cpp
char c = 'A';
c = c + 32;                  // 'a' (uppercase to lowercase)
c = c - 32;                  // 'A' (lowercase to uppercase)

// Better way (use tolower/toupper)
```

---

<br>

## ✅ SECTION 5: TYPE CONVERSIONS

### 5.1 Integer ↔ String

```cpp
// Integer to String
int n = 123;
string s = to_string(n);     // s = "123"

// String to Integer
string s = "123";
int n = stoi(s);             // n = 123

// String to Long Long
string s = "123456789";
long long n = stoll(s);      // For large numbers

// String to Double
string s = "3.14";
double d = stod(s);          // d = 3.14
```

**Examples:**
```cpp
int a = 100, b = 200;
string result = to_string(a) + to_string(b);  // "100200"

string s = "999";
int n = stoi(s) + 1;         // 1000
```

---

### 5.2 Character ↔ Integer (Digit)

```cpp
// Character digit to integer
char c = '5';
int n = c - '0';             // 5 ✅ IMPORTANT!

// Integer (0-9) to character digit
int n = 7;
char c = n + '0';            // '7' ✅ IMPORTANT!

// Examples:
// '0' - '0' = 0
// '1' - '0' = 1
// '5' - '0' = 5
// '9' - '0' = 9

// 0 + '0' = '0'
// 5 + '0' = '5'
// 9 + '0' = '9'
```

**Why this works:**
```cpp
// '0' has ASCII value 48
// '1' has ASCII value 49
// '2' has ASCII value 50
// ...
// '9' has ASCII value 57

// So: '5' - '0' = 53 - 48 = 5 ✅
// And: 5 + '0' = 5 + 48 = 53 = '5' ✅
```

---

### 5.3 Character ↔ Integer (Letter Position)

```cpp
// Uppercase letter to position (A=0, B=1, ..., Z=25)
char c = 'C';
int pos = c - 'A';           // 2

// Position to uppercase letter
int pos = 2;
char c = pos + 'A';          // 'C'

// Lowercase letter to position (a=0, b=1, ..., z=25)
char c = 'c';
int pos = c - 'a';           // 2

// Position to lowercase letter
int pos = 2;
char c = pos + 'a';          // 'c'
```

**Examples:**
```cpp
// 'A' - 'A' = 0  (position of A)
// 'B' - 'A' = 1  (position of B)
// 'Z' - 'A' = 25 (position of Z)

// 0 + 'A' = 'A'
// 1 + 'A' = 'B'
// 25 + 'A' = 'Z'
```

---

### 5.4 String ↔ Character Array

```cpp
// String to char array
string s = "hello";
for(int i = 0; i < s.length(); i++) {
    char c = s[i];
}

// Char array to string
char arr[] = {'h', 'e', 'l', 'l', 'o', '\0'};
string s = arr;              // s = "hello"

// Or build from characters
string s = "";
s += 'h';
s += 'e';
s += 'l';
s += 'l';
s += 'o';                    // s = "hello"
```

---

### 5.5 Number ↔ Digits

```cpp
// Extract digits from number
int n = 12345;
vector<int> digits;
while(n > 0) {
    int digit = n % 10;      // Last digit
    digits.push_back(digit);
    n /= 10;
}
reverse(digits.begin(), digits.end());  // [1,2,3,4,5]

// Build number from digits
vector<int> digits = {1, 2, 3, 4, 5};
int n = 0;
for(int d : digits) {
    n = n * 10 + d;          // n = 12345
}
```

---

### 5.6 Boolean ↔ Integer

```cpp
// Boolean to integer
bool b = true;
int n = b;                   // 1
bool b = false;
int n = b;                   // 0

// Integer to boolean
int n = 5;
bool b = n;                  // true (any non-zero)
int n = 0;
bool b = n;                  // false
```

---

<br>

## ✅ SECTION 6: VECTOR OPERATIONS (Essential STL)

### 6.1 Vector Basics

```cpp
#include <vector>

// Declaration
vector<int> v;               // Empty vector
vector<int> v(5);            // Size 5, all elements = 0
vector<int> v(5, 10);        // Size 5, all elements = 10
vector<int> v = {1,2,3,4,5}; // Initialize with values

// Size
int size = v.size();

// Check if empty
if(v.empty()) { }

// Clear all elements
v.clear();
```

---

### 6.2 Adding Elements

```cpp
vector<int> v;

// Add at end
v.push_back(10);             // v = [10]
v.push_back(20);             // v = [10, 20]
v.push_back(30);             // v = [10, 20, 30]

// Add at specific position
v.insert(v.begin() + 1, 15); // v = [10, 15, 20, 30]
```

---

### 6.3 Accessing Elements

```cpp
vector<int> v = {10, 20, 30, 40, 50};

// By index
int first = v[0];            // 10
int last = v[v.size()-1];    // 50
int second = v[1];           // 20

// Using at() (safer, checks bounds)
int first = v.at(0);         // 10

// Front and back
int first = v.front();       // 10
int last = v.back();         // 50
```

---

### 6.4 Removing Elements

```cpp
vector<int> v = {10, 20, 30, 40, 50};

// Remove last element
v.pop_back();                // v = [10, 20, 30, 40]

// Remove at specific position
v.erase(v.begin() + 1);      // v = [10, 30, 40] (removed 20)

// Remove range
v.erase(v.begin(), v.begin()+2);  // Remove first 2 elements

// Remove all occurrences of a value
v.erase(remove(v.begin(), v.end(), 30), v.end());  // Remove all 30s
```

---

### 6.5 Sorting Vector

```cpp
vector<int> v = {30, 10, 50, 20, 40};

// Ascending order
sort(v.begin(), v.end());    // v = [10, 20, 30, 40, 50]

// Descending order
sort(v.begin(), v.end(), greater<int>());  // v = [50, 40, 30, 20, 10]
```

---

### 6.6 Reversing Vector

```cpp
vector<int> v = {1, 2, 3, 4, 5};
reverse(v.begin(), v.end()); // v = [5, 4, 3, 2, 1]
```

---

### 6.7 Searching in Vector

```cpp
vector<int> v = {10, 20, 30, 40, 50};

// Find element
auto it = find(v.begin(), v.end(), 30);
if(it != v.end()) {
    cout << "Found at index: " << (it - v.begin());  // 2
} else {
    cout << "Not found";
}

// Count occurrences
int cnt = count(v.begin(), v.end(), 30);  // Number of times 30 appears

// Binary search (only on sorted vector)
sort(v.begin(), v.end());
bool found = binary_search(v.begin(), v.end(), 30);  // true/false
```

---

### 6.8 Vector Traversal

```cpp
vector<int> v = {10, 20, 30, 40, 50};

// Method 1: Index-based
for(int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
}

// Method 2: Range-based (EASIEST!)
for(int x : v) {
    cout << x << " ";
}

// Method 3: Iterator
for(auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
}
```

---

### 6.9 Min/Max in Vector

```cpp
vector<int> v = {30, 10, 50, 20, 40};

// Find minimum
int minVal = *min_element(v.begin(), v.end());  // 10

// Find maximum
int maxVal = *max_element(v.begin(), v.end());  // 50

// Find index of min
auto minIt = min_element(v.begin(), v.end());
int minIndex = minIt - v.begin();     // Index of minimum

// Find index of max
auto maxIt = max_element(v.begin(), v.end());
int maxIndex = maxIt - v.begin();     // Index of maximum
```

---

### 6.10 Sum of Vector

```cpp
vector<int> v = {10, 20, 30, 40, 50};

// Using accumulate
int sum = accumulate(v.begin(), v.end(), 0);  // 150

// Manual
int sum = 0;
for(int x : v) {
    sum += x;
}
```

---

### 6.11 Unique Elements (Remove Duplicates)

```cpp
vector<int> v = {10, 20, 10, 30, 20, 40};

// Method 1: Sort then unique
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
// v = [10, 20, 30, 40]

// Method 2: Using set (maintains order of first occurrence)
vector<int> v = {10, 20, 10, 30, 20, 40};
set<int> s;
vector<int> result;
for(int x : v) {
    if(s.find(x) == s.end()) {
        result.push_back(x);
        s.insert(x);
    }
}
// result = [10, 20, 30, 40]
```

---

<br>

## ✅ SECTION 7: SET & MAP OPERATIONS

### 7.1 Set (Stores Unique Elements, Sorted)

```cpp
#include <set>

// Declaration
set<int> s;

// Insert elements
s.insert(10);
s.insert(20);
s.insert(10);                // Duplicate, won't be added
// s = {10, 20} (automatically sorted)

// Check if element exists
if(s.find(10) != s.end()) {
    cout << "Found";
}

// Count occurrences (always 0 or 1 for set)
if(s.count(10) > 0) {
    cout << "Exists";
}

// Remove element
s.erase(10);                 // s = {20}

// Size
int size = s.size();

// Clear
s.clear();

// Traversal
for(int x : s) {
    cout << x << " ";
}
```

---

### 7.2 Unordered Set (Faster, Not Sorted)

```cpp
#include <unordered_set>

unordered_set<int> s;
s.insert(10);
s.insert(20);
s.insert(10);                // Duplicate ignored
// s = {10, 20} or {20, 10} (no specific order)

// Same operations as set
if(s.find(10) != s.end()) { }
s.erase(10);
```

**When to use:**
- `set`: Need sorted elements
- `unordered_set`: Just need uniqueness, faster ✅

---

### 7.3 Map (Key-Value Pairs)

```cpp
#include <map>

// Declaration
map<string, int> m;

// Insert/Update
m["apple"] = 5;
m["banana"] = 3;
m["apple"] = 10;             // Updates value
// m = {{"apple", 10}, {"banana", 3}}

// Access
int val = m["apple"];        // 10
if(m.find("apple") != m.end()) {
    cout << "Found";
}

// Check if key exists
if(m.count("apple") > 0) {
    cout << "Exists";
}

// Remove
m.erase("apple");

// Traversal
for(auto p : m) {
    cout << p.first << ": " << p.second << endl;
}
// Output:
// apple: 10
// banana: 3
```

---

### 7.4 Unordered Map (Faster)

```cpp
#include <unordered_map>

unordered_map<string, int> m;
m["apple"] = 5;
// Same operations as map, but faster and unordered
```

---

### 7.5 Frequency Counting (Common Pattern!)

```cpp
// Count frequency of array elements
vector<int> arr = {1, 2, 2, 3, 3, 3, 4};

map<int, int> freq;
for(int x : arr) {
    freq[x]++;
}
// freq = {{1,1}, {2,2}, {3,3}, {4,1}}

// Print frequency
for(auto p : freq) {
    cout << p.first << " appears " << p.second << " times\n";
}

// Count frequency of characters in string
string s = "hello";
map<char, int> freq;
for(char c : s) {
    freq[c]++;
}
// freq = {{'e',1}, {'h',1}, {'l',2}, {'o',1}}
```

---

### 7.6 Check for Duplicates

```cpp
vector<int> arr = {1, 2, 3, 4, 2, 5};

// Method 1: Using set
set<int> s;
bool hasDuplicate = false;
for(int x : arr) {
    if(s.find(x) != s.end()) {
        hasDuplicate = true;
        break;
    }
    s.insert(x);
}

// Method 2: Using map
map<int, int> freq;
for(int x : arr) {
    freq[x]++;
}
for(auto p : freq) {
    if(p.second > 1) {
        cout << p.first << " is duplicate\n";
    }
}
```

---

<br>

## ✅ SECTION 8: ARRAY OPERATIONS

### 8.1 Sorting

```cpp
vector<int> arr = {30, 10, 50, 20, 40};

// Ascending
sort(arr.begin(), arr.end());           // [10, 20, 30, 40, 50]

// Descending
sort(arr.begin(), arr.end(), greater<int>());  // [50, 40, 30, 20, 10]

// Sort specific range
sort(arr.begin(), arr.begin()+3);       // Sort first 3 elements

// For regular arrays
int arr[] = {30, 10, 50, 20, 40};
int n = 5;
sort(arr, arr + n);                     // Ascending
```

---

### 8.2 Finding Min/Max

```cpp
vector<int> arr = {30, 10, 50, 20, 40};

// Minimum
int minVal = *min_element(arr.begin(), arr.end());  // 10

// Maximum
int maxVal = *max_element(arr.begin(), arr.end());  // 50

// Manual
int minVal = arr[0], maxVal = arr[0];
for(int x : arr) {
    minVal = min(minVal, x);
    maxVal = max(maxVal, x);
}
```

---

### 8.3 Second Largest

```cpp
vector<int> arr = {30, 10, 50, 20, 40};

// Method 1: Sort and pick
sort(arr.begin(), arr.end());
int secondLargest = arr[arr.size()-2];  // 40

// Method 2: Remove duplicates first
set<int> s(arr.begin(), arr.end());
vector<int> unique(s.begin(), s.end());
sort(unique.begin(), unique.end());
int secondLargest = unique[unique.size()-2];

// Method 3: One pass (most efficient)
int first = INT_MIN, second = INT_MIN;
for(int x : arr) {
    if(x > first) {
        second = first;
        first = x;
    } else if(x > second && x != first) {
        second = x;
    }
}
// second = 40
```

---

### 8.4 Reverse Array

```cpp
vector<int> arr = {10, 20, 30, 40, 50};
reverse(arr.begin(), arr.end());        // [50, 40, 30, 20, 10]
```

---

### 8.5 Count Even/Odd

```cpp
vector<int> arr = {10, 15, 20, 25, 30};

int evenCount = 0, oddCount = 0;
for(int x : arr) {
    if(x % 2 == 0) evenCount++;
    else oddCount++;
}
// evenCount = 3, oddCount = 2
```

---

### 8.6 Sum and Average

```cpp
vector<int> arr = {10, 20, 30, 40, 50};

// Sum
int sum = accumulate(arr.begin(), arr.end(), 0);  // 150

// Average
double avg = (double)sum / arr.size();  // 30.0
```

---

### 8.7 Filter Even/Odd

```cpp
vector<int> arr = {10, 15, 20, 25, 30};

vector<int> even, odd;
for(int x : arr) {
    if(x % 2 == 0) even.push_back(x);
    else odd.push_back(x);
}
// even = [10, 20, 30]
// odd = [15, 25]
```

---

<br>

## ✅ SECTION 9: MATH FUNCTIONS

### 9.1 Basic Math

```cpp
#include <cmath>

// Absolute value
int a = abs(-5);             // 5
double a = fabs(-5.5);       // 5.5

// Power
double result = pow(2, 3);   // 8.0 (2^3)
double result = pow(5, 2);   // 25.0

// Square root
double result = sqrt(25);    // 5.0
double result = sqrt(2);     // 1.414...

// Ceiling (round up)
double result = ceil(3.2);   // 4.0
double result = ceil(3.9);   // 4.0

// Floor (round down)
double result = floor(3.2);  // 3.0
double result = floor(3.9);  // 3.0

// Round (nearest integer)
double result = round(3.2);  // 3.0
double result = round(3.5);  // 4.0
double result = round(3.9);  // 4.0
```

---

### 9.2 Min/Max

```cpp
// Minimum of two
int minVal = min(10, 20);    // 10

// Maximum of two
int maxVal = max(10, 20);    // 20

// Min of three
int minVal = min({10, 20, 5});  // 5

// Max of three
int maxVal = max({10, 20, 5});  // 20
```

---

### 9.3 GCD and LCM

```cpp
// GCD (Greatest Common Divisor)
int gcd(int a, int b) {
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Or use built-in (C++17)
int g = __gcd(12, 18);       // 6

// LCM (Least Common Multiple)
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}
// lcm(12, 18) = 36
```

---

### 9.4 Prime Number Check

```cpp
bool isPrime(int n) {
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    
    for(int i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i+2) == 0)
            return false;
    }
    return true;
}
```

---

### 9.5 Factorial

```cpp
// Iterative (BETTER for TCS NQT)
long long factorial(int n) {
    long long result = 1;
    for(int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Recursive (avoid in exams)
long long factorial(int n) {
    if(n <= 1) return 1;
    return n * factorial(n-1);
}
```

---

### 9.6 Fibonacci

```cpp
// Print first N Fibonacci numbers
void fibonacci(int n) {
    long long a = 0, b = 1;
    for(int i = 0; i < n; i++) {
        if(i == 0) cout << a << " ";
        else if(i == 1) cout << b << " ";
        else {
            long long c = a + b;
            cout << c << " ";
            a = b;
            b = c;
        }
    }
}
```

---

### 9.7 Armstrong Number

```cpp
bool isArmstrong(int n) {
    int original = n;
    int digits = to_string(n).length();
    int sum = 0;
    
    while(n > 0) {
        int digit = n % 10;
        sum += pow(digit, digits);
        n /= 10;
    }
    
    return sum == original;
}
// 153 = 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153 ✅
```

---

### 9.8 Palindrome Number

```cpp
bool isPalindrome(int n) {
    int original = n;
    int reversed = 0;
    
    while(n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    
    return reversed == original;
}
// 121 reversed = 121 ✅
// 123 reversed = 321 ❌
```

---

<br>

## ✅ SECTION 10: COMMON PATTERNS & IDIOMS

### 10.1 Swap

```cpp
int a = 10, b = 20;

// Using swap function ✅
swap(a, b);                  // a = 20, b = 10

// Manual
int temp = a;
a = b;
b = temp;
```

---

### 10.2 Two Pointers

```cpp
// Pattern: Check palindrome
bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    while(left < right) {
        if(s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

// Pattern: Remove duplicates from sorted array
vector<int> arr = {1, 1, 2, 2, 3, 4, 4, 5};
int i = 0;
for(int j = 1; j < arr.size(); j++) {
    if(arr[j] != arr[i]) {
        i++;
        arr[i] = arr[j];
    }
}
arr.resize(i + 1);           // arr = [1, 2, 3, 4, 5]
```

---

### 10.3 Sliding Window

```cpp
// Pattern: Find max sum of k consecutive elements
vector<int> arr = {1, 4, 2, 10, 23, 3, 1, 0, 20};
int k = 4;

int maxSum = 0, windowSum = 0;

// First window
for(int i = 0; i < k; i++) {
    windowSum += arr[i];
}
maxSum = windowSum;

// Slide window
for(int i = k; i < arr.size(); i++) {
    windowSum = windowSum - arr[i-k] + arr[i];
    maxSum = max(maxSum, windowSum);
}
```

---

### 10.4 Prefix Sum

```cpp
// Pattern: Find sum of subarray efficiently
vector<int> arr = {1, 2, 3, 4, 5};

// Build prefix sum
vector<int> prefix(arr.size());
prefix[0] = arr[0];
for(int i = 1; i < arr.size(); i++) {
    prefix[i] = prefix[i-1] + arr[i];
}
// prefix = [1, 3, 6, 10, 15]

// Sum from index l to r (0-indexed)
int l = 1, r = 3;
int sum = prefix[r] - (l > 0 ? prefix[l-1] : 0);
// sum = prefix[3] - prefix[0] = 10 - 1 = 9 (arr[1]+arr[2]+arr[3] = 2+3+4)
```

---

### 10.5 Frequency Counter Pattern

```cpp
// Pattern: Find first non-repeating character
string s = "swiss";
map<char, int> freq;
for(char c : s) {
    freq[c]++;
}

for(char c : s) {
    if(freq[c] == 1) {
        cout << c;           // 'w'
        break;
    }
}
```

---

### 10.6 Multiple Conditions

```cpp
// Check multiple vowels
char c = 'a';
if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
    cout << "Vowel";
}

// Better way
string vowels = "aeiouAEIOU";
if(vowels.find(c) != string::npos) {
    cout << "Vowel";
}
```

---

<br>

## ✅ SECTION 11: EDGE CASES TO REMEMBER

### 11.1 Common Edge Cases

```cpp
// ALWAYS check these:

// 1. Empty input
if(arr.size() == 0) { /* handle */ }
if(s.empty()) { /* handle */ }

// 2. Single element
if(arr.size() == 1) { /* handle */ }

// 3. All elements same
// [5, 5, 5, 5, 5]

// 4. Negative numbers
// [-5, -10, -3]

// 5. Zero
if(n == 0) { /* handle */ }

// 6. Very large numbers
long long n;  // Use instead of int

// 7. All sorted (ascending/descending)
// [1, 2, 3, 4, 5] or [5, 4, 3, 2, 1]

// 8. Overflow
// Use long long for factorial, large sums

// 9. String with spaces/special characters
// "hello world", "test@123"

// 10. Case sensitivity
// Convert to same case before comparing
```

---

### 11.2 Integer Overflow

```cpp
// BAD (overflow for large numbers)
int factorial(int n) {
    int result = 1;
    for(int i = 2; i <= n; i++) {
        result *= i;         // Overflow for n > 12
    }
    return result;
}

// GOOD (use long long)
long long factorial(int n) {
    long long result = 1;
    for(int i = 2; i <= n; i++) {
        result *= i;         // Works up to n = 20
    }
    return result;
}
```

---

### 11.3 Division by Zero

```cpp
// ALWAYS check before dividing
int a = 10, b = 0;

// BAD
int result = a / b;          // Runtime error ❌

// GOOD
if(b != 0) {
    int result = a / b;
} else {
    cout << "Cannot divide by zero";
}
```

---

### 11.4 Array Index Out of Bounds

```cpp
vector<int> arr = {10, 20, 30};

// BAD
cout << arr[5];              // Undefined behavior ❌

// GOOD
if(i >= 0 && i < arr.size()) {
    cout << arr[i];
}
```

---

<br>

## ✅ SECTION 12: QUICK REFERENCE TABLE

```
╔════════════════════════════════════════════════════════════════════╗
║                    QUICK REFERENCE CHEAT SHEET                     ║
╠════════════════════════════════════════════════════════════════════╣
║ TASK                          │ CODE                               ║
╠═══════════════════════════════╪════════════════════════════════════╣
║ Include all libraries         │ #include <bits/stdc++.h>          ║
║ Read integer                  │ int n; cin >> n;                  ║
║ Read string (no space)        │ string s; cin >> s;               ║
║ Read string (with space)      │ string s; getline(cin, s);        ║
║ Read array                    │ for(int i=0;i<n;i++) cin>>arr[i]; ║
║ Print with newline            │ cout << n << endl;                ║
║ Print without newline         │ cout << n;                        ║
╠═══════════════════════════════╪════════════════════════════════════╣
║ String length                 │ s.length() or s.size()            ║
║ String reverse                │ reverse(s.begin(), s.end())       ║
║ String to uppercase           │ transform(s.begin(), s.end(),     ║
║                               │   s.begin(), ::toupper)           ║
║ Character to lowercase        │ tolower(c)                        ║
║ Check if alphabetic           │ isalpha(c)                        ║
║ Check if digit                │ isdigit(c)                        ║
╠═══════════════════════════════╪════════════════════════════════════╣
║ Char digit to int             │ int n = c - '0';                  ║
║ Int to char digit             │ char c = n + '0';                 ║
║ Int to string                 │ to_string(n)                      ║
║ String to int                 │ stoi(s)                           ║
║ Char to position (A=0)        │ c - 'A' or c - 'a'                ║
╠═══════════════════════════════╪════════════════════════════════════╣
║ Sort ascending                │ sort(v.begin(), v.end())          ║
║ Sort descending               │ sort(v.begin(), v.end(),          ║
║                               │   greater<int>())                 ║
║ Reverse vector                │ reverse(v.begin(), v.end())       ║
║ Find min                      │ *min_element(v.begin(), v.end())  ║
║ Find max                      │ *max_element(v.begin(), v.end())  ║
║ Sum of vector                 │ accumulate(v.begin(), v.end(), 0) ║
╠═══════════════════════════════╪════════════════════════════════════╣
║ Add to vector end             │ v.push_back(x)                    ║
║ Remove from vector end        │ v.pop_back()                      ║
║ Vector size                   │ v.size()                          ║
║ Check if empty                │ v.empty()                         ║
║ Clear vector                  │ v.clear()                         ║
╠═══════════════════════════════╪════════════════════════════════════╣
║ Insert in set                 │ s.insert(x)                       ║
║ Find in set                   │ s.find(x) != s.end()              ║
║ Erase from set                │ s.erase(x)                        ║
╠═══════════════════════════════╪════════════════════════════════════╣
║ Insert/update in map          │ m[key] = value                    ║
║ Check if key exists           │ m.find(key) != m.end()            ║
║ Get value                     │ m[key]                            ║
║ Increment frequency           │ freq[x]++                         ║
╠═══════════════════════════════╪════════════════════════════════════╣
║ Power                         │ pow(base, exp)                    ║
║ Square root                   │ sqrt(n)                           ║
║ Absolute value                │ abs(n) or fabs(d)                 ║
║ Min of 2                      │ min(a, b)                         ║
║ Max of 2                      │ max(a, b)                         ║
║ Swap                          │ swap(a, b)                        ║
╠═══════════════════════════════╪════════════════════════════════════╣
║ GCD                           │ __gcd(a, b)                       ║
║ Integer division              │ a / b                             ║
║ Remainder                     │ a % b                             ║
╠═══════════════════════════════╪════════════════════════════════════╣
║ For loop                      │ for(int i=0; i<n; i++)            ║
║ For each                      │ for(int x : arr)                  ║
║ While loop                    │ while(condition)                  ║
╠═══════════════════════════════╪════════════════════════════════════╣
║ If condition                  │ if(condition) { }                 ║
║ If-else                       │ if(cond) { } else { }             ║
║ Ternary                       │ result = (cond) ? a : b           ║
╚═══════════════════════════════╧════════════════════════════════════╝
```

---

<br>

## 🎯 PRACTICE TEMPLATE (Copy This!)

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Input section
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Processing section
    // Your logic here
    
    // Output section
    for(int x : arr) {
        cout << x << endl;
    }
    
    return 0;
}
```

---

<br>

## ✅ FINAL CHECKLIST BEFORE CODING PRACTICE

Before you start solving questions, make sure you can:

**Input / Output:**
- [ ] Include correct headers (`#include <bits/stdc++.h>`)
- [ ] Read single integer (`cin >> n`)
- [ ] Read string without spaces (`cin >> s`)
- [ ] Read string with spaces (`getline(cin, s)`)
- [ ] Read array using vector
- [ ] Handle `cin.ignore()` after reading number before `getline`
- [ ] Print with newline (`cout << x << endl`)
- [ ] Print array elements (for loop or range-based)

**Strings:**
- [ ] Get string length (`s.length()`)
- [ ] Access string character (`s[i]`)
- [ ] Reverse string (`reverse(s.begin(), s.end())`)
- [ ] Convert string to upper/lowercase
- [ ] Check if character is alpha (`isalpha(c)`)
- [ ] Check if character is digit (`isdigit(c)`)
- [ ] Convert char to lowercase (`tolower(c)`)

**Type Conversions:**
- [ ] Convert char digit to int (`c - '0'`)
- [ ] Convert int to char digit (`n + '0'`)
- [ ] Convert int to string (`to_string(n)`)
- [ ] Convert string to int (`stoi(s)`)
- [ ] Convert char to position (`c - 'A'` or `c - 'a'`)

**Vectors & Arrays:**
- [ ] Sort vector (`sort(v.begin(), v.end())`)
- [ ] Reverse vector (`reverse(v.begin(), v.end())`)
- [ ] Find min/max (`*min_element()`, `*max_element()`)
- [ ] Calculate sum (`accumulate()`)
- [ ] Push to vector (`v.push_back(x)`)
- [ ] Check vector size (`v.size()`)

**Set & Map:**
- [ ] Use set for unique elements
- [ ] Use map for frequency counting (`freq[x]++`)
- [ ] Check if element exists in set/map (`find()`)

**Math & Numbers:**
- [ ] Check for prime number
- [ ] Calculate factorial
- [ ] Generate Fibonacci
- [ ] Check Armstrong number
- [ ] Check palindrome number

**Edge Cases:**
- [ ] Handle empty input
- [ ] Handle single element
- [ ] Handle negative numbers
- [ ] Handle zero
- [ ] Use `long long` for large numbers
- [ ] Check division by zero
- [ ] Check array bounds

---

> 🚀 **You're ready! Use this reference alongside `TCS_NQT_Coding_Analysis.md` for a complete exam prep toolkit.**
