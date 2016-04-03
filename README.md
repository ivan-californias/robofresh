# Robofresh

Robofresh is a robot that regulates the "freshness" of the site.

# Why?

I have a room where I hold two home-servers running some own applications, so ventilation during the day is something to care about, but during the night naturaly is cooler. So I want this robot to turn some fans for me when it is necesary. So based on the room temperature and humidity this robot will be turning on and off these fans.

# Communication

I want this robot be able to communicate with the external world, so I will attach the arduino to a raspberry by USB. So I want these to communicate with a simple serial messages protocol, so Raspberry will be able to ask arduino information about sensors and perform other operations, and arduino would send alerts or other messages.
