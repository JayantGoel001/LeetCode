<h2>1486. XOR Operation in an Array</h2><h3>Easy</h3><hr><div><p>Given an integer <code>n</code> and an integer <code>start</code>.</p>

<p>Define an array <code>nums</code> where <code>nums[i] = start + 2*i</code> (0-indexed) and <code>n == nums.length</code>.</p>

<p>Return the bitwise&nbsp;XOR&nbsp;of all elements of <code>nums</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 5, start = 0
<strong>Output:</strong> 8
<strong>Explanation: </strong>Array nums is equal to [0, 2, 4, 6, 8] where (0 ^ 2 ^ 4 ^ 6 ^ 8) = 8.
Where "^" corresponds to bitwise XOR operator.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 4, start = 3
<strong>Output:</strong> 8
<strong>Explanation: </strong>Array nums is equal to [3, 5, 7, 9] where (3 ^ 5 ^ 7 ^ 9) = 8.</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 1, start = 7
<strong>Output:</strong> 7
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> n = 10, start = 5
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>0 &lt;= start &lt;= 1000</code></li>
	<li><code>n == nums.length</code></li>
</ul></div>