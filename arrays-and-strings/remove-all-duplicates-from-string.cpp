/* Remove all duplicates from a given string, do it in place.

Input string:  geeksforgeeks
Output string: efgkos (if order isn't preserved) / geksfo (is order is preserved)

Below are the different methods to remove duplicates in a string:

METHOD 1 (Use Sorting)

Algorithm:

1) Sort the elements.
2) Now in a loop, remove duplicates by comparing the current character with previous character.
3) Remove extra characters at the end of the resultant string.

Time Complexity: O(nlogn), Space Complexity = O(1) If we use some nlogn sorting algorithm.

Note that, this method doesn’t keep the original order of the input string.

METHOD 2 (Use Hashing )

Algorithm:

1: Initialize:
    str  =  "test string" // input string 
    ip_ind =  0          // index to  keep track of location of next character in input string 
    res_ind  =  0         // index to  keep track of location of next character in the resultant string 
    bin_hash[0..255] = {0,0, ….} // Binary hash to see if character is already processed or not 
2: Do following for each character *(str + ip_ind) in input string:
              (a) if bin_hash is not set for *(str + ip_ind) then
                   // if program sees the character *(str + ip_ind) first time
                         (i)  Set bin_hash for *(str + ip_ind)
                         (ii)  Move *(str  + ip_ind) to the resultant string.
                              This is done in-place.
                         (iii) res_ind++
              (b) ip_ind++
  // String obtained after this step is "te sringng" 
3: Remove extra characters at the end of the resultant string.
  //  String obtained after this step is "te sring" 

Note that, this method doesn’t keep the original order of the input string.

Time complexity = O(n), Space Complexity = O(n)

Important Points:

1) Method 1 doesn’t maintain order of characters as original string, but method 2 does.
2) It is assumed that number of possible characters in input string are 256. NO_OF_CHARS should be changed accordingly.
3) Above algorithm also works for an integer array inputs if range of the integers in array is given. 
Example problem is to find maximum occurring number in an input array given that the input array contains
integers only between 1000 to 1100

*/


