
### About this project

I learned the basics of OpenGl in [this project](https://github.com/h-pina/open-gl), now I think is a good time to try to create a project on my own.
This will be a basic 2D game where a spaceship has to dodge different obstacles that appear on its way. Maybe I`ll add more mechanics for it later, but for now thats it :D
Apart from a working game, my main objective is to create a well structured project. I'll also use Cmake as a build system (just because I always wanted to test it)

### Running and Building the project

Clone the project by running:

```bash
git clone git@github.com:h-pina/2DGame.git  --recursive
```

Then run 
```bash
./deploy.sh
```
which uses cmake to build the dependecies and create the executables

This project requires
- git 
- OpenGL (usually already available through your graphics card driver)


### Code Convetions:

I chose to use a subsection of the Hungarian notation, to define only scopes. Variables will be named using camelCase.Also, the followiung prefixes will be used:
- **g_variableName**: for global variables
- **c_variableName**: for constant variables
- **s_variableName**: for static variables
- **m_variablename**: For class variables

### Learnings and Annotations 


### ROADMAP/TODO

This list will both be used to track my progress and to organize my next steps

**Step 1 : Base project structures and rendering**
- [x] Setup Build System
- [x] Create a blank window
- [x] Render a Triangle from window 
    - [x] Create a Mesh class to store a specified VBA
    - [x] Create a Shader class to store and manipulate Shader programs
- [x] Move rendering logic to a renderer class?
- [x] Define projection matrix inside renderer (since it is one for the whole game)
- [x] Render First Triangle  
- [x] Remove commented code from Application.cpp
- [x] Input and EventHandler working
- [x] Basic character movement working
- [x] **Cleanup and Refactoring (doing)**
    - [x] Remove Global Header
    - [x] Replace raw pointers when possible --> See Annotations 
    - [x] Attach player to inputHandler inside constructor --> Not done. Doesn`t make sense since the scene object and the game objects are created after the InputHandler initiazation 
    - [x] Create Subclass GameObject (Players / Enemies maybe?)
    - [x] Change Mesh create function to use constructors (one constructor for vbo only and one for index buffers)
- [ ] Maybe add a primitives namespace 

**Step 2 : Core Gameplay**
- [ ] Polish movement system
- [ ] Enemies
- [ ] Collision system
- [ ] Increasing speed with time
- [ ] Textures   
- [ ] VFX
- [ ] Music and SFX (maybe?)


**Step 3 - UI**
- [ ] Menu
- [ ] Points Count

**Step 4 - Events and Additional mechanics**
...

### Current Problems

- I defined a header called "Globals.h" to make some window properties acessible globally. However, I don't like this approach and think I can make it better
- The code has some annotations marked with "//TODO:" or "//NOTE:". They are points which I think can be improved, but couldn`t think of a better solution yet for them. To see exactly their location you can run:
```bash
cd src;
grep -rnE "//TODO:|//NOTE:"
```

