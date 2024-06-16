
### About this project

I learned the basics of OpenGl in [this project](https://github.com/h-pina/open-gl), now I think is a good time to try to create a project on my own.
This will be a basic 2D game where a spaceship has to dodge different obstacles that appear on its way. Maybe I`ll add more mechanics for it later, but for now thats it :D
Apart from a working game, my main objective is to create a well structured project. I'll also use Cmake as a build system (just because I always wanted to test it)

### Code Convetions:

I chose to use a subsection of the Hungarian notation, to define only scopes. Variables will be named using camelCase.Also, the followiung prefixes will be used:
- **g_variableName**: for global variables
- **c_variableName**: for constant variables
- **s_variableName**: for static variables
- **m_variablename**: For class variables

### ROADMAP/TODO

- [x] Setup Build System
- [x] Create a blank window
- [x] Render a Triangle from window 
    - [x] Create a Mesh class to store a specified VBA
    - [x] Create a Shader class to store and manipulate Shader programs
- [ ] Move rendering logic to a renderer class?
    - [ ] Define projection matrix (one for the whole game)

- [ ] Change Scene class name
- [ ] Create GameObject class   
    - [ ] Attributes: Mesh, texture, shader, Position, speed, ...
    - [ ] Functions: Can`t think about anything right now 


    
