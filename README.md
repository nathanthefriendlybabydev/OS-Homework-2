# ReadMe


---

#### Technologies

- Linux Ubuntu
- VsCode

---


#### Prerequisites
- gcc and pthread library
- Compile on Ubuntu/Linux
- C/C++ Extension

## How To Use
After cloning the repository and ensuring you have met the prerequisites
run these commands in order:
```html
    gcc ./BankersAlg.c -o Banker
    ./Banker
```
Make sure you have the input.txt file with data in the matching format.
The format for the input file is as follows:
```
# of Processes
# of Resource Instances
# Maximum Resources For Process seperated by space: # # #
# Allocated Resources For Process seperated by space: # # #
# of Resources Available seperated by space: # # #

```
The maxmimum and allocated should alternate based on the number of processes, for example if you put 3 for the number of processes the input file should look like this:
```
# of Processes
# of Resource Instances
# Maximum Resources For Process seperated by space: # # #
# Allocated Resources For Process seperated by space: # # #
# Maximum Resources For Process seperated by space: # # #
# Allocated Resources For Process seperated by space: # # #
# Maximum Resources For Process seperated by space: # # #
# Allocated Resources For Process seperated by space: # # #
# of Resources Available seperated by space: # # #


## Expected Output

PID     Maximum         Allocated       Need
P[0]    7 5 3           0 1 0           7 4 3
P[1]    3 2 2           2 0 0           1 2 2
P[2]    9 0 2           3 0 2           6 0 0
P[3]    2 2 2           2 1 1           0 1 1
P[4]    4 3 3           0 0 2           4 3 1
System is in SAFE State
Safe Sequence is: P[1] P[3] P[4] P[0] P[2]
```
Please refer to the input.txt file.

## References
---
This is a list of online material and provided material I used to analyze and or edit my code with.

- Banker's Algorithm || Deadlock || Safe State || Operating Systems with Dilip Kumar Gangwar  : https://www.youtube.com/watch?v=62kYwEt3YUA&t=2083s&ab_channel=DilipkumarGangwar

- Reading From Text Files In C by CodeVault : https://www.youtube.com/watch?v=k3gSBljW-OE&ab_channel=CodeVault

- Additional material provided to the class by Professor Guan, Qiang at Kent State University
