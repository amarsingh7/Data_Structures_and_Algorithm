
// ITERATIVE APPROACH

//ALGORITHM
/*
    Begin with an interval of the whole vector from start to end, 0 to nums.size() - 1.
    If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half. end = mid - 1
    Otherwise, narrow it to the upper half. start = mid + 1
    Repeatedly check until the value is found or the interval is empty. else return -1
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0,end = nums.size() - 1;
        
		// iterate till start doesn't exceed end
        while(start <= end)
        {
			// calculating mid
            int mid = start + (end - start)/2;
			
			// if value at mid is equals to target
            if(nums[mid] == target)
                return mid;
				
			// value at mid is less than target
			// update the start by mid + 1
			// key should be in range mid + 1 to end
            else if(nums[mid] < target)
                start = mid+1;
				
			// else update the end by mid - 1
			// value should be in range 0 to mid - 1
            else
                end = mid-1;
        }
        
		// if target doesn;t found
        return -1;
        
    }
};



// RECURSIVE APPROACH

//ALGORITHM
/*
    Compare x with the middle element.
    If x matches with the middle element, we return the mid index. return mid
    Else If x is greater than the mid element, then x can only lie in the right half subarray after the mid element. So we recur call for the right half.
    return binary(v, mid+1, r, key)
    Else (x is smaller) recur call for the left half. return binary(v, l, mid-1, key)
*/



class Solution {
public:
    int binary(vector<int>v,int l, int r, int key)
    {
		// till l doesn't exceed r
        if(r >= l)
        {
            int mid = (l+r)/2;
			
			// if key equals mid return mid
            if(key == v[mid])
                return mid;
				
			// if key is less than mid
			// recursive call for left half
            else if(key < v[mid])
                return binary(v,l,mid-1,key);
				
			// key is greater than mid
			// recursive call for right half
            else
                return binary(v,mid+1,r,key);
        }
		
		// if key not found
        return -1;
    }
    
    
    int search(vector<int>& nums, int target) {
        int result = binary(nums,0,nums.size()-1,target);
		
		// if func returns -1 key doesn't exists
        if (result == -1)
            return -1;
		
		// return index of key
        else
            return result;   
    }
};



