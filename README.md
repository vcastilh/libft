# Libft

![Project Badge](https://github.com/vcastilh/42projects-badges/blob/master/libfte.png)

## Description
This project aims to teach how to use a Makefile to create a static library(libft) with functions
that will be usefull for the next projects on 42. Most of them are re-coding of libc implementation functions
called **ft_**(str*.c, mem*.c, is*.c, to*.c) e.g ft_strlen.c, ft_strlcpy.c, referencing **f**ourty **t**wo.

What is a static library?
Basically the process of compilation go as follows: source file(.c) --> object file(.o) --> executable(.out)
A static library is an archieve with a set of object files so them can be used when linking to create the executable.

Take this main.c as an example,

```c
#include "libft.h"

int	main(void)
{
	char	*s;
	size_t	s_len;
	char	*s_upper;

	s = "hello world";
	s_len = ft_strlen(s) + 1;
	s_upper = ft_calloc(s_len, sizeof(char));
	while(--s_len)
	{
		*s_upper = ft_toupper(*s);
		write(1, s_upper, 1);
		s_upper++;
		s++;
	}
	write(1, "\n", 1);
	return (0);
}
```
To compile it without static library would be something like: 
```bash
clang libft.h main.c ft_strlen.c ft_calloc.c ft_toupper.c 
```

With static library:
```bash
clang libft.h main.c libft.a
```

## Installing
```bash
# Cloning project repository
git clone https://github.com/vcastilh/libft.git

# Changing to cloned directory
cd libft

# Compile and archieve functions into static library(libft.a) and then clean all object files generated using make utility(Makefile)
make && make clean

# Move the library and header file to your project directory
mv libft.h libft.a /path/your/project/
```

## Functions available

### Libc
| | Memory | 
---    | --- |
ft_memset | The memset() function writes len bytes of value c (converted to an unsigned char) to the string b. 	
ft_memcpy | The memcpy() function copies len bytes from buffer src to buffer dst. If the two buffers may overlap, memmove(3) must be used instead.
ft_memmove | The memmove() function copies len bytes from buffer src to buffer dst. The two buffers may overlap; the copy is always done in a non-destructive manner.
ft_memchr | The memchr() function locates the first occurrence of c (converted to an unsigned char) in string b.
ft_memcmp | The memcmp() function compares byte string b1 against byte string b2. Both strings are assumed to be len bytes long.
ft_calloc | The calloc() function allocates space for an array of nmemb objects, each of the specified size. The space is initialized to zero.

| | Character |
---   | --- |
ft_isalpha | Test whether c represents a letter.
ft_isdigit | Test for any decimal-digit character. The complete list of decimal digits is 0 and 1–9, in any locale.
ft_isalnum | The isalnum() function tests for any character for which isalpha(3) or isdigit(3) is true
ft_isascii | The isascii() function tests for an ASCII character, which is any character in the range from 0 to 0177, inclusive.
ft_isprint | Test for any printing character including space (‘ ’).
ft_toupper | Convert a lower-case letter to the corresponding upper-case letter.
ft_tolower | Convert a lower-case letter to corresponding upper-case letter.

| | String |
--- | --- |
ft_strlen | The strlen() function computes the length of the string s.
ft_strchr | The strchr() function locates the first occurrence of the character c (converted to a char) in the string s. The terminating NUL character is considered part of the string. If c is ‘\0’, strchr() locates the terminating ‘\0’.<Paste>
ft_strrchr | The strrchr() function locates the last occurrence of the character c (converted to a char) in the string s. The terminating NUL character is considered part of the string. If c is ‘\0’, strrchr() locates the terminating ‘\0’.
ft_strncmp | Compare the NUL-terminated strings s1 and s2, at most len characters.
ft_strnstr | The strnstr() function locates the first occurrence of the null-terminated string needle in the string haystack, where not more than len characters are searched.
ft_strlcpy | Copies up to dstsize - 1 characters from the string src to dst, NUL-terminating the result if dstsize is not 0.
ft_strlcat | Appends string src to the end of dst. It will append at most dstsize - strlen(dst) - 1 characters. It will then NUL-terminate, unless dstsize is 0 or the original dst string was longer than dstsize (in practice this should not happen as it means that either dstsize is incorrect or that dst is not a proper string). If the src and dst strings overlap, the behavior is undefined.
ft_strdup | The strdup() function allocates sufficient memory for a copy of the string s, does the copy, and returns a pointer to it. The pointer may subsequently be used as an argument to the function free(3).
ft_atoi | The atoi() function converts the initial portion of the string pointed to by nptr to integer representation.

### Aditional Functions
| | String |
--- | ----
ft_substr | Allocates (with malloc(3)) and returns a substringfrom the string ’s’.The substring begins at index ’start’ and is ofmaximum size ’len’.
ft_strjoin | Allocates (with malloc(3)) and returns a newstring, which is the result of the concatenationof ’s1’ and ’s2’.
ft_strtrim | Allocates (with malloc(3)) and returns a copy of’s1’ with the characters specified in ’set’ removedfrom the beginning and the end of the string.
ft_split | Allocates (with malloc(3)) and returns an arrayof strings obtained by splitting ’s’ using thecharacter ’c’ as a delimiter.  The array must beended by a NULL pointer.
ft_itoa | Allocates (with malloc(3)) and returns a stringrepresenting the integer received as an argument.Negative numbers must be handled.
ft_strmapi | Applies the function ’f’ to each character ofthe string ’s’ , and passing its index as firstargument to create a new string (with malloc(3))resulting from successive applications of ’f’.
ft_striteri | Applies the function f to each character of thestring passed as argument, and passing its indexas first argument.  Each character is passed byaddress to f to be modified if necessary.

| | Files |
--- | ---
ft_putchar_fd | Outputs the character ’c’ to the given filedescriptor.
ft_putstr_fd | Outputs the string ’s’ to the given filedescriptor.
ft_putendl_fd | Outputs the string ’s’ to the given filedescriptor, followed by a newline.
ft_putnbr_fd | Outputs the integer ’n’ to the given filedescriptor.

