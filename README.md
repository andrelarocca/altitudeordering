# Altitude Ordering
An implementation of a simple algorithm that yields a binary partition tree by altitude ordering, as seen in Laurent Najman, Jean Cousty, Benjamin Perret. Playing with Kruskal: algorithms for mor- phological trees in edge-weighted graphs. C.L. Luengo Hendriks, G. Borgefors, R. Strand. In- ternational Symposium on Mathematical Morphology, May 2013, Uppsala, Sweden. Springer, 7883, pp.135-146, 2013, Lecture Notes in Computer Science. &lt;hal-00798621>.

# Usage
To compile this program, simply type on the shell:
    make

There are two ways to use this algorithm:

* 1) Insert graph data manually:
  * - Run the program using `./altitude`
  * - The program will instruct you to type the weight of each edge, e.g.: `Edge between 'c' and 'g': `
  * - Type `-1` if there's no edge between 'c' and 'g', or the weight of the edge.
* 2) Get graph data from file:
  * - Run the program using `./altitude test.in`
  * - The program will automatically get data from file.
  * - You will learn how to format the file in the next section
  
## Debugging
_Debug is only available if you choose the *Get graph data from file* way of using._
Simple as it should be, just add the option `debug` after your command line, like this:
`./altitude test.in debug`

# File Format
The input file should have one integer on each line.
The first line represents the number of vertices, and the following ones represents the weight of the graph edges, according to the rule:
The first line (after the number of vertices) represents the weight of the edge between 'a' and 'b'. After that, in the next line, the weight of the edge between 'a' and 'c', an go on, like this:

    4  //Four vertices
    3  //Edge between 'a' and 'b' weights 3
    -1 //No edge between 'a' and 'c'
    2  //Edge between 'a' and 'd' weights 2
    5  //Edge between 'b' and 'c' weights 5
    -1 //No edge between 'b' and 'd'
    4  //Edge between 'c' and 'd' weights 4`

_**ATTENTION:** Comments are not allowed in the file, they are just a way to explain!_

Contact me if you want to suggest anything or complain about something!

André La Rocca <andrelarocca@gmail.com>
