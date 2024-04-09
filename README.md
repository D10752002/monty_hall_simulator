## Monty Hall simulator

The repository contains the C++ code for monty hall simulator.

To run the cpp file, use a compiler to create an executable file (for example, monty_hall.exe as shown)

Give the arguments that our code takes as input through the command line interface
* num_doors
* num_doors_opened_by_host
* num_simulations

Run the executable file as follows
```
.\monty_hall --num_doors 100 --num_doors_opened_by_host 98 --num_simulations 100000
```


The code outputs the required probabilities of winning using each of the two strategies:
- sticking with the initial choice (staying)
- switching from the initial choice

The code also outputs the theoretical probabilities expected in an ideal scenario\
(these probabilities can be achieved by considering infinite simulations)