
---
# 📟 Morse Code Decoder

<p align="center">
  <img src="https://raw.githubusercontent.com/arshc0der/Morse-Code-Decoder/refs/heads/main/preview/M1.png" alt="Morse Code Decoder Banner" width="70%"/>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Status-Stable-brightgreen.svg" alt="Status"/>
  <img src="https://img.shields.io/badge/License-MIT-blue.svg" alt="License"/>
  <img src="https://img.shields.io/badge/Open%20Source-Yes-brightgreen.svg" alt="Open Source"/>
  <img src="https://img.shields.io/badge/Platform-Windows-0078D4.svg" alt="Platform"/>
  <img src="https://img.shields.io/badge/Tech-Qt%20%7C%20C%2B%2B-026A2B.svg" alt="Tech Stack"/>
  <img src="https://img.shields.io/badge/Built%20With-Dedication-red.svg" alt="Built With Dedication"/>
  <img src="https://img.shields.io/badge/Made%20With-%E2%9D%A4-ff69b4.svg" alt="Made With Love"/>
  <img src="https://img.shields.io/badge/Maintained%20With-Care-blueviolet.svg" alt="Maintained"/>
  <img src="https://img.shields.io/github/stars/arshc0der/Morse-Code-Decoder?style=social" alt="GitHub Stars"/>
  <img src="https://img.shields.io/github/forks/arshc0der/Morse-Code-Decoder?style=social" alt="GitHub Forks"/>
  <img src="https://img.shields.io/github/issues/arshc0der/Morse-Code-Decoder" alt="Open Issues"/>
  <img src="https://img.shields.io/github/last-commit/arshc0der/Morse-Code-Decoder" alt="Last Commit"/>
</p>

---

## 🧭 About the Project

**Morse Code Decoder** is a lightweight, intuitive Qt-based application for decoding Morse code into readable text, with support for audio playback. It's a great educational tool for beginners learning Morse code or hobbyists practicing their decoding skills.

> 🎯 Built for simplicity and ease of use, especially on **Windows platforms**.

---

## 📸 Live Preview

<p align="center">
  <img src="https://raw.githubusercontent.com/arshc0der/Morse-Code-Decoder/refs/heads/main/preview/M2.png" width="30%" alt="Screenshot 1"/>
  <img src="https://raw.githubusercontent.com/arshc0der/Morse-Code-Decoder/refs/heads/main/preview/M4.png" width="30%" alt="Screenshot 2"/>
  <img src="https://raw.githubusercontent.com/arshc0der/Morse-Code-Decoder/refs/heads/main/preview/M5.png" width="30%" alt="Screenshot 3"/>
</p>

---

## ✨ Features

- 📥 **Morse Code Input** – Enter dots (.) and dashes (-) to instantly decode.
- 🧾 **Live Translation** – See decoded text in real-time.
- 🔊 **Audio Playback** – Hear Morse code as real beeps (using Windows API).
- 📋 **Copy to Clipboard** – Quickly copy the decoded result.
- 🎨 **Simple GUI** – Clean and minimal interface for distraction-free use.

---

## 🔧 Requirements

- 🛠️ **Qt Framework (5 or 6)**
- 🧱 **C++ Compiler** (MinGW, MSVC)
- 💻 **Windows OS** (uses `Beep()` from Windows API)

---

## 🚀 Getting Started

### 1️⃣ Clone the Repository

```bash
git clone https://github.com/arshc0der/Morse-Code-Decoder.git
cd Morse-Code-Decoder
````

---

### 2️⃣ Build the Project

Using **Qt Creator** or any Qt-compatible IDE:

* Open the `.pro` project file
* Configure a kit for your system
* Build and run the project

Alternatively:

```bash
qmake
make         # or mingw32-make for Windows
```

---

### 3️⃣ Run the App

Execute the built application and start decoding Morse code visually and audibly.

---

## 📁 Project Structure

```plaintext
Morse-Code-Decoder/
├── main.cpp                  # Entry point
├── mainwindow.h/.cpp        # UI logic
├── ui_mainwindow.h          # Auto-generated UI header
├── preview/                 # Screenshots
├── resources/               # (Optional) Add future sound or icon files here
└── MorseCodeDecoder.pro     # Qt project file
```

---

## 🧑‍🏫 Educational Use Case

Perfect for:

* 👨‍🏫 Morse code workshops
* 🧪 Engineering demos
* 🧒 Beginners learning telecommunications
* 🎓 Educational lab exercises

---

## 🛠️ Planned Enhancements

* 🌐 Linux/macOS compatibility
* 🔁 Reverse mode: Text → Morse
* 🎚️ Adjustable tone frequency
* 📱 Portable/embedded support

---

## 🤝 Contributing

Pull requests, suggestions, and ideas are welcome!

1. Fork the repo 🍴
2. Create a feature branch 🌿
3. Submit a pull request 📨

---

## 📄 License

This project is licensed under the [MIT License](LICENSE) – free to use and modify.

---

## 📬 Contact

For ideas, issues, or feedback:
📫 [Open a GitHub Issue](https://github.com/arshc0der/Morse-Code-Decoder/issues)

---

