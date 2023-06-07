# Least Prime Factor
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a number N, find the least prime factors for all numbers from 1 to N.&nbsp; The least prime factor of an integer X is the smallest prime number that divides it.<br><strong>Note : </strong></span></p>
<ul>
<li><span style="font-size: 18px;">1 needs to be printed for 1.</span></li>
<li><span style="font-size: 18px;">You need to return an array/vector/list of <strong>size N+1</strong>&nbsp;and need to use <strong>1-based indexing</strong> to store the answer for each number.</span></li>
</ul>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input</strong>: N = 6
<strong>Output:</strong> [0, 1, 2, 3, 2, 5, 2]&nbsp;
<strong>Explanation</strong>: least prime factor of 1 = 1,
least prime factor of 2 = 2,
least prime factor of 3 = 3,
least prime factor of 4 = 2,
least prime factor of 5 = 5,
least prime factor of 6 = 2.
So answer is[1, 2, 3, 2, 5, 2]. </span>
</pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>N = 4
<strong>Output:&nbsp;</strong>[0, 1, 2, 3, 2]
<strong>Explanation</strong>: least prime factor of 1 = 1,
least prime factor of 2 = 2,
least prime factor of 3 = 3,
least prime factor of 4 = 2.
So answer is[1, 2, 3, 2]. 
</span></pre>
<p><span style="font-size: 18px;"><strong>Your Task:&nbsp;&nbsp;</strong><br>You don't need to read input or print anything. Complete the function <strong>leastPrimeFactor()&nbsp;</strong>which takes N as input parameter and returns a list of integers containing all the least prime factors of each number from 1 to N.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(NlogN)<br><strong>Expected Auxiliary Space:</strong> O(N)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>2&lt;= n &lt;=10<sup>5</sup></span></p></div>