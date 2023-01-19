# dopamine-box
Side project: Arduino device to track daily tasks (integrates Arduino, electronics, a servo, 3D printing, and C++ programming)


## Description
 - This is a small personal side project to further develop my Arduino, electronics, programming, 3D printing, soldering, and other related skills, and to integrate these tools/techniques into a final product.
 - It is inspired by an idea popularized by Youtuber Mike Boyd (partly inspired by another Youtuber, Simone Giertz). The idea is to have a ***physical object for tracking completion of daily tasks*** (e.g. exercise, meditation, etc.)--an object that is more satisying to interact with so as to more effectively reinforce the behavioral pattern (as compared to, for example, just an app on your phone).
 - Mike Boyd used a set of ***switches and LEDs***. My design also includes a mechanical component with a ***servo that ratches back a hammer to strike a bell*** upon completion of the tasks.
 - I am currently working on a second version that is much simpler/cleaner and includes an SD card and bluetooth module for storing and transmitting data to an app (to track/visualize task completion across time).


## Components
 - Arduino Uno (second version uses an Arduino Nano)
 - Shift register (74HC595 serial to parallel converter)
 - Servo (MG995)
 - Power supply module (Mb102)
 - 9 LEDs (5mm)
 - 7 220 Ohm resistors
 - 9 momentary switches
 - 3D printer (I use a BIBO3D 3-in-1 printer)
 - 3D PLA filament (~250 grams)
 - Bell
 - Perfboard, wires, and soldering equipment
 - Assorted nuts and bolts


## Other Notes
 - See the diagram for a layout of the circuit


## Credits
 - Mike Boyd: https://www.youtube.com/watch?v=JJeQIXBdVuk
   - Concept/Inspiration
 - Chris Krenz
   - Design
   - 3D model design and printing
   - Wiring and soldering
   - Programming (C++/Arduino)
   - Testing and debugging
