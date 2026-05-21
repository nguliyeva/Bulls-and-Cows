# Bulls and Cows Game

A console-based implementation of the classic **Bulls and Cows** game written in **C++**.

## Project Description

In this game, the player tries to guess a secret number. After each guess, the program gives feedback using:

- **Bull**: correct digit in the correct position
- **Cow**: correct digit in the wrong position

The game supports different number lengths and includes input validation for the player’s guesses.

## Features

- Console-based menu system
- Player name input
- Selection of 2-, 3- or 4-digit numbers
- Secret number generation without repeated digits
- Input validation
- Bulls and Cows result calculation
- Round display
- Prediction history table

## Technologies

- C++
- Object-oriented programming
- STL `vector`
- Console input/output
- Random number generation

## Project Structure

- `main.cpp` – menu, instructions and program start
- `Game.h` / `Game.cpp` – game logic and result calculation
- `Player.h` / `Player.cpp` – player information

## Status

This project is still under development. The basic game logic is implemented and runnable, but some features, such as the computer guessing strategy, are planned to be improved.

## Purpose

This project was created as a personal C++ practice project to improve programming skills, algorithmic thinking and object-oriented design.
