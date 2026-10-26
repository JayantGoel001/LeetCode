<h2><a href="https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k">3823. Count Islands With Total Value Divisible by K</a></h2><h3>Medium</h3><hr><p>You are given an <code>m x n</code> matrix <code>grid</code> and a positive integer <code>k</code>. An <strong>island</strong> is a group of <strong>positive</strong> integers (representing land) that are <strong>4-directionally</strong> connected (horizontally or vertically).</p>

<p>The <strong>total value</strong> of an island is the sum of the values of all cells in the island.</p>

<p>Return the number of islands with a total value <strong>divisible by</strong> <code>k</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2025/03/06/example1griddrawio-1.png" style="width: 200px; height: 200px;" />
<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">grid = [[0,2,1,0,0],[0,5,0,0,5],[0,0,1,0,0],[0,1,4,7,0],[0,2,0,0,8]], k = 5</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p>The grid contains four islands. The islands highlighted in blue have a total value that is divisible by 5, while the islands highlighted in red do not.</p>
</div>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2025/03/06/example2griddrawio.png" style="width: 200px; height: 150px;" />
<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">grid = [[3,0,3,0], [0,3,0,3], [3,0,3,0]], k = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">6</span></p>

<p><strong>Explanation:</strong></p>

<p>The grid contains six islands, each with a total value that is divisible by 3.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 1000</code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>6</sup></code></li>
</ul>
