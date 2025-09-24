# workshop-1.0.0
Just an experiment with vibe coding, really.

## Build Instructions
# Install dependencies (Debian/Ubuntu)
sudo apt update
sudo apt install -y g++ meson ninja-build pkg-config \
    libgtkmm-4.0-dev libwebkit2gtk-4.1-dev

# Clone this repository (or place source files in a folder)
git clone https://github.com/fuzzyklein2/workshop-1.0.0.git
cd workshop-1.0.0

# Create build directory
meson setup build

# Compile
meson compile -C build

# Run
./build/gtkmm-browser
