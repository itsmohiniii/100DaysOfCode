**Dijkstra algo can be implemented using following 3 ways :**   
1. using Queue (least optimised way)  
2. using Priority queue (min heap)  
3. using Set (best way)  
  
**Why PQ and not Q?**   
Brute force (queue) -> If we use queue, we will explore all possible paths and then figure our the minimal. (unnecesaary exploration of paths, unnecessary iterations, hence more time complexity)   
PQ -> Using PQ, we will always go to the minimal first, minimal first and so on (greedy algorithm) so that we can mark all the minimal distances first and then go to the others, and then we will not need to explore those paths.

  
  
**Dijkstra Algorithm is only applicable for graphs with positive weights.**  
Not applicable to graphs with negative weight.  
  
![image](https://github.com/user-attachments/assets/e5fb57ce-8587-4ca7-b838-234b3e2ba0ba)    


    
**TC Derivation of Dijkstra's Algorithm:**  

TC: O(ElogV) where E-> no. of edges, V-> no. of nodes/vertices

Pseudocode of Priority Queue :  
  
![image](https://github.com/user-attachments/assets/b34ffae0-0055-4716-bff5-9369ff265469)

Derivation:

O( V * ( pop vertex from min heap + no. of edges on each vertex * push in PQ ))

O( V * ( log(heapSize) + no. of edges * log(heapSize))

O( V * (log(heapSize) + V-1 * log(heapSize))    { one vertex can have V-1 edges }

O( V * (log(heapSize) * (V-1+1))

O( V * V * log(heapSize))

Now, at the worst case the heapSize will be equivalent to v² as if we consider pushing adjacent elements of a node, at the worst case each element will have V-1 nodes and they will be pushed onto the queue.

O( V * V * log(v²))

O ( v² * 2 log (V))

O ( E * 2 log(V))  { E= v², total number of edges}

O ( E * log(V))  Worst case Time Complexity of Dijkstra’s Algorithm.

