Dijkstra algo can be implemented using following 3 ways :   
1. using Queue (least optimised way)  
2. using Priority queue (min heap)  
3. using Set (best way)  
  
**Why PQ and not Q?**   
Brute force (queue) -> If we use queue, we will explore all possible paths and then figure our the minimal. (unnecesaary exploration of paths, unnecessary iterations, hence more time complexity)
PQ -> Using PQ, we will always go to the minimal first, minimal first and so on (greedy algorithm) so that we can mark all the minimal distances first and then go to the others, and then we will not need to explore those paths.

  
  
Dijkstra Algorithm is only applicable for graphs with positive weights.  
Not applicable to graphs with negative weight.  
  
![image](https://github.com/user-attachments/assets/e5fb57ce-8587-4ca7-b838-234b3e2ba0ba)
