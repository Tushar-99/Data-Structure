
// hi-malik's avatar
// hi-malik
// 24
// 3 hours ago

// 8 VIEWS

// I hope this approach helps you to understand how I did, if you have any doubts do let me know in comment section.

// I tried to explain this question in video in "MUCH BETTER WAY" do check it out.
// Thanks (:
// https://www.youtube.com/watch?v=hYqwQC6kWIw



// Brute Force Solution :

public int[] sortedSquares(int[] nums) {
    // Created an result array to store square arrayed numbers
    int res[] = new int[nums.length];
    // Run the loop
    for (int i = 0; i < nums.length; i++) {
        res[i] = nums[i] * nums[i]; // Put every square value in the result array
    }
    Arrays.sort(res); // Sort the unsorted array
    return res;
}
// Time Complexity: O(NlogN), where N is the length of nums.
// Space complexity : O(N) or (logN)

// Two Pointer Solution :

public int[] sortedSquares(int[] nums) {
    int res[] = new int[nums.length]; // Created an result array to store square arrayed numbers
    int i = 0; // first pointer at 0th index
    int j = nums.length - 1; // another pointer at last element of array
    int index = nums.length - 1; // created this pointer helps in filling up the array from the last greatest element

    while (i <= j) {
        int val1 = nums[i] * nums[i]; // calculate square of ith
        int val2 = nums[j] * nums[j]; // calculate square of jth
        // check if val1 is greater
        if (val1 > val2) {
            res[index] = val1; // put in result array
            i++; // move ith pointer forward
        } else {
            // check if val2 > val1
            res[index] = val2; // put in result array
            j--; // move jth pointer backward
        }
        index--; // and every time index pointer will move back as well
    }
    return res; // finally return it
}
// Time Complexity: O(N), where N is the length of nums.
// Space Complexity: O(N) if you take output into account and O(1) otherwise.


public int[] sortedSquares(int[] nums) {
    int point = -1;
    int n = nums.length;
    int count = 0;
    for (int i = 0 ; i < n ; i++) {
        if (nums[i] >= 0) {
            point = i;
            break;
        }
        count++;
    }
    int temp[] = new int[nums.length];
    if (point == 0) { //this handle if our all the elements are positive
        for (int i = 0 ; i < n ; i++) {
            nums[i] = nums[i] * nums[i];
        }
        return nums;
    } else if (count == nums.length) {
        //this loop handles if all the cases are negative
        int i = n - 1;
        int j = 0;
        while (i >= 0) {
            temp[j] = nums[i] * nums[i];
            i--;
            j++;
        }
        return temp;
    } else {//this handles if our pivot element is between 0 to n-1
        //u can also use binary search to find pivot point.
        int i = point - 1 ;
        int j = point;
        int k = 0;
        while (i >= 0 && j < n) {
            if (Math.abs(nums[i]) < Math.abs(nums[j])) {
                temp[k] = Math.abs(nums[i] * nums[i]);
                i--;
            } else {
                temp[k] = Math.abs(nums[j] * nums[j]);
                j++;
            }
            k++;
        }
        while (i >= 0) {
            temp[k] = Math.abs(nums[i] * nums[i]);
            k++;
            i--;
        }
        while (j < n) {
            temp[k] = Math.abs(nums[j] * nums[j]);
            j++;
            k++;
        }
        return temp;
    }
}