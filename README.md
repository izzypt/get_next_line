# get_next_line
This project is about programming a function that returns a line read from a file descriptor one line at a time for each time the function is called. 

Our program should return only 1 line at a time regardless of the BUFFER_SIZE (from 1 to 9999)

Managing memory and stashing the read chuncks until a '\n' is found are important steps for the program.

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
            

    ### Here are some properties of the static variable in the C programming language.

    1 - A static variable is destroyed only after the whole program gets executed. It does not depend on the scope of the function in which it is declared.
    
    2 - A static variable has a property to retain its value from its previous scope. This means that its value does not get re-initialized if the function in which it is declared gets called multiple times.
    
    3 - If no value is assigned to a static variable, by default, it takes the value 0.
    
    4 - The memory of the static variable is available throughout the program but its scope is only restricted to the block where it is declared. For example, if we declare a static variable inside a function, we cannot access this static variable from outside of this function.
     
       
### read()

The read() function is a system call in the C standard library that reads data from a file descriptor. It takes three arguments:

- The file descriptor of the file to read from
- A pointer to a buffer that will hold the data that's read
- The number of bytes to read

It returns the number of bytes that were actually read. If an error occurs, -1 is returned and the global variable errno is set to indicate the error.

When you call the read() function, the system checks the file descriptor to see which file it corresponds to and reads that number of bytes from the file into the buffer. The position in the file from where the data will be read is determined by the file offset. This means that the next time you call read(), it will continue reading from the file from the point where it left off.

It's important to note that read() reads only one time and returns the number of bytes it has read.
In the case that you are using the read() to read a line by line, you will have to make a loop until a new line is found, on each loop the read() will be called.

read() reads the data in binary mode, meaning it reads the data as it is in the file, without adding or removing any characters. If you're reading a text file and want to treat the newline characters in a platform-independent way, you can use the fgets() or getline() function as explained earlier.
