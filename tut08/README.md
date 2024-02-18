# Task Description

The task is to develop a program to analyze targets tracked by radars.

We consider military targets and and own radar posts. The targets are determined by their x and y coordinates. The radars are described by their coordinates (again x and y coordinate) and a ranges. All coordinates/ranges are decimal numbers. The task is to determine the number of targets tracked by each radar.

The input is a list of the targets mixed with the list of radars. A target is described as T x y where x and y are decimal coordinates. A radar is described as R x y radius where x and y are decimal coordinates and radius is the range of the radar (the range is a decimal number). A radar can track only targets that are in the distance radius or closer.

The output of the program is a list of the radars and the number of targets the radar can track. The order of the radars in the output corresponds to the order of the radars in the input. The output format is clear from the example runs below.

If the input is invalid, the program must reject it. Use standard output to print the error message (do not use standard error output). The following is considered an error:

the input is neither a radar nor a target,
a coordinate is invalid (not a decimal, is missing),
radar range is invalid (not a decimal, is missing, is zero or negative).