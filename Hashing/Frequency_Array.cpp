// code to mark the frequency of elements of array using array not mapping

vector<int> frequencyCount(vector<int>& arr) {
    int n = arr.size();
    vector<int> freq(n, 0);
    // intialising a vector of size n and all element 0

   
    for (auto num : arr) {
        if (num >= 1 && num <= n) {
            freq[num - 1]++;
            // refering to the index in ans array 

        }
    }

    return freq;
}