# ESP8266 remote controller via MQTT

This program allows us to control a relay attached to an *ESP8266* (over NodeMCU board) through the MQTT protocol.
<p align="center"><img src="https://image.ibb.co/nFUKQH/IMG_20180317_231717_1.jpg" width="300" height="296" alt=""></p>

- - - -

# Navegación
<br>

> [:octocat: GitHub Repository](https://github.com/ismenc/esp8266-mqtt-control)<br>
> [:globe_with_meridians: Android App](https://github.com/ismenc/android-mqtt-controller)<br>
> [:arrow_down: Releases](https://github.com/ismenc/esp8266-mqtt-control/releases)<br>
> [:memo: Issues](https://github.com/ismenc/esp8266-mqtt-control/issues)<br>


- - - -

# How can I collaborate?

<details>
     <summary>Instrucciones</summary>
 <p>
  <!-- alternative placement of p shown above -->

  1. :v: Fork this repository and clone through terminal `git clone <url>`.
  2. :open_file_folder: Set the directory on the cloned folder `cd <folder>`.
  3. :memo: Modify the project as you wish.
  4. :sparkles: Stage the changes `git add *` and create new commit: `git commit -am "Summary of changes"`.
  5. :arrow_up: Upload your work: `git push origin master`.
  6. :email: Feel free to initiate a pull request :D

:octocat: Si deseas aprender Git, visita mi [guía sobre Git](https://github.com/ismenc/seminario-git).
      </p></details>

- - - -

# Index
<br>

* Index
  * [1. Functionality](#1-functionality)
  * [2. How to use](#2-how-to-use)

- - - -
<br>


## 1. Functionality

***MQTT*** is a machine-to-machine "Internet of Things" connectivity protocol and a extremely lightweight publish/subscribe messaging transport.

This application connects to a **MQTT** broker (wich you can find for free) and listens to the topic `lights` under `home` (`/home/lights`). If it receives '1' or '0' starting strings, the ESP will turn *on* or *off* a relay wich controls lights. It also publishes status info at the topic `/home/log`.

I also made an *Android* app for this program at this [repository](https://github.com/ismenc/android-mqtt-controller).

## 2. How to use

You will need:
1. To install *drivers* for your board depending on the system.
2. A well installed *Atom* text-editor with [PlatformIO](https://platformio.org/) environment installed.

For your own projects, you will need the [PubSubClient library](https://github.com/knolleary/pubsubclient) wich is included under the *lib* directory also installable via `PlatformIO home` at *Atom*, `Libraries`.

After that you can just clone this repository through atom or *Git* and modify and upload the main sketch.

#### If you have any question -> open an [:memo: Issue](https://github.com/ismenc/esp8266-mqtt-control/issues). <br><br>
