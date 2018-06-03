### complexity and stability of these sort algorithms  
---

| algorithm | worst time complexity | average time complexity | best time complexity | extra space complexity | stability | 
| :-------: | :-------------------: | :---------------------: | :------------------: | :--------------------: | :-------: |
| bubble sort | O(n^2) | O(n^2) | O(n) | O(1) | stable|
| insertion sort | O(n^2) | O(n^2) | O(n) | O(1) | stable|
| selection sort | O(n^2) | O(n^2) | O(n^2) | O(1) | not stable|
| quick sort | O(n^2) | O(nlogn) | O(nlogn) | O(logn) | not stable|
| merge sort | O(nlogn) | O(nlogn) | O(nlogn) | O(n) | stable|
| shell sort | O(n(logn)^2) | - | O(n) | O(1) | not stable|
| heap sort | O(nlogn) | O(nlogn) | O(nlogn) | O(1) | not stable|
| counting sort | O(n+k) (k is the length of count array) | O(n+k) | O(n+k) | O(n+k) | stable|
| bucket sort | O(n^2) (k is bucket number) | O(n+k) | O(n+k) | O(n * k) | stable|
| radix sort | O(d(r+n)) (r is radix, d is digit number) | O(d(r+n)) | O(d(r+n)) | O(r+n) | stable|
