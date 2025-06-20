# Nucleo POS 1
###### POS stands for Pseudo-operating system
## Authors
https://github.com/diabloblanko
Made all project, NeoInit, Most part of README.md

https://github.con/maldidev
Participant, made RInit, a bit of README.md

## Running
### First time running
Before you run Nucleo for first time, you have to select Init.(check Choosing Init)
Write your choice to init.conf
#### NeoInit
```bash
rm .init.conf && echo "neoinit" > .init.conf
```
#### RInit
```bash
rm .init.conf && echo "rinit" > .init.conf
```
## After choosing init
```bash
To run Nucleo, execute command below
```bash
./run
```
## Choosing Init
You can choose of two different inits: NeoInit and RInit
NOTE: NeoInit and RInit have a bit different shell.
### NeoInit
Pros:
* Simple
* Lightweight
* Easy service managing tools
* C-Written
Cons:
* May be not enough functions
### RInit
Pros:
* Fast
* Working with blocks
* C-Written

Cons:
* Bigger than NeoInit
* No service managing tools