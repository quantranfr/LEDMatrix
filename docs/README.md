# Control LED matrix modules with open-source platforms

## Overview

In Vietnam, advertisement banners using LED matrix modules are very popular. Just tell a vendor the size you want, the resolution you want, and you will get a beautiful, bright and dynamic banner over your commerce, a catch-eye for any person walking by.

![](img/intro.jpg)

Then you will have complet control over the content of your banner. The vendor you give you a compatible software to install into your computer, or an app to download from Google Play or iOS... so that you can design and "push" your own content to the banner.

Complet control? Not really so. Those app, although the user interface is in Vietnamese, are all Chinese-like and Windows-compatible only (if not mobile app). Upload content to the banner is a process that takes time. The only way to interact with commercial banners is through proprietary softwares, which offer no other, physical input methods (like buttons...).

That's why I try to make these awesome LED matrix modules really interactive, which responds immediately to users' actions, eg. display text according a kid's action in our Science Centre.

For that purpose, I propose to myself to test common LED matrix modules with common open-source microcontroller. At the end, people going through this guide will know how to make correct wiring, know which libraries to use and run an example sketch.

**Click on individual folders to see related docs.**

## Roadmap

* Display Vietnamese
* Chain modules
* Control the LED module with Raspberry Pi (more pins to use, but more expensive and other complications (voltage...)): [here](https://github.com/hzeller/rpi-rgb-led-matrix/);
* or with an ESP32 and [this library](https://github.com/mrfaptastic/ESP32-RGB64x32MatrixPanel-I2S-DMA).
