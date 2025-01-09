# Conway's Game of Life

Conway's Game of Life is a fascinating cellular automaton invented by mathematician John Conway. It simulates the evolution of patterns on a grid according to simple rules, demonstrating how complexity can arise from simplicity.

---

## **How It Works**

The Game of Life takes place on a 2D grid of cells, where each cell is either **alive** or **dead**. The grid evolves over discrete time steps, with each step calculated based on the following rules:

1. **For a live cell:**

   - It dies if it has fewer than 2 live neighbors (underpopulation).
   - It survives if it has 2 or 3 live neighbors.
   - It dies if it has more than 3 live neighbors (overpopulation).

2. **For a dead cell:**

   - It becomes alive if it has exactly 3 live neighbors (reproduction).

These simple rules result in intricate patterns and dynamics over time.

---

## **How to Run the Program**

1. Clone the repository from GitHub

2. Navigate to the Project Directory

3. Use `gcc` to compile the program

4. Run the Program

5. When prompted, select one of the available patterns to simulate.

6. Watch how the grid evolves according to the rules.

---

