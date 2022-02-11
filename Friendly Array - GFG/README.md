# Friendly Array
## Easy
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Like people, numbers are also friends with each other. Friendliness between any two numbers a and b is defined as the absolute difference between the two. Lower is this number more friendly the numbers are. Now you are given an array of numbers and you are required to find the friendliness of this array. This can be calculated as the sum of the friendliness of each element in the array with its closest friend in the same array. </span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N=3
arr[] = { 4,1,5 }
<strong>Output:</strong> 5
<strong>Explanation</strong>: Sum of absolute differences is
&nbsp;           |4-5| + |1-4| + |5-4| = 5</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N=3
arr[] = { 1,1,1 }
<strong>Output:</strong> 0
<strong>Explanation</strong>: Sum of absolute differences is 
&nbsp;            |1-1| + |1-1| + |1-1| = 0
</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function <strong>sumOfMinAbsDifferences</strong>() that takes <strong>array arr and integer N</strong>&nbsp;as parameters and return the value of friendliness for the given array.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(NLogN).<br>
<strong>Expected Auxiliary Space:</strong> O(1).</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
2 ≤ N ≤ 10<sup>5</sup></span></p>
 <p></p>
            </div>