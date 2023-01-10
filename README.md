# get_next_line
This project is about programming a function that returns a line read from a file descriptor

## Helpful Concepts

### Static Variables

Static variables have a property of preserving their value even after they are out of their scope! Hence, static variables preserve their previous value in their previous scope and are not initialized again in the new scope. 

-  A static int variable remains in memory while the program is running. A normal or auto variable is destroyed when a function call where the variable was declared is over. 
       
        For example, we can use static int to count a number of times a function is called, but an auto variable can’t be used for this purpose.
        For example below program prints “1 2” 
        
        ```        
          #include<stdio.h>
          
          int fun()
          {
            static int count = 0;
            count++;
            return count;
          }

          int main()
          {
            printf("%d ", fun());
            printf("%d ", fun());
            return 0;
          }
        ```
