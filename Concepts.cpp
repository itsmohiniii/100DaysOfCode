//initialised with garbage values (as no initialser given)
int array[5]; //{4199631, 4238448, 0, 0, 8}

//initialised with given values (as initialser is given) 
//and if the # of initializers < # of elements in the array, remaining elements are initialized to 0 for fundamental data types like int.
int array[5]={}; //{0, 0, 0, 0, 0}
int array[5]={0}; //{0, 0, 0, 0, 0}
int array[5]={-1}; //{-1, 0, 0, 0, 0}
