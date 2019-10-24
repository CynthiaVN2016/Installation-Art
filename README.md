# Installation-Art

# Interactive-Devices

## Table of Contents  
* [Objective](#objective)  
* [Development](#development)
  * [Hardware](#hardware)
  * [Code](#code)
* [Result](#result)
* [Demo](#demo)


<a name="objective"/>

## Objective 

Build a wireless device that must: 

* Address, in physical design and realization, the issue of “unseen effect”
  * the "unseen effect" is the removal of the traditional or expected 1:1, action/reaction/, cause/consequence or process/product pairs that typical installation art has on the viewer or listener
* Successfully combine earlier system configurations through use/reuse of sensors, config code, and physical design principles

<a name="development"/>

## Development

I wanted to push myself to use audio and create a device that has both artistic and practical usage. I am in a dance group, and a small annnoyance we have is having go back and forth between the mirror (to dance) and speaker system (to play, pause, repeat, etc. the music). I wanted to make a wireless device that allowed the dancer, who will be the user, to control the music without having to go back to the speaker system. With that in mind, I decided to make a sort of sleeve that the dancer would wear that allows them to stop and play the music, and control volume. At first, I wanted them to have manual control over the volume with a joystick of some sort; however, that did not seem that interesting. It has a clear 1:1 mapping from action to result, but did not provide some sort of unique effect that would add to the dance experience. 

Because of that, I decided to use the dancer's movement to almost "power" the volume. The more the dancer moved, the louder it would get. If they did not move, the volume would decrease. It is not an obvious effect because: (1) the dancer would usually not expect to have to move to increase volume (2) the more traditional usage of a piezoelectric sensor is to sense vibration by attaching it to a still object, but now it is attached to a moving person. However, once the user starts dancing, they can clearly see how their movement becomes connected to the volume. Looking at the sleeve is not initally obvious, but once one starts using it, the usage becomes clear, and I think it is interesting how the dancer becomes the piece of art itself with their movement.

With an idea conceptualize, I had to plan my piece. In my last assignment, I decided to work solely on software first and deal with the enclosure later, but doing that lead to a (personally) not satisfying design in the end because I had to work around my hardware rather than work with it. I changed my approach and thought of the design first before coding, and from there, I did not having to worry as much about the placement of my hardware. I also thought a lot on how a dancer would want to use a piece like this, for example, where on the arm would have the most movement. I reused my previous code for controlling LED pulse width modulation. I also reused previous code from lab that read UDP packets through wifi. With my foundation done, I went to building! 

![INITIAL](/imgs/IMG_0431.HEIC)

<a name="hardware"/>

The post should give an overview of your artistic vision. In particular for this assignment, you should address how you have specialized your generative art to the space. What creative decisions did you work lead you to, and which decisions did you take? How were your decisions motivated by your large creative vision for this project. In the same vein, also address any technical issues you encountered in your work. Particularly focus on issues that other artists may encounter when developing a generative art display for this space.

#### Hardware

Hardware used:
* Piezoelectric sensor
* DIY capacitive sensor 
* ESP32 
* Green LED light 

I followed the following [tutorial](https://www.instructables.com/id/How-To-Use-Touch-Sensors-With-Arduino/) to make a DIY capactive sensor 

![DIY](/imgs/IMG_0410.HEIC)

The following picture is everything wired up (and taped) on top of a piece of fabric. I included a LiPo battery (3.7V 600 mAh) because I wanted to use it in my sleeve to make it completely detached from a power source, but I ran into problems. I tried connecting the battery to the breadboard and wired it to the ESP32, but it seemed to not provide enough power for me piece. Then I tried connecting it directly to the 5V pin on the ESP32, and that seemed to work at one point, but overall, it was not sucessfully, so I powered it through my laptop. 

![WIRED](/imgs/IMG_0425.HEIC)

<a name="code"/>

#### Code 

I have set up my ESP32 to enable wireless connection and data transmission using UDP. I then wrote a python script that looked for my ESP32 network and read in any UDP packets coming. I initally wanted to stop and play a youtube video; however, that seemed a bit too complicated and out of the scope of the project, so I decided to write a script that played audio files off my computer using the VLC librar; based on what data packets, it would change the audio accordingly. There were some trial and errors with different audio library and applications, but in the end, the VLC library in python was sufficient for my need. 

### Result 

The sleeve is complete! 

![FINAL](/imgs/IMG_0418.HEIC)

![CLOSEUP](/imgs/IMG_0416.HEIC)

The functionality of the sleeve includes:

1. Play and pause 
  * Touching the capacvitive sensor placed below the wrist played and stopped the music
  * The LED light indicates the state of the LED 
    * Green meant the music was playing and vice versa
  * I placed it here for ease of access. It is a place many people would expect, and it does not intefere with the capactive sensor or other pieces of hardward
2. Volume control
  * The piezoelectric sensor measures the dancers' movement and adjusts the volume accordingly 
    * Moving the sensor increases the volume 
    * Not moving the sensor decreases the volume 
  * I placed it on the back of the hand because (1) one can move the hand without moving the rest of the arm and (2) dancers are constantly moving their hands, which makes it easy to use and (3) it forces the user to be more conscious of their movement 
  
<a name="demo"/>

## Demo

[Demo](https://youtu.be/IpnLLPoTYqw)

  
 

