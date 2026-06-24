# LED Rubik's Cube / Cube Rubik's LED

---

## 🇬🇧 English

### Description
An autonomous decorative LED Rubik's cube powered by a Raspberry Pi Pico. The cube generates a random scramble, animates the solution step-by-step in a loop, and restarts — functioning as a fully autonomous decorative object.

### Features
- Random scramble generation
- Layer-by-layer solver animation
- WS2812B addressable RGB LEDs (1 per cubie, 27 total)
- Infinite loop — plug and play
- ON/OFF button
- Powered by a 5V powerbank

### Hardware
- Raspberry Pi Pico
- 27x WS2812B addressable LEDs
- 5V powerbank
- 7mm ON/OFF button
- 3D printed enclosure (black PLA/PETG)
- Plexiglass diffusers (laser cut)

### Requirements
- MicroPython
- neopixel library (built-in with MicroPython)

### Installation
```bash
git clone https://github.com/nicolasbgt-cell/LED_Rubiks_Cube.git
```
Upload `main.py` to the Pico using Thonny or rshell.

### Project Structure
```
LED_Rubiks_Cube/
├── main.py         # Main code (MicroPython)
├── solver.py       # Layer-by-layer solver
├── shuffle.py      # Random scramble generator
└── README.md       # Documentation
```

### Author
Nicolas Bigot — École 42 Paris

### ☕ Support
If you like this project, feel free to buy me a coffee!
👉 https://ko-fi.com/nicolasbgt

---

## 🇫🇷 Français

### Description
Un cube Rubik's LED décoratif et autonome alimenté par un Raspberry Pi Pico. Le cube génère un mélange aléatoire, anime la résolution étape par étape en boucle, et recommence — fonctionnant comme un objet décoratif entièrement autonome.

### Fonctionnalités
- Génération de mélange aléatoire
- Animation de résolution couche par couche
- LEDs RGB adressables WS2812B (1 par cubie, 27 au total)
- Boucle infinie — plug and play
- Bouton ON/OFF
- Alimenté par une powerbank 5V

### Matériel
- Raspberry Pi Pico
- 27x LEDs adressables WS2812B
- Powerbank 5V
- Bouton ON/OFF 7mm
- Boîtier imprimé en 3D (PLA/PETG noir)
- Diffuseurs en plexiglas (découpe laser)

### Prérequis
- MicroPython
- Bibliothèque neopixel (intégrée à MicroPython)

### Installation
```bash
git clone https://github.com/nicolasbgt-cell/LED_Rubiks_Cube.git
```
Upload `main.py` sur le Pico via Thonny ou rshell.

### Structure du projet
```
LED_Rubiks_Cube/
├── main.py         # Code principal (MicroPython)
├── solver.py       # Solveur couche par couche
├── shuffle.py      # Générateur de mélange aléatoire
└── README.md       # Documentation
```

### Auteur
Nicolas Bigot — École 42 Paris

### ☕ Soutenir le projet
Si ce projet vous plaît, vous pouvez m'offrir un café !
👉 https://ko-fi.com/nicolasbgt

---

## 📄 License / Licence

MIT License

Copyright (c) 2026 Nicolas Bigot

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
