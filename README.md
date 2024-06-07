# GUIMaker

GUIMaker is a library designed to simplify the creation of graphical user interfaces (GUIs) for Arduino Giga Display Shield using the popular LVGL library.

## Installation

To use GUIMaker in your Arduino project, follow these steps:

1. Download the latest release of the GUIMaker library from the [GitHub repository](https://github.com/your-username/GUIMaker).
2. Extract the downloaded ZIP file.
3. Copy the extracted folder to the Arduino libraries directory.
4. Restart the Arduino IDE.

## Usage

To get started with GUIMaker, include the library in your Arduino sketch:

```cpp
#include <GUIMaker.h>
```

Next, initialize the Giga Display Shield and create a GUI object:

```cpp
GigaDisplayShield display;
GUIMaker gui(display);
```

You can now start creating your GUI elements using the provided functions and methods. For example, to create a button:

```cpp
gui.createButton(10, 10, 100, 50, "Click Me");
```

For more detailed documentation and examples, please refer to the [GUIMaker GitHub repository](https://github.com/VBNetLander/GUIMaker).

## Contributing

Contributions to GUIMaker are welcome! If you find any bugs or have suggestions for improvements, please open an issue on the [GitHub repository](https://github.com/VBNetLander/GUIMaker).

## License

GUIMaker is released under the [MIT License](https://opensource.org/licenses/MIT).
