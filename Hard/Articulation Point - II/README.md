<h2><a href="https://practice.geeksforgeeks.org/problems/articulation-point2616/1">Articulation Point - II</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an undirected graph (not necessarily connected) with&nbsp;<strong>V&nbsp;</strong>vertices and adjacency list&nbsp;<strong>adj</strong>. You are required to find all the vertices removing which</span>&nbsp;<span style="font-size: 18px;">(and edges through it) disconnects the graph into 2 or more components,</span>&nbsp;<span style="font-size: 18px;">or in other words,&nbsp;removing which increases the number of connected components.</span><br><span style="font-size: 18px;"><strong>Note:&nbsp;</strong>Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.</span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong></span><img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/705655/Web/Other/45dad444-f8bf-41ba-98a8-5aaee97661c3_1685087131.png" alt="">
<span style="font-size: 18px;"><strong>Output:</strong>{1,4}
<strong>Explanation: </strong>Removing the vertex 1 will
discconect the graph as-
</span><img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/705655/Web/Other/7a95e57c-2585-49de-8a1e-fa9d132d05eb_1685087131.png" alt="">
<span style="font-size: 18px;">Removing the vertex 4 will disconnect the
graph as-
</span><img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/705655/Web/Other/0fe03c03-a0d1-4b5b-bc17-bf2d8c67810e_1685087131.png" alt="">
</pre>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read or print anything. Your task is to complete the function&nbsp;<strong>articulationPoints</strong><strong>()&nbsp;</strong>which takes V and adj as input parameters and returns a list containing all the vertices removing which turn the graph into two or more disconnected components in sorted order. If there are no such vertices then returns a list containing -1.</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:&nbsp;</strong>O(V + E)<br><strong>Expected Auxiliary Space:&nbsp;</strong>O(V)</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ V ≤ 10<sup>4</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Graph</code>&nbsp;<code>Data Structures</code>&nbsp;