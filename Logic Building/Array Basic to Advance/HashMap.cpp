HashMap
#1
Create an Empty unordered_map
Very Easy
unordered_map<int,int>mp;

▾

#2
Add a Single Entry
Very Easy
unordered_map<int,int>mp;

M1
mp[1]=10;
M2
mp.insert({1,10})
M3
mp.insert(make_pair(1,10));
▾

#3
Add Multiple Entries

mp[1] = 10;
mp[2] = 20;
mp[3] = 30;

mp.insert({1,10})
mp.insert({2,20})
mp.insert({3,30})
Very Easy
▾

#4
Access a Value by Key

mp["key"]
mp.at(key)
Very Easy
▾

#5
Access a Non-Existent Key with []

map<string,int>mp;

mp["milk"]=60;

cout<<mp["Bread"]<<endl;

cout<<mp.size()<<endl;

Very Easy
▾

#6
Safe Access with find()

map<string,int>mp;

mp["Amit"]=71;

auto it = mp.find("sumit");

if(it!=mp.find())
{
cout<<it->second<<endl;
}
else{
cout<<"Not Found";
}


Very Easy
▾

#7
Phone Directory — 3 Contacts

map<string,int>mp;

mp["mom"]=8602131610;
mp["Dad"]=9424749549;
mp["Brother"]=2902922530;

for(auto it:mp)
{
cout<<it.first<<" "<<it.second;
}

M1:
cout<<mp["mom"]<<endl;

M2:
 auto it = mp.find("mom");

if(it !=mp.end())
{
cout<<it.second<<endl;

}



Very Easy
▾

#8
Check the Size

map<int ,int>mp;

mp["banana"]=100;
mp["Apple"]=60;
mp["Grapes"]=90;

cout<< mp.size()<<endl;
Very Easy
▾

#9
Check if a Key Exists using count()

map<string,int>mp;
mp["Hindi"]=100;
mp["English"]=90;
mp["maths"]=50;

if(mp.count("Hindi"))
{
cout<<"Yes";
}
else{
cout<<"No";
}
Very Easy
▾

#10
Check if a Value Exists

map<string, int> mp;

    mp["Hindi"] = 100;
    mp["English"] = 90;
    mp["maths"] = 50;

    bool found = false;

    for (auto it : mp) {
        if (it.second == 90) {
            found = true;
            break;         }
    }

    if (found) {
        cout << "Yes";
    } else {
        cout << "No";
Very Easy
▾

#11
Store Integers as Keys
Very Easy

map<int,string>mp;

mp[101]="mohan";
mp[102]="Spohan";
mp[103]="Rohan";

cout<<mp[101];


if(mp.find(101) != mp.end()){
    cout << mp[101];
}
▾

#12
Overwrite a Value
Very Easy

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string,string> mp;

    mp["java"] = "Easy";

    cout << mp["java"] << endl;

    mp["java"] = "Hard";   // overwrite

    cout << mp["java"] << endl;

    return 0;
}▾

#13
Initialize Using Initializer List

unordered_map<string,int>mp;

mp["Chhindwara"]=480107;
mp["Gwalior"]=480001;
mp["Indore"]=480102;

