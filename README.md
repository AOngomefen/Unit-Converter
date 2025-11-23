# Unit-Converter

Simple console-based Unit Converter written in C++.

Originally implemented for a CMCS140 assignment by Andrea Ongomefen, this small program provides a menu-driven toolkit to convert:
- Temperature: Celsius → Fahrenheit
- Distance: Kilometers → Miles
- Weight: Kilograms → Pounds

## Files
- `main.cpp` — main program implementing the menu and conversions.

## Build / Run

Requirements:
- A C++ compiler (g++ / clang++) supporting C++11 or later.

Build with g++:
```
g++ -std=c++11 -O2 -o unit_converter main.cpp
```

Run:
```
./unit_converter
```

Example session:
```
Enter a Country Name:
Canada
Converter Toolkit
------------------
1. Temperature Converter
2. Distance Converter
3. Weight Converter
4. Quit
Enter Your Choice (1-4):
1
please enter temperature in Celsius (such as 24):
24
it is 75 in Fahrenheit
Canada sounds fun!
Thank You for testing my program !!
PROGRAMMER: Andrea Ongomefen
CMCS140 Common Project 2
Due Date: 9/15/2023
```

## Behavior details
- Temperature conversion uses formula: F = 1.8 * C + 32.
- Distance conversion uses a factor of 0.6 (Kilometers → Miles).
- Weight conversion uses a factor of 2.2 (Kilograms → Pounds).
- Negative values for distance and weight are rejected with an error message.
- After any action the program prints the entered country and an author footer and then exits.

## Known limitations
- Single-shot program: the menu runs once and the program exits — it does not loop for repeated conversions.
- Input validation is minimal: non-numeric input can put the program into a failed state.
- Conversion constants are approximate (0.6 and 2.2).
- No unit selection (only one direction per unit type).
- No automated tests or CI configured.
- No command-line arguments support.

## Suggested improvements (short)
- Improve numeric input validation (check stream state, clear invalid input, prompt again).
- Use more accurate conversion constants:
  - km → mi: 1 km = 0.621371 miles
  - kg → lb: 1 kg = 2.20462 pounds
- Allow zero as a valid input (unless you intend to forbid it).
- Add a loop so the user can perform multiple conversions without restarting the program.
- Extract conversion logic into small functions (e.g., celsiusToFahrenheit, kmToMiles, kgToPounds) to make the code easier to test.
- Add unit tests (GoogleTest or simple assertion tests) and a GitHub Actions workflow for CI.
- Improve UI messages and formatting (capitalize messages, consistent punctuation).
- Handle invalid menu input (non-integer or out-of-range) gracefully.
- Add support for reverse conversions and additional units (e.g., miles → km, lb → kg, Celsius ↔ Fahrenheit).
- Add a CMakeLists.txt or simple Makefile for easier building across platforms.
- Add a LICENSE (e.g., MIT) and CONTRIBUTING.md if you want collaborators.

## Contributing
If you'd like to improve the project:
1. Fork the repo.
2. Create a feature branch.
3. Open a Pull Request with a clear description of changes.
