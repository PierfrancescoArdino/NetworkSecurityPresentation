# NetworkSecurityPresentation
Presentation for the NetSec course based on Buffer overflow exploit

# Requisite
    
## disable memory randomization, enable core dumps
    ```bash
    cat /proc/sys/kernel/randomize_va_space
    sudo bash -c 'echo "kernel.randomize_va_space = 0" >> /etc/sysctl.conf'
    sudo sysctl -p
    cat /proc/sys/kernel/randomize_va_space
    # verify "0"
    ulimit -c unlimited
    ulimit -c
    # verify "unlimited"
```

# First Exercise

The first exercise consists in overwrite a variable used to grant permission to a user using the `strcpy()` vulnerable function

## Compilation
```bash
    cd /path/to/repo/src
    gcc -O0 -m32 -z execstack -fno-stack-protector -mpreferred-stack-boundary=2 -g exercise1.c -o exercise1
```

## Execution
```bash
    cd /path/to/repo/src
    ./exercise input
```
# Second Exercise

The second exercise consists in overwrite the `%eip` register of the stack in order to redirect the program to a chosen function using the `strcpy()` vulnerable function and the `gdb` debugger in order to find out the right number of junk chars to fill up the stack

## Compilation
```bash
    cd /path/to/repo/src
    gcc -O0 -m32 -z execstack -fno-stack-protector -mpreferred-stack-boundary=2 -g exercise2.c -o exercise2
```

## Find out the function register
```bash
    cd /path/to/repo/src
    objdump -d exercise2 | grep <function_name>
```
## Execution
```bash
    cd /path/to/repo/src
    ./exercise $(python2 -c 'print"A"*<num_char> + "function register"')
```
    keep in mind that the intel cpu are Little Endian so pay attention when insert the register
# Third Exercise
    TO DO
