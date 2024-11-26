<h2><a href="https://leetcode.com/problems/find-champion-ii">3189. Find Champion II</a></h2><h3>Medium</h3><hr><p>There are <code>n</code> teams numbered from <code>0</code> to <code>n - 1</code> in a tournament; each team is also a node in a <strong>DAG</strong>.</p>

<p>You are given the integer <code>n</code> and a <strong>0-indexed</strong> 2D integer array <code>edges</code> of length <code><font face="monospace">m</font></code> representing the <strong>DAG</strong>, where <code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>]</code> indicates that there is a directed edge from team <code>u<sub>i</sub></code> to team <code>v<sub>i</sub></code> in the graph.</p>

<p>A directed edge from <code>a</code> to <code>b</code> in the graph means that team <code>a</code> is <strong>stronger</strong> than team <code>b</code> and team <code>b</code> is <strong>weaker</strong> than team <code>a</code>.</p>

<p>Team <code>a</code> will be the <strong>champion</strong> of the tournament if there is no team <code>b</code> that is <strong>stronger</strong> than team <code>a</code>.</p>

<p>Return <em>the team that will be the <strong>champion</strong> of the tournament if there is a <strong>unique</strong> champion, otherwise, return </em><code>-1</code><em>.</em></p>

<p><strong>Notes</strong></p>

<ul>
	<li>A <strong>cycle</strong> is a series of nodes <code>a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub>, a<sub>n+1</sub></code> such that node <code>a<sub>1</sub></code> is the same node as node <code>a<sub>n+1</sub></code>, the nodes <code>a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub></code> are distinct, and there is a directed edge from the node <code>a<sub>i</sub></code> to node <code>a<sub>i+1</sub></code> for every <code>i</code> in the range <code>[1, n]</code>.</li>
	<li>A <strong>DAG</strong> is a directed graph that does not have any <strong>cycle</strong>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><img height="300" src="https://assets.leetcode.com/uploads/2023/10/19/graph-3.png" width="300" /></p>

<pre>
<strong>Input:</strong> n = 3, edges = [[0,1],[1,2]]
<strong>Output:</strong> 0
<strong>Explanation: </strong>Team 1 is weaker than team 0. Team 2 is weaker than team 1. So the champion is team 0.
</pre>

<p><strong class="example">Example 2:</strong></p>

<p><img height="300" src="https://assets.leetcode.com/uploads/2023/10/19/graph-4.png" width="300" /></p>

<pre>
<strong>Input:</strong> n = 4, edges = [[0,2],[1,3],[1,2]]
<strong>Output:</strong> -1
<strong>Explanation:</strong> Team 2 is weaker than team 0 and team 1. Team 3 is weaker than team 1. But team 1 and team 0 are not weaker than any other teams. So the answer is -1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>m == edges.length</code></li>
	<li><code>0 &lt;= m &lt;= n * (n - 1) / 2</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= edge[i][j] &lt;= n - 1</code></li>
	<li><code>edges[i][0] != edges[i][1]</code></li>
	<li>The input is generated such that if team <code>a</code> is stronger than team <code>b</code>, team <code>b</code> is not stronger than team <code>a</code>.</li>
	<li>The input is generated such that if team <code>a</code> is stronger than team <code>b</code> and team <code>b</code> is stronger than team <code>c</code>, then team <code>a</code> is stronger than team <code>c</code>.</li>
</ul>
