
// class Solution{
//     public:
//     int search(int arr[], int l, int h, int key){
//     while(l<=h){
//           int mid=(l+h)/2;
//           if(arr[mid]==key)return mid;
//           else if(arr[mid]>=arr[l])
//           {
//               if(key>=arr[l] and key<=arr[mid])h=mid-1;
//               else
//               {l=mid+1;}
//           }
//           else
//           {
//               if(key>=arr[mid] and key<=arr[h])l=mid+1;
//               else{h=mid-1;}
//           }
//     }
//     return -1;
//     }
// };


// // class Solution{
// //      public:
// // int search(int arr[], int l, int h, int key){
// //         if(l>h) return -1;
// //         int m=(l+h)/2;
// //         if(arr[m]==key) return m;
// //         if(arr[l]<=arr[m]){
// //             if(key==arr[l]) return l;
// //             else if(key>arr[l] and key<arr[m]) return search(arr,l,m-1,key);
// //             else return search(arr,m+1,h,key);
// //         }
// //         if(arr[h]==key) return h;
// //         else if(key>arr[m] && key<arr[h]) return search(arr,m+1,h,key);
// //         else return search(arr,l,m-1,key);
// //     }
// // };



// // Given a sorted and rotated array A of N distinct elements which is rotated at some point, and given an element key. The task is to find the index of the given element key in the array A. The whole array A is given as the range to search.

// // Example 1:

// // Input:
// // N = 9
// // A[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}
// // key = 10
// // l = 0 , h = 8
// // Output:
// // 5
// // Explanation: 10 is found at index 5.
// // Example 2:

// // Input:
// // N = 4
// // A[] = {3, 5, 1, 2}
// // key = 6
// // l = 0 , h = 3
// // Output:
// // -1
// // Explanation: There is no element that has value 6.
// // Your Task:
// // Complete the function search() which takes an array arr[] and start, end index of the array and the K as input parameters, and returns the answer.

// // Can you solve it in expected time complexity?

// // Expected Time Complexity: O(log N).
// // Expected Auxiliary Space: O(1).