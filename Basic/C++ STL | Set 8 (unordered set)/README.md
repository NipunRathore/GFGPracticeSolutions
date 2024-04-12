<h2><a href="https://www.geeksforgeeks.org/problems/c-stl-set-8-unordered-set/1?page=1&difficulty=Basic&status=unsolved&sortBy=accuracy">C++ STL | Set 8 (unordered set)</a></h2><h3>Difficulty Level : Basic</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:20px">Implement different operations on an unordered set&nbsp;s&nbsp;.<br>
<br>
<strong>Input:</strong><br>
The first line of input contains an integer <strong>T</strong> denoting the no of test cases . Then T test cases follow. The first line of input contains an integer <strong>Q</strong> denoting the no of queries . Then in the next line are <strong>Q</strong>&nbsp;space separated queries .<br>
A query can be of&nbsp;four&nbsp;types&nbsp;<br>
1. a x (inserts an element x to the unordered set s)<br>
2. b&nbsp;x&nbsp;(erases an element x from the unordered set s)<br>
3. c&nbsp;x (prints 1 if the element x is present in the set&nbsp;else print -1)<br>
4. d &nbsp; &nbsp;(prints the size of the unordered set s)<br>
<br>
<strong>Output:</strong><br>
The output for each test case will&nbsp;&nbsp;be space separated integers denoting the results of each query .&nbsp;<br>
<br>
<strong>Constraints:</strong><br>
1&lt;=T&lt;=100<br>
1&lt;=Q&lt;=100<br>
<br>
<strong>Example(To be used only for only expected output):</strong></span></p>

<p><span style="font-size:20px"><strong>Input</strong><br>
2<br>
5<br>
a 1 a 2 a 3 b 2 d<br>
4<br>
a 1 a 5 d c 2<br>
<strong>&nbsp;<br>
Output</strong><br>
2<br>
2 -1<br>
<br>
<strong>Explanation :<br>
For the first test case</strong><br>
There are five&nbsp;queries.&nbsp;Queries&nbsp;are&nbsp;performed in this order<br>
1. a 1 &nbsp; &nbsp; {inserts 1 to set now set has {1}&nbsp;}<br>
2. a 2 &nbsp; &nbsp; {inserts 2&nbsp;to set now set has {1,2}&nbsp;}<br>
3. a 3 &nbsp; &nbsp; {inserts 3 to set now set has {1,2,3}&nbsp;}<br>
4. b&nbsp;2 &nbsp; &nbsp; {removes 2 from the set&nbsp;}<br>
5. d &nbsp; &nbsp; &nbsp; &nbsp;{prints the size of the unordered set ie 2}<br>
<br>
<strong>For the second test case&nbsp;</strong><br>
There are four&nbsp;queries.&nbsp;Queries&nbsp;are&nbsp;performed in this order<br>
1. a 1&nbsp; &nbsp; {inserts 1 to set now set has {1}&nbsp;}<br>
2. a 5&nbsp; &nbsp; {inserts 5&nbsp;to set now set has {1,5}&nbsp;}<br>
3. d&nbsp; &nbsp; &nbsp; &nbsp;{prints the size of the set ie 2}<br>
4. c&nbsp;2 &nbsp; &nbsp;{since 2 is not present in the set prints -1}</span><br>
<br>
<br>
<span style="font-size:16px"><strong>Note:</strong>The <strong>Input/Output</strong> format and <strong>Example</strong> given are used for system's internal purpose, and should be used by a user for <strong>Expected Output</strong> only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.</span></p>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>CPP</code>&nbsp;<code>STL</code>&nbsp;