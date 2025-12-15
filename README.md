# **C - Simple Shell**


## **Description** 

### **description of the printf function**

## **compilation**
```bash

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c

```

## **Requirements**

### **Requirements for the project**

**1. Text Editor:** you are allowed to use vi, vim, nano and emacs to modify the code

**2. Operating System:** this project has to be done on Ubuntu 20.04

**3. Coding Style:** you must use the betty style coding and documentation

**4. authorized functions and macros :** 


**5. File Endings:** Ensure that all source code files (.c files) end with a newline character (\n).

**6. Header Inclusion:** Include the "main.h" header file in all .c files to access necessary declarations and definitions.

## **Flowchart**



## **Example Usage**

**Consider the following input code:**

```C

int main(void) {
	int len;
	int len2;
	unsigned int ui;
	void *addr;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("Address:[%p]\n", addr);
	printf("Address:[%p]\n", addr);
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	_printf("Unknown:[%r]\n");
	printf("Unknown:[%r]\n");
	return (0);
}

```

### Expected Output


```bash

Let's try to printf a simple sentence.
Let's try to printf a simple sentence.
Length:[39, 39]
Length:[39, 39]
Negative:[-762534]
Negative:[-762534]
Unsigned:[2147484671]
Unsigned:[2147484671]
Unsigned octal:[20000001777]
Unsigned octalCreate a Printf Function

```
## **BUGS**

Currently  _printf can print the chars, the strings and the “%”,