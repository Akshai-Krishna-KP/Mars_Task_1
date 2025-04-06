
# #Mars Task-1
<hr>

### Learning Git 
I learned about Git and Github, which i already know but forgot due to not using lately.
The resources i used are the YT vieo provided by the FreeCodeCamp.

## Light Dose

### 1.Terminal Commands 
I learned Bash Script from the tutorial from FreecodeCamp yt video and to clear some doubt arise from that i watched a beginner video on linux cmd.
Now i uncderstand that Bash(Bourne Again SHell) is command-line interpreter widely used in LinuX for many years.
cmd used are:
  * touch - to create a new file
  * cd - to go into a directory
  * mkdir - to make a directory
  * mv - to move/rename file
  * echo - to display the string/variable
  * find - to find files.
  * cat - to view content of the file
  * grep - used to search for specific patterns or regular expressions
  * wc - used to count number of words, lines, bytes..
  * top - monitor system processer in real-time
  * sudo - enable user to perform administrative task.

### 2.Bash Scripting
I am using VScode for editing and making the code as it is easy to use.
We can use vscode using the command ' code filename.type '
In this task i have to write a Bash script.

I faced challenges in doing simple task because i am not that much familiar with bash still.
Therefor I used help from GeeksforGeeks and Stackoverflow. Both for getting new function and understand what it do.
I also came to know that unlike C space has some meaning in Bash, I was getting some error due to i add space when assigning variable.

## Medium Dose

### 1.Detect Red Circle and make a 360 turn 
The Task is to adjust the navigation system such that the center of the Mars Rover is perfectly center the circle.
I assumed that the circle is under the camera and therefore the distance if 55cm. we take the unit vector and change the frame of reference as center of the rover as origin.
This is a fairly good question acc. to me.

### 2.Morse Code to English translator 
Morse code is a system which represent letters and numbers in Dot and Dash format.
It has both military and Scientific uses to send and recieve long distance message using radios, sound, light .....
We have different type of Morse code, but the one I implemented is Internation Morse Code. 

I faced some challenges when trying to code in C to effectively implement a dictionary type data structure, therefore i used python for this.

### 3.Decode Encrypted Message
The task is to decode a encrypted message using logic.
I have implemented the code to decode the the message.
The program take encrypted message as input and print decoded message.

This task wasn't really a challenge, but a mistake some will miss is the case when char goes below 'A'. otherwise  it's a easy one.

### 4.Martian Filter to remove noise.
Muchiko Filter (Mean Filter) and Sanchiko Filter(Median Filter) is used to remove the noise.
Muchiko Filter is weak, when filtering Noise. Bcz just one extreme value can skew the mean.
Sanchiko is likely give a stable reading bcz it ignores extreme value.
But My choice is Hybrid, bcz it will give more smooth reading than Sanchiko keeping the property of it.
also then i don't know the correct way to implement the hybrid.

### 5.Convert Euler angle to Quaternion system.
Many Software for 3d modeling uses Euler Angle bcz it's easy to understand.
but it comes with disadvantages like Gimbal lock and Interpolation issue.
Gimbal lock occur when two rotational axes in 3-angle align, causing the loss of one DOF.
To overcome this, we have different system invloving imaginary numbers calles Quaternions.

This program convert given Euler angle to Quaternion system.
```math
w = \cos\left(\frac{\phi}{2}\right) \cos\left(\frac{\theta}{2}\right) \cos\left(\frac{\psi}{2}\right) + \sin\left(\frac{\phi}{2}\right) \sin\left(\frac{\theta}{2}\right) \sin\left(\frac{\psi}{2}\right)
```

```math
x = \sin\left(\frac{\phi}{2}\right) \cos\left(\frac{\theta}{2}\right) \cos\left(\frac{\psi}{2}\right) - \cos\left(\frac{\phi}{2}\right) \sin\left(\frac{\theta}{2}\right) \sin\left(\frac{\psi}{2}\right)
```

```math
y = \cos\left(\frac{\phi}{2}\right) \sin\left(\frac{\theta}{2}\right) \cos\left(\frac{\psi}{2}\right) + \sin\left(\frac{\phi}{2}\right) \cos\left(\frac{\theta}{2}\right) \sin\left(\frac{\psi}{2}\right)
```

```math
z = \cos\left(\frac{\phi}{2}\right) \cos\left(\frac{\theta}{2}\right) \sin\left(\frac{\psi}{2}\right) - \sin\left(\frac{\phi}{2}\right) \sin\left(\frac{\theta}{2}\right) \cos\left(\frac{\psi}{2}\right)
```
*Where:*
- $\phi$ = Roll (rotation about X-axis)
- $\theta$ = Pitch (rotation about Y-axis)
- $\psi$ = Yaw (rotation about Z-axis)

## Hard Dose

