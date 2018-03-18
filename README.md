# ESP8266 remote controller via MQTT

This program allows us to control a relay attached to an *ESP8266* (over NodeMCU board) through the MQTT protocol. With the mobile app, we can control it from anywhere.
<p align="center">
<img src="https://image.ibb.co/nFUKQH/IMG_20180317_231717_1.jpg" width="300" alt="">
<img src="https://image.ibb.co/g4Ckzc/ezgif_com_optimize.gif" width="220" alt="">
</p>

- - - -

# Navigation
<br>

> [:octocat: GitHub Repository](https://github.com/ismenc/esp8266-mqtt-control)<br>
> [:iphone: Android App](https://github.com/ismenc/android-mqtt-controller)<br>
> [:arrow_down: Releases](https://github.com/ismenc/esp8266-mqtt-control/releases)<br>
> [:memo: Issues](https://github.com/ismenc/esp8266-mqtt-control/issues)<br>


- - - -

# How can I collaborate?

<details>
     <summary>Instructions</summary>
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

I also made a simple *Android* app for this program at this [repository](https://github.com/ismenc/android-mqtt-controller).

## 2. How to use

You will need:

:white_check_mark: To install *drivers* for your board depending on the system.

:white_check_mark: A well installed *Atom* text-editor with [PlatformIO](https://platformio.org/platformio-ide) environment installed.

:white_check_mark: A cloud MQTT broker. (ok, take [this one](https://www.cloudmqtt.com/))

You will need the [knolleary](https://github.com/knolleary)'s great [:books: PubSubClient library](https://github.com/knolleary/pubsubclient) for your own projects wich is included under the *lib* directory. It can also be installed via `PlatformIO home` at *Atom*, `Libraries`.

:rocket: After that you can just clone this repository through atom or *Git* and modify and upload the main sketch. The program uses the main functions of the library but you can always check [knolleary's PubSubClient documentation](https://pubsubclient.knolleary.net/api.html) for more.

Finally, in case you need in depth information about hardware or library, checkout his repo [:books: PubSubClient library](https://github.com/knolleary/pubsubclient).

#### If you have any question -> open an [:memo: Issue](https://github.com/ismenc/esp8266-mqtt-control/issues). <br><br>