for(auto it:mp)
{
cout<<it.first<<" " <<it.second<<endl;
Very Easy
▾

#14
Store Boolean Values
Very Easy
unordered_map<string,bool>mp;

mp["HomeWork"]=true;
mp["Laundary"]=false;
mp["WaterBottle"=true;

for(auto it:mp){
cout<<it.first<<" " <<it.second<<endl;
}
▾

#15
Store Double Values
Very Easy
#14
Store Boolean Values
Very Easy
unordered_map<string,double>mp;

mp["HomeWork"]=1.2;
mp["Laundary"]=f4.25;
mp["WaterBottle"=5.6;

for(auto it:mp){
cout<<it.first<<" " <<it.second<<endl;
}
▾
▾

#16
Print All Keys Only
Very Easy
#include <iostream>
#include <map>
using namespace std;

int main() {

    map<string,string> mp = {
        {"Red", "#FF0000"},
        {"Green", "#00FF00"},
        {"Blue", "#0000FF"}
    };

    // Print only keys
    for(auto it : mp){
        cout << it.first << endl;
    }

    return 0;
}▾

#17
Print All Values Only

Very Easy
#include <iostream>
#include <map>
using namespace std;

int main() {

    map<string,string> mp = {
        {"Red", "#FF0000"},
        {"Green", "#00FF00"},
        {"Blue", "#0000FF"}
    };

    // Print only keys
    for(auto it : mp){
        cout << it.second << endl;
    }

    return 0;
}
▾

#18
insert() vs [] — The Difference
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

    unordered_map<string,int> mp;

    // Using []
    mp["python"] = 100;

    // Overwrites existing value
    mp["python"] = 200;

    cout << "After [] overwrite: " << mp["python"] << endl;

    // Using insert()
    mp.insert({"java", 300});

    // insert() will NOT overwrite existing key
    mp.insert({"java", 500});

    cout << "After insert(): " << mp["java"] << endl;

    return 0;
}
▾

#19
Create Map, Add 5 Items, Print Size
Very Easy
#include <iostream>
#include <map>
using namespace std;

int main() {

    map<string,int> mp;

    mp["Yashraj"] = 152;
    mp["Yogesh"]  = 154;
    mp["Aman"]    = 11;
    mp["Rohan"]   = 120;
    mp["Mohit"]   = 130;

    for (auto it : mp) {
        cout << it.first << " " << it.second << endl;
    }

    cout << mp.size() << endl;

    return 0;
}▾

#20
Access Value and Store in Variable
Very Easy

map<string,int>mp;

mp["Phon"]=25000;
mp["Tablet"]=30000;
mp["T.V"]=40000;


int PhonPrice=mp["Phon"];
cout<<PhonPrice<<endl;

if(mp.find("Phone") != mp.end()){
    int price = mp["Phone"];
}

▾

#21
Iterate and Print All Key-Value Pairs
Easy

unordered_map<string,int>mp;

mp["Science"]=42;
mp{"Maths"]=56;
mp["SocialScience"]=48;
mp["English"]=78;

for(auto it:mp)
{
cout<<"Subject"<<it.first<<" "<<"Marks"<<it.second<<endl;
}
▾

#22
Iterate Using Explicit Iterator
Easy
unordered_map<string,int>mp;

mp["Science"]=42;
mp{"Maths"]=56;
mp["SocialScience"]=48;
mp["English"]=78;


    // Explicit iterator
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }

▾

#23
Print Only Values Using a Loop
Easy

unordered_map<string,int>mp;

mp["Science"]=42;
mp["Maths"]=56;
mp["SocialScience"]=48;
mp["English"]=78;

for(auto it:mp)
{
cout<<it.second<<endl;
}
▾

#24
Print in Table Format
Easy
#include <iostream>
#include <map>
#include <iomanip>   // important
using namespace std;

int main() {

    map<string,int> mp = {
        {"Aman", 91},
        {"Bhavna", 85},
        {"Chirag", 72}
    };

    // Header
    cout << left << setw(12) << "Student" << "Marks" << endl;
    cout << "---------------------" << endl;

    // Data
    for (auto it : mp) {
        cout << left << setw(12) << it.first << it.second << endl;
    }

    return 0;
}
▾

#25
Count Entries Manually with a Loop
Easy

unordered_map<char,int>mp={{'A', 1},{'B',2}.{'C",3}};

int count=0;

for(auto it:mp)
{
count++;
}

cout<<count;


#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

    unordered_map<char,int> mp = {
        {'A', 1},
        {'B', 2},
        {'C', 3}
    };

    int count = 0;

    for (auto it : mp) {
        count++;
    }

    cout << count << endl;

    return 0;
}

#26
Print Keys Where Value > Threshold

unordered_map<string,int>mp;

mp["Yashrj"]=5;
mp["Ram"]=6;
mp["Shyam"]=8;
mp["Mohan"]=7;

for(auto it:mp)
{
if(it.second>=7)
{
cout<<it.first<<" "<<it.second<<endl;
}
}
▾

#27
Sum of All Values
Easy

Print Keys Where Value > Threshold

unordered_map<string,int>mp;

mp["Yashrj"]=5;
mp["Ram"]=6;
mp["Shyam"]=8;
mp["Mohan"]=7;

int sum=0;

for(auto it:mp)
{
sum=sum+it.second;
}

cout<<sum<<endl;

▾

#28
Find Maximum Value
Easy

unordered_map<string,int>mp;

mp["Yashrj"]=5;
mp["Ram"]=6;
mp["Shyam"]=8;
mp["Mohan"]=7;

int maxVal=INT_MIN;

for(auto it:mp)
{
if(it.second>maxVal)
{
maxVal=it.second;
}
}

cout<<maxVal<<endl;
▾

#29
Find Minimum Value
Easy

#28
Find Maximum Value
Easy

unordered_map<string,int>mp;

mp["Yashrj"]=5;
mp["Ram"]=6;
mp["Shyam"]=8;
mp["Mohan"]=7;

int minVal=INT_MAX;

for(auto it:mp)
{
if(it.second>minVal)
{
minVal=it.second;
}
}

cout<<minVal<<endl;
▾

#30
Print in Reverse Format — Value: Key
Easy

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

    unordered_map<string,int> mp;
    unordered_map<int,string> rmp;

    mp["Yashraj"] = 5;
    mp["Ram"] = 6;
    mp["Shyam"] = 8;
    mp["Mohan"] = 7;

    // Reverse map
    for (auto it : mp) {
        rmp[it.second] = it.first;
    }

    // Print Value : Key
    for (auto it : rmp) {
        cout << it.first << " : " << it.second << endl;
    }

    return 0;
}

▾

#31
Use std::for_each with Lambda
Easy
▾

#32
Print Keys in Sorted Order (std::map)
Easy

map<string,int>mp;

mp["Banana"]=42;
mp["Apple"]=58;
mp["Orange"]=89;

for(auto it :mp)
{
cout<<it.first<<" " <<it.second<<endl;
}

▾

#33
Print Entries with Even Values Only
Easy

map<string,int>mp;

mp["Banana"]=42;
mp["Apple"]=58;
mp["Orange"]=89;

for(auto it :mp)
{
if(it.second%2==0)
{
cout<<it.first<<" " <<it.second<<endl;
}
}
▾

#34
Convert Map to Two Vectors
Easy

map<string,int>mp;

vector<string>fr;
vector<int>val;

mp["Banana"]=42;
mp["Apple"]=58;
mp["Orange"]=89;

for(auto it :mp)
{
fr.push_back(it.first);
val.push_back(it.second);

}

cout<<"KEYS";

for(auto it:fr)
{
cout<<it<<endl;
}
▾

#35
Count Values Above Average
Easy
map<string,int>mp;

mp["Banana"]=42;
mp["Apple"]=58;
mp["Orange"]=89;

int count =0;

for(auto it :mp)
{
count++;
}
cout<<count<<endl;
▾

#36
Update a Value
Moderate
map<string,int>mp;

mp["Banana"]=42;
mp["Apple"]=58;
mp["Orange"]=89;
mp["Mango"]=90;

cout<<mp["Mango"]<<endl;

mp["Mango"]=100;

cout<<"After"<<mp["Mango"];

▾

#37
Increment a Value
Moderate

 unordered_map<string,int> mp;

    mp["PageViews"] = 150;

    mp["PageViews"]++;   // increment

    cout << "PageViews: " << mp["PageViews"] << endl;



▾

#38
Delete an Entry with erase()
Moderate
map<string,int>mp;

mp["Banana"]=42;
mp["Apple"]=58;
mp["Orange"]=89;
mp["Mango"]=90;


mp.erase("Apple");

for(auto it :mp)
{
cout<<it.first<<" " <<it.second<<endl;
}

▾

#39
Delete Only If Value Matches
Moderate
#include <iostream>
#include <map>
using namespace std;

int main() {

    map<string,int> mp;

    mp["Banana"] = 42;
    mp["Apple"] = 58;
    mp["Orange"] = 89;
    mp["Mango"] = 90;

    for (auto it = mp.begin(); it != mp.end(); ) {
        if (it->second == 58) {
            it = mp.erase(it);   // ✅ correct
        } else {
            ++it;
        }
    }

    for (auto it : mp) {
        cout << it.first << " " << it.second << endl;
    }

    return 0;
}
}
▾

