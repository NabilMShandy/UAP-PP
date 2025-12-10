# 🏓 Pong Game - C++ Ncurses Implementation

> *Tugas Akhir / Final Project Pemrograman C++*  
> Game konsol klasik Pong dengan fitur Multiplayer Lokal, Highscore System, dan Audio.

---

## 📋 Daftar Isi
1. [Latar Belakang & Studi Kasus](#-latar-belakang--studi-kasus)
2. [Fitur Utama](#-fitur-utama)
3. [Struktur Kode & Arsitektur](#-struktur-kode--arsitektur)
4. [Prasyarat & Instalasi](#-prasyarat--instalasi)
5. [Cara Kompilasi](#-cara-kompilasi)
6. [Kontrol Permainan](#-kontrol-permainan)
7. [Aset & File Eksternal](#-aset--file-eksternal)
8. [Credits](#-credits)

---

## 📖 Latar Belakang & Studi Kasus

Proyek ini dikembangkan sebagai *Proyek Akhir (Final Project)* untuk mata kuliah Pemrograman Dasar. Tujuan utamanya adalah untuk mendemonstrasikan pemahaman mendalam mengenai:

* **Object-Oriented Programming (OOP):** Implementasi Class, Object, Encapsulation, dan modularisasi kode.  
* **Game Loop Logic:** Logika real-time rendering, collision detection, dan update state.  
* **File Handling (I/O):** Membaca dan menulis data skor tertinggi (highscore) ke file eksternal `.txt`.  
* **External Library Implementation:** Penggunaan *Ncurses* untuk TUI dan *Windows API* (`windows.h`) untuk audio.

---

## ✨ Fitur Utama

* **Local Multiplayer:** Mendukung 2 pemain dalam satu keyboard.  
* **Dynamic Collision Detection:** Pantulan bola saat mengenai paddle atau dinding.  
* **Sistem Skor & Pemenang:** Game berakhir saat salah satu pemain mencapai skor 21.  
* **Persistent Highscore:** Menyimpan skor tertinggi dan pemenang terakhir ke file `highscore.txt`.  
* **Interactive Menu:** Navigasi menu dengan tampilan ASCII Art.  
* **Background Music:** Musik latar untuk lobby dan gameplay menggunakan file `.wav`.  
* **Intro & Story:** Tampilan pembuka dan animasi loading sebelum menu utama.

---

## 🏗 Struktur Kode & Arsitektur

Struktur proyek ini modular untuk memudahkan maintenance dan debugging:



📦 Pong-Game-CPP
┣ 📂 Musik
┃ ┣ 📜 lobby.wav
┃ ┗ 📜 gamepay.wav
┣ 📜 main.cpp
┣ 📜 game.cpp / .h
┣ 📜 bola.cpp / .h
┣ 📜 padel.cpp / .h
┣ 📜 menu.cpp / .h
┣ 📜 story.cpp / .h
┣ 📜 highscore.txt
┗ 📜 README.md



**Penjelasan Kelas:**  
* **Bola:** Koordinat X/Y, logika pantulan, dan perhitungan skor.  
* **Paddle:** Posisi dan tinggi raket pemain, gerakan Up/Down.  
* **MENU:** Tampilan visual UI, ASCII Art, navigasi menu.  
* **Game:** Mengatur objek Bola dan Paddle, input real-time, serta kondisi kemenangan.

---

## ⚙ Prasyarat & Instalasi

Pastikan lingkungan pengembangan memiliki:

* **Compiler C++:** MinGW (G++) atau lainnya.  
* **Library Ncurses:** Gunakan pre-compiled binaries untuk Windows / MSYS2.  
* **OS:** Windows (karena penggunaan `<windows.h>` dan `PlaySoundA`).

---

## 🛠 Cara Kompilasi

Buka terminal di direktori proyek, lalu jalankan:

```bash
g++ main.cpp bola.cpp padel.cpp menu.cpp game.cpp story.cpp -o pong -lncurses -lwinmm
````

Jalankan program:

```bash
./pong
```

---

## 🎮 Kontrol Permainan

| Pemain           | Aksi        | Tombol Keyboard  |
| ---------------- | ----------- | ---------------- |
| Pemain 1 (Kiri)  | Gerak Atas  | W                |
|                  | Gerak Bawah | S                |
| Pemain 2 (Kanan) | Gerak Atas  | Panah Atas (↑)   |
|                  | Gerak Bawah | Panah Bawah (↓)  |
| Sistem           | Keluar Game | Q (Saat bermain) |
|                  | Pilih Menu  | Enter            |

---

## 📂 Aset & File Eksternal

Pastikan struktur berikut tersedia agar program berjalan:

* **Folder Musik/**

  * `lobby.wav`
  * `gamepay.wav`
  * Format `.wav` agar kompatibel dengan WinMM.
* **File highscore.txt**

  * Akan otomatis dibuat jika belum ada.
  * Format: `[ID_Pemenang] [Skor]`

---

## 👨‍💻 Credits

Universitas Lampung

| Nama                    | NPM        |
| ----------------------- | ---------- |
| Habiburahman Al-Qomairi | 2517051004 |
| Talitha Reva Nabila     | 2517051020 |
| Nabil Muhammad Shandy   | 2517051032 |

Dibuat dengan ❤ menggunakan C++

```


```
