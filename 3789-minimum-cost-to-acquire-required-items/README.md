<h2><a href="https://leetcode.com/problems/minimum-cost-to-acquire-required-items">4147. Minimum Cost to Acquire Required Items</a></h2><h3>Medium</h3><hr><p>You are given five integers <code>cost1</code>, <code>cost2</code>, <code>costBoth</code>, <code>need1</code>, and <code>need2</code>.</p>

<p>There are three types of items available:</p>

<ul>
	<li>An item of <strong>type 1</strong> costs <code>cost1</code> and contributes 1 unit to the type 1 requirement only.</li>
	<li>An item of <strong>type 2</strong> costs <code>cost2</code> and contributes 1 unit to the type 2 requirement only.</li>
	<li>An item of <strong>type 3</strong> costs <code>costBoth</code> and contributes 1 unit to <strong>both</strong> type 1 and type 2 requirements.</li>
</ul>

<p>You must collect enough items so that the total contribution toward type 1 is <strong>at least</strong> <code>need1</code> and the total contribution toward type 2 is <strong>at least</strong> <code>need2</code>.</p>

<p>Return an integer representing the <strong>minimum</strong> possible total cost to achieve these requirements.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">cost1 = 3, cost2 = 2, costBoth = 1, need1 = 3, need2 = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>After buying three type 3 items, which cost <code>3 * 1 = 3</code>, the total contribution to type 1 is 3 (<code>&gt;= need1 = 3</code>) and to type 2 is 3 (<code>&gt;= need2 = 2</code>).<br data-end="229" data-start="226" />
Any other valid combination would cost more, so the minimum total cost is 3.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">cost1 = 5, cost2 = 4, costBoth = 15, need1 = 2, need2 = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">22</span></p>

<p><strong>Explanation:</strong></p>

<p>We buy <code>need1 = 2</code> items of type 1 and <code>need2 = 3</code> items of type 2: <code>2 * 5 + 3 * 4 = 10 + 12 = 22</code>.<br />
Any other valid combination would cost more, so the minimum total cost is 22.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">cost1 = 5, cost2 = 4, costBoth = 15, need1 = 0, need2 = 0</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p>Since no items are required (<code>need1 = need2 = 0</code>), we buy nothing and pay 0.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= cost1, cost2, costBoth &lt;= 10<sup>6</sup></code></li>
	<li><code>0 &lt;= need1, need2 &lt;= 10<sup>9</sup></code></li>
</ul>
