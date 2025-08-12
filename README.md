# 🗂️ Animated Stack Visualizer (Qt Widgets)

A **Qt Widgets** application that visually represents a **stack data structure** with smooth animations for push, pop, and peek operations.  
This project is designed to help visualize stack behavior while maintaining a **clean, modern UI**.

---

## ✨ Features

- **Push**, **Pop**, and **Peek** operations  
- **Smooth animations** using `QPropertyAnimation` & `QGraphicsOpacityEffect`  
- **Live graphical stack representation**  
- **Editable UI** with Qt Designer (`mainwindow.ui`)  
- **Customizable** stack element type, animation duration, and UI theme

---

## 📸 Demo
<img width="1011" height="751" alt="image" src="https://github.com/user-attachments/assets/317efdb3-3c6b-4651-a793-c13a17687822" />

---

## 🛠️ Requirements

- **Qt 5.15** or **Qt 6.x**
- **Qt Creator** (recommended for building)
- C++17-compatible compiler (MinGW / MSVC on Windows, g++/clang on Linux/macOS)

---

## 📂 Project Structure

---

## 🚀 How to Build & Run

### Option 1 — Using Qt Creator (recommended)
1. Open **Qt Creator**
2. `File → Open File or Project` → Select `StackVisualizer.pro` (or `CMakeLists.txt`)
3. Choose a **Desktop Kit** (e.g., `Desktop Qt 6.x GCC`)
4. Click the **Run ▶** button

### Option 2 — Command line (qmake)
```bash
qmake StackVisualizer.pro
make          # or mingw32-make on Windows
./StackVisualizer

