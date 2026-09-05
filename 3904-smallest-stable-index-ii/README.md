<h2><a href="https://leetcode.com/problems/smallest-stable-index-ii">4285. Smallest Stable Index II</a></h2><h3>Medium</h3><hr><p>You are given an integer array <code>nums</code> of length <code>n</code> and an integer <code>k</code>.</p>

<p>For each index <code>i</code>, define its <strong>instability score</strong> as <code>max(nums[0..i]) - min(nums[i..n - 1])</code>.</p>

<p>In other words:</p>

<ul>
	<li><code>max(nums[0..i])</code> is the <strong>largest</strong> value among the elements from index 0 to index <code>i</code>.</li>
	<li><code>min(nums[i..n - 1])</code> is the <strong>smallest</strong> value among the elements from index <code>i</code> to index <code>n - 1</code>.</li>
</ul>

<p>An index <code>i</code> is called <strong>stable</strong> if its instability score is <strong>less than or equal to</strong> <code>k</code>.</p>

<p>Return the <strong>smallest</strong> stable index. If no such index exists, return -1.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [5,0,1,4], k = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>At index 0: The maximum in <code>[5]</code> is 5, and the minimum in <code>[5, 0, 1, 4]</code> is 0, so the instability score is <code>5 - 0 = 5</code>.</li>
	<li>At index 1: The maximum in <code>[5, 0]</code> is 5, and the minimum in <code>[0, 1, 4]</code> is 0, so the instability score is <code>5 - 0 = 5</code>.</li>
	<li>At index 2: The maximum in <code>[5, 0, 1]</code> is 5, and the minimum in <code>[1, 4]</code> is 1, so the instability score is <code>5 - 1 = 4</code>.</li>
	<li>At index 3: The maximum in <code>[5, 0, 1, 4]</code> is 5, and the minimum in <code>[4]</code> is 4, so the instability score is <code>5 - 4 = 1</code>.</li>
	<li>This is the first index with an instability score less than or equal to <code>k = 3</code>. Thus, the answer is 3.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [3,2,1], k = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">-1</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>At index 0, the instability score is <code>3 - 1 = 2</code>.</li>
	<li>At index 1, the instability score is <code>3 - 1 = 2</code>.</li>
	<li>At index 2, the instability score is <code>3 - 1 = 2</code>.</li>
	<li>None of these values is less than or equal to <code>k = 1</code>, so the answer is -1.</li>
</ul>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [0], k = 0</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p>At index 0, the instability score is <code>0 - 0 = 0</code>, which is less than or equal to <code>k = 0</code>. Therefore, the answer is 0.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>
