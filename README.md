# ft_ls
My own version of unix command ls
Handles flags	: Raltrugf1
Different colours for different file types
No memory leaks.
Handles ACL

# Compilation
In order to get the excutable ft_ls you will have to use the Makefile to create an executable.

## First time compilation
To compile the executable run the following:

    make
    
Please follow the inforgraphic below:

![compile](compile.gif)

## Recompilation
To recomplie the project after making some changes

   make re

You can also delete file with:
   
   make clean
   make fclean

![recompile](recompile.gif)

## Running

Once you have compiled the executable with:

   make

You can run the program with the following:

    ./ft_ls

This will give you the basic output of the unix command ls.

    man ls

To find out all the flags and what they do. See above for list of flags that run with this ft ls.
Alternatively you may run:

    ./ft_ls help

