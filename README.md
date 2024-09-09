# Concurrent News Broadcasting Simulation

## Overview

This project simulates a concurrent news broadcasting system using C/C++. The system involves multiple producers generating news stories, a dispatcher sorting them into categories, co-editors processing the stories, and a screen manager displaying them. The project demonstrates the use of synchronization mechanisms, including semaphores and bounded buffers.

## Features

- **Producers**: Generate news stories of different types (SPORTS, NEWS, WEATHER).
- **Dispatcher**: Sorts stories into queues based on their type.
- **Co-Editors**: Simulate editing and forward the stories.
- **Screen Manager**: Displays the final stories.

## How to Run

1. Compile the project using the provided Makefile and run it with the configuration file:
   ```bash
   make
   ./ex3.out config.txt
