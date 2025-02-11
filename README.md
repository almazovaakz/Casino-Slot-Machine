# 🎰 Slot Machine Game (SFML C++)

## 📌 Overview
This is a **Slot Machine Simulation** built using **C++ and SFML**. The game mimics a classic slot machine, displaying three spinning icons that stop to determine a **win or loss**. Players can spin the reels, earn points for matching symbols, and track their balance dynamically.

---

## 🚀 Features
### 🎰 **1. Interactive Slot Machine Simulation**
- Three **randomized slot reels** spin sequentially.
- Players can press **Spacebar** to initiate a new spin.
- Matching symbols result in a **score increase**, while losing rounds deduct points.

### 🔢 **2. Randomized Slot Symbols**
- Uses **C++'s `<random>` library** to generate **random slot results** from `1-9`.
- Ensures fairness and unpredictability in each spin.

### 🎨 **3. Graphical User Interface (GUI)**
- **SFML-based UI rendering**:
  - Slot machine background (`automat.jpg`)
  - Slot symbols (`icons/*.png`)
  - Scoreboard text (`casinofont.ttf`)
- **Dynamic scaling and positioning** ensure proper alignment of UI elements.

### 📊 **4. Real-Time Score Tracking**
- Displays **player balance** dynamically.
- **Winning rounds** increase the balance.
- **Losing rounds** deduct `25` points per spin.

### 🎮 **5. Keyboard Controls**
- **Press `Spacebar`** → Start a new spin.
- **Press `Esc` or Close Window** → Exit the game.

### ⚠️ **6. Error Handling & Game Over Condition**
- Prevents division by zero when calculating slot results.
- If **balance reaches zero**, the game displays `"GAME OVER"` and resets.

---

## 🛠 Technologies Used
### 🖥 **Programming Language**
- **C++** → Core programming language for game logic and mechanics.

### 🎨 **Graphics & UI**
- **SFML (Simple and Fast Multimedia Library)** → Handles:
  - **2D graphics rendering** (icons, background).
  - **Event handling** (keyboard input).
  - **Game window creation**.

### 🎲 **Randomization**
- **C++ `<random>` library** → Generates **random slot outcomes**.

### 🏗 **Game Architecture**
- **Structured functions** (`setIcons`, `setIndexes`, `drawIcons`).
- Uses **structs** (`Icons`, `IconIndexes`) to manage slot symbols.
- **Game loop** ensures continuous execution while allowing user interaction.
