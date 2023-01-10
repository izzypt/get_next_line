# get_next_line
This project is about programming a function that returns a line read from a file descriptor

## Helpful Concepts

### Static Variables

            static int variable_name; // declaring static integer value with name variable_name


- Static variables are the variables which once declared, get destroyed only when the program has completed its execution. 

- They have the property of retaining their previous scope value if they are already declared once in the program. 

- They are different from normal variables because normal variables do not retain their previous value. 

- Normal variables get destroyed once they go out of scope. But when static variables are initialized, they get destroyed only after the whole program gets executed.

            
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
            //program prints “1 2” 
          }
