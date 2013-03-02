QxPoly2Tri
=========

[Poly2Tri](http://code.google.com/p/poly2tri/) wrapper class for Qt.

How to use
----------

1. Run and build QxPoly2Tri.pro.
2. Include QxPoly2Tri.pri to your project file.

Repository
----------

You can get the current development version from the [git repository](https://github.com/Skyrpex/QxPoly2Tri).

About Poly2Tri
--------------

A 2D constrained Delaunay triangulation library. Based on the paper "Sweep-line algorithm for constrained Delaunay triangulation" by V. Domiter and and B. Zalik

Caution
-------

Since there are no input validation of the data given for triangulation you need to think about this. QxPoly2Tri does not support repeat points within epsilon.

* If you have a cyclic function that generates random points make sure you don't add the same coordinate twice.
* If you are given input and aren't sure same point exist twice you need to check for this yourself.
* Only simple polygons are supported. You may add holes or interior Steiner points.
* Interior holes must not touch other holes, nor touch the polyline boundary.