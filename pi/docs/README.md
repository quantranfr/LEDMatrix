# Control P5 64x32 RGB with Raspberry Pi

Using Raspberry Pi to control LED matrix modules is a costly solution, but it turns out that it's the easiest way to control daisy-chained modules.

## Pre-requisites

Materials:

* 2 RGB LED matrix module of P5 form factor, 64x32 resolution, of which one with "P5(2121)-16S-6432-BO" written on the back and the other with "P5(2121)-3264-16S-M5" and interface "HUB75-D" written on the back;
* Raspberry Pi 4B.

Accessories:

* Power source: 5A 20A and power cables;
* 2 IDC 2x8 ribbon cable;
* 16 male-female dupont cables.

Wiring:

```
                      PI
                  -----------
(SPISCLK) 23  ←   R1      G1   →  13 (GPIO27)
 (SPICE1) 26  ←   B1      GND
 (SPICE0) 24  ←   R2      G2   →  21 (SPIMISO)
(SPIMOSI) 19  ←   B2      GND  →  14 (GND)
 (GPIO22) 15  ←   A       B    →  16 (GPIO23)
 (GPIO24) 18  ←   C       D    →  22 (GPIO25)
 (GPIO17) 11  ←   CLK     LAT  →  7  (GPIO4)
 (GPIO18) 12  ←   OE      GND  →  6  (GND)
```

> It's an easier-to-see version, inspired from [this guide](https://github.com/hzeller/rpi-rgb-led-matrix/blob/master/wiring.md).Daisy-chain to a 2nd display with a ribbon IDC cable if needed.

Librairies:

* [rpi-rgb-led-matrix](https://github.com/hzeller/rpi-rgb-led-matrix/)

## Code setup

1. Clone the library into a folder;
2. Go to the subfolder `examples-api-use` and run `make`

## How-to

### Display a ppm image

PPM images are great to show text in any language. Here's how to show "Bảo vệ môi trường là trách nhiệm của TTKP !!!" on 2 modules.

1. Generate a 450x32 white-on-black ppm PNG image from the text above using [this online tool](https://text2image.com/);
2. Convert the generated PNG image to a PPM image using [this online tool](https://convertio.co/png-ppm/);
3. Name the generated PPM image `mytext.ppm` and put it into the subfolder `examples-api-use`;
4. Run `sudo ./demo --led-rows=32 --led-cols=64 --led-slowdown-gpio=4 --led-chain=2 -D1 mytext.ppm`
