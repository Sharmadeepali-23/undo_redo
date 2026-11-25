# Undo-Redo Text Editor in C

## Project Overview
The Undo-Redo Text Editor is a simple console-based application developed using the C programming language. It allows users to insert text, display the current text, undo the previous operation, and redo the undone operation.

This project demonstrates the practical implementation of **Stack and Linked List** data structures.

## Technologies Used
- C Programming Language
- GCC Compiler
- Visual Studio Code

## Data Structures Used

### 1. Stack
- Follows the LIFO (Last In, First Out) principle.
- Used to store previous and undone text states.
- Two stacks are used: Undo Stack and Redo Stack.

### 2. Linked List
- Stores the current text character by character.
- Uses dynamic memory allocation.
- Allows flexible storage of text.

## Features
- Insert Text – Adds new text to the editor.
- Display Text – Displays the current text.
- Undo – Reverts the last text insertion.
- Redo – Restores the previously undone text.
- Exit – Closes the application.

## How It Works
1. When the user inserts text, the previous text is stored in the Undo Stack.
2. The new text is added to the Linked List.
3. When Undo is selected, the previous text is restored.
4. When Redo is selected, the undone text is restored.
5. A new text insertion clears the Redo Stack.

## Menu Options

| Choice | Operation |
|---|---|
| 1 | Insert Text |
| 2 | Display Text |
| 3 | Undo |
| 4 | Redo |
| 5 | Exit |

## How to Run the Project

**Step 1: Clone the repository**
```bash
git clone YOUR_REPOSITORY_URL
```

**Step 2: Open the project folder**
```bash
cd Undo-Redo-Text-Editor
```

**Step 3: Compile the C program**
```bash
gcc undo_redo.c -o undo_redo
```

**Step 4: Run the program**

For Windows:
```bash
.\undo_redo.exe
```

For Linux:
```bash
./undo_redo
```

## Sample Output

```text
===== UNDO REDO TEXT EDITOR =====
1. Insert Text
2. Display Text
3. Undo
4. Redo
5. Exit

Enter your choice: 1
Enter text to insert: Hello

Text inserted successfully!

Enter your choice: 2
Current Text: Hello

Enter your choice: 3
Undo successful!

Enter your choice: 2
Current Text:
```

## Concepts Covered
- Data Structures and Algorithms
- Stack Operations (Push and Pop)
- Singly Linked List
- Dynamic Memory Allocation
- String Handling
- Functions in C

## Limitations
- Supports text insertion at the end only.
- Does not support deleting or editing text at arbitrary positions.
- Uses a fixed maximum text and stack capacity.

## Future Improvements
- Add delete and edit operations.
- Support cursor-based text editing.
- Add file saving and loading functionality.
- Improve text editing features.

## Author
**Deepali**

## License
This project is open-source and available for educational purposes.
