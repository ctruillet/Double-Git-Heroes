#!/bin/sh

#Permet de lancer un serveur X
export DISPLAY=:0

#On lance Gnuplot
gnuplot ../data/gnuplot_param/rossler_param

