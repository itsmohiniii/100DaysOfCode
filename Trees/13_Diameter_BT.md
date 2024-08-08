**Diamter of Binary tree:**     
     
![image](https://github.com/user-attachments/assets/dc640a90-c556-4fb9-ab4e-34a314a70cd3)    
    
**Brute Force Approach:**          
Take the longest on every node considering that node as the curve point.           
Length of the longest path passing via the given node = lh+rh.     
For N nodes, we can find (lh+rh) for every node, then diameter of Binary tree = max(lh+rh).  
     
![image](https://github.com/user-attachments/assets/e7c00058-46fc-4737-a6b9-2f37eb13c25c)

TC: O(N)*O(N) ~ O(N*N) => O(N) for traversal of entire tree, O(N) for finding left height and right height overall (WC - if tree is skewed)     
      
![image](https://github.com/user-attachments/assets/2fd26a51-2156-46f6-b76d-71402ae63ed4)
          
