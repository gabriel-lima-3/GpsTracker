# Smart Sustainable Bus Stop 🚏🌱
An interdisciplinary IoT prototype developed for a university semester project focused on solving urban mobility challenges in Belém.
This project was created by students from Computer Science and Architecture as a proposal for a smart and sustainable bus stop, capable of estimating the arrival time of buses using real-time GPS data.

# 📌 Project Idea
The main idea was to design a modern bus stop that could improve the public transportation experience by displaying:
Estimated arrival time of buses
Real-time location tracking
Distance between the bus and the stop
Sustainable urban infrastructure concepts
The Architecture team focused on the physical and sustainable design of the bus stop, while the Computer Science team developed the technological prototype using embedded systems and GPS communication.


# ⚙️ Technologies Used
Arduino IDE
ESP32
Neo-6M GPS Module
C++ / Arduino Language
Serial Communication
GPS Coordinate Processing
Haversine Formula for distance calculation


# 🧠 How It Works
The ESP32 receives GPS coordinates from the Neo-6M module in real time.
Using the current speed and location data, the system:
Reads latitude and longitude from the GPS
Calculates the distance to a predefined destination
Estimates the arrival time based on current speed
Displays the information through Serial Monitor
The distance calculation is based on the Haversine formula, commonly used to determine distances between geographic coordinates:



# 🔌 Hardware Components
ESP32 Development Board
Neo-6M GPS Module
Jumper Wires
USB Connection for Serial Monitoring

🎥 Demonstration
A demonstration video of the prototype was recorded and published on YouTube with English subtitles to present the concept and functionality of the project.

https://youtu.be/zN-ekgJTjpo?feature=shared

## 📍 Academic Context
This prototype was created as part of a semester interdisciplinary project involving multiple university courses, with the objective of developing solutions for real urban issues in Belém.
Developed in May 2025 as part of an interdisciplinary university semester project.

## 👥 Authors
- Gabriel Lima — Computer Science, CESUPA
- Igor Vilhena — Computer Science, CESUPA
