# Image_processing
Basic image processing program for grayscale images (.pgm format).

In the implementation I used public inheritance. The base class -called ImageProcessor- contains the concept of a general image processing operation with a pure virtual function, named process_image(). The methods for read-in process and saving the processed image are also implemented here. All the derived classes do one specific image processing operation by overriding the base class' virtual process_image() function. Some minor addition to the program still needed, such as exception handling, but it's already fully operational. I also uploaded some sample images, and processed samples as well.
