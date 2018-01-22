# Neopixel strip control example

## Overview

Build and flash this app. Connect NeoPixel strip to power, ground, and
signal pin - for example, below we have 12-pixel strip attached
to pin 5 of ESP8266 NodeMCU board:

![](neopixel.gif)

If you're using a different strip, edit `fs/init.js` and modify
pixel count and pin number as needed, then rebuild and reflash the app.

## How to install this app

- Install and start [mos tool](https://mongoose-os.com/software.html)
- Switch to the Project page, find and import this app, build and flash it:
