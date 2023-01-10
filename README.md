# get_next_line
This project is about programming a function that returns a line read from a file descriptor

## Helpful Concepts

### Static Variables

            static int variable_name; // declaring static integer value with name variable_name


- Static variables are the variables which once declared, get destroyed only when the program has completed its execution. 

- They have the property of retaining their previous scope value if they are already declared once in the program. 

- They are different from normal variables because normal variables do not retain their previous value. 

- Normal variables get destroyed once they go out of scope. But when static variables are initialized, they get destroyed only after the whole program gets executed.


            void Func() {
              static int x = 0;
              // |x| is initialized only once across five calls of |Func| and the variable
              // will get incremented five times after these calls. The final value of |x|
              // will be 5.
              x++;
              printf("%d\n", x);  // outputs the value of |x|
            }

            int main() {
              Func();  // prints 1
              Func();  // prints 2
              Func();  // prints 3
              Func();  // prints 4
              Func();  // prints 5

              return 0;
            }
