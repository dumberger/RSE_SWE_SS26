#!/usr/bin/python3

# TKinter is a simple graphics library and should come with the normal python installation. 
# Otherwise it needs to be installed with "sudo apt install python-tk"
import tkinter as tk

import sudoku_py

class SudokuUI:
    def __init__(self, root):
        # private variables
        self.entries = []
        self.sudoku = sudoku_py.sudoku()

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
                self.sudoku.set(r, c, '_')

    # callback to sync the internal sudoku state with the UI
    def sync_with_sudoku_class(self):
        for r in range(9):
            for c in range(9):
                entry = self.entries[r][c]
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
        self.sudoku.solve()

        self.sync_with_sudoku_class()

    def generate(self):
        print("generating a new Sudoku")


        #TODO: call sudoku generator
        self.sudoku.generate()

        self.sync_with_sudoku_class()

# generate the UI and start the update loop
if __name__ == "__main__":
    root = tk.Tk()
    app = SudokuUI(root)
    root.mainloop()