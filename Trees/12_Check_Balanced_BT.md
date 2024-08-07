![image](https://github.com/user-attachments/assets/d2448811-7aff-4b6c-90ec-f7bc12f80b79)    
     
**Brute Force (Naive) Approach:**    
TC: O(N)*O(N) ~ O(N*N) => O(N) for traversal, O(N) for finding lh and rh overall (WC - if tree is skewed)
      
![image](https://github.com/user-attachments/assets/3ff4b650-b3a3-4dea-8bd2-fa5b283bb3ed)       

**Optimal Approach:**   
I want the function to return true or false basis on whether BT is balanced or not. But as maxDepth() function returns the height of BT. We will **return -1** if the BT is **unbalanced** and **return height of tree** if it is **balanced** BT.      

![image](https://github.com/user-attachments/assets/64a0ff54-7bd6-4de6-a990-5b4df34980e6)
    
    
    
