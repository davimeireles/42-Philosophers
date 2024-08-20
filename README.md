# Project: Philosophers - Simulating the Dining Philosophers Problem

## Project Overview

The primary objective of the Philosophers project was to develop a simulation of the dining philosophers problem, where a group of philosophers alternates between thinking, eating, and sleeping. The challenge is to manage the allocation of limited resources (forks) to avoid deadlock and ensure that each philosopher can eat.

### The Dining Philosophers Problem

The Dining Philosophers Problem is a classic synchronization problem that illustrates the challenges of resource allocation and deadlock prevention in concurrent systems. It involves a scenario with five philosophers sitting around a circular table, where each philosopher alternates between thinking and eating. There is a fork placed between each pair of adjacent philosophers, and a philosopher must pick up both the left and right forks to eat. The problem is to design a protocol that ensures no philosopher will starve (i.e., be unable to eat indefinitely) while avoiding deadlock, where no progress is possible because each philosopher holds one fork and waits for the other.

## Key Features

### Simulation Requirements

- Each philosopher alternates between three states: eating, thinking, and sleeping.
- Philosophers can only eat if they have both left and right forks.
- The simulation must avoid deadlock and starvation.
- The program should take the following arguments:
  - Number of philosophers
  - Time to die (in milliseconds)
  - Time to eat (in milliseconds)
  - Time to sleep (in milliseconds)
  - [Optional] Number of times each philosopher must eat

### Concurrency Management

- Use of threads to simulate philosophers
- Mutexes or semaphores to manage access to shared resources (forks)

## Technical Implementation

### Thread Management

- Each philosopher is represented by a separate thread.
- Threads are synchronized to ensure proper access to forks.

### Synchronization Techniques

- Implemented mutexes to prevent race conditions and ensure mutual exclusion.
- Used semaphores in the bonus part to manage resource allocation.
