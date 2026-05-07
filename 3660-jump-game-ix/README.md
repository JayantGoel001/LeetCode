<h2><a href="https://leetcode.com/problems/jump-game-ix">3981. Jump Game IX</a></h2><h3>Medium</h3><hr><p>You are given an integer array <code>nums</code>.</p>

<p>From any index <code>i</code>, you can jump to another index <code>j</code> under the following rules:</p>

<ul>
	<li>Jump to index <code>j</code> where <code>j &gt; i</code> is allowed only if <code>nums[j] &lt; nums[i]</code>.</li>
	<li>Jump to index <code>j</code> where <code>j &lt; i</code> is allowed only if <code>nums[j] &gt; nums[i]</code>.</li>
</ul>

<p>For each index <code>i</code>, find the <strong>maximum</strong> <strong>value</strong> in <code>nums</code> that can be reached by following <strong>any</strong> sequence of valid jumps starting at <code>i</code>.</p>

<p>Return an array <code>ans</code> where <code>ans[i]</code> is the <strong>maximum</strong> <strong>value</strong> reachable starting from index <code>i</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2,1,3]</span></p>

<p><strong>Output:</strong> <span class="example-io">[2,2,3]</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>For <code>i = 0</code>: No jump increases the value.</li>
	<li>For <code>i = 1</code>: Jump to <code>j = 0</code> as <code>nums[j] = 2</code> is greater than <code>nums[i]</code>.</li>
	<li>For <code>i = 2</code>: Since <code>nums[2] = 3</code> is the maximum value in <code>nums</code>, no jump increases the value.</li>
</ul>

<p>Thus, <code>ans = [2, 2, 3]</code>.</p>

<ul>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2,3,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">[3,3,3]</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>For <code>i = 0</code>: Jump forward to <code>j = 2</code> as <code>nums[j] = 1</code> is less than <code>nums[i] = 2</code>, then from <code>i = 2</code> jump to <code>j = 1</code> as <code>nums[j] = 3</code> is greater than <code>nums[2]</code>.</li>
	<li>For <code>i = 1</code>: Since <code>nums[1] = 3</code> is the maximum value in <code>nums</code>, no jump increases the value.</li>
	<li>For <code>i = 2</code>: Jump to <code>j = 1</code> as <code>nums[j] = 3</code> is greater than <code>nums[2] = 1</code>.</li>
</ul>

<p>Thus, <code>ans = [3, 3, 3]</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup>​​​​​​​</code></li>
</ul>
