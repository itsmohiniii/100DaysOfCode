A graph can have multiple components (not connected to each other via edge)  
and that is still a graph.

Hence,  
we need to keep a **vis array** for the nodes  
n=11

for(i=1;i<n;i++){  //1-based indexing  
  if(!vis[i]){  
    traversal(i);  
  }  
}  

![image](https://github.com/itsmohiniii/15DaysOfCode/assets/74259856/c4fd3fc9-ef09-4f17-8446-110b15288f29)

