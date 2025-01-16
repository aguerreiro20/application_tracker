# Application tracker (written in C++)

Hi there !
Thank you for your interest the project !

## I. Intro
This was written in order to help keep track of my job applications (and avoid spamming the same companies...).
Another objective was for me to improve my skills on another language that I'm interested in besides Java.

## II. Getting started 
### A. Requirements
- The compilation script mentions c++20. However, it can also be run with c++17 but not earlier
- The program has been exclusively tested on a Linux system. 
If you encounter issues on a Windows system and would like them fixed, feel free to let me know! 
For Mac you'll have to offer me one :)

### B. Compile and run
- Simply run the compile script present in the project `./compile.sh`
- Run the program `./prog`
- After adding a few applications **and** exiting the CLI, the current progress is then saved and can be viewed via `./showDb.sh`

## III. How it works overall
### A) Intent and companies
The point of the project is to 
- add new companies/applications as jobs are being applied for in real time (saved in **applications.db** btw)
- check later if a given company is already listed (in order to not apply for the same)

### B) Menu
When running the program, the user is presented with a menu from which he/she can choose between
- Searching (and if not found potentially adding) a new company by typing directly its name
- quitting the program (by entering 0)
- displaying all applications (1)
- updating the status of an application (2)
- deleting an application (3)

### C) Platforms
When adding a company, the user will also be prompted to choose the platform on which he/she applied.
- Entering 0 gives the user the option to add a new job board / platform to the list (saved in **platforms.db**)
- Othewise the user can choose between 1 and n where n is the number of added platforms since the first run of the program
