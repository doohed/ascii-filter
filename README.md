# ASCII Video Converter

This program converts a video file into ASCII art, displaying each frame as ASCII characters in the terminal. It utilizes OpenCV for video processing and manipulation.

## Requirements

- C++ compiler with C++11 support
- OpenCV library (version 2 or 3)
- CMake (optional, for building)

## Installation

1. **Clone the Repository:**

    ```bash
    git clone https://github.com/doohed/ascii-filter.git
    ```

2. **Build the Project:**

    ```bash
    cd ascii-filter
    mkdir build && cd build
    cmake ..
    make
    ```

## Usage

1. **Prepare a Video File:**

    Make sure you have a video file in a compatible format (e.g., mp4) that you want to convert to ASCII art. You can use any video file, but for demonstration purposes, a file named `porter.mp4` is included.

2. **Run the Program:**

    ```bash
    ./ascii-filter
    ```

    By default, the program will process the `porter.mp4` file. You can change the video file path in the `main()` function if you want to use a different file.

    The ASCII art will be displayed in the terminal as the video is processed.


## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
