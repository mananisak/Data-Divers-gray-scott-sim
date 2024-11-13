## About this Repo

Greetings Interns. This repo is for our very impressive software that performs a Gray-Scott Simulation.

## Getting Started

This tutorial assumes a basic understanding of git, GitHub and command line usage. If you do not have git installed please follow <a href="https://git-scm.com/book/en/v2/Getting-Started-Installing-Git">this tutorial</a>.

A C++ compiler (minimum C++11) is also required to compile and run this code. Installation is platform- and software-environment-dependent so please research how to install a compiler with your particular setup (you may already have one installed).

Finally, Make and optionally CMake are required to build the system. CMake is recommended. More info can be found <a href="https://cmake.org/download/">here</a>.

### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/mananisak/Data-Divers-gray-scott-sim.git
   ```
2. Move into the repo folder
   ```sh
   cd Data-Divers-gray-scott-sim
   ```

### Option 1: Using CMake to build the system for the software
This is a more robust build system that requires CMake.
1. Create and enter the build directory
   ```sh
   mkdir build
   cd build
   ```
2. Run CMake under the root path for configuration
   ```sh
   cmake ..
   ```
3. Compile project
   ```sh
   cmake --build .
   ```
4. Run the main program. Outputted .vtk files are stored in the /build/bin folder
   ```sh
   cmake --build . --target run
   ```
5. Run unit tests
   ```sh
   cmake --build . --target test
   ```
#### CMake cleanup options
1. Clean up all files generated by the build (complete cleanup)
   ```sh
   cmake --build . --target full-clean
   ```
2. Only clean executable files and target files
   ```sh
   cmake --build . --target clean-bin
   ```
3. Only clean up temporary CMake configuration files
   ```sh
   cmake --build . --target clean-cmake
   ```
4. Only clean up VTK output files
   ```sh
   cmake --build . --target clean-vtk
   ```

### Option 2: Using Make to build the system for the software
This is a less robust build system however Make may be easier to install and use.
* Running the build system to compile the necessary files
   ```sh
   make
   ```
* Running the simulation
   ```sh
   make run
   ```
This will run the simulation with the default variables (Diffusion Rate of U (Du) = 0.14, Diffusion Rate of V (Dv) = 0.07, Feed Rate (F) = 0.03, Kill Rate (k) = 0.0648 and threshold = 0.1)

* ADVANCED: Running the simulation with user-inputted parameters. Replace \<Du\> \<Dv\> \<F\> \<k\> \<threshold\> with the input for each variable.
   ```sh
   ./sim.out <Du> <Dv> <F> <k> <threshold>
   ```
* Running the simulation will output many vtk files into the current directory. To clear these use:
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
