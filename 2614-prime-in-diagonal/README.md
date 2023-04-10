<h2><a href="https://leetcode.com/problems/prime-in-diagonal/">2614. Prime In Diagonal</a></h2><h3>Easy</h3><hr><div><p>You are given a 0-indexed two-dimensional integer array <code>nums</code>.</p>

<p>Return <em>the largest <strong>prime</strong> number that lies on at least one of the <b>diagonals</b> of </em><code>nums</code>. In case, no prime is present on any of the diagonals, <em>return 0.</em></p>

<p>Note that:</p>

<ul>
	<li>An integer is <strong>prime</strong> if it is greater than <code>1</code> and has no positive integer divisors other than <code>1</code> and itself.</li>
	<li>An integer <code>val</code> is on one of the<strong>diagonals</strong> of <code>nums</code> if there exists an integer <code>i</code> for which <code>nums[i][i] = val</code> or an <code>i</code> for which <code>nums[i][nums.length - i - 1]= val</code>.</li>
</ul>

<p><img alt="" src="https://assets.leetcode.com/uploads/2023/03/06/screenshot-2023-03-06-at-45648-pm.png" style="width: 181px; height: 121px;"></p>

<p>In the above diagram, one diagonal is <strong>[1,5,9]</strong> and another diagonal is<strong> [3,5,7]</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [[1,2,3],[5,6,7],[9,10,11]]
<strong>Output:</strong> 11
<strong>Explanation:</strong> The numbers 1, 3, 6, 9, and 11 are the only numbers present on at least one of the diagonals. Since 11 is the largest prime, we return 11.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [[1,2,3],[5,17,7],[9,11,10]]
<strong>Output:</strong> 17
<strong>Explanation:</strong> The numbers 1, 3, 9, 10, and 17 are all present on at least one of the diagonals. 17 is the largest prime, so we return 17.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 300</code></li>
	<li><code>nums.length == nums<sub>i</sub>.length</code></li>
	<li><code>1 &lt;= nums<span style="font-size: 10.8333px;">[i][j]</span>&nbsp;&lt;= 4*10<sup>6</sup></code></li>
</ul>
</div>