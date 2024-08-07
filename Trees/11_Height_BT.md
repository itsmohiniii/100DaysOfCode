**Comparison of SC** (Recursive vs Level Order Approach):  

Recursive Approach :  
SC: O(N) => it takes O(H) for recursive auxiliary stack space WC: if skewed tree, height of binary tree will be N, hence, SC = O(N).  
This approach is better as generally, binary trees are not skewed rather they generally have a small height of logN. then SC: O(H) ~ O(logN).

using Level Order Traversal :  
SC: O(N) => for queue WC: if complete BT & last level is completely filled, queue will end up storing almost all N nodes.       
        
![image](https://github.com/user-attachments/assets/f652c7fb-3fe6-4f26-8195-e2c9c76c900a)   

**Recursive Approach:**   

Recurrence Relation : height of the node = 1 + max(lh, rh)  
where lh => height of left subtree, rh => height of right subtree.        
     
![image](https://github.com/user-attachments/assets/462daa4d-255f-4fa6-acf3-175323ab67f0)   

Implementation:    
       
![image](https://github.com/user-attachments/assets/5fef4cda-67b7-421e-a040-c8aaca87a237)

