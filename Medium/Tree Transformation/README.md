<h2><a href="https://practice.geeksforgeeks.org/problems/tree-transformation--170645/1?page=11&difficulty[]=1&sortBy=accuracy">Tree Transformation</a></h2><h3>Difficulty Level : Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a connected undirected tree with <strong>N&nbsp;</strong>nodes. In one move, you can merge any two adjacent nodes. Calculate the minimum number of moves required to turn the tree into a <strong>star</strong> tree.</span></p>

<blockquote>
<p><span style="font-size:18px">-&gt; Merging adjacent nodes means deleting the edge between them and considering both the nodes as a single one.<br>
-&gt;&nbsp;A Star tree is a tree with a center&nbsp;node, and all other nodes are connected to the center node only.</span></p>
</blockquote>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 5
p[] = {-1, 0, 0, 1, 1}
<strong>Output:
</strong>1
<strong>Explanation</strong>: 
Tree looks like:
            0
&nbsp;          / \ 
         1    2 
       /  \ 
      3    4
Merge the edge 0 - 2 in one operation

</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong> N = 8
p[] = {-1 0 0 0 0 2 2 5}
<strong>Output:</strong>
2
<strong>Explanation</strong>:
Tree looks like:
              0
           / / \ \
          / |   |  \
        1   2   3   4
           / \
          5   6
          |
          7
Merge node 5 to 2 and then 2 to 0, 
thus tree formed will be a star tree. </span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read, input, or print anything. Your task is to complete the function <strong><em>solve( )</em>, </strong>which takes integer <strong>N, </strong>and an array <strong>p[ ] </strong>as input parameters and returns the minimum number of moves required to turn the tree into a <strong>star</strong> tree.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(N)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>5</sup><br>
0 ≤ p[i] &lt; N<br>
p[0] = -1, 0 is the root node.</span></p>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;