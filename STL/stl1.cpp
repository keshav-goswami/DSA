#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

// Pairs
void explain_pairs(){
    pair<int,int> p;
    pair<int,int> p2 = {1,2};
    pair<int,char> p3 = {1,'K'};

    cout<<p2.first<<" "<<p2.second<<endl;
    cout<<p3.first<<" "<<p3.second<<endl;

    // 2D pairs

    pair<int,pair<int,int>> pr = {1,{2,3}};
    cout<<pr.first<<" "<<pr.second.first<<" "<<pr.second.second<<endl;

    // Array of Pairs

    pair<int,int> arr[] = {{1,2},{3,4},{4,5},{6,7}};
    for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++){
        cout<<arr[i].first<<" "<<arr[i].second<<endl;
    }
}

void explain_vectors(){
    // Vectors are dynamic in nature and we can change there size unlike arrays which are constant.
    vector<int> v;
    vector<int> v1 = {1,2,3,4,7,8,9};
    vector<pair<int,int>> vp;
    // Initializig an vector
    vector<int> v2(6);
    vector<bool> v3(10,false);

    vector<int> v4(v2);
    // Methods
    v.push_back(1);
    v.emplace_back(2);
    // Emplace back is similar to push_back and is faster than push_back

    vp.push_back({1,2});
    vp.emplace_back(1,2);

    // Iterator
    // Iterator is pointing at the memory address but the 
    vector<int>::iterator it;

    for(auto it = v1.begin();it!=v1.end();it++){
        cout<<*(it)<<endl;
    }

    // Erase Element in Vector {1,2,3,4,7,8,9};
    v1.erase(v1.begin()+1);
    for(auto a:v1) cout<<a<<" ";
    cout<<endl;
    v1.erase(v1.begin()+1,v1.begin()+3);
    for(auto a:v1) cout<<a<<" ";
    cout<<endl;

    // Inserting an Element 
    v1.insert(v1.begin(),100);

    // insert(Place, Number of Elements, Number)
    v1.insert(v1.begin()+1,4,10);
    for(auto a:v1) cout<<a<<" ";
    cout<<endl;
 
    // Insert another vector 
    v1.insert(v1.begin()+1,v.begin(),v.end());
    for(auto a:v1) cout<<a<<" ";
    cout<<endl;

    v.size(); //find size of vector
    v1.swap(v); //Swap the complete vectors
    v.clear(); //Erase the whole vector
    v.empty(); // To check whether vector is empty or not

}

void explain_list(){

    list<int> ls;

    ls.push_back(1);
    ls.emplace_back(2);

    // Very cheap as compared to insert function of vector
    ls.push_front(3);

    ls.emplace_front(10);

    for(auto i:ls){
        cout<<i<<" ";
    }
    cout<<endl;
}

void explain_deque(){

    deque<int> dq;

    dq.push_back(1);
    dq.emplace_back(2);
    dq.push_front(3);
    dq.emplace_front(4);

    dq.pop_front();
    dq.pop_back();

    // See first and last element 
    dq.front();
    dq.back();

    for(auto i:dq){
        cout<<i<<" ";
    }
    cout<<endl;
}


