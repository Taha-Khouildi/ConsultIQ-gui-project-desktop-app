# Tunisnap — 2D Platformer (C / SDL)

A 2D side-scrolling platformer written in **C** with **SDL 1.2**, built as a first-year
project at [Esprit](https://esprit.tn). The game features multiple levels, animated
combat, in-game puzzles, a minimap, and a save/load system.

![Menu screen](image_menu/background%201.jpg)

> _Replace the image above with an actual gameplay screenshot when you get the chance —
> a shot showing the hero, enemies, and HUD in a level will sell the project better than
> the menu backdrop._

## About

Tunisnap is a level-based platformer. You control a hero who runs, jumps, and attacks
through hand-built levels while solving puzzles (_enigmes_) to progress. Progress is
tracked per player via a name-based save system, so you can pick up where you left off.

## Features

- Multiple hand-designed levels with scrolling backgrounds
- Player animations: idle, run, jump, and attack
- Enemies with health and collision handling (pixel-perfect collision)
- In-game puzzles (_enigmes_) gating progression
- Minimap overlay
- Save / load system tied to a player name
- Menu system (Play / Settings / Quit) with background music and sound effects

## Controls

| Key            | Action              |
| -------------- | ------------------- |
| ← / →          | Move left / right   |
| Space          | Jump                |
| X              | Attack              |
| Escape         | Return to main menu |

At launch you're prompted to enter a player name, which is used to save your progress.

## Tech stack

- **Language:** C
- **Graphics / input:** SDL 1.2
- **Images:** SDL_image
- **Text / fonts:** SDL_ttf
- **Audio:** SDL_mixer

## Build & run

This project targets the legacy **SDL 1.2** libraries. On Debian/Ubuntu:

```bash
sudo apt-get install libsdl1.2-dev libsdl-image1.2-dev libsdl-ttf2.0-dev libsdl-mixer1.2-dev
```

Then build and run from the project root:

```bash
make
./prog
```

The executable expects to be run from the project root so it can find the `image_menu/`,
`image_level/`, `son/`, and `sprites/` asset folders using relative paths.

## Project structure

| Area            | Files                                                        |
| --------------- | ----------------------------------------------------------- |
| Entry point     | `main.c`                                                     |
| Player          | `player.c`, `input.c`                                        |
| Enemies         | `enemy.c`                                                    |
| Collision       | `collisionPP.c` (pixel-perfect)                             |
| World / camera  | `background.c`, `scrolling.c`, `minimap.c`                  |
| Puzzles         | `enigme.c`, `enigme6.c`                                      |
| Save system     | `sauvegarde.c`, `sauv.c`                                     |
| Timing          | `temps.c`                                                    |
| Shared helpers  | `fonction.c`                                                 |

## Notes

Built as an academic project to practice C fundamentals, modular design, and real-time
game programming with SDL. Some in-code comments are in French and Tunisian Arabic.
