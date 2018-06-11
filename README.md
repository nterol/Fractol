# Fractol
Fractal generator of the 42 school's graphic branch
Basic Projects, very fun to do. 

#### Set Up 
Clone the repo. 
Then launch `make`
When the compiling is done, launch 
`./fractol set_type` 
where `set_type`is either :
`julia`, `mandelbrot`, or `burningship`

#### Controls

You can zoom in using your the roll of your mouse, your trackpad, or with the **UP** and **DOWN** arrows of the keyboard. 
Note that the zoom will always follow to position of the mouse cursor. 
**LEFT** and **RIGHT** arrows will enabled you to swithc between the three sets. 
**O** and **P** will change the color of the set : 
[usual palette](/img/normal_color_set.jpg)
* **O** will calculate the cosinus color gradient from the initial palette
[cosinus](/img/O_color_set)
* **P** will calculate the sinus color gradient from the initial palette
[sinus](/img/P_color_set)
* **O**+**P** will switch the set to a secondary palette.
[secondary palette](/img/O+P_color_set)

**+** will increase the number of iterations
**-** will decrease the number of iterations

I did not take the time to optimize everything on this Fractol since it was just a mandatory -though funny- project. 
Fractol will not crash if you increase the number of iterations like crazy. But it will get very slow.

**ESC** whill shut the program and close the window.  
