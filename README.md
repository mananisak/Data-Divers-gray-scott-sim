## About this Repo

Greetings Interns. This repo is for our very impressive software that performs a Gray-Scott Simulation.

## Getting Started

This tutorial assumes a basic understanding of git, GitHub and command line usage. If you do not have git installed please follow <a href="https://git-scm.com/book/en/v2/Getting-Started-Installing-Git">this tutorial</a>.

A C++ compiler (minimum C++11) is also required to compile and run this code. Installation is platform- and software-environment-dependent so please research how to install a compiler with your particular setup (you may already have one installed).

### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/mananisak/Data-Divers-gray-scott-sim.git
   ```
2. Move into the repo folder
   ```sh
   cd Data-Divers-gray-scott-sim
   ```
3. Use Make to compile the files
   ```sh
   cd Data-Divers-gray-scott-sim
   ```

### Using the software
* Running the simulation
   ```sh
   make run
   ```
This will run the simulation with the default variables (Diffusion Rate of U (Du) = 0.14, Diffusion Rate of V (Dv) = 0.07, Feed Rate (F) = 0.03, Kill Rate (k) = 0.0648 and threshold = 0.1)

* ADVANCED: Running the simulation with user-inputted parameters. Replace \<Du\> \<Dv\> \<F\> \<k\> \<threshold\> with the input for each variable.
   ```sh
   ./sim.out <Du> <Dv> <F> <k> <threshold>
   ```
* Running the simulation will output many vtk files into the build folder. To clear these use:
   ```sh
   make cleanvtk
   ```
* To clear all vtk files and output files:
   ```sh
   make clean
   ```
* To compile and run a test-version of the simulation:
   ```sh
   make test
   ```

## Making Changes

Push and pulling and description of our CI system.
