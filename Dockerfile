# Use ubuntu jammy
FROM ubuntu:22.04

# Switch to the root user to install necessary packages
USER root

# Install necessary packages, such as Git, CMake, and Boost, as needed for your project
RUN apt-get update && apt-get install -y \
    build-essential \
    git \
    cmake \
    libboost-all-dev

# Clone the GitHub repository during the Docker build process
RUN git clone https://github.com/CanSanliturk/computational-geometry.git

# Set the working directory to ComputationalGeometry and build the project and run the tests
RUN cd computational-geometry/ComputationalGeometry && cmake . && make && ./Tests/ComputationalGeometryTests
