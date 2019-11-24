# Welcome!
![logo](https://github.com/portasynthinca3/neutron/blob/master/gfx/logo_cut.png "logo")\
*Neutron logo*\
**So, you somehow got to this page.** I really appreciate it, thank you!
# What's the purpose?
Neutron is the result of me trying to get into the low-level stuff. That means, writing in assembly. This is quite a new
experience for me as the lowest i've ever got was writing code in C++ for the AVR micro series.\
This project is **not** intended to do some crazy stuff like replacing the giants like Windows, Linux and macOS. No-no, that's just not possible. However, it doesn't mean i don't have an end goal. **The end goal is to write a simple OS that can run in 32-bit protected mode, complete with GUI and 3rd party applications, while requiring as little disk space, RAM and processor resources as possible**
# Who is involved?
* Me, Andrey Antonenko, the creator, maintainer and programmer
* Sasha Kulichkov, booted this on his PC several times
# List of features
Symbols:\
✔️ means that the feature is implemented.\
❌ means that the feature is going to be implemented.\
❌❌ means that the feature was going to be implemented, but was crossed out for some reason (it was too difficult for me to do, etc.)
* ✔️ bootloader
* ✔️ bootloader commandline on kernel load fail
* ✔️ bootloader disk I/O and FS
* ✔️ running in 32-bit protected mode
* ✔️ 640x480 256c VESA video mode
* ✔️ graphical font rendering
* ❌ keyboard input
* ✔️ mouse input
* ✔️ memory allocation
* ❌ memory freeing
* ❌ disk I/O in kernel
* ❌ multitasking
* ✔️ error screen
* ❌ not crashing on a real PC
* ❌ running apllications
* ❌ window manager
* ❌❌ writing everything completely in assembly
# What parts does this consist of?
1. First stage loader, called Muon-1
2. Second stage loader, called Muon-2
3. The monolithic kernel. So monolithic in fact, that all the system processes, even the graphics, are integrated. It's called Quark.
4. The font converter. Written in C#
5. The custom builder. Written in Python.

These names were chosen because real neutrons are made of quarks and muons
# Okay, what do I need to be aware of?
Keep in mind that the system is unstable. I am **not** responsible for **any** kind of damage.
However, please tell me if you have found a bug, especially if it's dangerous enough to do any damage. That would be very nice!
# Can I join the team?
Sorry, I don't think so. I want to do this project entirely on my own, at least yet.
