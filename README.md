# PasswordVault-C-GTK
🎯 A very simple password vault written in C with GTK3. 

🧩 Login GTK page.

## Requirements : 

* A C compiler
* The [GTK library](https://www.gtk.org) (GTK3 is used here)

## How to use ? 

* Start by cloning the repository (`src` folder). 
* Then you can add your login credentials in the file `show_data.c`.
* You can change your password in the verification function of `window.c`.
* Compile the program with : 

`gcc $(pkg-config --cflags gtk+-3.0) *.c -o PasswordVault-Louiss-exe $(pkg-config --libs gtk+-3.0)`

* And that's it ! 

## Screenshots : 

![Login](https://github.com/Louiss-exe/PasswordVault-C-GTK/blob/main/s1.png "Budgie - Solus")

![View Data](https://github.com/Louiss-exe/PasswordVault-C-GTK/blob/main/s2.png "data")

## ⚠️ WARNING : 
Do not use this software for too confidential data. (confidential data is converted to binary. The data can be hacked).