### 1.Brick_Map Creation
The task consisted of some co-ordinate relative to starting point where some obstacles are present.
(Starting Point - S, Obstaces - 0, Free Space - 1)
The task demanded the knowldege of File handling and matrix manipulation.
The task was relatively simple.
there is a bonus question to find Shortest Path, which i will do it later.

### 2.Arrow_distance
The task is to find the distnce of arrow(Object) from the pinhole camera.
After searching some youtube videos i came across the equation to find the distance which is :-

\[
D = \frac{W \cdot f}{P}
\]

Where:
- \( D \) = Distance from camera to object (in cm)  
- \( W \) = Real-world width of the object (in cm)  
- \( f \) = Focal length of the camera (in pixels)  
- \( P \) = Perceived width of the object in the image (in pixels)

Now the promblem was to find focal length from given measurement. Again through may youtube video and some papers
i found another equation explaning the relation between focal length and FOV. which was not easy to understand
even now i am not sure, my understanding is correct or not.
The eqaution was :- 
\[
f = \frac{\sqrt{w^2 + h^2} \,/\, 2}{\tan(\theta_d / 2)}
\]

Where:
- \( f \) = Focal length in pixels  
- \( \theta_d \) = Diagonal Field of View in radians  
- \( w \) = Image width in pixels  
- \( h \) = Image height in pixels

This is the most interesting and time consuming question i encountered in the tasks.
The possible challenges to the distance will inacuracy in some measurement. i think.

### 3.Behavior Tree
This is surely a entire new topic for me.
What i understand is that this tree is used to determine and give command to the computer how to behave in a certain situation.
Earilier they used FSM(Finite State Machine) which had some disadvantages which was overcome by BT.
I can't say much abt BT wihtout further studying and improving my knowledge.

## Bonus
The bonus question was to find the Shortest distance from a point to another point.
due to my luck, i guess, sir was teaching BFS topic and graph theory in discreet and DSA.
therefore finding the answer was simple, but implementiong was tough i say.
Now i started to understand why a BUG will ruin your entire day, just like we saw in reels.
my mistakes was so minute but devastating for me.

## Source of Info..
**Git** :  [Git explained by FreeCodeCamp](https://youtu.be/RGOj5yH7evk?si=xFTWpYeZUiL9wXRK)

**Linux** : [Linux Tutorial for Beginners](https://youtu.be/sWbUDq4S6Y8?si=ZF07AHNLTcxLuhZW)

**Bash** : [Bash for Beginners](https://youtu.be/tK9Oc6AEnR4?si=vekgAJ1sGL-Mzh3G)

**Linux Cmd** : [Linux Cmd Cheet Sheet](https://www.geeksforgeeks.org/linux-commands-cheat-sheet/)

**Morse Code** : [International Morse Code](https://en.wikipedia.org/wiki/Morse_code#:~:text=International%20Morse%20code%20encodes%20the,sequence%20of%20dits%20and%20dahs.)

**Python** : [Python for Beginners](https://youtu.be/eWRfhZUzrAc?si=7tSCfbt4PE0nuoCs)

**File Handling** : [Guide to File Handling in C](https://youtube.com/playlist?list=PLVjlbUxP51QpDaTpuNXA6Dua53-ks9gHp&si=4_ZwERcPHUiIeXX_)

**Euler angle** : [Euler angle and Gimbal lock](https://youtu.be/zc8b2Jo7mno?si=GTd2K5VrrdT5X4UH)

**Quaternion** : [Quaternion and Conversion](https://youtu.be/zjMuIxRvygQ?si=tWwlOA3OGYOZsNpN)

**BFS** : [Explaination by Jenny mam.](https://youtu.be/vf-cxgUXcMk?si=6uzlO2i-oNjB3c-G)

**OpenCV** : [OpenCV course](https://youtu.be/oXlwWbU8l2o?si=kBKf5LzicUvIyZMc)

**Pinhole Camera** : [What is Pinhole Camera](https://youtu.be/jhBC39xZVnw?si=UekH3thwEChdgxS_), [Focal length and FOV](https://www.edmundoptics.in/knowledge-center/application-notes/imaging/understanding-focal-length-and-field-of-view/?srsltid=AfmBOopNjWgLFqRAnUjA9ZWIoccGPA7cHe4O1MA-AYEgodLsVPLZ_35L)

**Behavior Tree** : [Introduction to Behavior tree](https://youtu.be/kRp3eA09JkM?si=vz5-pSE4L7Qwjm9j)



## Summary
Actually i don't need a summary part, but doing simply for fun.
This was some exciting questions for me, but some guys don't feel the same. 
Anyway I tried to not use AI as much as possible
and tried to read some papers and watch some youtube videos.
I can't answer all 100% question abt any 
topic, 
but i fairly know about all the equation, concepts and everything 
used to create this git repo.
