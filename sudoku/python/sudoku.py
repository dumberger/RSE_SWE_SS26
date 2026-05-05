#!/usr/bin/python3
#source ~/workspace/RSE_SWE_SS26/sudoku/python/venvSUDOKU/bin/activate

# TKinter is a simple graphics library and should come with the normal python installation. 
# Otherwise it needs to be installed with "sudo apt install python-tk"
import tkinter as tk
import pathlib

import sudoku_py

class SudokuUI:
    def __init__(self, root):
        # private variables
        self.entries = []
        self.sudoku = sudoku_py.sudoku()
        
        # Since my Generate class depends on a template.txt ...
        self.sudoku_path = "template.txt"

        # draw a window
        self.root = root
        self.root.title("Sudoku")
        frame = tk.Frame(root)
        frame.pack()

        # draw Sudoku grid
        for i in range(9):
            row_entries = []
            for j in range(9):
                var = tk.StringVar()

                def make_callback(r, c, v):
                    def callback(*args):
                        value = v.get()
                        self.on_cell_change(r, c, value)
                    return callback

                var.trace_add("write", make_callback(i, j, var))

                e = tk.Entry(frame, width=2, font=('Arial', 18),
                             justify='center', textvariable=var)
                e.grid(row=i, column=j, padx=1, pady=1)

                row_entries.append(e)

            self.entries.append(row_entries)

        # draw the buttons and connect a function to each
        btn_frame = tk.Frame(root)
        btn_frame.pack(pady=10)

        clear_btn = tk.Button(btn_frame, text="Clear", command=self.clear)
        clear_btn.grid(row=0, column=0, padx=5)

        generate_btn = tk.Button(btn_frame, text="Generate", command=self.generate)
        generate_btn.grid(row=0, column=1, padx=5)

        solve_btn = tk.Button(btn_frame, text="Solve", command=self.solve)
        solve_btn.grid(row=0, column=2, padx=5)

    # callback to sync UI with backend logic
    def on_cell_change(self, row, col, value):
        entry = self.entries[row][col]
        entry.config(bg="white")

        # cell should be cleared
        if value == "":
            print(f"clear cell ({row}, {col})")
            self.set_cell(row, col, '_')
            return

        # validity check
        if not value.isdigit() or not (1 <= int(value) <= 9):
            print(f"\"{value}\" is not a valid sudoku symbol")
            entry.delete(0, tk.END)
            return
        
        # set the cell
        print(f"set cell ({row}, {col}) to {value}")
        self.set_cell(row, col, value)
    
    # clear the whole Sudoku grid
    def clear(self):
        for r in range(9):
            for c in range(9):
                entry = self.entries[r][c]
                entry.delete(0, tk.END)

    # callback to sync the internal sudoku state with the UI
    def sync_with_sudoku_class(self):
        for r in range(9):
            for c in range(9):
                entry = self.entries[r][c]

                #TODO: read a value from the sudoku class and store in value variable
                value = self.sudoku.get(r, c)

                entry.config(bg="white")
                entry.delete(0, tk.END)
                if value != '_':
                    entry.insert(0, value)

    def set_cell(self, row, col, value):

        #TODO: interact with C++ Sudoku here and set valid variable
        valid = self.sudoku.set(row, col, value)

        if not valid:
            entry = self.entries[row][col]
            entry.config(bg="red")
            entry.delete(0, tk.END)

    def solve(self):
        print("solving...")

        #TODO: call solver to solve the sudoku
        solver = sudoku_py.solver()
        solver.load_sudoku(self.sudoku_path)
        solver.solve()
        self.sudoku = solver.get_sudoku()

        self.sync_with_sudoku_class()

    def generate(self):
        print("generating a new Sudoku")

        #TODO: call sudoku generator
        gen = sudoku_py.generator()
        gen.load_sudoku(pathlib.Path(self.sudoku_path))
        gen.generate()
        self.sudoku = gen.get_sudoku()

        self.sync_with_sudoku_class()

# generate the UI and start the update loop
if __name__ == "__main__":
    root = tk.Tk()
    app = SudokuUI(root)
    root.mainloop()