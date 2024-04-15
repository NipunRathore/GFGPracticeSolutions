<h2><a href="https://www.geeksforgeeks.org/problems/c-inheritance-introduction/1?page=1&difficulty=Basic&status=unsolved&sortBy=accuracy">C++ Inheritance introduction</a></h2><h3>Difficulty Level : Basic</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Create two classes:</span></p>

<p><span style="font-size:18px"><strong>Cuboid</strong><br>
The Cuboid class should have three data fields- length,&nbsp;<em>width</em>&nbsp;and&nbsp;<em>height</em>&nbsp;of&nbsp;<em>int</em>&nbsp;types. The class should have d<em>isplay()&nbsp;</em>method, to print the length,&nbsp;<em>width</em>&nbsp;and&nbsp;<em>height</em>&nbsp;of the cuboid separated by space.</span></p>

<p><span style="font-size:18px"><strong>CuboidVol</strong>&nbsp;<br>
The&nbsp;<em>CuboidVol</em>&nbsp;class is derived from Cuboid class, i.e., it is the sub-class of <em>Cuboid</em> class. The class should have&nbsp;<em>read_input()</em>&nbsp;method, to read the values of length,&nbsp;<em>width</em>&nbsp;and&nbsp;<em>height</em>&nbsp;of the Cuboid. The&nbsp;<em>CuboidVol</em>&nbsp;class should also overload the&nbsp;<em>display()</em>&nbsp;method to print the volume</span><span style="font-size:18px">&nbsp;of</span><span style="font-size:18px"> the&nbsp;Cuboid ( length * width * height ).</span></p>

<p><span style="font-size:18px"><strong>Input:</strong></span></p>

<p><em><span style="font-size:18px">The first line contains the number of test&nbsp;cases and one and only line of each test case contains 3 space separated integer denoting length, width, and height of the Cuboid</span></em></p>

<p><span style="font-size:18px"><strong>Output:</strong></span></p>

<p><span style="font-size:18px"><em>The output should consist of exactly two lines:&nbsp;<br>
In the first line, print the length, width,&nbsp;and&nbsp;height&nbsp;of the cuboid separated by space.&nbsp;<br>
In the second line, print the volume of the cuboid.</em><br>
<strong>Constraints:</strong></span></p>

<p><span style="font-size:18px"><em>0 &lt;= (length, width, height) &lt;= 100</em><br>
<strong>Example:</strong></span></p>

<p><strong><em><span style="font-size:18px">Sample input:</span></em></strong></p>

<p><span style="font-size:18px">1</span></p>

<p><span style="font-size:18px">12 10 2</span></p>

<p><strong><em><span style="font-size:18px">Sample output:</span></em></strong></p>

<p><span style="font-size:18px">12 10 2&nbsp;</span></p>

<p><span style="font-size:18px">240</span></p>

<p><span style="font-size:18px"><strong>Explanation:</strong></span></p>

<p><span style="font-size:18px">As here length = 12, width = 10 and height = 2</span></p>

<p><span style="font-size:18px">Volume of the cuboid is = ( length * width * height )</span></p>

<p><span style="font-size:18px">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; = 12 * 10 * 2</span></p>

<p><span style="font-size:18px">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; = 240</span></p>

<p>&nbsp;</p>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>CPP</code>&nbsp;<code>OOP</code>&nbsp;