#  Page Replacement Policies Simulation

## How to run
- Compile and run using the below command
```sh
g++ -I/usr/include/python3.8 main.cpp -o main -lpython3.8
./main
```
- The input is taken from a file 'input.txt' which contains the page reference string.
- All page replacement algorithms are then run and temporary output files are generated for each algorithm containing the page frame size and the number of page faults.

## Dependencies
- Install python in your machine
```sh
sudo apt-get install python3.8-dev
```
- Install matplotlib library to plot graphs in python
```sh
pip install matplotlib
```

## Output
- The temp output files are generated for each algorithm that are used for plotting graph.
- We plot graphs to show the performance of each algorithm separately.
- Graph with all algorithms for comparison (Miss Ratio vs. No. of frames) and (No. of swaps vs. No. of frames) is plotted.
- The temporary output files are then deleted.

