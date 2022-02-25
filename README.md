Blusher
=======

A Desktop GUI Toolkit for Linux with Wayland written in C++.

Introduction
------------

Blusher is a desktop GUI toolkit built on Wayland. This version of Blusher is using
Qt as a backend.

Blusher using Cairo as a 2D graphics engine and Pango for text rendering.


Dependencies
------------
Blusher has a dependency on `libblusher`. And it depends on `blusher-core` and `blusher-svg`.

Below is the list of all dependencies of those.

- Cairo
- Pango
- librsvg


Blusher is not...
-----------------
- a cross-platform GUI toolkit. We will support only Linux.
- for X11 systems. It supports only Wayland.
- for custom themes. It has its own design called Hydrogen, inspired by the KDE Oxygen theme.


License
-------
Blusher is developed under MIT License. For the detail, see the LICENSE file.

