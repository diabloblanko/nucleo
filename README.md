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
To run Nucleo, execute command below
```bash
./run
```
## Choosing Init
You can choose of two different inits: NeoInit and RInit
### NeoInit
Pros:
* C-Written shell, if you are into it.
* Simple && lightweight
* Faster
* Easy service managing tools
* C-Written


Cons:
* May be not enough functions
### RInit
Pros:
* Python-written shell, if you are into it.
* Working with blocks
* C-Written


Cons:
* Bigger than NeoInit
* No service managing tools

## Fetchs
### Neoinit -v
![ee](https://i.ibb.co/JFgHnZB0/neoinit-ffe.png)
### Fetch(ported from WhiteDevilOS)
![ee](https://i.ibb.co/v6KLz2CL/nucleo-wdf.png)
### Whitedevilfetch(with RInit logs)
![ee](https://i.ibb.co/Kcjv3bg2/rinit.png)
