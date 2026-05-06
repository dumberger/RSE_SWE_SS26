#!/usr/bin/python3

# Tkinter ist die Standard-GUI-Bibliothek von Python.
# Falls das Modul fehlt, muss es unter Ubuntu/Debian über `python3-tk`
# nachinstalliert werden.
import tkinter as tk
from pathlib import Path

import sudoku_py

class SudokuUI:
    def __init__(self, root):
        # Interne Zustände der Benutzeroberfläche:
        # - `entries` enthält alle sichtbaren Eingabefelder
        # - `sudoku` speichert den aktuellen Sudoku-Zustand
        # - `solver` wird für das Lösen benutzt
        # - `generator` erzeugt neue Rätsel
        self.entries = []
        self.sudoku = sudoku_py.sudoku()
        self.solver = sudoku_py.solver()
        self.generator = sudoku_py.generator()

        # Hauptfenster und Container für das Sudoku-Gitter
        self.root = root
        self.root.title("Sudoku")
        frame = tk.Frame(root)
        frame.pack()

        # Das 9x9-Gitter wird aus Tkinter-Entry-Feldern aufgebaut.
        # Jedes Feld ist mit einem StringVar verbunden, damit Änderungen
        # direkt erkannt werden.
        for i in range(9):
            row_entries = []
            for j in range(9):
                var = tk.StringVar()

                # Für jede Zelle wird ein Callback registriert.
                # Sobald der Benutzer etwas eingibt, wird on_cell_change()
                # mit Zeile, Spalte und neuem Inhalt aufgerufen.
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

        # Die Bedienknöpfe für die drei Hauptaktionen der GUI:
        # - Clear: Eingabefelder leeren
        # - Generate: ein neues Sudoku erzeugen
        # - Solve: das aktuelle Sudoku lösen
        btn_frame = tk.Frame(root)
        btn_frame.pack(pady=10)

        clear_btn = tk.Button(btn_frame, text="Clear", command=self.clear)
        clear_btn.grid(row=0, column=0, padx=5)

        generate_btn = tk.Button(btn_frame, text="Generate", command=self.generate)
        generate_btn.grid(row=0, column=1, padx=5)

        solve_btn = tk.Button(btn_frame, text="Solve", command=self.solve)
        solve_btn.grid(row=0, column=2, padx=5)

    # Wird aufgerufen, wenn sich ein Feld ändert.
    # Hier wird geprüft, ob der Inhalt gültig ist und anschließend in die
    # C++-Logik geschrieben.
    def on_cell_change(self, row, col, value):
        entry = self.entries[row][col]
        entry.config(bg="white")

        # Leeres Feld bedeutet: Die Zelle soll wieder frei sein.
        if value == "":
            print(f"clear cell ({row}, {col})")
            self.set_cell(row, col, '_')
            return

        # Erlaubt sind nur die Ziffern 1 bis 9.
        if not value.isdigit() or not (1 <= int(value) <= 9):
            print(f"\"{value}\" is not a valid sudoku symbol")
            entry.delete(0, tk.END)
            return
        
        # Gültiger Wert: direkt an das Sudoku-Objekt weitergeben.
        print(f"set cell ({row}, {col}) to {value}")
        self.set_cell(row, col, value)
    
    # Leert nur die sichtbaren Eingabefelder.
    # Das interne Sudoku-Objekt wird hier bewusst nicht verändert.
    def clear(self):
        for r in range(9):
            for c in range(9):
                entry = self.entries[r][c]
                entry.delete(0, tk.END)

    # Synchronisiert den Inhalt des internen Sudoku-Objekts mit der GUI.
    # Diese Methode wird nach `Generate` und `Solve` verwendet, damit die
    # Benutzeroberfläche immer den aktuellen Zustand anzeigt.
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

        # Die C++-Implementierung entscheidet, ob der Wert an der Stelle erlaubt
        # ist. Bei einem ungültigen Wert wird die Zelle rot markiert.
        valid = self.sudoku.set(row, col, value)

        if not valid:
            entry = self.entries[row][col]
            entry.config(bg="red")
            entry.delete(0, tk.END)

    def solve(self):
        print("solving...")

        # Der Solver schreibt die Lösung in einen Ergebnisordner.
        # Deshalb wird dieser Ordner vor dem Start angelegt, damit die Datei
        # später sicher gelesen werden kann.
        Path("/tmp/results").mkdir(parents=True, exist_ok=True)
        self.solver.loadSudoku(self.sudoku, "/tmp")
        solutions = self.solver.solve()
        print(f"Found {solutions} solution(s)")

        # Die erste Lösung wird vom C++-Solver in `/tmp/results/0.txt` abgelegt.
        # Diese Datei wird anschließend wieder eingelesen und in ein neues Sudoku
        # übertragen, damit die GUI wirklich die gelöste Version zeigt.
        solution_file = Path("/tmp/results/0.txt")
        if solution_file.exists():
            solved_sudoku = sudoku_py.sudoku()
            with solution_file.open("r", encoding="utf-8") as file:
                for row, line in enumerate(file):
                    values = line.split()
                    for col, value in enumerate(values):
                        solved_sudoku.set(row, col, value)
            self.sudoku = solved_sudoku

        self.sync_with_sudoku_class()

    def generate(self):
        print("generating a new Sudoku")

        # Ein neues Rätsel direkt aus dem C++-Generator holen.
        # Danach wird die GUI neu befüllt, damit die generierte Vorlage sofort
        # sichtbar ist.
        self.sudoku = self.generator.generate()

        self.sync_with_sudoku_class()

# Fenster erzeugen, UI aufbauen und die Ereignisschleife starten.
if __name__ == "__main__":
    root = tk.Tk()
    app = SudokuUI(root)
    root.mainloop()