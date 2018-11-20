#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

vector<string> findZeroSum(vector<int> arr) {
    // Write your code here.
    int n = arr.size();
    vector<string> ret;

    sort(arr.begin(), arr.end());    
    for (int i=0; i<n; i++) {
        int left = i+1;
        int right = n-1;
        
        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];
            //printf("%d %d %d\n", arr[i], arr[left], arr[right]);
            if (sum == 0) {
                //if (left == right)
                    //printf("equal %d\n", left);
                //else if (arr[left] == arr[right])
                    //printf("arr equal %d left %d right %d\n", arr[left], left, right);
                //printf("%d %d %d\n", arr[i], arr[left], arr[right]);
                ostringstream convert;
                convert << arr[i] << ", " << arr[left] << ", " << arr[right];
                string str = convert.str();
                ret.push_back(str);
                left++;
                right--;
            }
            if (sum < 0) {
                left++;
            } else if (sum >0) {
                right--;
            }
        }
    }
    vector<string> :: iterator it;
    sort(ret.begin(), ret.end());
    it = unique(ret.begin(), ret.end());
    ret.resize(distance(ret.begin(), it));
    return ret;
}

int main() {
	// your code goes here
	//vector<int> arr = {6,10,3,-4,1,-6,9};
	//vector<int> arr = {6,-1,-1,0,0,1,1};
	vector<int> arr = {91,44,-75,7,48,23,-35,-17,76,-73,-59,63,12,-43,48,56,9,-55,65,31,-70,-45,-21,12,38,22
,31,-65,-55,-4,-59,14,53,-7,12,-39,2,-26,13,43,11,80,-4,28,13,22,11,1,3,29,3,-33,-12,31,55,6,9,-28,97,-20,40
,6,-28,-68,-22,-30,38,-29,-25,10,47,38,17,43,17,-43,-2,37,-11,-32,-21,-2,20,-54,-51,-76,-88,14,64,-92,33,35};
	vector<string> ret = findZeroSum(arr);
	for (auto it=ret.begin(); it<ret.end(); it++) {
	    cout << *it << endl;
	}
	return 0;
}
