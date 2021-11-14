<h2>1286. Iterator for Combination</h2><h3>Medium</h3><hr><div><p>Design the <code>CombinationIterator</code> class:</p>

<ul>
	<li><code>CombinationIterator(string characters, int combinationLength)</code>&nbsp;Initializes the object with&nbsp;a string&nbsp;<code>characters</code>&nbsp;of <strong>sorted distinct</strong> lowercase English letters and a number&nbsp;<code>combinationLength</code> as arguments.</li>
	<li><code>next()</code>&nbsp;Returns the next combination of length <code>combinationLength</code>&nbsp;in <strong>lexicographical order</strong>.</li>
	<li><code>hasNext()</code>&nbsp;Returns <code>true</code>&nbsp;if and only if&nbsp;there exists a next combination.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["CombinationIterator", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[["abc", 2], [], [], [], [], [], []]
<strong>Output</strong>
[null, "ab", true, "ac", true, "bc", false]

<strong>Explanation</strong>
CombinationIterator itr = new CombinationIterator("abc", 2);
itr.next();    // return "ab"
itr.hasNext(); // return True
itr.next();    // return "ac"
itr.hasNext(); // return True
itr.next();    // return "bc"
itr.hasNext(); // return False
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= combinationLength &lt;=&nbsp;characters.length &lt;= 15</code></li>
	<li>All the characters of <code>characters</code> are <strong>unique</strong>.</li>
	<li>At most <code>10<sup>4</sup></code>&nbsp;calls will be made to <code>next</code> and <code>hasNext</code>.</li>
	<li>It's guaranteed that all&nbsp;calls&nbsp;of the function <code>next</code>&nbsp;are valid.</li>
</ul>
</div>