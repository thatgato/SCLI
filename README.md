# SCLI
 
## **A mathematics focused CLI, mainly made for solving exercises found at school.**

The idea of this project is to eliminate those lengthy calculations that schools force us to do by hand over and over again by giving the most repetitive homeworks ever. This CLI is planned to include solving algorithms to the most common mathematical problems found in schools, such as the pythagorean theorem, quadratic equations and more!

There is no clear roadplan as for what functions this CLI will include. I am just going to add random solving algorithms, typically ones that I manage to encounter on my math classes.


### WARNING
This is my  first ever real C++ project and this project is part of my journey of learning C++. The code may not always be of the highest quality and I do not guarantee that it is bug-prone.

*This project is heavily in development as of right now. I'm still building the framework of the entire CLI, there is no functionality yet.*

## Idea for the architecture of this project
- Step 1:
  - The  user starts up the main executable file, either by directly opening it, or by manually (or automatically, if I find out how to) adding it to the system PATH variable.
- Step 2:
  - The user is greeted with a main page, which by itself lists out some of the main categories.
- Step 3:
  - The user can navigate between pages by typing their indexes into the CLI. This process repeats, until the user reaches a command layer, where the available commands for that subcategory will be listed.
- Step 4:
  - Type the command's index and let it do it's thing. It will ask for parameters and it will spit the results out.

### Other ideas
- It would be great, if the console could support rich and colorful text.
- It would be great, if I found a way to make a cool-looking layout for each command, to improve the readability and usability.

## Contributing
As I'm new to open source, I do not really have any contributing rules as of right now. This will change as time goes by and I manage to build out the infrastructure. After the infrastructure is done, I'll list the main ways of contributing here. If you see something wrong with the code, feel free to point it out!

## Changelogs

*The major changes can be found at [CHANGELOG.md](https://github.com/thatgato/SCLI/blob/main/CHANGELOG.md)*