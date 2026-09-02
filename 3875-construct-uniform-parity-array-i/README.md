<h2><a href="https://leetcode.com/problems/construct-uniform-parity-array-i/editorial/?envType=daily-question&envId=2026-09-02&status=NOT_STARTED&page=1&difficulty=EASY&sorting=W3sic29ydE9yZGVyIjoiREVTQ0VORElORyIsIm9yZGVyQnkiOiJBQ19SQVRFIn1d">4256. Construct Uniform Parity Array I</a></h2><h3>Easy</h3><hr><p>You are given an array <code>nums1</code> of <code>n</code> <strong>distinct</strong> integers.</p>

<p>You want to construct another array <code>nums2</code> of length <code>n</code> such that the elements in <code>nums2</code> are either <strong>all odd or all even</strong>.</p>

<p>For each index <code>i</code>, you must choose <strong>exactly one</strong> of the following (in any order):</p>

<ul>
	<li><code>nums2[i] = nums1[i]</code></li>
	<li><code>nums2[i] = nums1[i] - nums1[j]</code>, for an index <code>j != i</code></li>
</ul>

<p>Return <code>true</code> if it is possible to construct such an array, otherwise, return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums1 = [2,3]</span></p>

<p><strong>Output:</strong> <span class="example-io">true</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Choose <code>nums2[0] = nums1[0] - nums1[1] = 2 - 3 = -1</code>.</li>
	<li>Choose <code>nums2[1] = nums1[1] = 3</code>.</li>
	<li><code>nums2 = [-1, 3]</code>, and both elements are odd. Thus, the answer is <code>true</code>​​​​​​​.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums1 = [4,6]</span></p>

<p><strong>Output:</strong> <span class="example-io">true</span></p>

<p><strong>Explanation:</strong>​​​​​​​</p>

<ul>
	<li>Choose <code>nums2[0] = nums1[0] = 4</code>.</li>
	<li>Choose <code>nums2[1] = nums1[1] = 6</code>.</li>
	<li><code>nums2 = [4, 6]</code>, and all elements are even. Thus, the answer is <code>true</code>.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n == nums1.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums1[i] &lt;= 100</code></li>
	<li><code>nums1</code> consists of distinct integers.</li>
</ul>