void explain_stack(){

    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.emplace(6);

    // See first and last element 
    cout<<st.top()<<endl;
    st.pop();
    st.size();
    st.empty();
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

void explain_queue(){

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.emplace(6);

    q.front();
    q.back();

    q.pop();

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

void explain_priority_queue(){

    // Push and pop time complexity O(log(N))
    priority_queue<int> pq;

    pq.push(5);
    pq.push(2); 
    pq.push(3);
    pq.push(6);
    pq.push(10);
    pq.emplace(1);

    cout<<pq.top()<<endl;
    pq.pop();

    cout<<pq.top()<<endl;

    // Min Heap

    priority_queue<int,vector<int>,greater<int>> min_pq;
    min_pq.push(5);
    min_pq.push(2);
    min_pq.push(3);
    min_pq.push(6);
    min_pq.push(10);
    min_pq.emplace(1);

    cout<<min_pq.top()<<endl;
    min_pq.pop();

    cout<<min_pq.top();
}

void explain_set(){ // Sorted and Unique
    // Everything happens in logarithmic time complexity
    cout<<"\nSET"<<endl;
    // Push and pop time complexity O(log(N))
    set<int> st;

    st.insert(1);
    st.insert(1);
    st.emplace(1);
    st.insert(2);
    st.insert(2);
    st.insert(3);
    st.insert(4);
    st.insert(4);

    for(auto i:st) cout<<i<<" ";

    auto it = st.find(3);
    cout<<endl<<*(it)<<" ";
    st.erase(3);
    auto it1 = st.find(3);
    // Here it1 will be == st.end() bcoz 3 doesn't exists

    // we can also use count function in set to find whether an element exists or not
    cout<<st.count(2)<<endl;

    auto it2 = st.upper_bound(2);
    auto it3 = st.lower_bound(2);


    // Unordered Set
    unordered_set<int> un_st;
    // Lower and upper bound doesn't work 
    // All operations are O(1) time
    // Rarest of rare case O(N) complexity can take place in very bad test case
}

void explain_multi_set(){
    // sorted but not unique
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    ms.insert(2);
    ms.insert(3);
    
    ms.erase(1); //all 1s are erased

    ms.erase(ms.find(1)); //single occurance of 1 will be erased

    // Rest all functions same are set;

}

void explain_map(){
    cout<<"\nMAP"<<endl;
    // sorted order and unique keys

    map<int,int> mp;
    map<pair<int,int>,int> mpr;

    mp[1] = 2;
    mp[10] = 22;
    mp[13] = 12;
    mp[8] = 10;
    mp[6] = 1;

    mp.insert({1,3});    
    mp.emplace(2,3);    

    for(auto i:mp){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;

    // Find the keys
    auto itr = mp.find(1);

    // Unordered map
    unordered_map<int,int> un_mp;
    // Multimap not unique keys
    multimap<int,int> mmp;

}

void binary_search_trick(){
    cout<<"\nBINARY TRICKS"<<endl;
    // sorted array
    int a[] = {1,2,5,7,8,10};
    int n = sizeof(a)/sizeof(a[0]);

    bool res = binary_search(a,a+n,1);
    cout<<res<<endl;

    bool res1 = binary_search(a,a+n,11);
    cout<<res1<<endl;

    // Lower and Upper Bound
    // lower bound means it will return the index of element if it exists otherwise it will
    // return the immediate next greater to that element.  
    
    int A[] = {1,4,5,6,9,9};
    int N = 6;
    int ind1 = lower_bound(A,A+N,4) - A; // => 1
    int ind2 = lower_bound(A,A+N,7) - A; // => 4 (pointing 9)
    int ind3 = lower_bound(A,A+N,10) - A; // => 6 (Pointing at end bcoz element doesn't exists)

    cout<<ind1<<" "<<ind2<<" "<<ind3<<endl;

    // For a vector
    // int ind = upper_bound(vp.begin(),vp.end(),3) - vp.begin();

    // Upper and lowerbound works in O(log(n)) complexity

    // 4 Questions to be covered->
    // Find the first occurance , last occurance , element just smaller than x or element just larger than x;
}


bool comp(pair<int,int> p1,pair<int,int> p2){
// Sorting according to second element
// if second is same , sort the first in descending order
    if(p1.second < p2.second) return true;  
    if(p1.second > p2.second) return false;  
    // if they are same
    if(p1.first > p2.first) return true;
    return false;
}
void Algorithms(){
cout<<"\nALGORITHMS"<<endl;

    int A1[] = {8,3,9,4,2,6,7,4,3,7};
    int n1 = 10; 
    vector<int> v = {8,3,9,4,2,6,7,4,3,7}; 

    sort(A1,A1+n1);
    sort(v.begin(),v.end());

    // descending order
    sort(A1,A1+n1,greater<int>());
    sort(v.begin(),v.end(),greater<int>());

    pair<int,int> pr[] = {{1,2},{3,2},{3,4},{5,3},{7,5},{9,5}};

    sort(pr,pr+6,comp);

    for(int i=0;i<5;i++){
        cout<<pr[i].first<<" "<<pr[i].second<<endl;
    }


    // Count the Number of set Bits
    int k = 7;
    int cnt = __builtin_popcount(k);
    long long int kl = 192386383483;
    int cnt1 = __builtin_popcountll(kl);
    cout<<cnt<<" "<<cnt1<<endl;

    string s = "123";

    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(),s.end()));

    int maxi = *max_element(v.begin(),v.end());
    int mini = *min_element(v.begin(),v.end());
}

int main(){
    explain_pairs();

    explain_vectors();

    explain_list();

    explain_deque();

    explain_stack();
    
    explain_queue();   

    explain_priority_queue();  

    explain_set();

    explain_multi_set();

    explain_map();

    binary_search_trick();

    Algorithms();

    return 0;
}