#40
Clear All Entries
Moderate

   map<string,int> mp;

    mp["Banana"] = 42;
    mp["Apple"] = 58;
    mp["Orange"] = 89;
    mp["Mango"] = 90;

for(auto it:mp)
{
cout<<it.first<<" "<<it.second<<endl;
}

cout<<"Size Before"<<mp.size()<<endl;

mp.clear();

cout<<"Size After"<<mp.size();

▾

#41
Merge Two unordered_maps
Moderate

unordered_map<char,int>mp1;
unordered_map<char,int>mp2;


mp1['A']=12;
mp1['B']=45;
mp1['C']=58;

mp2['M']=56;
mp2['V']=23;

 // Merge mp2 into mp1
    for (auto it : mp2) {
        mp1[it.first] = it.second;   // overwrite if key exists
    }

    // Print result
    for (auto it : mp1) {
        cout << it.first << " " << it.second << endl;


▾

#42
Handle Duplicate Keys During Merge
Moderate
▾

#43
Nested unordered_map — Student Subjects
Moderate
▾

#44
Iterate Over Nested Map
Moderate
▾

#45
Conditional Insert — Only If Key Absent
Moderate
▾

#46
Safe Erase During Iteration
Moderate
▾

#47
Frequency Counter ⭐
Moderate
▾

#48
Invert a Map (Swap Keys and Values)
Moderate
▾

#49
Group Items by Category
Moderate
▾

#50
Complete Mini-Project: Phone Directory
Moderate
▾
