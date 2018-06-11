# Fractol
Fractal generator of the 42 school's graphic branch written in C.  
Basic Projects, very fun to do. 

#### Set Up 
Clone the repo.  
Then launch `make` . 
When the compiling is done, launch .  
`./fractol set_type` .  
where `set_type`is either :
`julia`,

<img src="https://github.com/nterol/Fractol/blob/master/img/Julia.png" width="400" height="377"/>

`mandelbrot`,

<img src="https://github.com/nterol/Fractol/blob/master/img/mandelbrot.png" width="400" height="377"/>

or `burningship`

<img src="https://github.com/nterol/Fractol/blob/master/img/burningship.png" width="400" height="377"/>

#### Controls

You can zoom in using your the roll of your mouse, your trackpad, or with the **UP** and **DOWN** arrows of the keyboard. 
Note that the zoom will always follow to position of the mouse cursor. 
**LEFT** and **RIGHT** arrows will enabled you to swithc between the three sets. 
**O** and **P** will change the color of the set :

<img alt="usual palette" src="https://github.com/nterol/Fractol/blob/master/img/normal_color_set.png" width="400" height="377"/>

* **O** will calculate the cosinus color gradient from the initial palette

<img alt="cosinus gradient" src="https://github.com/nterol/Fractol/blob/master/img/O_color_set.png" width="400" height="377"/>

* **P** will calculate the sinus color gradient from the initial palette

<img alt="sinus gradient" src="https://github.com/nterol/Fractol/blob/master/img/P_color_set.png" width="400" height="377"/>

* **O**+**P** will switch the set to a secondary palette.

<img alt="secondary palette" src="https://github.com/nterol/Fractol/blob/master/img/O+P_color_set.png" width="400" height="377"/>

**+** will increase the number of iterations.  
**-** will decrease the number of iterations.

I did not take the time to optimize everything on this Fractol since it was just a mandatory -though funny- project.   
I just wanted to have the same color as the Julia on the wikipedia page "Fractal" . 
Fractol will not crash if you increase the number of iterations like crazy. But it will get very slow.  

**ESC** whill shut the program and close the window.  
